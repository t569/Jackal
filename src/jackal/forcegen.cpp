#include <jackal/forcegen.h>


namespace Jackal
{
    // FORCE FIELDS
    // instantiate the gravity with the required acceleration
     ParticleCustomGravityForce::ParticleCustomGravityForce(const Vector3& gravity): gravity_accel(gravity){};

    void ParticleCustomGravityForce::updateForce(Particle *particle, numeric interval_dt) 
    {
        // has infinite mass, then dont apply any gravity 
        if(!particle->getInverseMass()) return;
        particle->addForce(gravity_accel* particle->getMass());
    }


    // SPRING FORCES
    ParticleSpringForce::ParticleSpringForce(numeric spring_const, numeric rest_len,Particle* f_source) :spring_constant(spring_const), rest_length(rest_len), force_source(f_source){}
    
    void ParticleSpringForce::updateForce(Particle *force_reciever, numeric interval_dt)
    {
        Vector3 force(0,0,0);
        
        //  get the positions
        force += force_reciever->getPosition();
        force -= force_source->getPosition();

        // get the magnitude of the force
        numeric mag = std::abs(force.magnitude() - rest_length);

        // now incorperate the spring constant
        mag *= spring_constant;

        // normalise the force to get the direction
        force.normalize();
        force *= -mag;

        force_reciever->addForce(force);

    }


    // FORCE ENTRIES
    void ForceStack::add(Particle* particle, ParticleForceGenerator* force_gen)
    {
        forcesAtWork.emplace_back(particle, force_gen);     // add a force stack entry
    }
    

    // remove a force stack entry
    void ForceStack::remove(Particle* particle, ParticleForceGenerator* force_gen)
    {
       std::vector<ForceStackEntry>::iterator stack_pointer; 
       size_t st_p = 0;
       for(stack_pointer = forcesAtWork.begin(); stack_pointer != forcesAtWork.end(); stack_pointer++)
       {
            if(stack_pointer->particle == particle && stack_pointer->forcegen == force_gen)
            {
                forcesAtWork.erase(forcesAtWork.begin() + st_p);
                return;
            }
            st_p++;
       }
    }

    void ForceStack::updateAllForces(numeric interval_dt)
    {
        std::vector<ForceStackEntry>::iterator stack_pointer;
        for(stack_pointer = forcesAtWork.begin(); stack_pointer != forcesAtWork.end(); stack_pointer++)
        {
            stack_pointer->forcegen->updateForce(stack_pointer->particle,interval_dt);
        }
    }

    // WRAPPER AROUND THE std::vector clear function: Removes all the ForceEntries in the ForceStack
    void ForceStack::clear()
    {
        forcesAtWork.clear();
    }
}
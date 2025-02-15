#include <jackal/particle.h>
#include <assert.h>

namespace Jackal 
{
    numeric Particle::getInverseMass() const
    {
        return (*this).inverseMass;
    }

    void Particle::setInverseMass(numeric inv_mass)
    {
        (*this).inverseMass = inv_mass;
    }

    numeric Particle::getMass() const
    {
        assert(inverseMass > 0.0);  // cannot return an infinite mass explcitly
        return static_cast<numeric>(1)/inverseMass;
    }

    void Particle::setMass(numeric mass_set)
    {
        assert(mass_set > 0.0);     // ensures that the mass being set is not zero to ensure no infinite zero mass
        (*this).inverseMass = static_cast<numeric>(1)/mass_set;
    }

    /* TODO: write the integrator function well */
    void Particle::integrate(numeric interval_dt)
    {
        assert(interval_dt > 0.0);

        // dont integrate anything with zero invers mass i.e. infinite mass
        if(inverseMass <= static_cast<numeric>(0.0)) return;


        // update the position
        position.addScaledVector(velocity, interval_dt);

        /* i can remove this if the accelerations are relatively small */
        position.addScaledVector(acceleration,interval_dt*interval_dt*0.5);


        // work out the and update acceleration from current force
        // acceleration will then be force_accel + default_accel
        Vector3 update_Accel = acceleration;    
        update_Accel.addScaledVector(forceAccumulator, inverseMass);


        // update the velocity
        velocity.addScaledVector(update_Accel, interval_dt);


        // work out the drag
        velocity *= std::pow(damping, interval_dt);

        // clear the forces
        clearAccumulator();

    }

    void Particle::setDamping(numeric damping_factor)
    {
        damping = damping_factor;
    }

    numeric Particle::getDamping() const{
        return damping;
    }

    void Particle::setPosition(const Vector3& position)
    {
        (*this).position = position;
    }

    void Particle::setPosition(const numeric x, const numeric y, const numeric z)
    {
        position.x = x;
        position.y = y;
        position.z = z;
    }

    Vector3 Particle::getPosition() const
    {
        return position;
    }

    
    void Particle::setVelocity(const Vector3& velocity)
    {
        (*this).velocity = velocity;
    }

    void Particle::setVelocity(const numeric v_x, const numeric v_y, const numeric v_z)
    {
        velocity.x = v_x;
        velocity.y = v_y;
        velocity.z = v_z;
    }

    Vector3 Particle::getVelocity() const
    {
        return velocity;
    }

    
    void Particle::setAcceleration(const Vector3& accel)
    {
        (*this).acceleration = accel;
    }

    void Particle::setAcceleration(const numeric a_x, const numeric a_y, const numeric a_z)
    {
        acceleration.x = a_x;
        acceleration.y = a_y;
        acceleration.z = a_z;
    }

    Vector3 Particle::getAcceleration() const
    {
        return acceleration;
    }

    /* clear the accumulator */
    void Particle::clearAccumulator()
    {
        forceAccumulator.clear();
    }
    
    /* add forces to the accumulator */
    void Particle::addForce(const Vector3& force)
    {
        forceAccumulator += force;
    }

    /* addForce alternate form */
    void Particle::addForce(const numeric f_comp_x, const numeric f_comp_y, const numeric f_comp_z)
    {
        forceAccumulator.x += f_comp_x;
        forceAccumulator.y += f_comp_y;
        forceAccumulator.z += f_comp_z;
    }
}


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
    void Particle::integrate(numeric interval)
    {
        assert(interval > 0.0);

        // work out the position

        // work out the acceleration

        // work out the velocity

        // work out the drag


    }
}
#ifndef PARTICLE_H
#define PARTICLE_H

#include <jackal/core.h>    // for the vector functionality

namespace Jackal
{
    class Particle
    {
        public:
            Vector3 position;

            Vector3 velocity;

            Vector3 acceleration;

        protected:
            numeric inverseMass;    // more useful to store the inverse mass of the object

        public:
            /* getters and setters for the mass */
            numeric getInverseMass() const;
            numeric getMass() const;
            void setInverseMass(numeric inverse_mass);
            void setMass(numeric mass_set);

            void integrate(numeric interval);   // integrate the particles position and acceleration over time

    };
}

#endif
#ifndef JACKAL_PARTICLE_H
#define JACKAL_PARTICLE_H

#include <jackal/core.h>    // for the vector functionality

namespace Jackal
{
    class Particle
    {
        public:
            Vector3 position;

            Vector3 velocity;

            Vector3 acceleration;

            Vector3 forceAccumulator;

            numeric damping;

        protected:
            numeric inverseMass;    // more useful to store the inverse mass of the object

        public:

            // integrate the particles position and acceleration over time
            void integrate(numeric interval_dt); 


            /* getters and setters for the mass */
            numeric getInverseMass() const;
            numeric getMass() const;
            void setInverseMass(numeric inverse_mass);
            void setMass(numeric mass_set);

            /* getters and setters for the damping factor */
            void setDamping(numeric damping_value);
            numeric getDamping() const;

            /* getters and setters for position */
            void setPosition(const Vector3& position);
            void setPosition(const numeric x, const numeric y, const numeric z);
            Vector3 getPosition() const;

            /* getters and setters for velocity */
            void setVelocity(const Vector3& velocity);
            void setVelocity(const numeric v_x, const numeric v_y, const numeric v_z);
            Vector3 getVelocity() const;

            /* getters and setters for acceleration */
            void setAcceleration(const Vector3& accel);
            void setAcceleration(const numeric a_x, const numeric a_y, const numeric a_z);
            Vector3 getAcceleration() const;

            /* force functions */
            void clearAccumulator();
            void addForce(const Vector3& force);
            void addForce(const numeric f_comp_x, const numeric f_comp_y, const numeric f_comp_z);
            

    };
}

#endif
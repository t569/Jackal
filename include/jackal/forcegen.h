#ifndef JACKAL_FORCE_GEN_H
#define JACKAL_FORCE_GEN_H
#include <jackal/particle.h>
#include <vector>
namespace Jackal
{
    class ParticleForceGenerator
    {
        // the duration of the force is needed by some force generators
        public:
            virtual void updateForce(Particle *particle, numeric interval_dt) = 0;
    };

    class ParticleCustomGravityForce : public ParticleForceGenerator
    {
        protected:
            Vector3 gravity_accel;

        public:
            ParticleCustomGravityForce(const Vector3& gravity);
            void updateForce(Particle *particle, numeric interval_dt) override;
    };

    class ParticleSpringForce : public ParticleForceGenerator
    {
        protected:
            numeric spring_constant;
            numeric rest_length;
            Particle* force_source;

        public:
            //
            ParticleSpringForce(numeric spring_const, numeric rest_len, Particle* f_source);
            void updateForce(Particle *force_reciever, numeric interval_dt) override;
    };


    class ForceStack
    {
        struct ForceStackEntry
        {
            Particle* particle;
            ParticleForceGenerator* forcegen;
        };
        protected:
             std::vector<ForceStackEntry> forcesAtWork;


        public:
            void add(Particle* particle, ParticleForceGenerator* force_gen);
            void remove(Particle* particle, ParticleForceGenerator* force_gen);
            void clear();
            void updateAllForces(numeric interval_dt);
    };
}
#endif
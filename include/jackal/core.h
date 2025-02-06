#ifndef CORE_H
#define CORE_H

#include <cmath>    // this is subject to change in the future


namespace Jackal    // the definition of the numerical precision system
{
    using numeric = float;    
    using sqrt_type = numeric(*)(numeric);
    sqrt_type sqrt = std::sqrt;  // overloaded sqrt that works for any numeric type
}

namespace Jackal
{
    class Vector3
    {
        public:
            numeric x;

            numeric y;

            numeric z;

        /*
        private:
            numeric padding;    // addition paddinf for word alignment
        */

       public:
            Vector3();      // the zero value constructor

        public:
            Vector3(numeric x, numeric y, numeric z);     // constructor for initialised values

            Vector3 operator*(const numeric value) const;       // scalar multiplication to return a copy of a 3d vector

            Vector3 operator+(const Vector3& other) const;     

            Vector3 operator-(const Vector3& other) const;

            void operator *= (const numeric value);       // scalar multiplcation

            void operator += (const Vector3& other);      // Vector3 update addition

            void operator -= (const Vector3& other);      // Vector3 update subtraction
            

            void invert();

            void normalize();

            numeric magnitude() const;                   // get the magnitude of the vector

            numeric squareMagnitude() const;             // get the square magnitude





    };
}
#endif
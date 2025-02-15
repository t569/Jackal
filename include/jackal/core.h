#ifndef CORE_H
#define CORE_H

/* NOTE: THIS IS A RIGHT HANDED SYSTEM */
#include <cmath>    // this is subject to change in the future

namespace Jackal    // the definition of the numerical precision system
{
    using numeric = float;    
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

            numeric operator*(const Vector3& other) const;      // by default the dot Porduct

            Vector3 operator+(const Vector3& other) const;     

            Vector3 operator-(const Vector3& other) const;

            void operator *= (const numeric value);       // scalar multiplcation

            void operator += (const Vector3& other);      // Vector3 update addition

            void operator -= (const Vector3& other);      // Vector3 update subtraction
            
            void addScaledVector(const Vector3& other, numeric scale_num);  // add a scaled Vector3

            Vector3 componentProduct(const Vector3& other);     // component product

            void componentProductUpdate(const Vector3& other);  // update the current Vector3 using the component product

            numeric scalarProduct(const Vector3& other) const;    // the dot product

            Vector3 vectorProduct(const Vector3& other) const;

            void invert();

            void normalize();

            numeric magnitude() const;                   // get the magnitude of the vector

            numeric squareMagnitude() const;             // get the square magnitude

            void clear();



    };
}
#endif
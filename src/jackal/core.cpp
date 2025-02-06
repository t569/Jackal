#include <jackal/core.h>


namespace Jackal{
    Vector3::Vector3(): x(0), y(0), z(0) {};    // zero value constructor

    Vector3::Vector3(numeric j_x, numeric j_y, numeric j_z): x(j_x), y(j_y), z(j_z) {};


    /* returns a scaled Vector3 object */
    Vector3 Vector3::operator*(const numeric value) const
    {
        return Vector3(x * value, y * value, z * value);
    }


    /* the dot product */
    numeric Vector3::operator*(const Vector3& other) const 
    {
        return x*other.x + y*other.y + z*other.z;
    }


    /* returns the sum of two Vector3 objects as a Vector3 object */
    Vector3 Vector3::operator+(const Vector3& other) const
    {
        return Vector3((*this).x + other.x, (*this).y + other.y, (*this).z + other.z);
    }


    /* returns the difference of two Vector3 objects as a Vector3 object */
    Vector3 Vector3::operator-(const Vector3& other) const
    {
        return Vector3((*this).x - other.x, (*this).y - other.y, (*this).z - other.z);
    }


    /* update a Vector3 by scaling up by value */
    void Vector3::operator*=(const numeric value)
    {
        x *= value;
        y *= value;
        z *= value;

    } 


    /* update a Vector3 by suming a Vector3 object into it */
    void Vector3::operator+=(const Vector3& other)
    {
        x += other.x;
        y += other.y;
        z += other.z;
    }


    /* update a Vector3 by subtracting a Vector3 object from it */
    void Vector3::operator-=(const Vector3& other)
    {
        x -= other.x;
        y -= other.y;
        z -= other.z;
    }


    /* add a Scaled Vector3 to self */
    void Vector3::addScaledVector(const Vector3& other, numeric num)
    {
        x += (other.x)*num;
        y += (other.y)*num;
        z += (other.z)*num;
    }


    /* the component product of 2 Vector3 s */
    Vector3 Vector3::componentProduct(const Vector3& other)
    {
        return Vector3((*this).x * other.x, (*this).y * other.y, (*this).z * other.z);
    }



    /* the self updated component product */
    void Vector3::componentProductUpdate(const Vector3& other)
    {
        x *= other.x;
        y *= other.y;
        z *= other.z;
    }



    /* the scalar/dot product between two vectors */
    numeric Vector3::scalarProduct(const Vector3& other) const
    {
        return x*other.x + y*other.y + z*other.z;
    }



    /* the vector/cross product between two vectors producing a vector itself */
    Vector3 Jackal::Vector3::vectorProduct(const Vector3& other) const 
    {
        return Vector3(y*other.z - z*other.y,
                    z*other.x - x*other.z,
                    x*other.y - y*other.x);
    }



    /* invert the values of the Vector3 */
    void Vector3::invert()
    {
        x= -x;
        y = -y;
        z = -z;
    }

    /* transform the Vector3 into a unit vector */
    void Vector3::normalize()
    {
        numeric length = squareMagnitude();

        (*this) *= static_cast<numeric>(1)/(length);
    }


    numeric Vector3::magnitude() const  // these names are getting disgusting lmao
    {
        return sqrt(x*x + y*y + z*z);   // look into the code for sqrt
    }

    numeric Vector3::squareMagnitude() const
    {
        return x*x + y*y + z*z;
    }
}
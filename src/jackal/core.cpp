#include <jackal/core.h>



Jackal::Vector3::Vector3(): x(0), y(0), z(0) {};    // zero value constructor

Jackal::Vector3::Vector3(numeric j_x, numeric j_y, numeric j_z): x(j_x), y(j_y), z(j_z) {};


/* returns a scaled Vector3 object */
Jackal::Vector3 Jackal::Vector3::operator*(const numeric value) const
{
    return Vector3(x * value, y * value, z * value);
}


/* returns the sum of two Vector3 objects as a Vector3 object */
Jackal::Vector3 Jackal::Vector3::operator+(const Jackal::Vector3& other) const
{
    return Vector3((*this).x + other.x, (*this).y + other.y, (*this).z + other.z);
}


/* returns the difference of two Vector3 objects as a Vector3 object */
Jackal::Vector3 Jackal::Vector3::operator-(const Jackal::Vector3& other) const
{
    return Vector3((*this).x - other.x, (*this).y - other.y, (*this).z - other.z);
}


/* update a Vector3 by scaling up by value */
void Jackal::Vector3::operator*=(const numeric value)
{
    x *= value;
    y *= value;
    z *= value;

} 


/* update a Vector3 by suming a Vector3 object into it */
void Jackal::Vector3::operator+=(const Jackal::Vector3& other)
{
    x += other.x;
    y += other.y;
    z += other.z;
}


/* update a Vector3 by subtracting a Vector3 object from it */
void Jackal::Vector3::operator-=(const Jackal::Vector3& other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
}


/* invert the values of the Vector3 */
void Jackal::Vector3::invert()
{
    x= -x;
    y = -y;
    z = -z;
}

/* transform the Vector3 into a unit vector */
void Jackal::Vector3::normalize()
{
    numeric length = squareMagnitude();

    (*this) *= static_cast<numeric>(1)/(length);
}


Jackal::numeric Jackal::Vector3::magnitude() const  // these names are getting disgusting lmao
{
    return sqrt(x*x + y*y + z*z);   // look into the code for sqrt
}

Jackal::numeric Jackal::Vector3::squareMagnitude() const
{
    return x*x + y*y + z*z;
}
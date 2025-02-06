#include <jackal/core.h>
#include <iostream>
using namespace Jackal;

int main()
{
    Vector3 v1(1, 2, 3);
    Vector3 v2(4, 5, 6);
    Vector3 v3 = v1 + v2;

    std::cout<<"The Jackal Engine!"<<std::endl;
    std::cout<<v1.scalarProduct(v2)<<std::endl;
    std::cout<<v2.scalarProduct(v1)<<std::endl;
    std::cout<<"x: "<<v3.x<<"y: "<<v3.y<<"z: "<<v3.z<<std::endl;
    return 0;   // don't do anything yet nothing yet
}
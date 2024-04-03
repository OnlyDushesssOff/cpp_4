#include "Vector.h"

int main(){

    Vector<int> vector2 = {6, 8};
    Vector<int> vector3 = { 0, 0 };
    vector3 = vector2; 
    std::cout << vector3;  
}
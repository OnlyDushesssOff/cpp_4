#include "Vector.h"

int main(){

    Vector<int> vector1 = {11, 11};
    Vector<int> vector2 = {6, 8};
    vector1 = vector2;
    int* array3 = new int(2);
    array3[0] = 99;
    array3[1] = 99;
    vector1.SetArray(array3);
    std::cout << vector1 << vector2;  
}
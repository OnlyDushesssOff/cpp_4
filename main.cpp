#include "Matrix.h"

int main(){

    Vector<int> vector1 = {1, 2, 3, 4, 5};
    Vector<int> vector2 = {10, 20, 30, 40, 50};

    std::cout << "Sum = " << vector1 + vector2 << std::endl;
    std::cout << "Raz = " << vector1 - vector2 << std::endl;
    std::cout << "Scal = " << vector1 * vector2 << std::endl;

    Vector<int> vector3 = {8, 6};
    std::cout << "Leng = " << vector3.GetLeng() << std::endl;
    std::cout << "Normalize = " << vector3.Normaliz() << std::endl;
    
    Vector<double>* vec1 = new Vector<double>[3];
    for(int i = 0; i < 3; i++){
        vec1[i] = Vector<double>(3);
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            vec1[i][j] = i * 3 + j + 1;
        }
    }
    Matrix<double> mat1 = Matrix<double>(3, vec1);

    Vector<double>* vec2 = new Vector<double>[3];
    for(int i = 0; i < 3; i++){
        vec2[i] = Vector<double>(3);
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            vec2[i][j] = (i * 3 + j + 1) * 10;
        }
    }
    Matrix<double> mat2 = Matrix<double>(3, vec2);
    std::cout << mat2 - mat1;
}
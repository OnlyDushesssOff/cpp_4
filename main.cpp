#include "Matrix.h"

template<typename T>
double Scal_Proiz(const Vector<T>& vec1, const Vector<T>& vec2){ // если надо вернуть ссылку из функции, то и переменные, которые мы вносим, передаем через ссылку
    double scal = vec1 * vec2;
    return scal;
}

int main(){

    Vector<int> vector1 = {1, 2, 3, 4, 5};
    Vector<int> vector2 = {10, 20, 30, 40, 50};

    std::cout << "Sum = " << vector1 + vector2 << std::endl;
    std::cout << "Raz = " << vector1 - vector2 << std::endl;
    std::cout << "Scal = " << vector1 * vector2 << std::endl;

    Vector<int> vector3 = {8, 6};
    std::cout << "Leng = " << vector3.GetLeng() << std::endl;
    std::cout << "Normalize = " << vector3.Normaliz() << std::endl;
    double res = Scal_Proiz(vector1, vector2);
    std::cout << res <<std::endl;

}
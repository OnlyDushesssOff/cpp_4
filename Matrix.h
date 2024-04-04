#include "Vector.h"

template<typename T>
class Matrix{
private:
    Vector<T>* _vectors;
    size_t _size;

public:
    Matrix() = delete;

    Matrix(size_t rows, size_t cols){
        _size = rows;
        _vectors = new Vector<T>[rows];
        for(size_t i = 0; i < _size; i++){
            _vectors[i] = Vector<T>(cols);
        }
    }

    ~Matrix(){
        delete [] _vectors;
    }

    Vector<T>& operator[](int index){
        return _vectors[index];
    }

    const Vector<T>& operator[](int index) const {
        return _vectors[index];
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matr){
        for(size_t i = 0; i < matr._size; i++){
            os << matr._vectors[i] << std::endl;
        }
        return os;
    }

    /*1.перегрузить оператор сложения, разности, умножения(на обратную), деления
      2.метод нахождения обратной матрицы
      3.нахождения определения определителя любого порядка
      4.метод транспонирование матриц
      5.предусмотреть рандомное заполнение матрицы(от 0 до 1)
      6.метод векторного произведения векторов(это задание на позоследующую неделю) в классе вектора*/
};
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

    Matrix(size_t size, Vector<T>* vec) {
        _size = size;
        _vectors = new Vector<T>[_size];
        for(size_t i = 0; i < _size; i++){
            _vectors[i] = Vector<T>(vec[0].GetSize());
        }
        for(int i = 0; i < _size; i++){
            for(int j = 0; j < vec[0].GetSize(); j++){
                _vectors[i][j] = vec[i][j];
            }
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

    template<typename F>
    Matrix operator+(const Matrix<F> mat) const {
        if(_size != mat._size || _vectors[0].GetSize() != mat._vectors[0].GetSize()){
            std::cout << "Matrix: input error";
            exit(0);
        }
        Matrix res = Matrix(_size, _vectors->GetSize());
        for(int i = 0; i < _size; i++){
            for(int j = 0; j < _vectors[0].GetSize(); j++){
                res[i][j] = _vectors[i][j] + mat._vectors[i].GetArray()[j];
            }
        }
        return res;
    }

    template<typename F>
    Matrix operator-(const Matrix<F> mat) const {
        if(_size != mat._size || _vectors[0].GetSize() != mat._vectors[0].GetSize()){
            std::cout << "Matrix: input error";
            exit(0);
        }
        Matrix res = Matrix(_size, _vectors->GetSize());
        for(int i = 0; i < _size; i++){
            for(int j = 0; j < _vectors[0].GetSize(); j++){
                res[i][j] = _vectors[i][j] - mat._vectors[i].GetArray()[j];
            }
        }
        return res;
    }

    /*1.перегрузить оператор сложения, разности, умножения(на обратную), деления
      2.метод нахождения обратной матрицы
      3.нахождения определения определителя любого порядка
      4.метод транспонирование матриц
      5.предусмотреть рандомное заполнение матрицы(от 0 до 1)
      6.метод векторного произведения векторов(это задание на позоследующую неделю) в классе вектора*/
};
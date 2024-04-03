#include <iostream>
#include <math.h>
#include <cstdint>

template<typename T>
class Vector {
private:
    T* _array;
    size_t _size;
    double _leng;

    double Leng() {
        double sum = 0;
        for (int i = 0; i < _size; i++) {
            sum += pow(_array[i], 2);
        }
        return pow(sum, 0.5);
    }

public:
    Vector() = delete; // если дефолтный конструктор не нужен, то пишем так, просто не написать его не получится
    Vector(size_t size, T* array) :_size(size), _array(new T[size]) {// если используются шаблоны, то лучше писать это в хидере, в срр это будет долго и нудно
        for (int i = 0; i < _size; i++) {
            _array[i] = array[i];
        }
        _leng = Leng();
    }

    Vector(size_t size) : _size(size) {// параметры можно выносить через двоеточие, но хз зачем оно надо
        _array = new T[size];
        for (int i = 0; i < _size; i++)
            _array[i] = 0;
        _leng = Leng();
    }

    Vector(std::initializer_list<T> list) { // конструктор для того, чтобы нароямую задавать векторы
        _size = list.size();
        _array = new T[_size];
        int i = 0;
        for (auto elem = list.begin(); elem != list.end(); elem++, i++) {
            _array[i] = *elem;
        _leng = Leng();
        }
    }

    ~Vector() { // деструктор, самоудаляется, когда перестает испоользоваться
        delete[] _array;
    }

    T& operator[](int i) {
        return _array[i];
    }

    inline int GetSize() const {
        return _size;
    }

    inline T* GetArray() const {
        return _array;
    }

    inline int GetLeng() const {
        return _leng;
    }

    Vector<double> Normaliz(){
        double* array = new double[_size];
        for(int i = 0; i < _size; i++){
            array[i] = _array[i] / _leng;
        }
        Vector<double> res = Vector<double>(_size, array);
        return res;
    }

    friend std::ostream& operator<< (std::ostream& os, const Vector& vec) {
        os << "(";
        for (int i = 0; i < vec._size; i++) {
            os << vec._array[i];
            if (i + 1 != vec._size)
                os << ", ";
        }
        os << ")";
        return os;
    }

    template<typename F>
    Vector operator+ (const Vector<F>& vec) const {
        size_t size = vec.GetSize();
        auto* array = vec.GetArray();
        if (_size != size) {
            std::cout << "Error input";
            exit(111);
        }
        T* array_res = new T[_size];
        for (int i = 0; i < _size; i++) {
            array_res[i] = _array[i] + array[i];
        }
        Vector vector = Vector(size, array_res);
        return vector;
    }

    template<typename F>
    Vector operator- (const Vector<F>& vec) const {
        size_t size = vec.GetSize();
        auto* array = vec.GetArray();
        if (_size != size) {
            std::cout << "Error input";
            exit(111);
        }
        T* array_res = new T[_size];
        for (int i = 0; i < _size; i++) {
            array_res[i] = _array[i] - array[i];
        }
        Vector vector = Vector(size, array_res);
        return vector;
    }
    
    template<typename F>
    double operator* (const Vector<F>& vec) const {
        size_t size = vec.GetSize();
        auto* array = vec.GetArray();
        if (_size != size) {
            std::cout << "Error input";
            exit(111);
        }
        double scal = 0;
        for(int i = 0; i < _size; i++)
            scal += _array[i] * array[i];
        return scal;
    }

    Vector operator=(const Vector& vec){
        _size = vec.GetSize();
        _leng = vec.GetLeng();
        _array = vec.GetArray();
        return *this;
    }

    inline void SetArray( T* array){
        _array = array;
    }
};
/* Домашка:
    1. перегрузка сложения, вычитания, скалярного умножения
    2. поиск длины
    3. нормализация(деление каждой координаты на длину)
    4. */
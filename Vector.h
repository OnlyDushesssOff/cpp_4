#include <iostream>

template<typename T>
class Vector{
private:
    T* _array;
    size_t _size;

public:
    Vector() = delete; // если дефолтный конструктор не нужен, то пишем так, просто не написать его не получится
    Vector(size_t size, T* array):_size(size), _array(new T[size]){// если используются шаблоны, то лучше писать это в хидере, в срр это будет долго и нудно
        for(int i = 0; i < _size; i++){
            _array[i] = array[i];
        }
    }

    Vector(size_t size): _size(size) {// параметры можно выносить через двоеточие, но хз зачем оно надо
        _array = new T[size];
        for(int i = 0; i < _size; i++)
            _array[i] = 0;
    }

    Vector(std::initializer_list<T> list){ // конструктор для того, чтобы нароямую задавать векторы
        _size = list.size();
        _array = new T[_size];
        int i = 0;
        for(auto elem = list.begin(); elem != list.end(); elem++, i++){
            _array[i] = *elem;
        }
    }

    ~Vector(){ // деструктор, самоудаляется, когда перестает испоользоваться
        delete [] _array;
    }

    T& operator[](int i){
        return _array[i];
    }

    friend std::ostream& operator<< (std::ostream& os, const Vector& vec){
        os << "(";
        for(int i = 0; i < vec._size; i++){
            os << vec._array[i];
            if(i+1 != vec._size)
                os << ", ";
        }
        os << ")";
        return os;
    }
};
/* Домашка:
    1. перегрузка сложения, вычитания, скалярного умножения
    2. поиск длины
    3. нормализация(деление каждой координаты на длину)
    4. */
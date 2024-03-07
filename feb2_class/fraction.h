#pragma once
#include <iostream>//хидер, описание файлов
#include <cstdint>

class fraction{
private: //запрещает доступ к полям класса
    int32_t _num; //числитель, всегда маленькая буква и _
    uint32_t _denom; //знаменатель, поля классов (в данном случае 2)


public:
    fraction(); //объявили конструктор (по умолчанию)
    fraction(int32_t num, uint32_t denom); //sмаленькие буквы с параметрами

    fraction(const fraction& fraction);//конструктор копирования

    fraction (double realfract);
    void reduce();

    operator double() const {
        return static_cast<double>(_num)/_denom;
    }

    fraction& operator=(const fraction& fra){
        _num=fra._num;
        _denom=fra._denom;
        return *this;
    }

    //перегрузка операции сложения - функция, знак  + как функция
    fraction operator+(const fraction& frac) const{
        int32_t new_num= _num* frac._denom + frac._num* _denom;
        uint32_t new_denom = _denom * frac._denom;
        fraction res=fraction(new_num, new_denom);
        return res;
    }

    fraction operator+(double rit) const{
        fraction res=*this +fraction(rit);
        return res;
    }

    fraction operator*(const fraction& fr) const{
        int32_t new_num=_num*fr._num;
        uint32_t new_denom = _denom * fr._denom;
        fraction res=fraction(new_num, new_denom);
        return res;
    }

     fraction operator/(const fraction& fr) const{
        int32_t new_num=_num*fr._denom;
        uint32_t new_denom = _denom * fr._num;
        fraction res=fraction(new_num, new_denom);
        return res;
    }
    


    void setnum(int32_t newnum);
    void setdenom(uint32_t newdenom);

    inline int32_t getnum(){
        return _num;
    }
    inline int32_t getnumdenom(){
        return _denom;
    }
    //bool Isvalid=true;
    void print(); //метод
    inline void printdouble(){
        std::cout << static_cast<double>(_num)/_denom << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& os, const fraction& tmp){
        os << tmp._num << "/" << tmp._denom;
        return os;
    } 

    bool operator>(const fraction& tmp) const{
        int32_t new_num=_num*tmp._denom;
        int32_t new_num1=tmp._num*_denom;
        return new_num>new_num1;
    }
    
    bool operator<(const fraction& tmp) const{
        int32_t new_num=_num*tmp._denom;
        int32_t new_num1=tmp._num*_denom;
        return new_num<new_num1;
    }

    bool operator==(const fraction& tmp) const{
        int32_t new_num=_num*tmp._denom;
        int32_t new_num1=tmp._num*_denom;
        return new_num==new_num1;
    }


    // ~fraction(){
    //     std::cout << "destructor" << this << std::endl;
    // }
};
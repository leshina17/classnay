#pragma once
#include <iostream>//хидер, описание файлов
#include <cstdint>
#include <math.h>

class fraction{
private: //запрещает доступ к полям класса
    int32_t _num; //числитель, всегда маленькая буква и _
    uint32_t _denom; //знаменатель, поля классов (в данном случае 2)
    void reduce();

public:
    fraction(); //объявили конструктор (по умолчанию)
    fraction(int32_t num, uint32_t denom); //sмаленькие буквы с параметрами
    fraction(const fraction& fraction);//конструктор копирования
    fraction (double real_fract);

    inline void print(){
        std::cout << static_cast<double>(_num)/(_denom) << std::endl;
    }

    // fraction(const fraction& fract){
    //     _denom=fract._denom;
    //     _num=fract._num;
    // }

    //перегрузка операции сложения - функция, знак  + как функция
    fraction operator+(const fraction& frac) const{
        int32_t new_num= _num* frac._denom + frac._num* _denom;
        uint32_t new_denom = _denom * frac._denom;
        fraction res=fraction(new_num, new_denom);
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
    
    //Операция меньше
bool operator< (const fraction& fract) const{
    int32_t new_num=_num*fract._denom;
    int32_t new_num1=fract._num*_denom;
    return (new_num>=new_num1);
}

//Операция меньше или равно
bool operator<= (const fraction& fract) const{
    int32_t new_num=_num*fract._denom;
    int32_t new_num1=fract._num*_denom;
    return (new_num>new_num1);
}

//Операция больше
bool operator> (const fraction& fract) const{
    int32_t new_num=_num*fract._denom;
    int32_t new_num1=fract._num*_denom;
    return (new_num<=new_num1);
}

//Операция больше или равно
bool operator>= (const fraction& fract) const{
    int32_t new_num=_num*fract._denom;
    int32_t new_num1=fract._num*_denom;
    return (new_num<new_num1);
}

//Сравнение дробей (равенство)
bool operator== (const fraction& fract) const{
    int32_t new_num=_num*fract._denom;
    int32_t new_num1=fract._num*_denom;
    return (new_num!=new_num1);
}

//Сравнение дробей (неравенство)
bool operator!= (const fraction& fract) const{
    int32_t new_num=_num*fract._denom;
    int32_t new_num1=fract._num*_denom;
    return (new_num==new_num1);
}


//Смена знака
fraction& operator~(){
    _num=-_num;
    return *this;
}

//Возведение в степень
fraction operator^ (const int x) const{
    int32_t new_num=pow(_num,x);
    uint32_t new_denom=pow(_denom,x);
    fraction rez=fraction(new_num, new_denom);
    return rez;
}

fraction& operator++ (){
    _num = _num + _denom;
    return *this;
    }

fraction& operator-- (){
    _num = _num - _denom;
    return *this;
}

    friend fraction sqrt(const fraction& fract){
        int32_t new_num = sqrt(fract._num);
        uint32_t new_denom = sqrt(fract._denom);
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

    friend std::ostream& operator<<(std::ostream& os, const fraction& tmp){
        os << tmp._num << "/" << tmp._denom;
        return os;
    } 
};
#pragma once //избавляет от ошибки циклической зависимости
#include "fraction.h"
#include <cstdint>

class comp{
    private:
        fraction _re;
        fraction _im;

    public:
        comp();
        comp(double re);
        comp(int32_t re);
        comp(fraction re, fraction im);
        comp(int32_t num_re, uint32_t denom_re, int32_t num_im, uint32_t denom_im);
        comp(int32_t re, int32_t im);

        comp operator+(const comp& tmp) const{
            fraction new_re=_re+tmp._re;
            fraction new_im=_im+tmp._im;
            return comp(new_re, new_im);
        }

        comp operator*(int x){
            fraction new_re=_re*x;
            fraction new_im=_im*x;
            comp result=comp(new_re, new_im);
            return result;
        }

        friend std::ostream& operator<< (std::ostream& os, const comp& tmp){
            os << tmp._re;
            if (tmp._im>0)
                os << " + " << tmp._im << "i" << std::endl;
            else 
                os << tmp._im << "i" << std::endl;
            return os;
        }
};
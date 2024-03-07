#pragma once //избавляет от ошибки циклической зависимости
#include "fraction.h"

class comp{
    private:
        fraction _re;
        fraction _im;

    public:
        comp();
        comp(fraction re, fraction im);
        comp(int32_t num_re, uint32_t denom_re, int32_t num_im, uint32_t denom_im);

        comp operator+(const comp& complex) const{
            fraction new_re=_re+complex._re;
            fraction new_im=_im+complex._im;
            return comp(new_re, new_im);
        }

        friend std::ostream& operator <<(std::ostream& os, const comp& tmp){
            os << tmp._re;
            if (tmp._im>0) 
                os << " + " << tmp._im << "i" << std::endl;
            else 
                os << tmp._im << "i" << std::endl;
            return os;
        }
};
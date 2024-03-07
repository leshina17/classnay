#include "comp.h"

comp::comp(){
    _re=fraction();
    _im=fraction();
}

comp::comp(fraction re, fraction im){
    _re=fraction(re);
    _im=fraction(im);
}
comp::comp(int32_t num_re, uint32_t denom_re,int32_t num_im, uint32_t denom_im){
    _re=fraction(num_re, denom_re);
    _im=fraction(num_im, denom_im);
}

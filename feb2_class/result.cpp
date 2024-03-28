#progma once
#include "result.h"
#include <math.h>

square::square(double a, double b, double c){
    _a=fraction(a);
    _b=fraction(b);
    _c=fraction(c);
    decision();
}

square::square(int32_t a, int32_t b, int32_t c){
    _a=fraction(a);
    _b=fraction(b);
    _c=fraction(c);
    decision();
}

square::square(fraction a, fraction b, fraction c){
    _a=a;
    _b=b;
    _c=c;
    decision();
}

square::square(fraction x1, fraction x2){
    _x1=comp(x1,0);
    _x2=comp(x2,0);
    _a=1;
    _b=(x1+x2)*(-1);
    _c=x1*x2;
}

square::square(){
    _a=fraction();
    _b=fraction();
    _c=fraction();
    _x1=compl();
    _x2=compl();
    find_d();
}

void square::find_root(){

    fraction tmp1=fraction();
    fraction tmp2=fraction();
    find_d();
    if(_d==0){
        tmp1=_b*(-1)/(_a*2);
    _x1=comp(tmp1,0);
    _x2=_x1;
    
    }

    if(_d>0){
        _d=sqrt(_d);
        tmp1=(_b*(-1)+_d)/(_a*2);
        tmp2=(_b*(-1)-_d)/(_a*2);
        _x1=comp(tmp1,0);
        _x2=comp(tmp2,0);
    }
    if(_d<0){
        _d=sqrt(_d*(-1));
        tmp1=_b*(-1)/(_a*2);
        tmp2=_b*(-1)/(_a*2);
        _x1=comp(tmp1, _d/(_a*2));
        _x2=comp(tmp2,_d*(-1)/(_a*2));


    }

};



void square::find_d(){
    _d=_b*_b-_a*_c*4;
    
}
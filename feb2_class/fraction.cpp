#include "fraction.h"
#include <string.h>
#include <cmath>

unsigned int NOD(unsigned int a, unsigned int b) {
  if (a == b) return a;
  if (a > b) return NOD(a - b, b);
  return NOD(a, b - a);
}
int after_point(double realFract){
  int zero_count = 0, overall_count = 0;
  while(zero_count < 5){
     overall_count++;
    int a = realFract*pow(10,overall_count);
    if(a % 10 == 0) zero_count++;
    else zero_count = 0;
  }
  return overall_count-zero_count;
}
fraction::fraction(int32_t num,uint32_t denom){
  _num = num;
  _denom = denom;
  reduce();
}
fraction::fraction(double real_fract){
    int p = pow(10,after_point(real_fract)),a = real_fract*p, nod = NOD(abs(a),p);
    _num = a/nod;
    _denom = p/nod; 
}


void fraction::reduce(){
    int nod = NOD(abs(_num),_denom);
    _num /= nod;
    _denom /= nod;
}

void fraction::setdenom(uint32_t newdenom){
    if (newdenom == 0)
        throw "denomirate can't be zero";
    _denom = newdenom;
    
}

void fraction::setnum(int32_t newnum){
    _num=newnum;
}

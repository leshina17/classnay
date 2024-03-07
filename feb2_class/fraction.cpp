#include "fraction.h"

void fraction::print() {
    std::cout << _num << "/" << _denom << std::endl;
   
}//тип название и функция
void fraction::setdenom(uint32_t newdenom){
    if (newdenom == 0)
        throw "denomirate can't be zero";
    _denom = newdenom;
    
}
void fraction::setnum(int32_t newnum){
    _num=newnum;
}

fraction::fraction(){
    _num=0;
    _denom=1;
}
fraction::fraction(int32_t num, uint32_t denom){
    _num=num;
    setdenom(denom);
}
fraction::fraction(const fraction& fraction){
    _num=fraction._num;
    _denom=fraction._denom;
}

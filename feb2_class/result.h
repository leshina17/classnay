#pragma once
#include "comp.h"
#include <cstdint>

class square{
    private: 
        fraction _a;
        fraction _b;
        fraction _c;
        comp _x1;
        comp _x2;
        fraction _d;
        void find_d();
        void decision();

    public: 
        square();
        square(fraction a, fraction b, fraction c);
        square(double a, double b, double c);
        square(int32_t a, int32_t b, int32_t c);
        square(fraction x1, fraction x2);


 friend std::ostream& operator<<(std::ostream& os, const square& tmp){
        if(tmp._a==1)
            os << "x^2";
        else{
            if(tmp._a!=0)
                os<<tmp._a<<"x^2";
        }
    if(tmp._b==1)
            os << " + x";
        else{
                if(tmp._b>0)
                os<<" + "<<tmp._b<<"x";
                if(tmp._b<0)
                os<<tmp._b<<"x";
            }
        

        if(tmp._c>=0)
        os<<" + "<<tmp._c<<std::endl;
        else
        os<<tmp._c<<std::endl;

        os<<"x1= "<<tmp._x1<<" , x2= "<<tmp._x2<<std::endl;
        return os;
    }
};
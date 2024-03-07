#include <iostream>
#include "fraction.h" //название
#include "comp.h"

fraction operator+(double left, const fraction& rit){
    fraction fract=rit+fraction(left);
    return fract;
}

int main(){
    fraction fract1=fraction(1,2); //тип и название переменной
    //fract1.print(); //вызываем метод
    ////fract1.setnum(1);
    ////fract1.setdenom(5);
    ////fract1.printdouble();
    //fraction fract2();
    //fraction fract3 = fraction();  // объекты в стеке
    
   
    fraction fract=fraction(1, 2);

    comp chis= comp(fract, fract1);
    comp chislo= comp(fract, fract1);

    comp res=chis+chislo;
    
    //////////////fraction result=fract+5;

    //double converted=static_cast<double>(fract); //посмотреть
    //fract.print(); 
    //std::cout<<fract;
    //raction fract_copy=fraction(fract);
    //std::cout << fract_copy;
    //fract_copy.print();
    //fraction* fract_pointer = new fraction(); //в динамической памяти
    //delete fract_pointer;


    /*fraction result=fract + fract_copy; //=fract.operator+ (fract_copy)
    std::cout << result;

    
    fraction rez=fract-fract_copy;
    std::cout << rez;

    fraction rezu=fract*fract_copy;
    std::cout << rezu;

    fraction re=fract/fract_copy;
    std::cout << re;*/

    // fraction* point= new fraction();
    // delete point;

    fraction fitcha=fraction{1,2};

    fraction* array=new fraction[3];
    delete [] array;

    return 0;
}
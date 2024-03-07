#include <iostream>
#include <random>
#include <algorithm>

struct WithVeryBigName{
    int a=0;
};

inline double sq(double a){ //просто берет внутренность функции и подставляет в программу
    return a*a;
}

double sum(double a, double b=10){
    return a+b;
}

enum BluetoothState {connected, disconected, connecting, disconnecting};//перечисление

using namespace std; //если надоело использовать std?

//пример функционального полиморфизма
double divide(double a, double b){
    return a/b;
}
double divide(int a, int b){
    return a/b;
}

/*template<typename T, typename D>
double dividetemplate(T a, T b, D c){ // T, D - какое-то имя типа
    if (b==0)
        throw "durak sovsem?";
    return a/b;
}*/

int main(){
    auto myStruct=WithVeryBigName();

    int a=myStruct.a;
    double res1=sq(10);
    double res2=10*10;

    double res3=sum(5); //15 так как в=10 указано выше
    double res4=sum(5, 20); //25
    
    bool isFlag=true;

    BluetoothState currentBluetoothState=BluetoothState::connected;
    switch(currentBluetoothState){
        case BluetoothState::connected:
            std::cout<<"device connected"<<std::endl;
            break;
        case BluetoothState::connecting:
            std::cout<<"device connecting"<<std::endl;
            break;
        case BluetoothState::disconected:
            std::cout<<"device disconnected"<<std::endl;
            break;
        case BluetoothState::disconnecting:
            std::cout<<"device disconnecting"<<std::endl;
            break;
    }
    //массивы
    int* arr= new int[100]; //массив на 100 элементов, new - выделяем память и ищем подходящее место
    for (int i=0; i<100; i++){
        arr[i]=i;
    }
    delete []arr; // удаляем массив
    int s=arr[0]; // нельзя использовать массив после его удаления

    //константы
    const int const_a=10;
    int b=10;
    int c=100;
    //consta_a=10; //не можем изменить переменную
    //константный указатель
    const int* const pointer_b= &b;
    //pointer_b=&c; нельзя мекнять значение указателя

    //*pointer_b=100; нельзя менять значение переменной, на которую ссылается указатель
    const int* const_pointer=&const_a; //хранить адрес на константу может только указатель на константную переменную

    double base_val=100.0;
    int target_val=static_cast<int>(base_val);//преобразование типов

    double res_div=divide(10.10, 10.10);
    double res_div1=divide(10, 10);
    //std::cin >> a; //ввод
    //std::cout << a << std::endl; //вывод в консоль
    //ouble res_template=dividetemplate(1, 0, 1.0); //пример вызова шаблонной функции
    //dividetemplate(10, 'a', 1.0); //так нельзя, пот ому что первые две должны иметь один тип данныx
    /*try{
        dividetemplate(10, 0, 1.0);
    } 
    catch(const char* message){
        std::cout<<message<<std::endl;
    }*/

    int array[10]={1, 2, 3, 4, 5, 6, 7}; //обход массива 
    for(auto elem: array){
        std::cout<<elem<<std::endl;
    }

    std::cout<<std::endl;
    std::cout<<std::endl;
    int abc=10;
    int& ref_abc=abc; //ссылка - константный указатель
    std::cout<<ref_abc<<std::endl;

    int dsa=1000;
    ref_abc=dsa;

    int** matrix=new int*[5]; //массив 2мерный;
    for (int i=0; i<5; i++){
        matrix[i]=new int[5];
    }

    for (int i=0; i<5; i++){
        delete [] matrix[i];
    }
    delete [] matrix;

    str:mt19937 gen;
    gen.seed(std::random_device()());
    std:uniform_int_distribution<std::mt19937::result_type>dist;

    std::cout<<dist(gen)<<std::endl;
    


    return 0;
}
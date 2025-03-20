#include <iostream>
#include "complex_number.hpp"

using namespace std;

int main(void){

    using C_num = complex_number<double>; //Mi riferisco alla classe complex_number con l'alias C_num

    C_num z(2,1);
    C_num w(-1.5,3);
    C_num x(5);
    C_num y;

    //Print test e verifica overload <<
    cout<<"z = "<<z<<endl;
    cout<<"w = "<<w<<endl;
    cout<<"x = "<<x<<endl;
    cout<<"y = "<<y<<endl<<endl;

    cout<<"La parte reale di z è: "<<z.Re()<<endl;
    cout<<"La parte immaginaria di z è: "<<z.Im()<<endl;
    cout<<"Il coniugato di z è: "<<z.conj()<<endl<<endl;

    //Verifica overload di +=, +, *=, *
    cout<<"z+w = "<<z+w<<" oppure w+z = "<<w+z<<endl;
    cout<<"7+z = "<<7.0+z<<" oppure z+7 = "<<z+7.0<<endl<<endl;

    cout<<"z*w = "<<z*w<<" oppure w*z = "<<w*z<<endl;
    cout<<"z*2.2 = "<<z*2.2<<" oppure 2.2*z = "<<2.2*z<<endl<<endl;


    return 0;
}
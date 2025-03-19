#include <iostream>
#include "complex_number.hpp"

using namespace std;

int main(void){

    using C_num = complex_number<double>; //Mi riferisco alla classe complex_number con l'alias C_num

    C_num z(2,3);
    C_num w(5.2,3);
    cout<<z+2.0<<' '<<2.0+z<<endl;
    cout<<4.0*z<<' '<<z*4.0<<endl;
    cout<<5.0*w<<' '<<w*5.0<<endl;


    return 0;
}
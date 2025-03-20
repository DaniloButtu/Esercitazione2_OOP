#pragma once
using namespace std;

template<typename T>
class complex_number{
    //Attributi privati della classe che modellano parte reale e parte immaginaria di un numero complesso
    T real_part, imm_part;

    public:
        //Costruttore di default: scelgo di inizializzare il numero complesso a (0,0) se l'utente non passa parametri
        complex_number()
            : real_part(0),imm_part(0)
            {}

        
        //Costruttore definito dall'utente: inizializza Re(z) e Im(z) di un numero complesso z 
        complex_number(T a, T b)
        {
            real_part=a;
            imm_part=b;
        }


        explicit complex_number(T a)
            : real_part(a),imm_part(0)
            {
                cout<<"E' stato chiamato il convertitore per passare dal campo complesso al campo reale"<<endl;
            }


        //Metodi che consentono di vedere parte reale e parte immaginaria
        T Re(void) const 
        {
            return real_part;
        }

        T Im(void) const 
        {
            return imm_part;
        }

        //Metodo per avere il coniugato di un numero complesso
        complex_number conj(void) const 
        {
            return complex_number(real_part,-imm_part);   
        }

        ////////////////////////////////////////////////////////////////////////////
        //Definisco l'operatore += e + tra due complex_numbers, facendo overloading
        complex_number& operator+=(const complex_number& other)
        {
            T x1=real_part;
            T y1=imm_part;
            T x2=other.real_part;
            T y2=other.imm_part;
            real_part=x1+x2;
            imm_part=y1+y2;
            return *this;
        }

        complex_number operator+(const complex_number& other) const
        {
            complex_number sum=*this;
            sum+=other;
            return sum;
        }
        

        //Gestisco anche il caso in cui somma un complesso con un reale
        complex_number& operator+=(const T& other)
        {
            real_part+=other;
            return *this;
        }

        complex_number operator+(const T& other) const 
        {
            complex_number sum=*this;
            sum+=other;
            return sum;
        }


        //Implemento l'operatore *= e * tra due numeri complessi
        complex_number& operator*=(const complex_number& other)
        {
            T x1=real_part;
            T y1=imm_part;
            T x2=other.real_part;
            T y2=other.imm_part;
            real_part=(x1*x2)-(y1*y2);
            imm_part=(x1*y2)+(y1*x2);
            return *this;
        }

        complex_number operator*(const complex_number& other) const
        {
            complex_number prod=*this;
            prod*=other;
            return prod;
        }

        
        //Implemento anche la moltiplicazione di un complesso per uno scalare, in particolare nell'ordine complex_number*scalare
        complex_number& operator*=(const T& other)
        {
            real_part*=other;
            imm_part*=other;
            return *this;
        }

        complex_number operator*(const T& other) const
        {
            complex_number mol=*this;
            mol*=other;
            return mol;
        }
    };


    //Faccio overloading sull'operatore << per stampare a schermo correttamente i numeri complessi
template<typename T>
ostream& operator<<(ostream& output_stream, const complex_number<T>& z)
{   
    if (z.Re())
    {
        output_stream<<z.Re();
    }
    else if (!z.Re() && !z.Im())
    {
        return output_stream<<0;
    }
    else
    {
        return output_stream<<z.Im()<<'i'; //in questo modo gestisco il caso in cui Re=0 e im>0
    }


    if (z.Im()<0)
    {
        output_stream<<z.Im()<<'i'; //Se la parte immaginaria è negativa il segno è già presente
    }
    else if (z.Im()>0)
    {
        output_stream<<'+'<<z.Im()<<'i';//Se la parte immaginaria è positiva aggiungo un segno +
    }
    return output_stream;
}


//Implemento la commutatività delle operazioni + * (type T a sx)
template<typename T> 
complex_number<T> 
operator+(const T& t, const complex_number<T>& z)
{  
    return z+t; //Qua svolgo l'operazione con l'operatore + su cui ho precedentemente definito questa operazione
}


template<typename T>
complex_number<T> operator*(const T& t, const complex_number<T>& z)
{
    return z*t;
}


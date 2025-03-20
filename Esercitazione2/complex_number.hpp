#pragma once
using namespace std;

template<typename T> requires floating_point<T>
class complex_number
{   
    //Attributi privati della classe che modellano parte reale e parte immaginaria di un numero complesso
    T real_part, imm_part;

    public:
        //Costruttore di default: scelgo di inizializzare il numero complesso a (0,0) se l'utente non passa parametri
        complex_number()
        {
            real_part=0, imm_part=0;
        }

        //Costruttore definito dall'utente: inizializza Re(z) e Im(z) di un numero complesso z 
        complex_number(T a, T b)
        {
            real_part=a, imm_part=b;
        }

        explicit complex_number(T a)
        {
            real_part=a, imm_part=0;
            cout<<"E' stato chiamato il convertitore per passare dal campo complesso al campo reale"<<endl;
        }
           
        //Metodi che consentono di vedere parte reale, parte immaginaria e coniugato
        T Re(void) const 
        {
            return real_part;
        }

        T Im(void) const 
        {
            return imm_part;   
        } 
        
        complex_number conj(void) const 
        {
            return complex_number(real_part,-imm_part);     
        }   
    

        //overload degli operatori richiesti 
        //Definisco l'operatore += e + tra due complex_numbers, facendo overloading
        complex_number& operator+=(const complex_number& other)
        {
            T x1=real_part, y1=imm_part;
            T x2=other.real_part, y2=other.imm_part;
            real_part=x1+x2;
            imm_part=y1+y2;
            return *this; //sfrutto l'operatore di default this che punta sempre all'istanza che verrà generata
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
            T x1=real_part, y1=imm_part;
            T x2=other.real_part, y2=other.imm_part;
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
    T re=z.Re(), im=z.Im();
    bool has_re=(re!=0), has_im=(im!=0); 

    //Caso in cui il numero complesso è l'origine
    if (!has_re && !has_im) return output_stream<<0;

    //Caso di numero reale
    else if (has_re && !has_im) return output_stream<<re;
    
    //Caso di numero immaginario puro (in cui gestisco anche il caso in cui |im|=1, in cui devo stamapre solo +-i e non 1+-i)
    else if (!has_re && has_im) 
    {
        if (im == 1.0) return output_stream<<'i';
        else if (im == -1.0) return output_stream<<"-i";
        else return output_stream<<im<<'i';
    }

    //Caso di numero complesso 'completo', in cui vado pre qui a gestire il problema del +-1
    else
    {
        output_stream<<re;
        if (im==1.0) return output_stream<<"+i";
        else if (im==-1.0) return output_stream<<"-i";
        else if (im>0) return output_stream<<'+'<<im<<'i';
        else return output_stream<<im<<'i';
    }
    
}


//Implemento la commutatività delle operazioni + * (type T a sx)
template<typename T> 
complex_number<T> 
operator+(const T& t, const complex_number<T>& z)
{  
    return z+t; //Qua svolgo l'operazione con l'operatore + su cui ho precedentemente definito questa operazione
}

template<typename T>
complex_number<T> 
operator*(const T& t, const complex_number<T>& z)
{
    return z*t;
}


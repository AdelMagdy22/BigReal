// #include "BigRealClass.h"
#include "BigRealClass.cpp"
#include "BigDecimalIntClass.cpp"

int main()
{
    BigDecimalInt o3("65");
    string s1 = "+50.65";
    BigReal o1(s1), o2("+52.40");
    BigReal o5(o3), o4("55.00");

    cout<<"\no5: "<<o5.returnNumber()<<endl;
    cout<<"o5 decPointPos: "<<o5.getDecPointPos()<<endl; //65.00
    
    cout<<"\n 50.65 + 52.40 = ";

    string re = addition(o1.returnNumber(),o2.returnNumber());

    for (long long i = 0; i < re.length(); i++)
    {
        int resDecPointPos; 
        resDecPointPos = max(o1.getDecPointPos(), o2.getDecPointPos()) + (re.length() - max(o1.returnNumber().length(), o2.returnNumber().length() ));
        if (i == resDecPointPos)
        {
            cout<<'.';
            cout<<re[i];
        }
        else cout<<re[i];
    }    
    cout<<endl;

    BigReal o6(move(o4));
    cout<<o6.returnNumber()<<" DecPointPos: "<<o6.getDecPointPos()<<endl;
    cout<<o4.returnNumber()<<" DecPointPos: "<<o4.getDecPointPos()<<endl;

    BigReal o7("55.50");
    BigReal o8;
    o8 = move(o7);
    cout<<'\n'<<o8.returnNumber()<<endl;

    o1 = o8;
    cout<<'\n'<<"o1: "<<o1.returnNumber()<<endl;
    cout<<'\n'<<"o7: "<<o7.returnNumber()<<endl;  
}

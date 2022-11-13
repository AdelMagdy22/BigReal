// FCAI – Object-Oriented Programming 2 – 2022 - Assignment 2
// Program Name: BigReal
// Last Modification Date: 13/11/2022
// Author1 and ID and Group: Adel Magdy Abd El-Hay Mohammed  ID: 20210190 (Orange Part (First))
// Author2 and ID and Group: Mohammed Ayman  ID: 20210569 (Black Part (Second))
// Author3 and ID and Group: Asmaa Saleh ID: 20211014 (Blue Part (last))
/*
description: In this problem we developed a new C++ type (class).
that can hold unlimited Real values and performs arithmetic operations on them.
such as: +, -, <, and >,
diffrent things such as: Copy Constructor, move constructor, Assignment operator and move assignment.
and we use BigDecimalIntClass that BGad do it.
 */

// #include "BigRealClass.h"
// #include "BigDecimalIntClass.h"
#include "BigRealClass.cpp"
#include "BigDecimalIntClass.cpp"
using namespace std;

int main()
{
    
    // BigDecimalInt o3("65");
    string s1 = "500", s2 = "450";
    BigReal o1("+50.5"), o2("-53.5");
    // BigReal o5(o3), o4("55.00");
    cout<<subtraction(s1,s2)<<endl;
    // cout<<"\no5: "<<o5.returnNumber()<<endl;
    // cout<<"o5 decPointPos: "<<o5.getDecPointPos()<<endl; //65.00
    
    // cout<<o1.GetSign();//<<" "<<o2<<endl;
    cout<<"\n 50.5 + (-53.5) = ";
    cout<< o1 + o2<<endl;
    //cout<<o1<<" "<<o2;

/*    string re = addition(o1.returnNumber(),o2.returnNumber());

    for (long long i = 0; i < re.length(); i++)
    {
        long resDecPointPos;
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
    cout<<'\n'<<"o7: "<<o7.returnNumber()<<endl;*/

    // BigReal oo("522.500");
    // BigReal ooo("522.50");
    // cout << "enter the num: ";
  //  cin >> ooo;
    // cin.ignore();
    
//    cout<<'\n'<<"o1: "<<oo.GetSign()<<endl;
    //cout<<'\n'<<"o1: "<<oo.GetSize()<<endl;
   // cout<< "ooo: "<<ooo <<endl;
   // cout<<"oo: ";
    //cout << oo << endl;
    // if(oo==ooo){cout<<"yes"<<endl;}
    // else{cout<<"no"<<endl;}
    // (oo<ooo)? cout<<"oo>ooo"<<endl:cout<<"";
    // (ooo>oo)? cout<<"ooo<oo"<<endl:cout<<"";
    // cout<<"oo>ooo: "<<oo>ooo;
    // cout<<"oo<ooo: "<< oo<ooo:
   // ooo.AddZeros(oo);
    //cout<<" ooo: "<<ooo<<" oo: "<<oo;
     
}

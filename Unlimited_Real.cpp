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

    BigDecimalInt o3("65");
    string s1 = "40", s2 = "70";
    BigReal o1("-107.50"), o2("23.0");
    BigReal o5(o3), o4("55.00");
    cout << "\no5: " << o5 << endl;
    cout << "o5 decPointPos: " << o5.getDecPointPos() << endl; 
    cout << o1.GetSign();                                      
    cout << "\n -4.0 + (-7.0) = " << o1 + o2 << endl;
    cout << "-4.0 - (-7.0) = " << o1 - o2 << endl;
    cout << "enter number: ";
    cin >> o1;
    cout << "o1: " << o1 << endl;
    cout << "o4 + o5 = " << o4 + o5<<endl;

    BigReal o6(move(o4));

    cout << o6 << endl;
    cout << o4 << endl;

    BigReal o7("55.50");
    BigReal o8;
    o8 = move(o7);
    cout << '\n'<< o8 << endl;

    o1 = o8;
    cout << '\n'<< "o1: " << o1 << endl;
    cout << '\n'<< "o7: " << o7 << endl;

    BigReal oo("522.500");
    BigReal ooo("522.50");
    cout << "enter the num: ";
    cin >> ooo;
    // cin.ignore();

    cout << '\n'<< "oo: " << oo.GetSign() << endl;
    cout << '\n'<< "oo: " << oo.GetSize() << endl;
    cout << "ooo: " << ooo << endl;
    cout << "oo: ";
    cout << oo << endl;
    (oo == ooo)? cout << "yes" << endl: cout << "no" << endl;

    (oo < ooo) ? cout << "oo<ooo" << endl : cout << "oo>ooo"<<endl;
    (ooo > oo) ? cout << "ooo>oo" << endl : cout << "ooo<oo"<<endl;
    // cout << "oo>ooo: " << oo > ooo;
    // cout << "oo<ooo: " << oo < ooo;
    ooo.AddZeros(oo);
    cout << " ooo: " << ooo << " oo: " << oo;
}

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
#include "BigRealClass.h"

bool BigReal :: checkValidInputRealNum(string input)
{
    const regex ValidInput("[+-]?[0-9]+\\.[0-9]+");
    return regex_match(input, ValidInput);
    
}

void BigReal :: assNumber(string num)
{
    int pos;
    bool ValidRealNumber = checkValidInputRealNum(num);
    if(ValidRealNumber)
    {
        pos = num.find(".",0);

        if(num[0] == '+' || num[0] == '-') decPointPos = pos - 1;
        else decPointPos = pos;
        cout<<"\n"<<"decPointPos: "<< decPointPos<<endl;
        num.erase(pos, 1);
        wholeNum.setNumber(num);
        cout<<wholeNum.sign()<<wholeNum.getNumber()<<endl;

    }else
    {
        cout<<"Invalid"<<"\n";
        exit(1);
    }    
}

BigReal :: BigReal(BigDecimalInt other)
{
    wholeNum = other.getNumber(); 
    decPointPos = other.getNumber().length();
}

BigReal :: BigReal(const BigReal& other) // copy constructor
{
    cout<<'\n'<<"copy constructor";
    wholeNum = other.wholeNum;
    decPointPos = other.decPointPos;
} 

BigReal :: BigReal(BigReal&& other)
{
    cout<<'\n'<<"move constructor";
    this->wholeNum = other.wholeNum;
    this->decPointPos = other.decPointPos;
    other.assNumber("0.00");    
}

BigReal& BigReal :: operator = (BigReal& other)
{
    cout<<'\n'<<"assingment operator";
    if(this != &other)
    {
        this->wholeNum = other.wholeNum;
        this->decPointPos = other.decPointPos;
    }

    return *this;
}

BigReal& BigReal:: operator = (BigReal&& other)
{
    cout<<"\n"<<"move Assignment"<<endl;
    if(this != &other)
    {
        this->wholeNum = other.wholeNum;
        this->decPointPos = other.decPointPos;
        other.assNumber("0.00");
    }

    return *this;
}
int BigReal :: GetSize()
{
   string a=wholeNum.getNumber();
   
   for(int i=0;i<wholeNum.size();i++){
        if(a [i]=='.'){
            return (wholeNum.size()-1);
        }
    }
    return wholeNum.size();
    
}

char BigReal :: GetSign()
{
    return wholeNum.sign();
   
}

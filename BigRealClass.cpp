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

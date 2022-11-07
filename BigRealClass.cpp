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
        pos = num.find(".",1);
        cout<<"decPointPos: "<< pos<<endl;
        decPointPosFromEnd = num.length() - pos;
        cout<<"decPointPosFromEnd: "<< decPointPosFromEnd<<endl;
        num.erase(pos, 1);
        wholeNum.setNumber(num);
        cout<<wholeNum.sign()<<wholeNum.getNumber()<<endl;

    }else
    {
        cout<<"Invalid"<<"\n";
        exit(1);
    }    
}
BigReal :: BigReal(const BigReal& other)
{
    wholeNum = other.wholeNum;
    decPointPosFromEnd = other.decPointPosFromEnd;
} 
/*
BigReal :: BigReal(BigReal&& other)
{
    wholeNum = other.wholeNum;
    // other.wholeNum = nullptr;
}*/

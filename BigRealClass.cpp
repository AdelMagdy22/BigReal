#include "BigRealClass.h"

bool BigReal :: checkValidInputRealNum(string input)
{
    const regex ValidInput("[+-]?[0-9]+\\.[0-9]+");
    return regex_match(input, ValidInput);
    
}

void BigReal :: setNumber(string num)
{
    bool ValidNumber = checkValidInputRealNum(num);
    if(ValidNumber)
    {
        if(num[0] == '+')
        {
            sign = '+';
            num.erase(0,1);
        }
        else if(num[0] == '-')
        {
            sign = '+';
            num.erase(0,1);
        }
        else 
        {
            sign = '+';
        }
        decPointPos = num.find(".");
        wholeNum = num;
        cout<<sign<<num<<endl;
        cout<<wholeNum<<endl;
    }else
    {
        cout<<"Not Valid input"<<endl;
    }    
}
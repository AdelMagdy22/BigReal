#ifndef BigRealClass_H
#define BigRealClass_H

#include "BigDecimalIntClass.h"


class BigReal
{ 
private:
    BigDecimalInt wholeNum;
    int decPointPos; // position of Decimal Point
    bool checkValidInputRealNum(string input);

public:
    BigReal():decPointPos(1)
    {wholeNum.setNumber("000");};

    void assNumber(string num);
    BigReal(string realNumber)
    {
        assNumber(realNumber);
    };

    string returnNumber()
    {
        return wholeNum.getNumber();
    }
    int getDecPointPos()
    {
        return decPointPos;
    }


    BigReal(BigDecimalInt bigInt);

    BigReal (const BigReal& other); // copy constructor

    BigReal& operator= ( BigReal& other); // Assignment operator

    BigReal (BigReal&& other); // move constructor

    BigReal& operator= (BigReal&& other); // move Assignment
};

#endif

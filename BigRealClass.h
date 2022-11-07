#ifndef BigRealClass_H
#define BigRealClass_H

#include "BigDecimalIntClass.h"


class BigReal
{ 
private:
    BigDecimalInt wholeNum;
    int decPointPosFromEnd; // position of Decimal Point
    bool checkValidInputRealNum(string input);

public:
    BigReal():decPointPosFromEnd(1)
    {wholeNum.setNumber("0.0");};

    void assNumber(string num);
    BigReal(string realNumber)
    {
        assNumber(realNumber);
    };

    //BigReal(BigDecimalInt bigInt);

    BigReal (const BigReal& other); // copy constructor

    BigReal (BigReal&& other); // move constructor
};

#endif

#ifndef BigRealClass_H
#define BigRealClass_H

#include "BigDecimalInt.h"


class BigReal{
private:
    string wholeNum;
    long long decPointPos; // position of Decimal Point
    char sign;
    void setNumber(string num);
    bool checkValidInputRealNum(string input);

public:
    BigReal(){};

    BigReal(string realNumber)
    {
        setNumber(realNumber);
    };

    BigReal(BigDecimalInt bigInt);
};

#endif
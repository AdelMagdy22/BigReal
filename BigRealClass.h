// FCAI – Object-Oriented Programming 2 – 2022 - Assignment 2
// Program Name: BigReal
// Last Modification Date: 10/11/2022
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

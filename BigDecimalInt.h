#ifndef BigDecimalInt_H
#define BigDecimalInt_H

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class BigDecimalInt
{
private:
    string str;
    char sign;

public:
    BigDecimalInt(){}; 
    BigDecimalInt(string decStr);

    BigDecimalInt(int decInt);

    int Sign();
    int Size();
    BigDecimalInt operator+ (BigDecimalInt anotherDec);

    BigDecimalInt operator- (BigDecimalInt anotherDec);

    bool operator < (BigDecimalInt anotherDec);

    bool operator == (BigDecimalInt anotherDec);
    bool operator > (BigDecimalInt anotherDec);

    BigDecimalInt operator = (BigDecimalInt anotherDec);

    friend ostream& operator << (ostream& out, BigDecimalInt b);

};

#endif

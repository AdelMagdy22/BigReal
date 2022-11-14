// FCAI – Object-Oriented Programming 1 – 2022 - Assignment 1
// Program Name: BigDecimalInt
// Last Modification Date: 13/10/2022
// Author1 and ID and Group: Basmala Mohamed Sayed Gad  ID: 20210090 (a, b, c)
// Author2 and ID and Group: Aya Ali Hassan  ID: 20210083 (d, e)
// Author3 and ID and Group: Mohamed Ashraf Fahim  ID: 20210329 (f, i, j , k)
/*
description: In this problem we developed a new C++ type (class).
that can hold unlimited decimal integer values and performs arithmetic operations on them.
such as: +, -, <, and >.
 */

#include "BigDecimalIntClass.h"

// regex function that checks the validation of the input.
bool BigDecimalInt ::checkValidInput(string input)
{
    regex validInput("[-+]?[0-9]+");
    return regex_match(input, validInput);
}

// constructor that takes a string as an input.
void BigDecimalInt ::setNumber(string num)
{
    bool validNumber = checkValidInput(num);
    if (validNumber)
    {
        number = num;
        if (number[0] == '+')
        {
            number.erase(0, 1);
            signNumber = '+';
        }
        else if (number[0] == '-')
        {
            number.erase(0, 1);
            signNumber = '-';
        }
        else
        {
            signNumber = '+';
        }
    }
    else
    {
        cout << "Invalid"
             << "\n";
        exit(1);
    }
}

// operator < overloading function.
bool BigDecimalInt ::operator<(const BigDecimalInt &anotherDec)
{
    string comp1 = "", comp2 = "";
    long long len1 = number.length(), len2 = anotherDec.number.length();

    while (len1 < len2)
    {
        comp1 += '0';
        len1++;
    }
    while (len2 < len1)
    {
        comp2 += '0';
        len2++;
    }
    comp1 += number;
    comp2 += anotherDec.number;

    if (signNumber == '-' && anotherDec.signNumber == '+')
    {
        return true;
    }
    else if (signNumber == '+' && anotherDec.signNumber == '-')
    {
        return false;
    }
    else if (signNumber == '+' && anotherDec.signNumber == '+')
    {
        return comp1 < comp2;
    }
    else
    {
        return comp1 > comp2;
    }
}

// operator > overloading function.
bool BigDecimalInt ::operator>(const BigDecimalInt &anotherDec)
{
    string comp1 = "", comp2 = "";
    long long len1 = number.length(), len2 = anotherDec.number.length();

    while (len1 < len2)
    {
        comp1 += '0';
        len1++;
    }
    while (len2 < len1)
    {
        comp2 += '0';
        len2++;
    }
    comp1 += number;
    comp2 += anotherDec.number;

    if (signNumber == '-' && anotherDec.signNumber == '+')
    {
        return false;
    }
    else if (signNumber == '+' && anotherDec.signNumber == '-')
    {
        return true;
    }
    else if (signNumber == '+' && anotherDec.signNumber == '+')
    {
        return comp1 > comp2;
    }
    else
    {
        return comp1 < comp2;
    }
}

// operator == overloading function.
bool BigDecimalInt ::operator==(const BigDecimalInt anotherDec)
{
    if (signNumber == anotherDec.signNumber && number == anotherDec.number)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// operator = overloading function.
BigDecimalInt &BigDecimalInt ::operator=(BigDecimalInt anotherDec)
{
    signNumber = anotherDec.signNumber;
    number = anotherDec.number;
    return *this;
}

// addition implementation.
string addition(string num1, string num2)
{
    auto it1 = num1.rbegin();
    auto it2 = num2.rbegin();
    string res = "";
    int carry = 0;
    int twoDigitsSum;
    do
    {
        carry = 0;
        twoDigitsSum = ((*it1 - '0') + (*it2 - '0'));
        if (twoDigitsSum >= 10)
        {
            carry = 1;
        }
        *(it1 + 1) = char(((*(it1 + 1) - '0') + carry) + '0');
        res = char((twoDigitsSum % 10) + '0') + res;
        it1++;
        it2++;

    } while (it1 != num1.rend());

    if (carry)
    {
        res = char((carry) + '0') + res;
    }
    return res;
}

// // subtraction implementation
// string subtraction(string num1, string num2)
// {
//     string res = "";
//     string temp = "";
//     if (num1.length() == num2.length())
//     {

//         for (int i = 0; i < num1.length(); i++)
//         {
//             if (num1[i] < num2[i])
//             {
//                 swap(num1, num2);
//                 break;
//             }
//         }
//         int carry = 0;
//         for (int i = num1.length() - 1; i >= 0; i--)
//         {
//             res += (char)((int)num1[i] - (int)num2[i] + 48 - carry);
//             if (res[i] < '0')
//             {
//                 carry = 1;
//                 res[i] = (char)((int)res[i] - 48 + 10);
//             }
//             else
//                 carry = 0;
//         }
//         for (int i = res.length() - 1; i >= 0; i--)
//         {
//             temp += res[i];
//         }

//         return temp;
//     }
//     int count = 1;
//     for (int i = num1.length() - 1; i >= 0; i--)
//     {
//         if (num1[i] < num2[i] && num1[i - 1] != '0')
//         {
//             num1[i] = (char)((int)num1[i] - 48 + 10);
//             num1[i - 1] = (char)((int)num1[i] - 48 - 1);
//         }
//         else if (num1[i] < num2[i] && num1[i - 1] == '0')
//         {
//             while ((num1[i - count] == 0))
//             {
//                 num1[i - count] = (char)((int)num1[i - count] + 9 - 48);
//                 count++;
//             }
//             num1[i - count] = (char)((int)num1[i] + 48 - 1);
//         }
//         res += (char)((int)num1[i] - (int)num2[i] + 48);
//     }
//     for (int i = res.length(); i >= 0; i--)
//     {
//         temp += res[i];
//     }

//     return temp;
// }
int getMax(string str1, string str2)
{
    // 1---> if str1 is max  // 2----> if str2 is max
    if (str1.length() < str2.length())
    {
        return 2;
    }
    else if (str2.length() < str1.length())
    {
        return 1;
    }
    else
    {
        string s1, s2;
        int x, y;
        for (int i = 0; i < str1.length(); i++)
        {
            s1 += str1[i];
            x = stoi(s1);
            s2 += str2[i];
            y = stoi(s2);
            if (x == y)
            {
                continue;
            }
            else if (x < y)
            {
                return 2;
                break;
            }
            else if (x > y)
            {
                return 1;
                break;
            }
        }
    }
    return 0;
}

string subtraction(string stt1, string stt2)
{
    string max, min;
    if (getMax(stt1, stt2))
    {
        max = stt1;
        min = stt2;
    }
    else 
    {
        min = stt2;
        max = stt1;
    }
    if(stt2 == stt1)
    {
        max = "0";
        return max;
    }
    string s1 = max, s2 = min;
    string FinalResult, reResult, sep1, sep2, sep3;
    int x, y, z, carry = 0;
    for (int i = s1.length() - 1; i >= 0; i--)
    {
        sep1 += s1[i];
        x = stoi(sep1);
        x -= carry;
        sep2 = s2[i];
        y = stoi(sep2);
        if (x >= y)
        {
            z = x - y;
            carry = 0;
            sep3 = to_string(z);
        }
        else
        {
            carry = 1;
            z = (x + 10) - y;
            sep3 = to_string(z);
        }
        reResult += sep3;
        sep1.clear();
        sep2.clear();
        sep3.clear();
    }
    // to delete zeros in the left side
    int j;
    for (int i = reResult.size() - 1; i >= 0; i--)
    {
        if (reResult[i] == '0')
        {
            continue;
        }
        else
        {
            j = i;
            break;
        }
    }
    for (int i = j; i >= 0; i--)
    {
        FinalResult += reResult[i];
    }
    cout << "FinalResult: " << FinalResult << endl;
    return FinalResult;
}
// operator + overloading function.
BigDecimalInt BigDecimalInt ::operator+(BigDecimalInt number2)
{
    BigDecimalInt result;
    char signNumber1 = signNumber, signNumber2 = number2.signNumber;
    string num1 = number, num2 = number2.number;
    BigDecimalInt number1 = *this;

    while (num1.length() < num2.length())
    {
        num1 = '0' + num1;
    }
    while (num2.length() < num1.length())
    {
        num2 = '0' + num2;
    }

    if (signNumber1 == signNumber2)
    {
        result.signNumber = signNumber1;
        result.number = addition(num1, num2);
    }
    else
    {

        if (number1.signNumber == '-')
        {
            number1.signNumber = '+';
            result = (number2 - number1);
        }
        else
        {
            number2.signNumber = '+';
            result = (number1 - number2);
        }
    }
    return result;
}

// operator - overloading function.
BigDecimalInt BigDecimalInt ::operator-(BigDecimalInt anotherDec)
{
    BigDecimalInt obj;
    deque<long long> d;
    string strmin = "", res = "";
    string num1 = number, num2 = anotherDec.number;
    char sign1 = signNumber, sign2 = anotherDec.signNumber;

    if (number.length() > anotherDec.number.length())
    {
        for (long long i = 0; i < number.length() - anotherDec.number.length(); i++)
        {
            strmin += '0';
        }
        strmin += anotherDec.number;
        num2 = strmin;
    }
    else if (number.length() < anotherDec.number.length())
    {
        for (long long i = 0; i < anotherDec.number.length() - number.length(); i++)
        {
            strmin += '0';
        }
        strmin += number;
        num1 = strmin;
    }

    bool ok = false, is_determined = false;
    if (num1 < num2)
    {
        swap(num1, num2);
        swap(sign1, sign2);
        ok = true;
    }

    if (sign1 == sign2)
    {
        res = subtraction(num1, num2);

        if (sign1 == '-')
            ok = !ok;
    }
    else
    {
        res = addition(num1, num2);
        if (signNumber == '-')
        {
            obj.signNumber = '-';
            is_determined = true;
        }
        else
        {
            obj.signNumber = '+';
            is_determined = true;
        }
    }

    bool right = false;
    for (long long i = 0; i < res.length(); i++)
    {
        if (res[i] != '-' && res[i] != '0')
        {
            right = true;
        }
        if (!right && res[i] == '0')
        {
            res.erase(i, 1);
            i--;
        }
    }

    if (res.empty())
        res = "0";
    if (!is_determined && (ok))
    {
        obj.signNumber = '-';
    }
    else if (!is_determined)
    {
        obj.signNumber = '+';
    }

    obj.number = res;
    return obj;
}

// function to return the size of number.
int BigDecimalInt ::size()
{
    return number.size();
}

// function returns the sign.
char BigDecimalInt ::sign()
{
    return signNumber;
}

// operator << overloading function.
ostream &operator<<(ostream &out, BigDecimalInt num)
{
    if (num.signNumber == '+')
    {
        out << num.number;
    }
    else
    {
        if (num.number == "0")
        {
            out << num.number;
        }
        else
        {
            out << num.signNumber << num.number;
        }
    }
    return out;
}

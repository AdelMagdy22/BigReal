#include "BigDecimalInt.h"


BigDecimalInt :: BigDecimalInt(string decStr) {
    const regex pattern("[+-]?[0-9]+");
    if (regex_match(decStr, pattern)) {
        cout << "valid input" << endl;
        if (decStr[0] == '-') {
            sign = '-';
            str = decStr.substr(1);
        }
        else if (decStr[0] == '+') {
            sign = '+';
            str = decStr.substr(1);
        }
        else {
            sign = '+';
            str = decStr;
        }
    }
    else
        cout << "invalid input" << endl;
}

BigDecimalInt :: BigDecimalInt(int decInt) {
    string decStr = to_string(decInt);
    if (decStr[0] == '-') {
        sign = '-';
        str = decStr.substr(1);
    }
    else if (decStr[0] == '+') {
        sign = '+';
        str = decStr.substr(1);
    }
    else {
        sign = '+';
        str = decStr;
    }
}

int BigDecimalInt::Sign()
{
    return sign;
}

int BigDecimalInt::Size()
{
    return (str.length());
}

BigDecimalInt BigDecimalInt:: operator+ (BigDecimalInt anotherDec){
    BigDecimalInt x;
    char tsign;
    if (str.length() < anotherDec.str.length()){
        swap(str,anotherDec.str);
        swap(sign,anotherDec.sign);
    }
    if (str.length() > anotherDec.str.length()) {
        tsign=sign;
        int n = str.length() - anotherDec.str.length();
        char add[n+anotherDec.str.length()];
        for (int i = 0; i < n; i++)add[i] ='0';
        for(int i=n,j=0;j<anotherDec.str.length();i++,j++)add[i]=anotherDec.str[j];
        anotherDec.str= add;
    }
    if ((sign == '+' && anotherDec.sign == '+') || (sign == '-' && anotherDec.sign == '-')) {
        int carry = 0;
        for (int i = str.length() - 1; i >= 0; i--) {
            x.str[i] =(int)str[i] +(int) anotherDec.str[i]-48+ carry;
            if ( x.str[i]> '9' ) {
                carry = 1;
                x.str[i] = (int)x.str[i]-10;
            } else
                carry = 0;
        }
        if (sign == '+') {
            if (carry==1)cout<<carry;
            for(int i=0;i<str.length();i++)cout<<x.str[i];
            cout<<endl;return 0;
        } else {
            cout<<'-';
            if (carry==1)cout<<carry;
            for(int i=0;i<str.length();i++)cout<<x.str[i];
            cout<<endl;return 0;
        }
    }else{
        bool is_large = false;
        if(str.length()==anotherDec.str.length()){
            for(int i=0;i<str.length();i++){
                if(str[i]>anotherDec.str[i]){
                    tsign=sign;
                    is_large = true;
                    break;
                }else if(str[i]<anotherDec.str[i]){
                    tsign=anotherDec.sign;
                    swap(str,anotherDec.str);
                    is_large = true;
                    break;
                }
            }
            if(is_large == false && ((sign == '+' && anotherDec.sign == '-') || (sign == '-' && anotherDec.sign == '+')))
            {
                cout<<"0"<<endl;
                return 0;
            }
        }
        int carry=0;
        for(int i = str.length() - 1; i >= 0; i--){
            x.str[i] =(int)str[i] -(int) anotherDec.str[i]+ 48-carry;
            if(x.str[i]< '0') {
                carry = 1;
                x.str[i] = (int) x.str[i] + 10;
            }else
                carry = 0;
        }
        int c=0;
        for(int i=0;i<str.length();i++){
            if(x.str[i]=='0'){
                c++;
            }else
                break;
        }
        if (tsign == '+') {
            for(int i=c;i<str.length();i++)cout<<x.str[i];
            cout<<endl;return 0;
        } else {
            cout<<'-';
            for(int i=c;i<str.length();i++)cout<<x.str[i];
            cout<<endl;return 0;
        }
    }
}

BigDecimalInt BigDecimalInt::operator-(BigDecimalInt anotherDec)
{
    BigDecimalInt x;
    if((str.length() -  anotherDec.str.length() ) > 0)
    {
        if(sign == '+') x.sign = sign;
        else x.sign = sign;

        string temp = "";
        for (int i = 0; i < (str.length() -  anotherDec.str.length()); i++) temp += '0';

        temp += anotherDec.str;
        anotherDec.str = temp;
    }
    else if((str.length() -  anotherDec.str.length()) < 0)
    {
        if(anotherDec.sign == '+') x.sign = '-';
        else x.sign = '+';

        string temp = "";
        for (int i = 0; i < (anotherDec.str.length() - str.length()); i++) temp += '0';

        temp += str;
        str = temp;
    }
    bool is_large = false;
    for (int i = str.length()-1; i >= 0 ; i--)
    {
        if(str[i] > anotherDec.str[i] && str.length() == anotherDec.str.length())
        {
            x.sign = sign;
            is_large = true;
            break;
        }
        else if (str[i] < anotherDec.str[i] && str.length() == anotherDec.str.length())
        {
            if(anotherDec.sign == '+') x.sign = '-';
            else x.sign = '+';
            is_large = true;
            break;
        }
    }
    if(is_large == false) 
    {
        cout<<"0"<<endl;
        return 0;
    }
    if((sign == '+' && anotherDec.sign == '-') || (sign == '-' && anotherDec.sign == '+'))
    {
        int carry = 0;
        for (int i = str.length() - 1; i >= 0; i--) {
            x.str[i] =(int)str[i] +(int) anotherDec.str[i]-48+ carry;
            if ( x.str[i]> '9' ) {
                carry = 1;
                x.str[i] = (int)x.str[i]-10;
            } else carry = 0;
        }
    }
    

    else if((sign == '+' && anotherDec.sign == '+') || (sign == '-' && anotherDec.sign == '-'))
    {
        if(str.length()==anotherDec.str.length())
        {
           
            for(int i=0;i<str.length();i++){
                if(str[i]<anotherDec.str[i])
                {
                    swap(str,anotherDec.str);
                    break;
                }
            }
            int carry=0;
            for(int i = str.length() - 1; i >= 0; i--)
            {
                x.str[i] =(int)str[i] -(int) anotherDec.str[i]+ 48-carry;
                if(x.str[i]< '0') 
                {
                    carry = 1;
                    x.str[i] = (int) x.str[i] - 48 + 10;
                }
                else carry = 0;
            }
            goto finish; // go to line 241 (finish:)
        }
        int count = 1;
        for (int i = str.length() - 1; i >= 0; i--)
        {
            if( str[i] < anotherDec.str[i] && str[i-1] != '0')
            {
                str[i] = (char)((int)str[i] - 48 + 10);
                str[i-1] = (char)((int)str[i] - 48 - 1);
            }
            else if (str[i] < anotherDec.str[i] && str[i - 1] == '0')
            {
                while((str[i-count] == 0))
                {
                    str[i-count] = (char)((int)str[i-count] + 9 - 48);
                    count++;
                }
                str[i-count] = (char)((int)str[i] + 48 - 1);
            }
            x.str[i] = (char)((int)str[i] - (int)anotherDec.str[i] + 48);
        }
    }

    finish: // this line linked with line 218 (goto finish;)
    int c=0;
    for(int i=0;i<str.length();i++){
        if(x.str[i]=='0'){
            c++;
        }else
            break;
    }
    if (x.sign == '+') {
        for(int i=c;i<str.length();i++)cout<<x.str[i];
        cout<<endl;return 0;
    } else {
        cout<<'-';
        for(int i=c;i<str.length();i++)cout<<x.str[i];
        cout<<endl;return 0;
    }

}

bool BigDecimalInt::operator<(BigDecimalInt anotherDec)
{
    if(((char)sign == '-' && (char)anotherDec.sign == '+') ||
    ((char)sign == '+' && (char)anotherDec.sign == '+' && str.length() < anotherDec.str.length() )||
    ((char)sign == '-' && (char)anotherDec.sign == '-' && str.length() > anotherDec.str.length())
    )
        return true;

    else if(sign == anotherDec.sign && str.length() == anotherDec.str.length() && sign == '+')
    {
        for (int i = 0; i < str.length(); i++)
        {
            if(str[i] < anotherDec.str[i])
                return true;
        }
    }
    else if (sign == anotherDec.sign && str.length() == anotherDec.str.length() && sign == '-')
    {
        for (int i = 0; i < str.length(); i++)
        {
            if(str[i] > anotherDec.str[i])
                return true;
        }
    }
    return false;
}
bool BigDecimalInt::operator == (BigDecimalInt anotherDec) {
    if (str == anotherDec.str && sign == anotherDec.sign) {
        return true;
    }
    else
        return false;
};

bool BigDecimalInt::operator > (BigDecimalInt anotherDec) {
    if (sign == anotherDec.sign && sign == '+' && str.length() == anotherDec.str.length())
    {
        for (int i = 0; i < str.length(); ++i) {
            if ((int)str[i] > (int)anotherDec.str[i]) {
                return true;
            }
            else if ((int)str[i] < (int)anotherDec.str[i]) {
                return false;
            }
            else if ((int)str[i] == (int)anotherDec.str[i] && (i < str.length()-1))
                continue;
            else
                return false;
        }
    }
    else if (sign == anotherDec.sign && sign == '-' && str.length() == anotherDec.str.length())
    {
        for (int i = 0; i < str.length(); ++i) {
            if ((int)str[i] > (int)anotherDec.str[i]) {
                return false;
            }
            else if ((int)str[i] < (int)anotherDec.str[i]) {
                return true;
            }
            else if ((int)str[i] == (int)anotherDec.str[i] && (i < str.length() - 1))
                continue;
            else
                return false;
        }
    }
    else if(sign == anotherDec.sign && str.length() > anotherDec.str.length() ||
            sign == '+' && anotherDec.sign == '-')
        return true;
    else
        return false;

    return 0;    
}

BigDecimalInt BigDecimalInt::operator= (BigDecimalInt anotherDec) {
    sign = anotherDec.sign;
    str = anotherDec.str;
    return true;
}

ostream& operator << (ostream& out, BigDecimalInt b) {
    return out << b.sign << b.str;
}

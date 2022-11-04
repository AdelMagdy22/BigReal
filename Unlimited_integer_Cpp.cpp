#include "BigDecimalInt.cpp"


int main()
{
    BigDecimalInt("+ 00099999");
    BigDecimalInt o1("+500");
    BigDecimalInt o2("+111111111111111111000000000000000000000001111111111");
    BigDecimalInt o3("+1111004548");
    BigDecimalInt o4 = o3;
    BigDecimalInt o5 ("-121");
    BigDecimalInt o6 ("-11111");
    BigDecimalInt o7 ("-124");
    BigDecimalInt o8 ("+200");
    BigDecimalInt o9 ("+12550014780014");
    BigDecimalInt o10 ("+12550014780014");
    BigDecimalInt o13 ("-12550014780014");
    BigDecimalInt o11 ("+55654354499565");
    BigDecimalInt o12 ("-2842695969599900001111");
    

    cout << char(o1.Sign()) << endl;
    cout << o1.Size() << endl;

    BigDecimalInt a;
    cout << "o9 + o10: " ; a = o9 + o10 ;
    cout << "o13 + o9: " ; a = o13 + o9 ;
    cout << "o6 + o10: " ; a = o6 + o10;
    cout<<endl;
    cout << "o7 - o5: "; a = (o7 - o5);
    cout << "o5 - o7: "; a = (o5 - o7);     
    cout << "o8 - o7: "; a = (o8 - o7);
    cout << "o7 - o7: "; a = (o7 - o7);
    cout << "o7 - o8: "; a = (o7 - o8);
    cout << "o1 - o8: "; a = (o1 - o8);
    cout << "o8 - o1: "; a = (o8 - o1);

    cout<<endl;

    
    cout <<"o3 < o2: "<< (o3 < o2 )<< endl;
    cout <<"o3 < o4: "<< (o3 < o4)<< endl;
    cout << "o11 < o12: "<< (o11 < o12)<<endl;
 
    cout<<endl;

    cout <<"o1 == o2: "<< (o1 == o2) << endl;

    cout <<"o2 > o3: "<< (o2 > o3) << endl;

    cout <<"o3 == o4: "<< (o3 == o4) << endl;
    cout <<"o3 > o4: "<< (o3 > o4) << endl;

    cout <<"o3: "<< o3 << endl;
    cout <<"o3.Size(): "<< o3.Size();
}

#include<iostream>
using namespace std;

void ChangeCoine(int amount)
{
    int note1=0;    //1     Taka coin
    int note2=0;    //2     Taka coin
    int note3=0;    //5     Taka coin
    int note4=0;    //10    Taka coin
    int note5=0;    //20    Taka coin
    int note6=0;    //50    Taka coin
    int note7=0;    //100   Taka coin
    int note8=0;    //200   Taka coin
    int note9=0;    //500   Taka coin
    int note10=0;   //1000  Taka coin
    int totalCoin=0;
    if(amount>=1000)
    {
        cout<<"1000 Taka note :"<<amount/1000<<" times."<<endl;
        totalCoin+=amount/1000;
        amount%=1000;
        if(amount==0)
        {
            cout<<"Total coin: "<<totalCoin<<"."<<endl;
            return;
        }
    }
    if(amount>=500)
    {
        cout<<"500 Taka note :"<<amount/500<<" times."<<endl;
        totalCoin+=amount/500;
        amount%=500;
        if(amount==0)
        {
            cout<<"Total coin: "<<totalCoin<<"."<<endl;
            return;
        }
    }
    if(amount>=200)
    {
        cout<<"200 Taka note :"<<amount/200<<" times."<<endl;
        totalCoin+=amount/200;
        amount%=200;
        if(amount==0)
        {
            cout<<"Total coin: "<<totalCoin<<"."<<endl;
            return;
        }
    }
    if(amount>=100)
    {
        cout<<"100 Taka note :"<<amount/100<<" times."<<endl;
        totalCoin+=amount/100;
        amount%=100;
        if(amount==0)
        {
            cout<<"Total coin: "<<totalCoin<<"."<<endl;
            return;
        }
    }
    if(amount>=50)
    {
        cout<<"50 Taka note :"<<amount/50<<" times."<<endl;
        totalCoin+=amount/50;
        amount%=50;
        if(amount==0)
        {
            cout<<"Total coin: "<<totalCoin<<"."<<endl;
            return;
        }
    }
    if(amount>=20)
    {
        cout<<"20 Taka note :"<<amount/20<<" times."<<endl;
        totalCoin+=amount/20;
        amount%=20;
        if(amount==0)
        {
            cout<<"Total coin: "<<totalCoin<<"."<<endl;
            return;
        }
    }
    if(amount>=10)
    {
        cout<<"10 Taka note :"<<amount/10<<" times."<<endl;
        totalCoin+=amount/10;
        amount%=10;
        if(amount==0)
        {
            cout<<"Total coin: "<<totalCoin<<"."<<endl;
            return;
        }
    }
    if(amount>=5)
    {
        cout<<"5 Taka coin :"<<amount/5<<" times."<<endl;
        totalCoin+=amount/5;
        amount%=5;
        if(amount==0)
        {
            cout<<"Total coin: "<<totalCoin<<"."<<endl;
            return;
        }
    }
    if(amount>=2)
    {
        cout<<"2 Taka coin :"<<amount/2<<" times."<<endl;
        totalCoin+=amount/2;
        amount%=2;
        if(amount==0)
        {
            cout<<"Total coin: "<<totalCoin<<"."<<endl;
            return;
        }
    }
    if(amount>=1)
    {
        cout<<"1 Taka coin :"<<amount<<" times."<<endl;
        totalCoin+=amount/1;
    }
    cout<<"Total coin: "<<totalCoin<<"."<<endl;
}
int main()
{
    cout<<"Value of coins you want to change in TAKA :";
    int amount; cin>>amount;
    ChangeCoine(amount);
    return 0;
}

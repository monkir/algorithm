#include<iostream>
using namespace std;
class item
{
    string name="";
    float amount=0.1;
    float TotalPrice=0;
public:
    void setName()
    {
        cout<<"Enter Name: ";
        cin>>name;
        setName(name);
    }
    void setName(string name)
    {
        this->name=name;
    }
    void setAmount()
    {
        cout<<"Enter amount: ";
        cin>>amount;
        setAmount(amount);
    }
    void setAmount(int amount)
    {
        this->amount=amount;
        if(amount<0.01)
        {
            cout<<"Wrong Input. Please try again";
            setAmount();
        }
    }
    void setTotalPrice()
    {
        cout<<"Enter Total Price: ";
        cin>>TotalPrice;
        setTotalPrice(TotalPrice);
    }
    void setTotalPrice(int TotalPrice)
    {
        this->TotalPrice=TotalPrice;
        if(TotalPrice<=0)
        {
            cout<<"Wrong Input. Please try again";
            setTotalPrice();
        }
    }
    void setEveryThing()
    {
        setName();
        setAmount();
        setTotalPrice();
    }
    string getName()
    {
        return name;
    }
    float getAmount()
    {
        return amount;
    }
    float getTotalPrice()
    {
        return TotalPrice;
    }
    float getAvgPrice()
    {
        return TotalPrice/amount;
    }
};
class knapsack
{
    int n=0;
    item *itm=NULL;
    float bagCap=0;//bag capacity
    float restCap=0;//rest capacity of bag
public:
    void insertItem()
    {
        cout<<"Number of items: ";
        cin>>n;
        itm=new item[n];
        for(int i=0; i<n; i++)
        {
            cout<<"For item no "<<i+1<<": "<<endl;
            itm[i].setEveryThing();
            cout<<endl;
        }
    }
    void getKnapsackSolution()
    {
        cout<<"Enter capacity of the bag: ";
        cin>>bagCap;
        int benefit=0;
        if(bagCap<=0)
        {
            cout<<"Wrong Input! Please try again."<<endl;
            getKnapsackSolution();
            return;
        }
        sortByGreedyMethod();
        for(int i=0; i<n; i++)
        {
            if(bagCap==0)
            {
                break;
            }
            else if(bagCap>itm[i].getAmount())
            {
                cout<<"Take "<<itm[i].getName()<<": "<<itm[i].getAmount()<<" amounts."<<endl;
                benefit+=itm[i].getTotalPrice();
                bagCap-=itm[i].getAmount();
            }
            else if(bagCap<itm[i].getAmount())
            {
                cout<<"Take "<<itm[i].getName()<<": "<<bagCap<<" amounts."<<endl;
                benefit+=bagCap*itm[i].getAvgPrice();
                bagCap=0;
            }
        }
        cout<<"\nTotal Benefit: "<<benefit<<".\n";
    }
    void sortByGreedyMethod()
    {
        for(int i=0; i<n; i++)
        {
            int k=i;
            for(int j=i+1; j<n; j++)
            {
                if(itm[j].getAvgPrice()>itm[k].getAvgPrice())
                {
                    k=j;
                }
            }
            if(k!=i)
            {
                swap(&itm[i], &itm[k]);
            }
        }
    }
    void swap(item *i, item *j)
    {
        item temp=*i;
        *i=*j;
        *j=temp;
    }
};
int main()
{
    knapsack k;
    k.insertItem();
    k.getKnapsackSolution();
    return 0;
}


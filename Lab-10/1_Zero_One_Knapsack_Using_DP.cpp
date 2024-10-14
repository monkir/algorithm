#include<iostream>
using namespace std;
class element
{
    int weight=0;
    int benefit=0;
public:
    void setWeight()
    {
        cout<<"Enter weight: ";
        cin>>weight;
    }
    void setWeight(int w)
    {
        weight=w;
    }
    void setBenefit()
    {
        cout<<"Enter benefit: ";
        cin>>benefit;
    }
    void setBenefit(int b)
    {
        benefit=b;
    }
    void setAll()
    {
        setWeight();
        setBenefit();
    }
    int getWeight()
    {
        return weight;
    }
    int getBenefit()
    {
        return benefit;
    }
};
class Knapsack
{
    int W=0;//max weight
    int n=0;//number of elements
    element *e=NULL;
    int **B=NULL;
public:
    void setW()
    {
        cout<<"Enter maximum weight: ";
        cin>>W;
    }
    void setW(int w)
    {
        W=w;
    }
    void setN()
    {
        cout<<"Enter number of elements: ";
        cin>>n;
    }
    void setN(int n)
    {
        this->n=n;
    }
    int getW()
    {
        return W;
    }
    int getN()
    {
        return n;
    }
    void Zero_One_Knapsack()
    {
        B=new int*[n+1];
        for(int i=0; i<=n; i++)
        {
            B[i]=new int[W+1];
        }
        e=new element[n];
        for(int i=0; i<n; i++)
        {
            cout<<"For element no \'"<<i+1<<"\':"<<endl;
            e[i].setAll();
            cout<<endl;
        }
        for(int w=0; w<=W; w++)
        {
            B[0][w]=0;
        }
        for(int i=0; i<=n; i++)
        {
            B[i][0]=0;
        }
        for(int i=1; i<=n; i++)
        {
            B[i][0]=0;
            int bi=e[i-1].getBenefit();
            int wi=e[i-1].getWeight();
            for(int w=1; w<=W; w++)
            {
                if(wi<=w)//item i can be part of the solution
                {
                    if( ( bi+B[i-1][w-wi] ) > B[i-1][w])
                    {
                        B[i][w]=bi+B[i-1][w-wi];
                        //cout<<"Take element \'"<<i<<"\': "<<endl;
                    }
                    else
                    {
                        B[i][w]=B[i-1][w];
                    }
                }
                else
                {
                    B[i][w]=B[i-1][w];//wi>w
                }
            }
        }
        cout<<"Maximum Benefit: "<<B[n][W]<<endl;
    }
};
int main()
{
    Knapsack k;
    k.setW();
    k.setN();
    k.Zero_One_Knapsack();
    return 0;
}

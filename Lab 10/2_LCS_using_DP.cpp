#include<iostream>
using namespace std;
class LCS
{
    int **c=NULL;
    string **b=NULL;
    int m=0, n=0;
    string X="", Y="";
public:
    void setX()
    {
        cout<<"Enter value of string \'X\': ";
        cin>>X;
    }
    void setY()
    {
        cout<<"Enter value of string \'Y\': ";
        cin>>Y;
    }
    void setX(string x)
    {
        X=x;
    }
    void setY(string y)
    {
        Y=y;
    }
    void LCS_Length()
    {
        m=X.length();
        n=Y.length();
        c=new int*[m+1];
        for(int i=0; i<=m; i++)
        {
            c[i]=new int[n+1];
        }
        b=new string*[m+1];
        for(int i=0; i<=m; i++)
        {
            b[i]=new string[n+1];
        }
        //main algoritm
        cout<<"LCS: ";
        for(int i=1; i<=m; i++)
        {
            c[i][0]=0;
        }
        for(int j=0; j<=n; j++)
        {
            c[0][j]=0;
        }
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(X[i-1]==Y[j-1])
                {
                    c[i][j]=c[i-1][j-1]+1;
                    b[i][j]="copy";
                }
                else if(c[i-1][j]>=c[i][j-1])
                {
                    c[i][j]=c[i-1][j];
                    b[i][j]="skipX";
                }
                else
                {
                    c[i][j]=c[i][j-1];
                    b[i][j]="skipY";
                }
            }
        }
        //return c, b;
    }
    void print_LCS()
    {
        print_LCS(m,n);
    }
    void print_LCS(int i, int j)
    {
        if(i==0 || j==0)
        {
            return;
        }
        if(b[i][j]=="copy")
        {
            print_LCS(i-1, j-1);
            cout<<X[i-1];
        }
        else if(b[i][j]=="skipX")
        {
            print_LCS(i-1,j);
        }
        else
        {
            print_LCS(i,j-1);
        }
    }
};
int main()
{
    LCS l;
    l.setX();
    l.setY();
    l.LCS_Length();
    l.print_LCS();
    return 0;
}

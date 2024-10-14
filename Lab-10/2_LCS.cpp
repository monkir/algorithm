#include<iostream>
using namespace std;
class LCS
{

};

void LCS_Length(string X, string Y, int m, int n)
{
    string b[m+1][n+1];
    int c[m+1][n+1];
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
        for(int j=0; j<=n; j++)
        {
            if(X[i]==Y[i])
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
    // return c,b;
}
int main()
{
    return 0;
}

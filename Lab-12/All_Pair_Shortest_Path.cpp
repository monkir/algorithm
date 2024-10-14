#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void insertDEdge(int **G,int s,int d){
    G[s][d]=1;
}
void insertDEdge(int **G,int s,int d, int weight){
    G[s][d]=weight;
}
void insertUDEdge(int **G,int s,int d){
    G[s][d]=1;
    G[d][s]=1;
}

void DisplayGraph(int **G,int N){
    cout<<"\t";
    for(int i=0;i<N;i++){
        cout<<(char)(65+i)<<"\t";
    }
    cout<<endl;

    for(int i=0;i<N;i++){
        cout<<(char)(65+i)<<"\t";
        for(int j=0;j<N;j++){
                if(G[i][j]==1000)
                {
                    cout<<"MAX"<<"\t";
                }
                else
                {
                    cout<<G[i][j]<<"\t";
                }
        }
        cout<<endl;
    }
}
void Display_P_Graph(int **G,int N){
    cout<<"\t";
    for(int i=0;i<N;i++){
        cout<<(char)(65+i)<<"\t";
    }
    cout<<endl;

    for(int i=0;i<N;i++){
        cout<<(char)(65+i)<<"\t";
        for(int j=0;j<N;j++){
                if(G[i][j]==-1)
                {
                    cout<<"NIL"<<"\t";
                }
                else
                {
                    cout<<G[i][j]<<"\t";
                }
        }
        cout<<endl;
    }
}

int main(){
    int N=5;
    int **G = new int*[N];
    int **D = new int*[N];
    int **P = new int*[N];

    for(int i=0;i<N;i++){
        G[i] = new int[N];
        D[i] = new int[N];
        P[i] = new int[N];
        for(int j=0;j<N;j++){
            G[i][j]=0;
            D[i][j]=1000;
            P[i][j]=-1;
        }
    }

    insertDEdge(G,0,1,3);
    insertDEdge(G,0,2,8);
    insertDEdge(G,0,4,-4);
    insertDEdge(G,1,3,1);
    insertDEdge(G,1,4,7);
    insertDEdge(G,2,1,4);
    insertDEdge(G,3,0,2);
    insertDEdge(G,3,2,-5);
    insertDEdge(G,4,3,6);
    DisplayGraph(G,N);
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(G[i][j]!=0)
            {
                D[i][j]=G[i][j];
                P[i][j]=i;
            }
            else if(i==j)
            {
                D[i][j]=0;
                P[i][j]=-1;
            }
            else
            {
                D[i][j]=1000;
                P[i][j]=-1;
            }
        }
    }

    cout<<endl<<"D------:"<<endl;
    DisplayGraph(D,N);
    cout<<endl<<"P------:"<<endl;
    Display_P_Graph(P,N);
    //starting Floyd Warshall Algorithm
    for(int k=0; k<N; k++)
    {
        for(int s=0; s<N; s++)
        {
            for(int d=0; d<N; d++)
            {
                if(D[s][d]>D[s][k]+D[k][d])
                {
                    D[s][d]=D[s][k]+D[s][d];
                    P[s][d]=P[k][d];
                }
            }
        }
    }
    DisplayGraph(D,N);
    Display_P_Graph(P,N);

return 0;
}

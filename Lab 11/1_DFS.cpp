#include<iostream>
using namespace std;
class graph
{
    int N=-1;
    int** G=NULL;
    string* colour=NULL;
    int* d=NULL;
    int* f=NULL;
    int* p=NULL;
    int time=0;
    string valueOfDFS="";
public:
    graph()
    {
        //;
    }
    graph(int nodes)
    {
        setNodes(nodes);
    }
    void setNodes(int nodes)
    {
        N=nodes;
        G=new int*[N];
        for(int i=0; i<N; i++)
        {
            G[i]=new int[N];
            for(int j=0; j<N; j++)
            {
                G[i][j]=0;
            }
        }
        colour=new string[N];
        d=new int[N];
        f=new int[N];
        p=new int[N];

    }
    void setNodes()
    {
        cout<<"Enter number of nodes: ";
        cin>>N;
        setNodes(N);
    }
    void insertDEdge(int s,int d)
    {
        G[s][d]=1;
    }
    void insertDEdge()
    {
        int s, d;
        cout<<"Enter starting Node: ";
        cin>>s;
        cout<<"Enter destination Node: ";
        cin>>d;
        insertDEdge(s,d);
        cout<<"Directed Edge ["<<(char)(65+s)<<(char)(65+d)<<"] is inserted"<<endl;
    }
    void insert_D_edges(int n)
    {
        for(int i=0; i<n; i++)
        {
            insertDEdge();
        }
    }
    void insert_D_edges()
    {
        cout<<"Enter number of edges: ";
        int n;
        cin>>n;
        insert_D_edges(n);
    }
    void insertUDEdge(int s,int d)
    {
        G[s][d]=1;
        G[d][s]=1;
    }
    void insertUDEdge()
    {
        int s, d;
        cout<<"Enter starting Node: ";
        cin>>s;
        cout<<"Enter destination Node: ";
        cin>>d;
        insertUDEdge(s,d);
        cout<<"UnDirected Edge ["<<s<<"] ["<<d<<"] is inserted"<<endl;
    }
    void DisplayGraph()
    {
        cout<<endl<<"Graph display: "<<endl;
        for(int i=0;i<N;i++)
        {
            cout<<"\t"<<(char)(65+i);
        }
        cout<<endl;
        for(int i=0;i<N;i++)
        {
            cout<<(char)(65+i)<<"\t";
            for(int j=0;j<N;j++)
            {
                cout<<G[i][j]<<"\t";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    void DisplayNodes()
    {
        cout<<"Nodes: \t\t";
        for(int i=0; i<N; i++)
        {
            cout<<(char)(65+i)<<"\t";
        }
        cout<<endl;
        cout<<"Positions: \t";
        for(int i=0; i<N; i++)
        {
            cout<<i<<"\t";
        }
        cout<<endl;
    }
    void DFS()
    {
        for(int u=0; u<N; u++)
        {
            colour[u]="white";
        }
        time=0;
        valueOfDFS="";
        cout<<"DFS: \t";
        for(int u=0; u<N; u++)
        {
            if(colour[u]=="white")
            {
                visitDFS(u);
            }
        }
        cout<<endl;
    }
    void visitDFS(int u)
    {
        valueOfDFS=valueOfDFS+(char)(65+u)+" ";
        colour[u]="gray";
        d[u]=++time;
        for(int v=0; v<N; v++)
        {
            if(colour[v]=="white" && G[u][v]==1)
            {
                p[v]=u;
                visitDFS(v);
            }
        }
        colour[u]="black";
        f[u]=++time;
    }
    void printDFS()
    {
        cout<<"DFS: "<<valueOfDFS<<endl;
    }
};

int main()
{
    graph g;
    g.setNodes();
    g.DisplayNodes();
    g.insert_D_edges();
    g.DisplayGraph();
    g.DFS();
    g.printDFS();
    return 0;
}



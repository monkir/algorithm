#include<iostream>
using namespace std;
class Queue
{
    int Front=-1;
    int Rear=-1;
    int Size;
    int *arr=NULL;
public:
    Queue()
    {
        Size=10;
        arr=new int[Size];
    }
    Queue(int n)
    {
        Size=n;
        arr=new int[Size];
    }
    bool isEmpty()
    {
        if(Front==-1 && Rear==-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isFull()
    {
        if(((Rear+1)%Size)==Front)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void enQueue(int c)
    {
        if(isFull())
        {
            Resize();
            enQueue(c);
        }
        else if(isEmpty())
        {
            Front=0;
            Rear=0;
            arr[Rear]=c;
        }
        else
        {
            Rear=((Rear+1)%Size);
            arr[Rear]=c;
        }
    }
    int deQueue()
    {
        if(isEmpty())
        {
            cout<<"The Queue is Empty"<<endl;
            return 0;
        }
        else
        {
            if(Front==Rear)
            {
                int TempElement=arr[Front];
                Front=-1;
                Rear=-1;
                return TempElement;
            }
            else
            {
                int TempElement=arr[Front];
                Front=((Front+1)%Size);
                return TempElement;
            }
        }
    }
    int RearElement()
    {
        if(isEmpty())
        {
            cout<<"The Queue is Empty"<<endl;
            return 0;
        }
        else
        {
            return arr[Rear];
        }
    }
    int FrontElement()
    {
        if(isEmpty())
        {
            cout<<"The Queue is Empty"<<endl;
            return 0;
        }
        else
        {
            return arr[Front];
        }
    }
    void printQueue()
    {
        cout<<"Queue :";
        if(Front<=Rear)
        {
            for(int i=Rear; i>=Front; i--)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
        else
        {
            for(int i=Rear; i>=0; i--)
            {
                cout<<arr[i]<<" ";
            }

            for(int i=(Size-1); i>=Front; i--)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }

    }
    void Resize()
    {
        int *tempArr= new int[Size+10];
        int tempFrontCounter=0;
        if(Front<=Rear)
        {
            for(int i=Rear; i>=Front; i--)
            {
                tempArr[i]=arr[i];
                tempFrontCounter++;
            }
        }
        else
        {
            for(int i=Rear; i>=0; i--)
            {
                tempArr[i]=arr[i];
                tempFrontCounter++;
            }

            for(int i=(Size-1); i>=Front; i--)
            {
                tempArr[i]=arr[i];
                tempFrontCounter++;
            }
        }
        Front=0;
        Rear=tempFrontCounter-1;
        delete [] arr;
        arr = tempArr;
        Size=Size+10;
    }
    int getCount()
    {
        int counter=0;
        if(isEmpty())
        {
            counter=0;
        }
        else if(Front<=Rear)
        {
            for(int i=Rear; i>=Front; i--)
            {
                counter++;
            }
        }
        else
        {
            for(int i=Rear; i>=0; i--)
            {
                counter++;
            }

            for(int i=(Size-1); i>=Front; i--)
            {
                counter++;
            }
        }
        return counter;
    }
    int Search(int s)
    {
        int i=0;
        while(i<getCount())
        {
            if(s==arr[i])
            {
                return i;
            }
                i++;
        }
        return -1;
    }
};

class graph
{
    int N=-1;
    int** G=NULL;
    string* colour=NULL;
    int* d=NULL;
    int* f=NULL;
    int* p=NULL;
    int time=0;
    string valueOfDSF="";
    Queue *q=NULL;
    string valueOfBFS="";
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
    void BFS()
    {
        valueOfBFS="";
        for(int i=0; i<N; i++)
        {
            colour[i]="white";
        }
        q=new Queue(N);
        colour[0]="gray";
        d[0]=1;
        p[0]=-1;
        (*q).enQueue(0);
        while(!(*q).isEmpty())
        {
            int u=(*q).deQueue();
            valueOfBFS=valueOfBFS+(char)(65+u)+" ";
            for(int v=0; v<N; v++)
            {
                if(colour[v]=="white" && G[u][v]==1)
                {
                    colour[v]="gray";
                    d[v]=d[u]+1;
                    p[v]=u;
                    (*q).enQueue(v);
                }
            }
            colour[u]="black";
        }
    }
    void printBFS()
    {
        cout<<"BFS: "<<valueOfBFS<<endl;
    }
};

int main()
{
    graph g;
    g.setNodes();
    g.DisplayNodes();
    g.insert_D_edges();
    g.DisplayGraph();
    g.BFS();
    g.printBFS();
    return 0;
}



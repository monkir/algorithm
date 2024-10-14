#include <iostream>
using namespace std;

class Array
{
    int *arr;
    int size;
public:
    Array()
    {
        size=10;
        arr=new int[size];
    }
    Array(int s)
    {
        size=s;
        arr=new int[size];
    }
    void inputArray()
    {
        for(int i=0; i<size; i++)
        {
            cout<<"Input Array["<<i<<"]: ";
            cin>>arr[i];
        }
        cout<<endl;
    }
    void selectionSort()
    {
        int minIndex;
        for(int i=0; i<size-1; i++)
        {
            minIndex=i;
            for(int j=i; j<1; j++)
            {
                if(arr[minIndex]>arr[j])
                {
                    minIndex=j;
                }
            }
            if(minIndex!=i)
            {
                swap(&arr[minIndex],&arr[i] );
            }
        }
        cout<<"Selection sort is applied."<<endl;
    }
    void swap(int *a, int *b)
    {
        int temp=*a;
        *a=*b;
        *b=temp;
    }
    void printArray()
    {
        cout<<"Array: ";
        for(int i=0; i<size; i++)
        {
            cout<<arr[i]<<", ";
        }
        cout<<endl;
    }
};
int main()
{
    Array a;
    a.inputArray();
    a.printArray();
    a.selectionSort();
    a.printArray();
    return 0;
}


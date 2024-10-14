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
    void BubbleSort()
    {
        bool sorted;
        for(int i=0; i<size-1; i++)
        {
            for(int j=0; j<size-i-1; j++)
            {
                sorted=true;
                if(arr[j]>arr[j+1])
                {
                    swap(&arr[j], &arr[j+1]);
                    sorted=false;
                }
            }
            if(sorted==true)
            {
                break;
            }
        }
        cout<<"Bubble sort is applied."<<endl;
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
    a.BubbleSort();
    a.printArray();
    return 0;
}



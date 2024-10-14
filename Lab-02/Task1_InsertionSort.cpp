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
    void insertionSort()
    {
        int key;
        for(int i=1; i<size; i++)
        {
            key=arr[i];
            int j=i-1;
            while (j>=0 && arr[j]>key)
            {
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=key;
        }
        cout<<"Insertion sort is applied."<<endl;
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
    a.insertionSort();
    a.printArray();
    return 0;
}

#include <iostream>
#include <bits/stdc++.h>
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
    void quickSort()
    {
        quickSort(0, size-1);
        cout<<"Quick sort is applied"<<endl;
    }
    void quickSort(int start, int end)
    {
        if(start<end)
        {
            int piv_pos=partition(start, end);
            quickSort(start, piv_pos-1);
            quickSort(piv_pos+1, end);
        }
    }

    int partition(int start, int end)
    {
        int i=start;
        int piv=arr[start];
        for(int j=start+1; j<=end; j++)
        {
            if(arr[j]<piv)
            {
                swap(&arr[++i],&arr[j]);
            }
        }
        swap(&arr[start],&arr[i]);
        return i;
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
    a.quickSort();
    a.printArray();
    cout<<endl<<"<----Sorry for late submission Sir----->"<<endl;
    return 0;
}




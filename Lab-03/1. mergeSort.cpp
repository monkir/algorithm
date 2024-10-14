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
    void mergeSort()
    {
        mergeSort(0, size-1);
        cout<<"The array has been sorted!"<<endl;
    }
    void mergeSort(int p, int r)
    {
        if (p<r)
        {
            int q=(p+r)/2;//dividing into two parts
            mergeSort(p,q);//recursion left parts
            mergeSort(q+1,r);//recursion right parts
            merge(p,q,r);//merging two parts
        }
    }
    void merge(int p, int q, int r)
    {
        int n1=q-p+1;//left parts array size
        int n2=r-q;//right parts array size
        int leftSide[n1+1];//declaring new array to merge
        int rightSide[n2+1];//declaring new array to merge
        for (int i=0; i<n1; i++)
        //putting value of the left parts to 'leftSide' array
        {
            leftSide[i]=arr[p+i];
        }
        for (int i=0; i<n2; i++)
        //putting value of the right parts to 'rightSide' array
        {
            rightSide[i]=arr[q+i+1];
        }
        leftSide[n1]=INT_MAX;//define the last index as infinite value
        rightSide[n2]=INT_MAX;//define the last index as infinite value
        int i=0, j=0;
        for (int k=p; k<=r; k++)
        {
            if(leftSide[i]<=rightSide[j])
            {
                arr[k]=leftSide[i++];
            }
            else
            {
                arr[k]=rightSide[j++];
            }
        }
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
    a.mergeSort();
    a.printArray();
    return 0;
}



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
    void countingSort()
    {
        int k=arr[0];//variable k is for maximum number
        int min=arr[0];
        for(int i=1;i<size; i++)
        {
            if(arr[i]>k)
            {
                k=arr[i];
            }
            if(arr[i]<min)
            {
                min=arr[i];
            }
        }
        int cArr[k-min+1];//counting array
        for(int i=0; i<=k-min; i++)
        {
            cArr[i]=0;
        }
        for(int i=0; i<size; i++)
        {
            cArr[arr[i]-min]++;
            //counting the numbers occoures for how many times
        }
        for(int i=1; i<=k-min; i++)
        {
            cArr[i]=cArr[i]+cArr[i-1];
        }
        for(int i=0; i<=k-min; i++)
        {
            cArr[i]--;
            //In programming language indexes normally counted from 0;
        }
        int tempArr[size];//result array
        for(int i=size-1; i>=0; i--)
        {
            tempArr[cArr[arr[i]-min]--]=arr[i]-min;
        }
        for(int i=0; i<size; i++)
        {
            arr[i]=tempArr[i]+min;
        }
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
    a.countingSort();
    a.printArray();
    return 0;
}



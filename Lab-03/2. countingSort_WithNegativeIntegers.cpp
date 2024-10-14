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
    void countingSort()
    {
        int min=arr[0],max=arr[0];
        //variable min is for minimum integer
        //variable max is for maximum integer
        for(int i=1;i<size; i++)
        {
            if(arr[i]<min)
            {
                min=arr[i];
            }
            else if(arr[i]>max)
            {
                max=arr[i];
            }
        }
        int cArr[max-min+1];
        //counting array for counting from min to max
        /*considering index 0 as index min, index 1 as min+1,
            index i as min+i, index size-1 as max */

        for(int i=0; i<=max-min; i++)
        {
            cArr[i]=0;
            //initially all number are not counted
        }
        for(int i=0; i<size; i++)
        {
            cArr[arr[i]-min]++;
            //counting the numbers occur for how many times
        }
        for(int i=1; i<=max-min; i++)
        {
            cArr[i]=cArr[i]+cArr[i-1];
        }
        int tempArr[size];//result array
        for(int i=size-1; i>=0; i--)
        {
            tempArr[--cArr[arr[i]-min]]=arr[i];
            //In programming language indexes normally counted from 0;
            //Thats why pre increment is used here
        }
        for(int i=0; i<size; i++)
        {
            arr[i]=tempArr[i];
            //overwriting the value of result to input array
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




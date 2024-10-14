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
        bool sorted=false;
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
    void BinarySearch(int item)
    {
        BubbleSort();
        //An array must be sorted before Binary Search
        printArray();
        int left=0, right=size-1, mid;
        bool founded=false;
        while(left<=right)
        {
            mid=(left+right)/2;
            if((arr[mid]==item))
            {
                cout<<"The item "<<item<<" is founded at index "<<mid<<"."<<endl;
                founded=true;
                break;
            }
            else if((arr[mid]<item))
            {
                left=mid+1;
            }
            else if((arr[mid]>item))
            {
                right=mid-1;
            }
        }
        if(founded==false)
        {
            cout<<"The item "<<item<<" was not founded"<<endl;
        }
    }
    void BinarySearch()
    {
        cout<<"Enter item to binary search: ";
        int item;
        cin>>item;
        BinarySearch(item);
    }
};
int main()
{
    Array a;
    a.inputArray();
    a.printArray();
    a.BinarySearch();
    return 0;
}




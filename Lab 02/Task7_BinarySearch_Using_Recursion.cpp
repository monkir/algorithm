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
    void BinarySearch(int item, int left, int right)
    {
        if(left<=right)
        {
            int mid=(left+right)/2;
            if((arr[mid]==item))
            {
                cout<<"The item "<<item<<" is founded at index "<<mid<<"."<<endl;
            }
            else if((arr[mid]<item))
            {
                left=mid+1;
                BinarySearch(item, left, right);
            }
            else if((arr[mid]>item))
            {
                right=mid-1;
                BinarySearch(item, left, right);
            }
        }
        else
        {
            cout<<"The item "<<item<<" is not founded."<<endl;
        }
    }
    void BinarySearch()
    {
        cout<<"Enter item to binary search: ";
        int item;
        cin>>item;
        BubbleSort();
        //An array must be sorted before Binary Search
        printArray();
        BinarySearch(item, 0, size-1);
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





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
    void printArray()
    {
        cout<<"Array: ";
        for(int i=0; i<size; i++)
        {
            cout<<arr[i]<<", ";
        }
        cout<<endl;
    }
    void linearSearch(int item)
    {
        bool founded=false;
        for(int i=0; i<size; i++)
        {
            if(item==arr[i])
            {
                founded=true;
                cout<<"The item "<<item<<" is founded at index "<<i<<"."<<endl;
                break;
            }
        }
        if(founded==false)
        {
            cout<<"The item "<<item<<" was not founded"<<endl;
        }
    }
    void linearSearch()
    {
        cout<<"Enter item to linear search: ";
        int item;
        cin>>item;
        linearSearch(item);
    }
};
int main()
{
    Array a;
    a.inputArray();
    a.printArray();
    a.linearSearch();
    return 0;
}




#include<iostream>
using namespace std;
class activity
{
    string name="";
    int beg=0;//beginning time
    int end=0;//ending time
public:
    void setName(string name)
    {
        this->name=name;
    }
    void setName()
    {
        cout<<"Enter activity name: ";
        cin>>name;
    }
    void setBeg(int beg)
    {
        this->beg=beg;
        if(beg>end && beg<0)
        {
            cout<<"Wrong input! Please try again."<<endl;
            setBeg();
        }
    }
    void setBeg()
    {
        cout<<"Enter Beginning time: ";
        cin>>beg;
        setBeg(beg);
    }
    void setEnd(int end)
    {
        this->end=end;
        if(beg>end && end<0)
        {
            cout<<"Wrong input! Please try again."<<endl;
            setEnd();
        }
    }
    void setEnd()
    {
        cout<<"Enter Ending time: ";
        cin>>end;
        setEnd(end);
    }
    void setAll()
    {
        setName();
        setBeg();
        setEnd();
    }
    int getBeg()
    {
        return beg;
    }
    string getName()
    {
        return name;
    }
    int getEnd()
    {
        return end;
    }
    int getLeangth()
    {
        return end-beg;
    }
    void getInformation()
    {
        cout<<"Activity Name: "<<name<<"."<<endl;
        cout<<"Beginning time: "<<beg<<"."<<endl;
        cout<<"Ending time: "<<end<<"."<<endl;
    }
};
class activitySelection
{
    activity *act=NULL;
    int n=0;
public:
    void enterActivites()
    {
        cout<<"Enter number of activities: ";
        cin>>n;
        act=new activity[n];
        for(int i=0; i<n; i++)
        {
            cout<<"For activity no "<<i+1<<": "<<endl;
            act[i].setAll();
            cout<<endl;
        }
    }
    void sortActivity()
    {
        //sort by ending time first
        for(int i=0; i<n; i++)
        {
            int k=i;
            for(int j=i+1; j<n; j++)
            {
                if(act[j].getEnd()<act[k].getEnd())
                {
                    k=j;
                }
            }
            if(k!=i)
            {
                swap(&act[i], &act[k]);
            }
        }
        //sort by beginning when ending time is same
        for(int i=0; i<n; i++)
        {
            int k=i;
            for(int j=i+1; j<n; j++)
            {
                if(act[j].getEnd()==act[k].getEnd() && act[j].getBeg()<act[k].getBeg())
                {
                    k=j;
                }
            }
            if(k!=i)
            {
                swap(&act[i], &act[k]);
            }
        }
    }
    void swap(activity *i, activity *j)
    {
        activity temp=*i;
        *i=*j;
        *j=temp;
    }
    void solveActivitySelection()
    {
        sortActivity();
        int currentEnd=act[0].getEnd();
        int totalTime=act[0].getLeangth();
        cout<<"------------------------------------------------------------------"<<endl;
        cout<<"Solve of activity selection :"<<endl<<endl;
        act[0].getInformation();
        cout<<endl;
        for(int i=1; i<n; i++)
        {
            if(act[i].getBeg()>=currentEnd)
            {
                currentEnd=act[i].getEnd();
                totalTime+=act[i].getLeangth();
                act[i].getInformation();
                cout<<endl;
            }
        }
        cout<<"<-------- Total activity time: "<<totalTime<<". ------------->"<<endl;
    }
};
int main()
{
    activitySelection as;
    as.enterActivites();
    as.solveActivitySelection();
    return 0;
}

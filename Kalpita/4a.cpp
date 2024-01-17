//4a : pre-emptive srtn
#include <iostream>
#define pending 1
#define finished 2

using namespace std;

class processes
{
private:
    char name;
    int BT;
    int AT;
    int WT;
    int TAT;
    int RT;
    int status;

public:
    void input(int);
    void srtn(int, processes[]);
    void output(int);
    int minimum(int,processes[]);
};

void processes::input(int i)
{
    cout << "\n\nPROCESS " << i + 1;
    cout << "\nPROCESS NAME : ";
    cin >> name;
    cout << "BURST TIME : ";
    cin >> BT;
    cout << "ARRIVAL TIME : ";
    cin >> AT;
    status = pending;
    RT = BT;
}

void processes::output(int i)
{ 
    cout<<name<<"\t\t"<<BT<<"\t\t"<<AT<<"\t\t"<<WT<<"\t\t"<<TAT<<"\n";
}

void processes::srtn(int n, processes p[])
{
    int total_time = minimum(n,p), k = 0;
    float avg_WT = 0;
    float avg_TAT = 0;
    cout << "\n\n"<<total_time;
    while(true)
    {
        int rt=9999;
        for (int j = 0; j < n; j++)
        {
            if (p[j].status == pending && p[j].RT < rt && p[j].AT<=total_time)
            {
                k = j;
                rt=p[j].RT;
            }
        }
        int j,check=0;
        for(j=0;j<p[k].RT;j++)
        {
            for(int l=0;l<n;l++)
            {
                if(l!=k)
                {
                    if(p[l].AT==total_time + j)
                    {
                        if(p[l].RT<(p[k].RT-j))
                        {
                            check=1;
                            break;
                        }
                    }
                }
            }
            if(check)break;
        }
        total_time+=j;
        if(j==p[k].RT)
        {
        p[k].status=finished;
        p[k].TAT = total_time - p[k].AT;
        avg_TAT += p[k].TAT;
        p[k].WT= p[k].TAT-p[k].BT;
        avg_WT += p[k].WT;
        }
        else
        {
            p[k].RT-=j;
        }
        cout<<"|--"<<p[k].name;
        for(int k = 0;k<total_time;k++)
        {
            cout<<"-";
        }
        cout<<total_time;

        int if_finished=0;
        for(int i=0;i<n;i++)
        if(p[i].status==pending)
        if_finished=1;
        if(!if_finished)
        break;
    }
cout << "|";
cout << "\n\n\nAVERAGE WAITING TIME : " << avg_WT / n;
cout << "\nAVERAGE TURN AROUND TIME : " << avg_TAT / n << endl;
}
int processes::minimum(int n,processes p[])
{
    int  min=9999;
    for(int i=0;i<n;i++)
    if(p[i].AT<min)
    min=p[i].AT;
    return min;
}
int main()
{
    int n;
    cout << "Enter total number of processes :";
    cin >> n;
    processes *p;
    p = new processes[n];

    for (int i = 0; i < n; i++)
    {
        p[i].input(i);
    }
    processes x;
    x.srtn(n, p);
    cout << "\nProcess\t\tBT\t\tAT\t\tWT\t\tTAT\n";
    for (int i = 0; i < n; i++)
    {
        p[i].output(i);
    }
    return 0;
}
//EXP4b : pre-emptive priority scheduling
#include <iostream>

using namespace std;

class sequencing
{
	char name;
    int BT;
    int AT;
    int WT;
    int TAT;
    int status;
    int priority;
    int remaining_time;
    
public:
    void input(int);
    void prio(int, sequencing[]);
    void output(int);
       int minimum(int,sequencing[]);
};

#define pending 1
#define finished 2

void sequencing::input(int i)
{
	cout << "\n\nPROCESS " << i + 1;
	 cout << "\nPROCESS NAME : ";
	 cin >> name;
	 cout << "BURST TIME : ";
	 cin >> BT;
	 cout << "ARRIVAL TIME : ";
	 cin >> AT;
	 cout<<"PRIORITY : ";
	 cin>>priority;
	 status=pending;
	 remaining_time=BT;

}
void sequencing::output(int i)
{
    cout<<name<<"\t\t"<<BT<<"\t\t"<<AT<<"\t\t"<<WT<<"\t\t"<<TAT<<"\t\t"<<priority<<"\n";
}
void sequencing::prio(int n, sequencing p[])
{
    int total_time = minimum(n,p), k = 0;
    float avg_WT = 0;
    float avg_TAT = 0;
    cout << "\n\n"<<total_time;
    while(true)
    {
        int pt=9999;
        for (int j = 0; j < n; j++)
        {
            if (p[j].status == pending && p[j].priority < pt && p[j].AT<=total_time)
            {
                if(p[j].priority<pt)
                {
                k = j;
                pt=p[j].priority;
                }
                else
                {
                    if(p[k].remaining_time>p[j].remaining_time)
                    {
                    k=j;
                    pt=p[j].priority;
                    }
                    else
                    {
                        k=j;
                        pt=p[j].priority;
                    }
                }
            }
        }
        int j,check=0;
        for(j=0;j<p[k].remaining_time;j++)
        {
            for(int l=0;l<n;l++)
            {
                if(l!=k)
                {
                    if(p[l].AT==total_time + j)
                    {
                        if(p[l].priority<=(p[k].priority))
                        {
                            if(p[l].priority==p[k].priority)
                            {
                                if(p[k].remaining_time>p[l].remaining_time-j)
                                {
                                    check=1;
                                    break;
                                }
                            }
                            else
                            {
                                check=1;
                                break;
                            }
                        }
                    }
                }
            }
            if(check)break;
        }
        total_time+=j;
        if(j==p[k].remaining_time)
        {
        p[k].status=finished;
        p[k].TAT = total_time - p[k].AT;
        avg_TAT += p[k].TAT;
        p[k].WT= p[k].TAT-p[k].BT;
        avg_WT += p[k].WT;
        }
        else
        {
            p[k].remaining_time-=j;
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

    }//end of while loop
cout << "|";
cout << "\n\nAVERAGE WAITING TIME : " << avg_WT / n;
cout << "\n\nAVERAGE TURN AROUND TIME : " << avg_TAT / n << endl;
}


int sequencing::minimum(int n,sequencing p[])
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
    cout << "ENTER THE NUMBER OF JOBS : ";
    cin >> n;
    sequencing *p;
    p = new sequencing[n];
    for (int i = 0; i < n; i++)
        p[i].input(i);
    sequencing x;
    x.prio(n, p);
    cout << "\nProcess\t\tBT\t\tAT\t\tWT\t\tTAT\t\tPriority\n";
    for (int i = 0; i < n; i++)
        p[i].output(i);
    return 0;
}



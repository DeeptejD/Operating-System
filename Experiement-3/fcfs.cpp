#include<bits/stdc++.h>
#define N 30

using namespace std;

struct p{
    int bt, wt, tat, p_no;
};



int main(int argc, char const *argv[])
{
    int n, atat=0, awt=0;
    struct p pro[N];
    cout<<"Enter the number of processes: ", cin>>n;    

    for(int i=0;i<n;i++)
    {
        pro[i].p_no = i+1;
        cout<<"enter the burst time: ", cin>>pro[i].bt;
        pro[i].wt = pro[i].tat=0;
    }

    // calc tats
    int ct=0;
    for(int i=0;i<n;i++)
    {
        ct=0;
        for(int j=0;j<i;j++)
            ct+=pro[j].bt;
        ct+=pro[i].bt;
        pro[i].tat = ct;
    }

    // calc wt
    for(int i=0;i<n;i++)
        pro[i].wt = pro[i].tat - pro[i].bt;
    
    // calc atat and awt
    
    for(int i=0;i<n;i++)
        atat+=pro[i].tat, awt+=pro[i].wt;

    // table
    for(int i=0;i<n;i++)
    {
        cout<<pro[i].p_no<<"\t"<<pro[i].wt<<"\t"<<pro[i].tat<<endl;
    }

    cout<<"Avg waiting time: "<<awt/n<<endl<<"Avg tat: "<<atat/n;

    return 0;
}

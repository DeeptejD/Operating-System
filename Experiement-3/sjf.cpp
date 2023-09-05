#include<bits/stdc++.h>
#define N 30

using namespace std;

struct p{
    int bt, wt, tat, p_no;
};

bool cmp(p a, p b)
{
    return (a.bt <  b.bt);
}

bool cmp_id(p a, p b)
{
    return (a.p_no < b.p_no);
}

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

    sort(pro, pro + n, cmp);

    // calc tats
    for(int i=0;i<n;i++)
    {
        int ct=0;
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

    sort(pro, pro+n, cmp_id);

    // table
    cout<<"Pro no\twaiting time\t\tTAT"<<endl;
    for(int i=0;i<n;i++)
        cout<<pro[i].p_no<<"\t"<<"\t"<<pro[i].wt<<"\t"<<pro[i].tat<<endl;

    cout<<"Avg waiting time: "<<awt/n<<endl<<"Avg tat: "<<atat/n<<endl;;

    sort(pro, pro+n, cmp);

    // gantt
    for(int i=0;i<n;i++)
    {
        cout<<"|";
        for(int j=0;j<pro[i].bt;j++)
        {
            if(j==pro[i].bt/2)
                cout<<"P"<<pro[i].p_no;
            else
                cout<<" ";
        }
    }
    cout<<"|";
    cout<<endl;
    int global_ct=0;
    cout<<global_ct;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<pro[i].bt-1;j++)
            cout<<" ";
        global_ct+=pro[i].bt;
        if(global_ct<10)
            cout<<"  "<<global_ct;
        else
            cout<<" "<<global_ct;
    }
    cout<<endl;

    return 0;
}


/*
4
9
1
6
8

*/
#include <bits/stdc++.h>
#define N 30

using namespace std;

struct p
{
    int at, bt, wt, tat, p_no, ct;
};

bool cmp(p a, p b)
{
    return (a.at < b.at);
}

bool cmp_id(p a, p b)
{
    return (a.p_no < b.p_no);
}

int main(int argc, char const *argv[])
{
    int n;
    float atat = 0, awt = 0;
    struct p pro[N];
    cout << "Enter the number of processes: ", cin >> n;

    for (int i = 0; i < n; i++)
    {
        pro[i].p_no = i + 1;
        cout << "enter the burst time: ", cin >> pro[i].bt;
        cout << "enter the arrival time: ", cin >> pro[i].at;
        pro[i].wt = pro[i].tat = pro[i].ct = 0;
    }

    sort(pro, pro + n, cmp);

    // calc tats
    int ctime = 0;
    for (int i = 0; i < n; i++)
    {
        if (pro[i].at > ctime)
            ctime = pro[i].at + pro[i].bt;
        else
            ctime += pro[i].bt;

        pro[i].ct = ctime;
        pro[i].tat = pro[i].ct - pro[i].at;
    }

    // calc wt
    for (int i = 0; i < n; i++)
        pro[i].wt = pro[i].tat - pro[i].bt;

    // calc atat and awt
    for (int i = 0; i < n; i++)
        atat += pro[i].tat, awt += pro[i].wt;

    sort(pro, pro + n, cmp_id);

    // table
    cout << "Pro no\tAT\tWT\tTAT" << endl;
    for (int i = 0; i < n; i++)
        cout << pro[i].p_no << "\t" << pro[i].at << "\t" << pro[i].wt << "\t" << pro[i].tat << endl;

    cout << "Avg waiting time: " << std::setprecision(4) << awt / n << endl
         << "Avg tat: " << std::setprecision(4) << atat / n << endl;

    sort(pro, pro + n, cmp);

    // gantt
    for (int i = 0; i < n; i++)
    {
        cout << "|";
        for (int j = 0; j < pro[i].bt; j++)
        {
            if (j == pro[i].bt / 2)
                cout << "P" << pro[i].p_no;
            else
                cout << " ";
        }
    }
    cout << "|";
    cout << endl;
    int global_ct = 0;
    cout << global_ct;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < pro[i].bt - 1; j++)
            cout << " ";
        global_ct += pro[i].bt;
        if (global_ct < 10)
            cout << "  " << global_ct;
        else
            cout << " " << global_ct;
    }
    cout << endl;

    return 0;
}

/*
failing testcase
5
400
2
5
0
4
4
2
2
3
1

*/

/*
5
2
3
0
5
4
4
2
2
1
3

*/
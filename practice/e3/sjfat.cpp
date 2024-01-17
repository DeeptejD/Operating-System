// SJF
#include <bits/stdc++.h>
#define N 30
#define infinity INT_MAX
using namespace std;

enum state
{
    not_arrived,
    arrived,
    completed
};

struct p
{
    int at, bt, wt, tat, id, order;
    state flag;
};

int currentTime = 0, rtime = 0, gorder = 1;

bool cmp(p a, p b)
{
    return (a.at < b.at);
}

bool cmp_order(p a, p b)
{
    return (a.order < b.order);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    struct p pro[N];

    for (int i = 0; i < n; i++)
    {
        cin >> pro[i].at >> pro[i].bt;
        // in sjf we set wt, tat and order to -1
        pro[i].wt = pro[i].tat = pro[i].order = -1;
        pro[i].flag = not_arrived;
        pro[i].id = i + 1;
        rtime += pro[i].bt;
    }

    // sort according to at
    sort(pro, pro + n, cmp);

    while (rtime)
    {
        // update the processes to reflect the ones that have arrived
        for (int i = 0; i < n; i++)
            if (pro[i].flag == not_arrived && pro[i].at <= currentTime)
                pro[i].flag = arrived;
        int index = -1, max_bt = infinity;
        // find the shortest bt process that has arrived
        for (int i = 0; i < n; i++)
            if (pro[i].bt < max_bt && pro[i].flag == arrived)
                max_bt = pro[i].bt, index = i;

        if (index == -1)
        {
            currentTime++; // tick the clock
            continue;
        }
        pro[index].order = gorder++;
        currentTime += pro[index].bt;
        rtime -= pro[index].bt;
        pro[index].flag = completed;
    }

    // sort according to the order of execution
    sort(pro, pro + n, cmp_order);

    for (int i = 0; i < n; i++)
    {
        int ct = 0;
        for (int j = 0; j < i; j++)
        {
            ct += pro[j].bt;
        }
        ct += pro[i].bt;
        pro[i].tat = ct - pro[i].at;
    }

    // calc wt
    for (int i = 0; i < n; i++)
        pro[i].wt = pro[i].tat - pro[i].bt;

    // Printing the table
    cout << "ID\tAT\tBT\tWT\tTAT" << endl;
    for (int i = 0; i < n; i++)
        cout << pro[i].id << "\t" << pro[i].at << "\t" << pro[i].bt << "\t" << pro[i].wt << "\t" << pro[i].tat << endl;
    cout << endl;

    // Calc AWT, ATAT
    float awt = 0, atat = 0;
    for (int i = 0; i < n; i++)
        awt += pro[i].wt, atat += pro[i].tat;

    cout << endl
         << "Average Waiting Time:" << std::fixed << std::setprecision(4) << awt / n << endl;
    cout << "Average Turnaround Time:" << std::fixed << std::setprecision(4) << atat / n << endl;

    // Printing the GANTT Chart
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "|";
        for (int j = 0; j < pro[i].bt; j++)
        {
            if (j == pro[i].bt / 2)
                cout << "P" << pro[i].id;
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
4
0
8
1
4
2
9
3
5

*/
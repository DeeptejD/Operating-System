#include <bits/stdc++.h>
using namespace std;

#define inf INT_MAX

enum state
{
    not_arrived,
    arrived,
    completed
};

struct p
{
    int bt, at, wt, tat, id, order;
    state flag;
};

bool cmp_at(p a, p b)
{
    return a.at < b.at;
}

bool cmp_order(p a, p b)
{
    return a.order < b.order;
}

int currentTime = 0, remainingTime = 0, globalOrder = 1;

int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter the number of processes: ", cin >> n;
    struct p pro[n];

    for (int i = 0; i < n; i++)
    {
        pro[i].id = i + 1;
        cout << "Enter the arrival time: ", cin >> pro[i].at;
        cout << "Enter the burst time: ", cin >> pro[i].bt;
        pro[i].wt = pro[i].tat = pro[i].order = -1;
        pro[i].flag = not_arrived;
        remainingTime += pro[i].bt;
    }

    // sort according to arrival time
    sort(pro, pro + n, cmp_at);

    while (remainingTime)
    {

        // update the processes to reflect the ones that have arrived
        for (int i = 0; i < n; i++)
        {
            if (pro[i].flag == not_arrived && pro[i].at <= currentTime)
                pro[i].flag = arrived;
        }

        int index = -1, max_bt = inf;

        // finding the shortest among those that have arrived
        for (int i = 0; i < n; i++)
        {
            if (pro[i].flag == arrived && (pro[i].bt < max_bt))
                max_bt = pro[i].bt, index = i;
        }

        if (index == -1)
        {
            currentTime++;
            continue;
        }
        pro[index].order = globalOrder++;
        pro[index].flag = completed;
        remainingTime -= pro[index].bt;
        currentTime += pro[index].bt;
    }

    // sort according to order of execution
    sort(pro, pro + n, cmp_order);

    // calc TAT (CT - AT)
    for (int i = 0; i < n; i++)
    {
        int ct = 0;
        for (int j = 0; j < i; j++)
            ct += pro[j].bt;
        ct += pro[i].bt;
        pro[i].tat = ct - pro[i].at;
    }

    // calc WT
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
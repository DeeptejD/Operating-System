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
    int bt, at, wt, tat, id, order, priority;
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
        cout << "Enter the priority: ", cin >> pro[i].priority;
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

        int index = -1, highest_priority = inf;

        // finding the process with the highest priority among those that have arrived
        for (int i = 0; i < n; i++)
        {
            if (pro[i].flag == arrived && (pro[i].priority < highest_priority))
                highest_priority = pro[i].priority, index = i;
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
        ct += pro[i].at;

        // ct += pro[i].bt;
        // // this piece of code adds the cpu vacant times to the overall completion time
        // for (int j = 1; j < n; j++)
        // {
        //     ct += pro[j].at - ct;
        //     ct+=pro[j].bt;
        // }
        // // this removes the burst times so only the vacant times are in the ct;
        // for(int j=0;j<n;j++)
        //     ct-=pro[j].bt;

        for (int j = 0; j < i; j++)
            ct += pro[j].bt;
        ct += pro[i].bt;
        pro[i].tat = ct - pro[i].at;
    }

    // calc WT
    for (int i = 0; i < n; i++)
        pro[i].wt = pro[i].tat - pro[i].bt;

    // Printing the table
    cout << endl
         << endl;
    cout << "ID\tAT\tBT\tPRIO\tWT\tTAT" << endl;
    for (int i = 0; i < n; i++)
        cout << pro[i].id << "\t" << pro[i].at << "\t" << pro[i].bt << "\t" << pro[i].priority << "\t" << pro[i].wt << "\t" << pro[i].tat << endl;
    cout << endl;

    // Calc AWT, ATAT
    float awt = 0, atat = 0;
    for (int i = 0; i < n; i++)
        awt += pro[i].wt, atat += pro[i].tat;

    cout << endl
         << endl
         << "Average Waiting Time:" << std::fixed << std::setprecision(4) << awt / n << endl;
    cout << "Average Turnaround Time:" << std::fixed << std::setprecision(4) << atat / n << endl;

    // Printing the GANTT Chart
    cout << endl
         << endl;
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
    int global_ct = pro[0].at; // this is the first arrival time
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
the example that starts at zero instead of 1
4
1
2
3
2
4
2
2
1
1
3
2
4

*/

/*
4
0
10
4
2
5
0
1
8
1
3
4
3

*/
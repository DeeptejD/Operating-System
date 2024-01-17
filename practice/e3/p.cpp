#include <bits/stdc++.h>
#define N 30
#define inf INT_MAX

using namespace std;

enum state
{
    not_arrived,
    arrived,
    completed
};

struct p
{
    int at, bt, wt, tat, id, order, prio;
    state flag;
};

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
    float awt = 0, atat = 0;

    struct p pro[N];

    int remainingTime = 0, gorder = 1, currentTime = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> pro[i].at >> pro[i].bt >> pro[i].prio;
        remainingTime += pro[i].bt;
        pro[i].flag = not_arrived;
        pro[i].id = i + 1;
        pro[i].wt = pro[i].tat = pro[i].order = -1;
    }

    // sort according to the increasing order of arrival time
    sort(pro, pro + n, cmp);

    while (remainingTime)
    {
        // update the processes to reflect the ones that have arrived
        for (int i = 0; i < n; i++)
        {
            if (pro[i].flag == not_arrived && pro[i].at <= currentTime)
                pro[i].flag = arrived;
        }

        // find the smallest priority
        int index = -1, highest_priority = inf;
        for (int i = 0; i < n; i++)
        {
            if (pro[i].flag == arrived && pro[i].prio < highest_priority)
                index = i, highest_priority = pro[i].prio;
        }

        // if we didnt find any
        if (index == -1)
        {
            currentTime++;
            continue;
        }

        pro[index].order = gorder++;
        pro[index].flag = completed;
        remainingTime -= pro[index].bt;
        currentTime += pro[index].bt;
    }

    // sort according to order of execution
    sort(pro, pro + n, cmp_order);

    // calc TAT
    int ct = 0;
    for (int i = 0; i < n; i++)
    {
        if (pro[i].at > ct)
            ct = pro[i].at + pro[i].bt;
        else
            ct += pro[i].bt;

        pro[i].tat = ct - pro[i].at;
    }

    // calc WT
    for (int i = 0; i < n; i++)
        pro[i].wt = pro[i].tat - pro[i].bt;

    // calc awt, atat
    for (int i = 0; i < n; i++)
        awt += pro[i].wt, atat += pro[i].tat;

    // sort according to the process id
    sort(pro, pro + n, cmp);

    // table
    cout << "Pro no\tAT\tWT\tTAT" << endl;
    for (int i = 0; i < n; i++)
        cout << pro[i].id << "\t" << pro[i].at << "\t" << pro[i].wt << "\t" << pro[i].tat << endl;

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
The testcase that does not start at 0
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
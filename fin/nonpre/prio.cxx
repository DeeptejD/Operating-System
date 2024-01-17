#include <bits/stdc++.h>
#define N 30
using namespace std;

enum state
{
    na,
    a,
    c
};

struct p
{
    int at, bt, wt, tat, id, prio, order;
    state flag;
};

bool cmp(p a, p b)
{
    return a.at < b.at;
}

bool cmp_order(p a, p b)
{
    return a.order < b.order;
}

int remTime = 0, currentTime = 0, go = 1;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    struct p pro[N];
    for (int i = 0; i < n; i++)
    {
        cin >> pro[i].at >> pro[i].bt >> pro[i].prio;
        pro[i].wt = pro[i].tat = pro[i].order = -1;
        pro[i].flag = na;
        remTime += pro[i].bt;
    }

    sort(pro, pro + n, cmp);

    while (remTime)
    {
        for (int i = 0; i < n; i++)
        {
            if (pro[i].flag == na && pro[i].at <= currentTime)
                pro[i].flag = a;
        }

        int index = -1, highest_prio = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (pro[i].flag == a && pro[i].prio < highest_prio)
                index = i, highest_prio = pro[i].prio;
        }

        if (index == -1)
        {
            currentTime++;
            continue;
        }
        pro[index].order = go++;
        pro[index].flag = c;
        remTime -= pro[index].bt;
        currentTime += pro[index].bt;
    }

    sort(pro, pro + n, cmp_order);

    // calc TAT
    for (int i = 0; i < n; i++)
    {
        int ct = 0;
        ct += pro[i].at;
        for (int j = 0; j < i; j++)
            ct += pro[j].bt;
        ct += pro[i].bt;
        pro[i].tat = ct - pro[i].at;
    }

    // calc wt
    for (int i = 0; i < n; i++)
        pro[i].wt = pro[i].tat - pro[i].bt;

    return 0;
}

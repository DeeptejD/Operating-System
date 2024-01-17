#include <bits/stdc++.h>
#define pending 1
#define done 2
using namespace std;

class processes
{
private:
    int bt, at, rt, priority, id, wt, tat, status;

public:
    void ip(int);
    void prio(int, processes[]);
    int getmin(int, processes[]);
};

int processes::getmin(int n, processes p[])
{
    int min = INT_MAX;
    for (int i = 0; i < n; i++)
        if (p[i].at < min)
            min = p[i].at;
    return min;
}

void processes::ip(int i)
{
    id = i;
    cin >> at >> bt >> priority;
    wt = tat = -1;
    rt = bt;
    status = pending;
}

void processes::prio(int n, processes p[])
{
    int total_time = getmin(n, p), index = 0;
    float awt = 0, atat = 0;
    cout << "\n\n"
         << total_time;
    while (true)
    {
        int max_priority = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (p[i].status == pending && p[i].at <= total_time && p[i].priority < max_priority)
            {
                index = i;
                max_priority = p[i].priority;
            }
        }
        int j, check = 0;
        // IDEA: we search for a process that is not the process at index, and check if its arrival time is equal to total_time+j, and if its priority is less than or eq to the priority of index
        // if the priority is eq then we check whose remaining time is more and accordingly choose
        for (j = 0; j < p[index].rt; j++)
        {
            for (int l = 0; l < n; j++)
            {
                if (l != index && p[l].at == total_time + j && p[l].priority <= p[index].priority)
                {
                    // now check if its equal
                    if (p[l].priority == p[index].priority)
                    {
                        if (p[l].rt - j < p[index].rt)
                        {
                            check = 1;
                            break;
                        }
                    }
                    else
                    {
                        check = 1;
                        break;
                    }
                }
            }
            if (check)
                break;
        }
        total_time += j;
        if (j == p[index].rt)
        {
            p[index].status = done;
            p[index].tat = total_time - p[index].at;
            atat += p[index].tat;
            p[index].wt = p[index].tat - p[index].bt;
            awt += p[index].wt;
        }
        else
            p[index].rt -= j;
        cout << "|   " << p[index].id;
        for (int k = 0; k < j; k++)
            cout << " ";
        cout << total_time;
        cout << "|";

        // check if all done
        bool all_done = true;
        for (int i = 0; i < n; i++)
            if (p[i].status == pending)
                all_done = false;
        if (all_done)
            break;
    }
    cout << "ATAT: " << atat / n << endl
         << "AWT: " << awt / n << endl;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    processes *p;
    p = new processes[n];
    for (int i = 0; i < n; i++)
        p[i].ip(i);
    processes x;
    x.prio(n, p);
    return 0;
}

/*
4
1 2 3
2 4 2
2 1 1
3 2 4

*/
#include <bits/stdc++.h>
#define pending 1
#define fin 2
using namespace std;

class processes
{
private:
    int at, bt, id, wt, tat, status, priority, rt;

public:
    void input(int);
    void prio(int, processes[]);
    int minimum(int, processes[]);
};

void processes::input(int i)
{
    cin >> at >> bt >> priority;
    id = i + 1;
    status = pending;
    rt = bt;
}

void processes::prio(int n, processes p[])
{
    int total_time = minimum(n, p);
    int index = 0;

    float awt = 0, atat = 0;

    cout << "\n\n"
         << total_time;

    while (true)
    {
        int max_prio = INT_MAX; // we need to select the numerically smallest priority since its priority scheduling
        // find among all the processes the one with numerically min prio
        for (int i = 0; i < n; i++)
        {
            if (p[i].status == pending && p[i].priority < max_prio && p[i].at <= total_time)
                index = i, max_prio = p[i].priority;
        }

        int j, check = 0;
        // during the remaining time of the process check if another process with numerically lesser priority comes
        for (j = 0; j < p[index].rt; j++)
        {
            for (int l = 0; l < n; l++)
            {
                if (l != index)
                {
                    if (p[l].at == total_time + j && p[index].priority >= p[l].priority) // TAKE CARE: HERE WE SEE IF THE PRIORITY IS EQUAL ALSO, UNLIKE SRTN
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
            p[index].status = fin;
            p[index].tat = total_time - p[index].at;
            atat += p[index].tat;
            p[index].wt = p[index].tat - p[index].bt;
            awt += p[index].wt;
        }
        else
        {
            p[index].rt -= j;
        }

        // print gantt
        cout << "|  " << p[index].id;
        for (int x = 0; x < j; x++)
            cout << " ";

        // check if all done
        bool done = true;
        for (int i = 0; i < n; i++)
            if (p[i].status == pending)
                done = false;
        if (done)
            break;
    }
    cout << "awt: " << awt << endl
         << "atat: " << atat << endl;
}

int processes::minimum(int n, processes p[])
{
    int min = INT_MAX;
    for (int i = 0; i < n; i++)
        if (p[i].at < min)
            min = p[i].at;
    return min;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    processes *p;
    p = new processes[n];
    for (int i = 0; i < n; i++)
        p[i].input(i);
    processes x;
    x.prio(n, p);
    return 0;
}

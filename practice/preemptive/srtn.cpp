#include <bits/stdc++.h>
#define pending 1
#define done 2

using namespace std;

class processes
{
private:
    int bt, at, wt, tat, rt, status, id;

public:
    void input(int);
    void srtn(int, processes[]);
    int minimum(int, processes[]);
};

void processes::input(int i)
{
    cin >> at >> bt;
    wt = tat = -1;
    status = pending;
    rt = bt;
    id = i + 1;
};

void processes::srtn(int n, processes p[])
{
    // get the total time
    int index = 0, total_time = minimum(n, p);
    float awt = 0, atat = 0;
    cout << endl
         << endl
         << total_time; // this prints it in the beginning
    while (1)
    {
        int rt = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (p[i].status == pending && p[i].at <= total_time && p[i].rt < rt)
                rt = p[i].rt, index = i;
        }
        int check = 0, j;
        for (j = 0; j < p[index].rt; j++)
        {
            for (int l = 0; l < n; l++)
            {
                if (l != index && p[l].at == total_time + j && p[l].rt < p[index].rt - j)
                {
                    check = 1;
                    break;
                }
            }
            if (check)
                break;
        }
        total_time += j;
        if (j == p[index].rt)
        {
            // complete it
            p[index].status = done;
            p[index].tat = total_time - p[index].at;
            atat += p[index].tat;
            p[index].wt = p[index].tat - p[index].bt;
            awt += p[index].wt;
        }
        else
            p[index].rt -= j;

        // GANTT
        cout << "|  ";
        cout << "p" << p[index].id;
        for (int i = 0; i < j; i++)
            cout << " ";
        cout << total_time;

        // check if all_done
        bool all_done = true;
        for (int i = 0; i < n; i++)
            if (p[i].status != done)
                all_done = false;
        if (all_done)
            break;
    }
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
    x.srtn(n, p);
    return 0;
}

/*
5
2 3
0 5
4 4
2 2
1 3

*/
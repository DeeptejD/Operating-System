#include <bits/stdc++.h>
#define pending 1
#define fin 2

using namespace std;

class processes
{
private:
    int id, bt, at, wt, tat, rt, status; // rt is remaining time since its shortest remaining time next
public:
    void input(int);
    void srtn(int, processes[]);
    int minimum(int, processes[]);
};

void processes::input(int i)
{
    id = i + 1;
    cin >> at >> bt;
    status = pending;
    rt = bt;
}

void processes::srtn(int n, processes p[])
{
    int total_time = minimum(n, p);
    int index = 0;

    float awt = 0, atat = 0;

    cout << "\n\n"
         << total_time;

    while (true)
    {
        int RT = INT_MAX; // since its shortest remaining time so we keep rt

        // find shortest remaining time that has arrived
        for (int i = 0; i < n; i++)
        {
            if (p[i].status == pending && p[i].rt < RT && p[i].at <= total_time)
                index = i, RT = p[i].rt;
        }

        // during the current processes remaining time see if another process with a shorter remaining time arrives
        int j, check = 0;
        for (j = 0; j < p[index].rt; j++)
        {
            // check among all the processes
            for (int l = 0; l < n; l++)
            {
                if (l != index)
                {
                    if (p[l].at == total_time + j && p[l].rt < p[index].rt - j)
                    {
                        check = 1;
                        break;
                    }
                }
            }
            if (check)
                break;
        }

        // update total_time
        total_time += j;

        // check if we executed the entire process at index
        if (j == p[index].rt)
        {
            // if its completed
            p[index].status = fin;
            p[index].tat = total_time - p[index].at;
            atat += p[index].tat;
            p[index].wt = p[index].tat - p[index].bt;
            awt += p[index].wt;
        }
        else
        {
            // if its not completed
            p[index].rt -= j;
        }

        // print gantt
        cout << "|   " << p[index].id;
        for (int i = 0; i < j; i++)
            cout << " ";
        cout << total_time;

        // check if all processes are over
        bool over = true;
        for (int i = 0; i < n; i++)
            if (p[i].status == pending)
                over = false;

        if (over)
            break;
    }

    cout << "|\n";
    cout << "ATAT: " << atat << endl
         << "AWT: " << awt << endl;
}

int processes::minimum(int n, processes p[])
{
    int minat = INT_MAX;
    for (int i = 0; i < n; i++)
        if (p[i].at < minat)
            minat = p[i].at;
    return minat;
}

int main(int argc, char const *argv[])
{

    // step 1: input processes
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

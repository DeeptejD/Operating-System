#include <bits/stdc++.h>

#define pending 1
#define finished 2

using namespace std;

class sequencing
{
    int burst_time, AT, WT, TAT, remaining_time, status;

public:
    void input(int);
    void FCFS(int, sequencing[]);
    void output(int);
    int minimum(int, sequencing[]);
};

void sequencing::input(int i)
{
    cin >> burst_time, cin >> AT;
    status = pending;
    remaining_time = burst_time;
}
void sequencing::output(int i)
{
    cout << "P[" << i + 1 << "] \t" << burst_time << "\t\t" << AT
         << " \t" << WT << "\t\t" << TAT << endl;
}
void sequencing::FCFS(int n, sequencing p[])
{
    int total_time = minimum(n, p), k = 0;
    float avgWT = 0, avgTAT = 0;
    cout << "Gantt Chart: " << total_time;
    while (true)
    {
        int rt = 9999;
        for (int j = 0; j < n; j++)
        {
            if (p[j].status == pending && p[j].remaining_time < rt &&
                p[j].AT <= total_time)
            {
                k = j;
                rt = p[j].remaining_time;
            }
        }
        int j, check = 0;
        for (j = 0; j < p[k].remaining_time; j++)
        {
            for (int l = 0; l < n; l++)
            {
                if (l != k)
                {
                    if (p[l].AT == total_time + j)
                    {
                        if (p[l].remaining_time < (p[k].remaining_time - j))
                        {
                            check = 1;
                            break;
                        }
                    }
                }
            }
            if (check)
                break;
        }
        total_time += j;
        if (j == p[k].remaining_time)
        {
            p[k].status = finished;
p[k].TAT = total_time - p[k].AT;
            avgTAT += p[k].TAT;
            p[k].WT = p[k].TAT - p[k].burst_time;
            avgWT += p[k].WT;
        }
        else
        {
            p[k].remaining_time -= j;
        }
        cout << "|_ P[" << k + 1 << "] _|" << total_time;
        int if_finished = 0;
        for (int i = 0; i < n; i++)
            if (p[i].status == pending)
                if_finished = 1;
        if (!if_finished)
            break;
    }
    cout << "|";
    cout << "\nAvg WT: " << avgWT / n;
    cout << "\nAvg TAT: " << avgTAT / n << endl;
}

int sequencing::minimum(int n, sequencing p[])
{
    int min = 9999;
    for (int i = 0; i < n; i++)
        if (p[i].AT < min)
            min = p[i].AT;
    return min;
}

int main()
{
    int n;
    cout << "Number of processes: ";
    cin >> n;
    sequencing *p;
    p = new sequencing[n];
    for (int i = 0; i < n; i++)
        p[i].input(i);
    sequencing x;
    x.FCFS(n, p);
    cout << "\nProcess (BT AT WT TAT):\n";
    for (int i = 0; i < n; i++)
        p[i].output(i);
    return 0;
}

/*
Test case

4
10 0
5 1
2 3
5 4

*/
// EXP 4c : round robin scheduling algorithm
#include <iostream>

using namespace std;

class processes
{
public:
    char name;
    int BT;
    int AT;
    int WT;
    int TAT;
    int RT;
    int status;

    void input(int);
    void round_robin(int, processes[]);
    void output(int);
    int minimum(int, processes[]);
};

#define max 200
int q[max];
int front = -1;
int rear = -1;
int isempty();
int isfull();
int del();
void ins(int);
#define pending 1
#define finished 2
#define queued 3

void processes::input(int i)
{
    cout << "\n--Process " << i + 1 << "--" << endl;
    cout << "Name : ";
    cin >> name;
    cout << "Burst time : ";
    cin >> BT;
    cout << "Arrival time : ";
    cin >> AT;
    status = pending;
    RT = BT;
}

void processes::output(int i)
{
    cout << name << "\t\t" << BT << "\t\t" << AT << " \t\t" << WT << "\t\t" << TAT << endl;
}

void processes::round_robin(int n, processes p[])
{
    int total_time = minimum(n, p), k, Time_slice;
    cout << "\nEnter time slice: ";
    cin >> Time_slice;
    for (int i = 0; i < n; i++)
    {
        if (p[i].AT == total_time)
        {
            p[i].status = queued;
            ins(i);
        }
    }
    float avg_WT = 0;
    float avg_TAT = 0;
    cout << "\n\n"
         << total_time;
    while (true)
    {
        int j;
        k = del();
        int time;
        time = (p[k].RT <= Time_slice ? p[k].RT : Time_slice);
        for (j = 0; j < time; j++)
        {
            for (int l = 0; l < n; l++)
            {
                if (l != k)
                {
                    if (p[l].status == pending)
                    {
                        if (p[l].AT == total_time + j)
                        {
                            ins(l);
                            p[l].status = queued;
                        }
                    }
                }
            }
        }
        total_time += time;
        p[k].RT -= time;
        if (p[k].RT == 0)
        {
            p[k].status = finished;
            p[k].TAT = total_time - p[k].AT;
            avg_TAT += p[k].TAT;
            p[k].WT = p[k].TAT - p[k].BT;
            avg_WT += p[k].WT;
        }
        else
        {
            ins(k);
            p[k].status = queued;
        }
        for (int i = 0; i < n; i++)
        {
            if (p[i].status == pending)
                if (p[i].AT == total_time)
                {
                    ins(i);
                    p[i].status = queued;
                }
        }

        cout << "|--" << p[k].name << "--|" << total_time;
        int if_finished = 0;
        for (int i = 0; i < n; i++)
            if (p[i].status == pending || p[i].status == queued)
                if_finished = 1;
        if (!if_finished)
        {
            break;
        }
    }
    cout << "\n\nAverage Waiting Time: " << avg_WT / n << endl;
    cout << "Average Turnaround Time: " << avg_TAT / n << endl;
}

int processes::minimum(int n, processes p[])
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
    cout << "Enter number of processes : ";
    cin >> n;
    processes p[n];
    for (int i = 0; i < n; i++)
    {
        p[i].input(i);
    }
    p[0].round_robin(n, p);

    cout << "\n\nName\t\tBT\t\tAT\t\tWT\t\tTAT" << endl;

    for (int i = 0; i < n; i++)
    {
        p[i].output(i);
    }
    return 0;
}

int isempty()
{
    if (front == -1)
        return 1;
    else
        return 0;
}

int isfull()
{
    if (front == (rear + 1) % max)
        return 1;
    else
        return 0;
}

void ins(int a)
{
    if (!isfull())
    {
        q[++rear] = a;
        if (front == -1)
            front = 0;
        if (rear == max)
            rear = 0;
    }
    else
    {
        printf("Ready queue is full...\n");
    }
}

int del()
{
    if (!isempty())
    {
        int x;
        x = front;
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;
        }
        return q[x];
    }
    return -1;
}
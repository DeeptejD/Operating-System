// Bankers algo
#include <bits/stdc++.h>
#define N 30
using namespace std;

void printss(int ss[], int n)
{
    for (int i = 0; i < n; i++)
        cout << ss[i] << " ";
    cout << endl;
}

bool isSafe(int av[], int m, int n, int all[][N], int need[][N], int ss[])
{
    bool fin[N];
    // init false
    for (int i = 0; i < n; i++)
        fin[i] = false, ss[i] = 0;

    // init work
    int work[N];
    for (int i = 0; i < m; i++)
        work[i] = av[i];

    // find an index i such that its fin is false and need is less than work
    int count = 0;    // keeps a track of the ss
    while (count < n) // while safe sequence is not full
    {
        bool found = false;
        for (int i = 0; i < n; i++)
        {
            // check if its fin is false
            if (fin[i] == false)
            {
                // check if tis need is less than work
                int j;
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > work[j])
                        break;
                }
                if (j == m) // means need is less than work
                {
                    // releast its allocated resources into work
                    for (int k = 0; k < m; k++)
                        work[k] += all[i][k];
                    ss[count++] = i;
                    fin[i] = true;
                    found = true;
                }
            }
        }
        if (!found)
        {
            cout << "Not in safe state\n";
            return false;
        }
    }
    cout << "In safe state\n";
    return true;
}

// resource request algo
// i is the index of the resource that is requesting for the resource
// request is the request vector of size m, which basically contains the number of instances of resources requested

bool rr(int i, int m, int n, int ss[], int av[], int need[][N], int req[], int all[][N])
{
    bool tempsafe = true; // temporary safe state

    for (int j = 0; j < m; j++)
    {
        // step1: check if the request is greater than the need
        if (req[j] > need[i][j])
        {
            tempsafe = false;
            break;
        }

        // step2: check if the request is greater than available
        if (req[i] > av[i])
        {
            tempsafe = false;
            break;
        }
    }

    // we continue only if tempsafe is true
    if (tempsafe)
    {
        // pretend to allocate the resources
        for (int j = 0; j < m; j++)
        {
            all[i][j] += req[j];
            av[j] -= req[j];
            need[i][j] -= req[j];
        }

        // check if its still in safe state
        tempsafe = isSafe(av, m, n, all, need, ss);

        if (!tempsafe)
        {
            // revert back to the prev snapshot
            for (int j = 0; j < m; j++)
            {
                all[i][j] -= req[j];
                need[i][j] += req[j];
                av[j] += req[j];
            }
        }
    }

    return tempsafe;
}

int main(int argc, char const *argv[])
{
    int m, n, need[N][N], ss[N], av[N], max[N][N], all[N][N];
    cin >> n >> m;

    // available
    for (int i = 0; i < m; i++)
        cin >> av[i];

    // maxm
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> max[i][j];
        }
    }

    // allocation
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> all[i][j];
        }
    }

    // need
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - all[i][j];

    // check whether system is in safe state and get the safety sequence
    if (isSafe(av, m, n, all, need, ss))
        printss(ss, n);

    int choice, requesting_process, request[N];
    while (1)
    {
        cout << "Enter choice\n1. Enter request for a new process\n2. Exit\n", cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Which Process?\n", cin >> requesting_process;
            for (int i = 0; i < m; i++)
                cout << "R" << i << ": ", cin >> request[i];
            if (rr(requesting_process, m, n, ss, av, need, request, all))
                cout << "The request has been granted successfully Leaving the system in a Safe State\nSafe Sequence: ", printss(ss, n);
            else
                cout << "The request cannot be granted. The Process needs to wait for the resources to free up!\n";
            break;

        case 2:
            exit(EXIT_SUCCESS);

        default:
            cout << "Invalid choice\n";
            break;
        }
    }

    return 0;
}

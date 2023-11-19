// Bankers Algorithm
#include <bits/stdc++.h>
using namespace std;
#define N 30

// Safety algo begins here
bool isSafe(int available[], int n, int m, int allocation[][N], int need[][N], int safeSeq[])
{
    // Mark all processes as unfinished
    bool fin[N];
    for (int i = 0; i < n; i++)
        fin[i] = false, safeSeq[i] = 0;
    // Initializing work equal to available
    int work[N];
    for (int i = 0; i < m; i++)
        work[i] = available[i];
    // Find an index i such that the process is not finished and needs less than or equal to work
    int count = 0;
    while (count < n)
    {
        bool found = false;
        for (int i = 0; i < n; i++)
        {
            if (!fin[i])
            {
                int j;
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > work[j])
                        break;
                }
                if (j == m)
                {
                    for (int k = 0; k < m; k++)
                        work[k] += allocation[i][k];
                    safeSeq[count++] = i;
                    fin[i] = true;
                    found = true;
                }
            }
        }
        // If no process is found, the system is not in a safe state
        if (!found)
        {
            cout << "The system is not in a safe state\n";
            return false;
        }
    }
    // If all processes are finished, the system is in a safe state
    cout << "The system is in a safe state\n";
    return true;
}

// resource request algo begins here
// here i is the process number
// request is the request vector
bool resourceRequest(int i, int m, int n, int request[], int need[][N], int safeSeq[], int available[], int allocation[][N])
{
    // request vector has a size m
    // reqi[j]=k means process i wants k instances of resource j
    bool tempSafe = true; // Initialize a flag for temporary safety

    for (int j = 0; j < m; j++)
    {
        // if request is greater than need, return false
        if (request[j] > need[i][j])
        {
            tempSafe = false;
            break;
        }

        // if request is greater than available, return false
        if (request[j] > available[j])
        {
            tempSafe = false;
            break;
        }
    }

    if (tempSafe)
    {
        // pretend to allocate the resources
        for (int j = 0; j < m; j++)
        {
            available[j] -= request[j];
            allocation[i][j] += request[j];
            need[i][j] -= request[j];
        }

        // check if the temp state is safe
        tempSafe = isSafe(available, n, m, allocation, need, safeSeq);

        // revert back to original state if not safe
        if (!tempSafe)
        {
            for (int x = 0; x < m; x++)
            {
                available[x] += request[x];
                allocation[i][x] -= request[x];
                need[i][x] += request[x];
            }
        }
    }

    return tempSafe;
}

// Utility Functions
void printMat(int x, int y, int mat[][N])
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void printDetails(int n, int m, int allocation[][N], int maxm[][N], int need[][N], int available[])
{
    cout << "Allocation\n";
    printMat(n, m, allocation);

    cout << "Max\n";
    printMat(n, m, maxm);

    cout << "Need\n";
    printMat(n, m, need);

    cout << "Available\n";
    for (int i = 0; i < m; i++)
        cout << available[i] << " ";

    cout << endl;
}

// print safe sequence
void printSafeSeq(int safeSeq[], int n)
{
    for (int i = 0; i < n; i++)
        cout << safeSeq[i] << (i == n - 1 ? "\n" : " -> ");
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int need[N][N], safeSeq[N];
    // int n = 5, m = 3;
    // int available[] = {3, 3, 2};
    // int maxm[][N] = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}};
    // int allocation[][N] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}};

    int m, n, available[N], maxm[N][N], allocation[N][N];
    cout << "Enter the number of processes: ", cin >> n;
    cout << "Enter the number of resources: ", cin >> m;
    cout << "How many instances of each resource are available?\n";
    for (int i = 0; i < m; i++)
        cout << "R" << i << ": ", cin >> available[i];

    cout << "Enter the maximum resources required for each process\n";
    for (int i = 0; i < n; i++)
    {
        cout << "P" << i << ": ";
        for (int j = 0; j < m; j++)
            cin >> maxm[i][j];
    }

    cout<<"Enter the number of resources allocated to each process\n";
    for (int i = 0; i < n; i++)
    {
        cout << "P" << i << ": ";
        for (int j = 0; j < m; j++)
            cin >> allocation[i][j];
    }


    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = maxm[i][j] - allocation[i][j];

    printDetails(n, m, allocation, maxm, need, available);

    if (isSafe(available, n, m, allocation, need, safeSeq))
    {
        cout << "The safe sequence is: ";
        printSafeSeq(safeSeq, n);
    }

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
            if (resourceRequest(requesting_process, m, n, request, need, safeSeq, available, allocation))
                cout << "The request has been granted successfully Leaving the system in a Safe State\nSafe Sequence: ", printSafeSeq(safeSeq, n), printDetails(n, m, allocation, maxm, need, available);
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

/*
Test Case:
3
3
3 3 2
7 5 3
3 2 2
9 0 2
0 1 0
2 0 0
3 0 2
*/

/*
Assignment 3 Test Case
3
3
7 7 10
3 6 8
4 3 3
3 4 4
2 2 3
2 0 3
1 2 4

*/

/*
Assignment 3 Test Case-2
4
3
1 0 0
5 2 0
1 0 0
2 1 2
1 2 1
2 1 0
1 0 0
0 1 2
1 1 1

*/
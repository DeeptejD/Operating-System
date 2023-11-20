// FCFS

#include <bits/stdc++.h>
#define N 50

using namespace std;

int FCFS(int headPosition, int totalRequests, int requests[])
{
    int seekTime = 0, currentPosition = headPosition;
    cout<<"[H: "<<currentPosition<<"]->";

    for (int i = 0; i < totalRequests; i++)
        seekTime += abs(currentPosition - requests[i]), currentPosition = requests[i], i==totalRequests-1?cout<<currentPosition:cout<<currentPosition<<"->";

    return seekTime;
}

int main(int argc, char const *argv[])
{
    int totalRequests, headPosition, requests[N];
    cout << "Enter the number of requests: ", cin >> totalRequests;
    cout << "Enter the head position: ", cin >> headPosition;
    for (int i = 0; i < totalRequests; i++)
        cin >> requests[i];

    cout<<"\nSeek Sequence: ";
    cout << "\nTotal Seek Time: " << FCFS(headPosition, totalRequests, requests)<<endl<<endl;

    return 0;
}

/*
TestCase
8
50
176
79
34
60
92
11
31
114

*/

#include <bits/stdc++.h>
#define N 50

using namespace std;

// left = true
// right = false

int CSCAN(int headPosition, int totalRequests, int requests[], bool direction)
{
    int seekTime = 0, currentPosition = headPosition;

    sort(requests, requests + totalRequests);

    // find the index of head position
    int i = 0;
    while (requests[i] < headPosition)
        i++;

    cout << "[H: " << headPosition << "] -> ";

    // check which is the shortest seek time and move to it
    int left = direction ? i - 1 : 0;
    int right = direction ? totalRequests : i;

    while (direction ? left >= 0 : right < totalRequests)
    {
        if (direction)
            seekTime += abs(currentPosition - requests[left]), cout << "(Distance: " << abs(currentPosition - requests[left]), currentPosition = requests[left], cout <<", " << currentPosition << ")" << " -> ", left--;
        else
            seekTime += abs(currentPosition - requests[right]), cout << "(Distance: " << abs(currentPosition - requests[right]), currentPosition = requests[right], cout <<", " << currentPosition << ")" << " -> ", right++;
    }

    // if there are no more requests on the left side, move to the right side
    while (direction ? requests[right] > headPosition : requests[left] < headPosition)
    {
        if (direction)
            seekTime += abs(currentPosition - requests[right]), cout << "(Distance: " << abs(currentPosition - requests[right]), currentPosition = requests[right], cout <<", " << currentPosition << ")" << " -> ", right--;
        else
            seekTime += abs(currentPosition - requests[left]), cout << "(Distance: " << abs(currentPosition - requests[left]), currentPosition = requests[left], cout <<", " << currentPosition << ")" << " -> ", left++;
    }

    return seekTime;
}

int main()
{
    int totalRequests, headPosition, requests[N], cylinders;
    cout << "Enter the number of requests: ", cin >> totalRequests;
    totalRequests += 1;
    cout << "Enter the head position: ", cin >> headPosition;
    cout << "Enter the number of cylinders: ", cin >> cylinders;
    cout << "Enter the direction\n0 - Increasing disk number\n1 - Decreasing Disk number\n";
    bool direction;
    cin >> direction;
    requests[0] = 0;
    for (int i = 1; i < totalRequests; i++)
        cin >> requests[i];
    requests[totalRequests] = cylinders - 1;
    cout << "\nTotal Seek Time: " << CSCAN(headPosition, totalRequests, requests, direction);

    return 0;
}

/*
10
100
200
1
27
129
110
160
186
147
41
10
64
120

*/
// SSTF

#include <bits/stdc++.h>
#define N 50

using namespace std;

int SSTF(int headPosition, int totalRequests, int requests[])
{
    int seekTime = 0, currentPosition = headPosition;

    sort(requests, requests + totalRequests);
    // find the index of head position
    int i = 0;
    while (requests[i] < headPosition)
        i++;

    cout << "[H: " << headPosition << "]->";

    // check which is the shortest seek time and move to it
    int left = i - 1, right = i;
    while (left >= 0 && right < totalRequests)
    {
        if (abs(currentPosition - requests[left]) < abs(currentPosition - requests[right]))
            seekTime += abs(currentPosition - requests[left]), cout << "(Distance: " << abs(currentPosition - requests[left]), currentPosition = requests[left], cout <<", " << currentPosition << ")" << " -> ", left--;
        else
            seekTime += abs(currentPosition - requests[right]), cout << "(Distance: " << abs(currentPosition - requests[right]), currentPosition = requests[right], cout <<", " << currentPosition << ")" << " -> ", right++;
    }

    // if there are no more requests on the left side, move to the right side
    while (left >= 0)
        seekTime += abs(currentPosition - requests[left]), cout << "(Distance: " << abs(currentPosition - requests[left]), currentPosition = requests[left], cout <<", " << currentPosition << ")" << " -> ", left--;

    // if there are no more requests on the right side, move to the left side
    while (right < totalRequests)
        seekTime += abs(currentPosition - requests[right]), cout << "(Distance: " << abs(currentPosition - requests[right]), currentPosition = requests[right], cout <<", " << currentPosition << ")" << " -> ", right++;

    return seekTime;
}

int main(int argc, char const *argv[])
{
    int totalRequests, headPosition, requests[N];
    cout << "Enter the number of requests: ", cin >> totalRequests;
    cout << "Enter the head position: ", cin >> headPosition;
    for (int i = 0; i < totalRequests; i++)
        cin >> requests[i];

    cout << "\nTotal Seek Time: " << SSTF(headPosition, totalRequests, requests);

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

/*
Assignment Test Case
10
100
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
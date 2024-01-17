#include <bits/stdc++.h>
#define N 50

using namespace std;

// left = true
// right = false

int CLOOK(int headPosition, int totalRequests, int requests[], bool direction)
{
    int seekTime = 0, currentPosition = headPosition;

    sort(requests, requests + totalRequests);

    // find the index of head position
    int i = 0;
    while (requests[i] < headPosition)
        i++;

    cout << "[H: " << headPosition << "]->";

    // check which is the shortest seek time and move to it
    int left = direction ? i - 1 : 0;
    int right = direction ? totalRequests - 1 : i;

    while (direction ? left >= 0 : right < totalRequests)
    {
        if (direction)
            seekTime += abs(currentPosition - requests[left]), cout << "(Distance: " << abs(currentPosition - requests[left]), currentPosition = requests[left], cout << ", " << currentPosition << ")"
                                                                                                                                                                      << " -> ",
                                                                                                                               left--;
        else
            seekTime += abs(currentPosition - requests[right]), cout << "(Distance: " << abs(currentPosition - requests[right]), currentPosition = requests[right], cout << ", " << currentPosition << ")"
                                                                                                                                                                         << " -> ",
                                                                                                                                 right++;
    }

    // if there are no more requests on the left side, move to the right side
    while (direction ? requests[right] > headPosition : requests[left] < headPosition)
    {
        if (direction)
            seekTime += abs(currentPosition - requests[right]), cout << "(Distance: " << abs(currentPosition - requests[right]), currentPosition = requests[right], cout << ", " << currentPosition << ")"
                                                                                                                                                                         << " -> ",
                                                                                                                                 right--;
        else
            seekTime += abs(currentPosition - requests[left]), cout << "(Distance: " << abs(currentPosition - requests[left]), currentPosition = requests[left], cout << ", " << currentPosition << ")"
                                                                                                                                                                      << " -> ",
                                                                                                                               left++;
    }

    return seekTime;
}

int main(int argc, char const *argv[])
{
    int totalRequests, headPosition, requests[N];
    cout << "Enter the number of requests: ", cin >> totalRequests;
    cout << "Enter the head position: ", cin >> headPosition;
    cout << "Enter the direction\n0 - Decreasing disk number\n1 - Increasing Disk number\n";
    bool direction;
    cin >> direction;
    for (int i = 0; i < totalRequests; i++)
        cin >> requests[i];

    cout << "\nTotal Seek Time: " << CLOOK(headPosition, totalRequests, requests, direction);

    return 0;
}

/*
10
100
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

/*
KEY POINTS THAT MAKE THIS DIFF FROM CSCAN
1) we dont add input in the first and last
2) no need to take number of cylinders as the input
3) when setting right according to direction, set it to n-1 and not n since we aremt starting from the extreme right
*/
#include <bits/stdc++.h>
using namespace std;

void optimal(int n, int r[], int frames)
{
    int pf = 0;
    vector<int> frame;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        flag = false;
        // check if the frame is alreadt present
        for (int j = 0; j < frame.size(); j++)
        {
            if (frame[j] == r[i])
            {
                flag = true;
                break;
            }
        }
        if (flag == false)
        {
            if (frame.size() < frames)
            {
                frame.push_back(r[i]);
                pf++;
            }
            else
            {
                // find the page that will not be used for the longest time
                int max = INT_MIN, index = -1;
                for (int j = 0; j < frame.size(); j++)
                {
                    int k;
                    for (k = i + 1; k < n; k++)
                    {
                        if (frame[j] == r[k])
                        {
                            if (k > max)
                            {
                                max = k;
                                index = j;
                            }
                            break;
                        }
                    }
                    if (k == n)
                    {
                        index = j;
                        break;
                    }
                }
                frame[index] = r[i];
                pf++;
            }
            for (int j = 0; j < frame.size(); j++)
            {
                cout << frame[j] << " ";
            }
            cout << endl;
        }
    }
    cout << "Number of page faults using OPTIMAL: " << pf << endl;
}

int main(int argc, char const *argv[])
{
    int n, frames;
    cin >> n >> frames;
    int r[n];
    for (int i = 0; i < n; i++)
        cin >> r[i];
    optimal(n, r, frames);
    return 0;
}

/*
21
3
4 2 3 0 3 2 1 7 5 5 1 2 0 3 0 2 0 1 7 0 7
*/
#include <bits/stdc++.h>
#define N 30
using namespace std;

void lru(int r[], int n, int frames)
{
    vector<int> frame;
    int pf = 0;
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
                frame.erase(frame.begin() + j); // remove the element from the frame
                frame.push_back(r[i]);          // push it to the end of the frame
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
                frame.erase(frame.begin());
                frame.push_back(r[i]);
                pf++;
            }
            for (int j = 0; j < frame.size(); j++)
            {
                cout << frame[j] << " ";
            }
            cout << endl;
        }
    }
    cout << "Number of page faults using LRU: " << pf << endl;
}

int main(int argc, char const *argv[])
{
    int n, frames, pf = 0;
    cin >> n >> frames;
    int r[N];
    // taking input for the reference string
    for (int i = 0; i < n; i++)
        cin >> r[i];
    lru(r, n, frames);
    return 0;
}

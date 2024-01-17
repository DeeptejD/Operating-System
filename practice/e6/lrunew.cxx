#include <bits/stdc++.h>
#define N 30
using namespace std;

// NOTE: considering the right side of the vector to be the incoming/latest element

void lru(int r[], int n, int f)
{
    vector<int> frame;
    bool flag = false;
    int pf = 0;
    for (int i = 0; i < n; i++)
    {
        // check if its in the frame
        flag = false;
        for (int j = 0; j < frame.size(); j++)
        {
            if (frame[j] == r[i])
            {
                // update its position
                frame.erase(frame.begin() + j);
                frame.push_back(r[i]);
                flag = true;
                break;
            }
        }
        if (flag == false)
        {
            // we didnt find it in the frame
            // either replace the oldest, in out case its the front of the vector, or simply pushback
            pf++;
            if (frame.size() < f)
                frame.push_back(r[i]);
            else
            {
                frame.erase(frame.begin());
                frame.push_back(r[i]);
            }
        }
        for (int j = 0; j < frame.size(); j++)
            cout << frame[j] << " ";
        cout << endl;
    }
    cout << pf << endl;
}

int main(int argc, char const *argv[])
{
    int n, f, r[N];
    cin >> n >> f;
    for (int i = 0; i < n; i++)
        cin >> r[i];
    lru(r, n, f);
    return 0;
}

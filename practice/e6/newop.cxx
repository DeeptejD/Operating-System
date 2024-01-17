#include <bits/stdc++.h>
#define N 30
using namespace std;

void op(int r[], int f, int n)
{
    vector<int> frame;
    bool flag = false; // flag is used to notify if the element is present in the frame
    int pf = 0;        // page faults
    // searching if r[i] is present in the frames
    for (int i = 0; i < n; i++)
    {
        flag = false;
        for (int j = 0; j < frame.size(); j++)
        {
            if (frame[j] == r[i])
            {
                // found
                flag = true;
                break;
            }
        }
        if (flag == false)
        {
            // we didnt find, now we need to either add it in frame or choose one to replace
            // since we are using optimal we need to find a frame that is used the furthest in the reference string
            if (frame.size() < f)
            {
                // there are vacant frame slots
                frame.push_back(r[i]);
                pf++;
            }
            else
            {
                // since not frame slots are vacant we need to find a slot thats vacant
                int max = INT_MIN, index = -1;
                for (int j = 0; j < frame.size(); j++)
                {
                    int k;
                    for (k = i + 1; k < n; k++)
                    {
                        if (frame[j] == r[k])
                        {
                            if (k > max)
                                max = k, index = j;
                            break; // we break since we found at least one instance
                        }
                    }
                    if (k == n)
                    {
                        //  this part will be triggered if we find one such element in the frame that will never occur again, so we can safely replace it in the frames
                        index = j;
                        break;
                    }
                }
                frame[index] = r[i];
                pf++;
            }
            // now we basically print the frame
            for (int j = 0; j < frame.size(); j++)
                cout << frame[j] << " ";
            cout << endl;
        }
    }
    cout << "Number of page faults are: " << pf << endl;
}

int main(int argc, char const *argv[])
{
    int n, r[N], f;
    cin >> n >> f;
    for (int i = 0; i < n; i++)
        cin >> r[i];
    op(r, f, n);
    return 0;
}

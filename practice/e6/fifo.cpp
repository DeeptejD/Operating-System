#include <bits/stdc++.h>
#define N 30
using namespace std;

// utility function
void print_frame(int frame[], int n)
{
    for (int i = 0; i < n; i++)
        frame[i] == -1 ? cout << "- " : cout << frame[i] << " ";
    cout << endl;
}

void fifo(int r[], int n, int frames)
{
    int frame[frames], pc = 0, pf = 0, k = 0;
    // init
    for (int i = 0; i < frames; i++)
        frame[i] = -1;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        flag = false;
        // check if the frame is alreadt present
        for (int j = 0; j < frames; j++)
        {
            if (frame[j] == r[i])
            {
                flag = true;
                break;
            }
        }
        if (flag == false)
        {
            //  the frame is not present so that means we have to find a way to put it into the frame
            // case 1: the frame is not full
            // case 2: the frame is full
            if (pc < frames)
            {
                frame[pc++] = r[i];
                pf++;
            }
            else
            {
                frame[k] = r[i];
                k = (k + 1) % frames;
                pf++;
            }
            print_frame(frame, frames);
        }
    }
    cout << "Number of page faults using FIFO: " << pf << endl;
}

int main(int argc, char const *argv[])
{
    int r[N], n, frames;
    cin >> n >> frames;
    for (int i = 0; i < n; i++)
        cin >> r[i];
    fifo(r, n, frames);
    return 0;
}
/*
21
3
4 2 3 0 3 2 1 7 5 5 1 2 0 3 0 2 0 1 7 0 7
*/
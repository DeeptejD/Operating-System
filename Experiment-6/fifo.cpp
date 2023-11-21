#include <bits/stdc++.h>
#define N 50

using namespace std;

void print_frame(int frame[], int n)
{
    for (int i = 0; i < n; i++)
        frame[i] == -1 ? cout << "- " : cout << frame[i] << " ";
    cout << endl;
}

void fifo(int reference_string[], int n, int frames)
{
    // idea: k is the index that we use to circularly go around the frames, frame_count is basically how many frames have been utilized
    int frame[frames], frame_count = 0, page_faults = 0, k = 0;
    // init
    for (int i = 0; i < frames; i++)
        frame[i] = -1;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        flag = false;
        // check if the page already present
        for (int j = 0; j < frames; j++)
        {
            if (frame[j] == reference_string[i])
            {
                flag = true;
                break;
            }
        }
        // if the page not present
        if (flag == false)
        {
            // check if frame isnt full
            if (frame_count < frames)
                frame[frame_count++] = reference_string[i], page_faults++;
            // if frame is full
            else
            {
                frame[k] = reference_string[i];
                k = (k + 1) % frames;
                page_faults++;
            }
            print_frame(frame, frames);
        }
    }
    cout << "Number of page faults using FIFO: " << page_faults << endl;
}

int main(int argc, char const *argv[])
{
    int reference_string[N], n, frames;
    cout << "Enter the number of elements in the reference string: ", cin >> n;
    cout << "Enter the elements of the reference string\n";
    for (int i = 0; i < n; i++)
        cin >> reference_string[i];
    cout << "Enter the number of frames: ", cin >> frames;
    fifo(reference_string, n, frames);

    return 0;
}

/*
Assignment Test Case
21
4 2 3 0 3 2 1 7 5 5 1 2 0 3 0 2 0 1 7 0 7
3

*/

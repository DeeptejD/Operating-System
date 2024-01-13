#include <bits/stdc++.h>
#define N 50

using namespace std;

void print_frame(int frame[], int n)
{
    for (int i = 0; i < n; i++)
        frame[i] == -1 ? cout << "- " : cout << frame[i] << " ";
    cout << endl;
}

void lru(int reference[], int n, int frames)
{
    int frame[frames], frame_count = 0, page_faults = 0, k = 0;

    // init
    for (int i = 0; i < frames; i++)
        frame[i] = -1;

    int ix = 0;
    for (int i = 0; i < n; i++)
    {
        // look for page
        auto tellme = find(frame, frame + frames, reference[i]);

        // if the page not present
        if (tellme == frame + frames)
        {
            page_faults++;
            if (frame[ix] == -1)
            {
                frame[ix] = reference[i];
                ix = (ix + 1) % frames;
            }
            else
            {
                map<int, int> buffer;
                for (int j = 0; j < frames; j++)
                    buffer[frame[j]] = j;

                int j = i + 1;
                while (j < n && buffer.size() > 1)
                {
                    if (buffer.find(reference[j]) != buffer.end())
                        buffer.erase(reference[j]);
                    j++;
                }

                int target = buffer.begin()->second;
                frame[target] = reference[i];
            }

            print_frame(frame, frames);
        }
    }
    cout << "Number of page faults using OPTIMAL: " << page_faults << endl;
}

int main(int argc, char const *argv[])
{
    int reference_string[N], n, frames;
    cout << "Enter the number of elements in the reference string: ", cin >> n;
    cout << "Enter the elements of the reference string\n";
    for (int i = 0; i < n; i++)
        cin >> reference_string[i];
    cout << "Enter the number of frames: ", cin >> frames;
    lru(reference_string, n, frames);

    return 0;
}

/*
Assignment Test Case
21
4 2 3 0 3 2 1 7 5 5 1 2 0 3 0 2 0 1 7 0 7
3
*/

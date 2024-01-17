#include <bits/stdc++.h>
using namespace std;

struct p
{
    int at, bt, wt, tat, p_no, ct;
};

bool cmp(p a, p b) { return (a.at < b.at); }
bool cmp_id(p a, p b) { return (a.p_no < b.p_no); }

bool cmp(p a, p b)
{
    return a.at < b.at;
}

bool cmp_id(p a, p b)
{
    return a.p_no < b.p_no;
}

int main(int argc, char const *argv[])
{
    int n, ts;
    cin >> n >> ts;

    // dummy is just a copy
    vector<struct p> pro, dummy;
    map<int, int> ct; // completion time

    // simple input
    for (int i = 0; i < n; i++)
    {
        struct p temp;
        cin >> temp.at >> temp.bt;
        temp.wt = temp.tat = temp.ct = -1;
        temp.p_no = i + 1;
        pro.push_back(temp);
        dummy.push_back(temp);
    }

    // sort based on the arrival time
    sort(pro.begin(), pro.end(), cmp);

    deque<struct p> q;

    int ix = 0, time = 0, running = 0;
    // ix tells how many processes are in the queue
    // running is like a timer used to keep a track of the timeslice

    cout << "0";
    while (!q.empty() || ix < n)
    {
        // insert into queue if any
        if (ix < n)
        {
            for (int i = 0; i < n; i++)
            {
                if (pro[i].at <= time)
                {
                    q.push_back(pro[i]);
                    pro[i].at = INT_MAX;
                    ix++;
                }
            }
        }

        if (running > 0)
        {
            running--;
            struct p temp = q.front();
            q.pop_front();
            temp.bt--;
            time++;

            if (temp.bt != 0 && running != 0)
                q.push_front(temp);
            else if (temp.bt != 0 && running == 0)
                q.push_back(temp);
            else if (temp.bt == 0)
                ct[temp.p_no] = time; // storing the time at which p_no was completed in a map

            cout << " P(" << temp.p_no << ") " << time;
        }
        else
        {
            if (q.empty())
            {
                time++;
                cout << " " << time;
            }
            else
            {
                running = min(ts, q.front().bt);
            }
        }
    }

    // print table
    sort(dummy.begin(), dummy.end(), cmp_id);
    float atat = 0, awt = 0;
    cout << "\npno\tat\ttat\twt\n";
    

    return 0;
}

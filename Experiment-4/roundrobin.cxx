#include <bits/stdc++.h>
using namespace std;

struct p
{
    int at, bt, wt, tat, p_no, ct;
};

bool cmp(p a, p b) { return (a.at < b.at); }
bool cmp_id(p a, p b) { return (a.p_no < b.p_no); }

int main()
{
    int n, ts;
    cin >> n >> ts;

    // dummy is just a copy
    vector<struct p> pro, dummy;
    map<int, int> ct; // completion time

    for (int i = 0; i < n; i++)
    {
        struct p temp;
        cout << "enter bt and at\n";
        cin >> temp.bt >> temp.at;
        temp.p_no = i + 1;
        temp.ct = temp.tat = temp.wt = -1;
        pro.push_back(temp);
        dummy.push_back(temp);
    }

    sort(pro.begin(), pro.end(), cmp);

    deque<struct p> que;

    int current_start = 0, ix = 0, time = 0, running = 0;
    struct p current;

    cout << "0";
    while (!que.empty() || ix < n)
    {
        // insert into queue if any
        if (ix < n)
        {
            for (int i = 0; i < n; i++)
            {
                if (pro[i].at <= time)
                {
                    que.push_back(pro[i]);
                    pro[i].at = INT_MAX;
                    ix++;
                }
            }
        }

        if (running > 0)
        {
            running--;
            struct p temp = que.front();
            que.pop_front();
            temp.bt--;
            time++;

            if (temp.bt != 0 && running != 0)
                que.push_front(temp);
            else if (temp.bt != 0 && running == 0)
                que.push_back(temp);
            else if (temp.bt == 0)
                ct[temp.p_no] = time;

            cout << " P(" << temp.p_no << ") " << time;
        }
        else
        {
            if (que.empty())
            {
                time++;
                cout << " " << time;
            }
            else
            {
                running = min(ts, que.front().bt);
            }
        }
    }

    // print table
    sort(dummy.begin(), dummy.end(), cmp_id);
    int atat = 0, awt = 0;
    cout << "\npno\tat\ttat\twt\n";
    for (int i = 0; i < n; i++)
    {
        cout << dummy[i].p_no << "\t";
        cout << dummy[i].at << "\t";
        dummy[i].tat = ct[dummy[i].p_no] - dummy[i].at;
        cout << dummy[i].tat << "\t";
        dummy[i].wt = dummy[i].tat - dummy[i].bt;
        cout << dummy[i].wt << "\n";

        atat += dummy[i].tat;
        awt += dummy[i].wt;
    }

    cout << atat * 1.0 / n << ' ' << awt * 1.0 / n << "\n";
}

/*

5
2
2
3
2
5
4
4
2
2
1
3

*/
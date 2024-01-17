#include <bits/stdc++.h>
#define inf INT_MAX
#define N 30
using namespace std;

enum s
{
    na,
    ar,
    comp
};

struct p
{
    int at, bt, wt, tat, ct, id, order;
    s flag;
};

bool cmp(p a, p b) { return a.at < b.at; }
bool cmp_id(p a, p b) { return a.id < b.id; }

int currentTime = 0, remainingTime = 0, GO = 1;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    float atat = 0, awt = 0;
    struct p pro[N];
    for (int i = 0; i < n; i++)
    {
        cin >> pro[i].at >> pro[i].bt;
        pro[i].id = i + 1;
        remainingTime += pro[i].bt;
        pro[i].flag = na;
    }

    while (remainingTime)
    {
        // update
        for (int i = 0; i < n; i++)
        {
            if (pro[i].flag == na && pro[i].at <= currentTime)
                pro[i].flag = ar;
        }

        int index = -1, min = inf;
        for (int i = 0; i < n; i++)
            if (pro[i].flag == na && pro[i].bt < min)
                index = i, min = pro[i].bt;

        if (index != -1)
        {
            pro[index].flag = comp;
            pro[index].order = GO++;
            currentTime += pro[index].bt;
            remainingTime -= pro[index].bt;
            pro[index].ct = currentTime;

            pro[index].tat = pro[index].ct - pro[index].at;
            pro[index].wt = pro[index].tat - pro[index].bt;
            awt += pro[index].wt;
            atat += pro[index].tat;
        }
        else
            currentTime++;
    }
    cout << "ATAT: " << atat << endl
         << "AWT: " << awt << endl;

    sort(pro, pro + n, cmp_id);
    cout << "id\tat\tbt\twt\ttat\t\n";
    for (int i = 0; i < n; i++)
        cout << pro[i].id << "\t" << pro[i].at << "\t" << pro[i].bt << "\t" << pro[i].wt << "\t" << pro[i].tat << "\t" << endl;
    return 0;
}
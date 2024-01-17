#include <bits/stdc++.h>
#define N 30
using namespace std;

struct p
{
    int at, bt, wt, tat, ct, id;
};

bool cmp(p a, p b) { return a.at < b.at; }
bool cmp_id(p a, p b) { return a.id < b.id; }

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    float atat = 0, awt = 0;
    struct p pro[N];
    for (int i = 0; i < n; i++)
        cin >> pro[i].at >> pro[i].bt, pro[i].id = i + 1;

    sort(pro, pro + n, cmp);

    int current_time = 0;
    for (int i = 0; i < n; i++)
    {
        if (pro[i].at > current_time)
            current_time += pro[i].at + pro[i].bt;
        else
            current_time += pro[i].bt;
        pro[i].ct = current_time;
        pro[i].tat = pro[i].ct - pro[i].at;
        pro[i].wt = pro[i].tat - pro[i].bt;
        awt += pro[i].wt;
        atat += pro[i].tat;
    }

    cout << "ATAT: " << atat << endl
         << "AWT: " << awt << endl;

    sort(pro, pro + n, cmp_id);
    cout << "id\tat\tbt\twt\ttat\t\n";
    for (int i = 0; i < n; i++)
        cout << pro[i].id << "\t" << pro[i].at << "\t" << pro[i].bt << "\t" << pro[i].wt << "\t" << pro[i].tat << "\t" << endl;

    return 0;
}

/*
5
2 3
0 5
4 4
2 2
1 3

*/
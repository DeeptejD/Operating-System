#include <bits/stdc++.h>
#define N 30
using namespace std;

void fcfs(int r[], int n, int h)
{
    int seek = 0, current = h;
    cout << "[H: " << h << "]->";
    for (int i = 0; i < n; i++)
        seek += abs(current - r[i]), current = r[i], i == n - 1 ? cout << current : cout << current << "->";
    cout << "\nSeek time: " << seek << endl;
}

int main(int argc, char const *argv[])
{
    int n, r[N], h;
    cin >> n >> h;
    for (int i = 0; i < n; i++)
        cin >> r[i];
    fcfs(r, n, h);
    return 0;
}

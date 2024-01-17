#include <bits/stdc++.h>
#define N 30
using namespace std;

void scan(int h, int n, int r[], bool d)
{
    int seek = 0, current = h;
    sort(r, r + n);
    // get approx head
    int i = 0;
    while (r[i] < h)
        i++;
    cout << "[H: " << h << "]->";
    int left = i - 1, right = i;

    while (d ? left >= 0 : right < n)
    {
        if (d)
            seek += abs(current - r[left]), current = r[left], cout << current, left == 0 ? cout << "" : cout << "->", left--;
        else
            seek += abs(current - r[right]), current = r[right], cout << current, right == n - 1 ? cout << "" : cout << "->", right++;
    }
    // remaining
    while (d ? right < n : left >= 0)
    {
        if (d)
            seek += abs(current - r[right]), current = r[right], cout << current, right == n - 1 ? cout << "" : cout << "->", right++;
        else
            seek += abs(current - r[left]), current = r[left], cout << current, left == 0 ? cout << "" : cout << "->", left--;
    }
    cout << endl
         << "Seek: " << seek << endl;
}

// IDEA: left direction is 1, right is 0

int main(int argc, char const *argv[])
{
    int n, h, r[N], c;
    cin >> n >> h >> c; // i/p
    n++;
    bool d;
    cin >> d; // i/p
    r[0] = 0;
    for (int i = 1; i < n; i++)
        cin >> r[i];
    r[n] = c - 1;
    scan(h, n, r, d);
    return 0;
}

#include <bits/stdc++.h>
#define N 30
using namespace std;

void cscan(int n, int h, int r[], bool d)
{
    int seek = 0, current = h;
    sort(r, r + n);
    // find approx head
    int i = 0;
    while (r[i] < h)
        i++;
    cout << "[H: " << h << "]->";
    // set the left and right according to the direction
    int left = d ? i - 1 : 0;
    int right = d ? n - 1 : i;

    while (d ? left >= 0 : right < n)
    {
        if (d)
            seek += abs(current - r[left]), current = r[left], cout << current << "->", left--;
        else
            seek += abs(current - r[right]), current = r[right], cout << current << "->", right++;
    }
    // remaining
    while (d ? r[right] > h : r[left] < h)
    {
        if (d)
            seek += abs(current - r[right]), current = r[right], cout << current << "->", right--;
        else
            seek += abs(current - r[left]), current = r[left], cout << current << "->", left++;
    }
    cout << endl
         << "seek: " << seek << endl;
}

int main(int argc, char const *argv[])
{
    int n, h, r[N], c;
    cin >> n >> h;
    bool d;
    cin >> d;
    for (int i = 0; i < n; i++)
        cin >> r[i];
    cscan(n, h, r, d);
    return 0;
}

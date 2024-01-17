#include <bits/stdc++.h>
#define N 30
using namespace std;

void sstn(int r[], int n, int h)
{
    int seek = 0, current = h;
    // sort the requests
    sort(r, r + n);
    // IDEA: find the approx head posn, and keep a track of the left and right
    int i = 0;
    while (r[i] < h)
        i++;
    cout << "[H: " << h << "]->";
    int l = i - 1, right = i;
    while (l >= 0 && right < n)
    {
        if (abs(current - r[l]) < abs(current - r[right]))
            seek += abs(current - r[l]), cout << "(Distance: " << abs(current - r[l]), current = r[l], l--, cout << ", " << current << ")->";
        else
            seek += abs(current - r[right]), cout << "(Distance: " << abs(current - r[right]), current = r[right], right++, cout << ", " << current << ")->";
    }
    // pending requests
    while (l >= 0)
        seek += abs(current - r[l]), cout << "(Distance: " << abs(current - r[l]), current = r[l], l--, cout << ", " << current << ")->";

    while (right < n)
        seek += abs(current - r[right]), cout << "(Distance: " << abs(current - r[right]), current = r[right], right++, cout << ", " << current << ")->";

    cout << "\nSeek: " << seek << endl;
}

int main(int argc, char const *argv[])
{
    int n, r[N], h;
    cin >> n >> h;
    for (int i = 0; i < n; i++)
        cin >> r[i];
    sstn(r, n, h);
    return 0;
}

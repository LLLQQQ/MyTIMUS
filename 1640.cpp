#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int n, x[101], y[101];
int sq(int a, int b)
{
    return a * a + b * b;
}
int main()
{
    int i, r = 0, sx = 1001, sy = 1001, t;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
        t = sq(x[i] - sx, y[i] - sy);
        if (t > r)
        {
            r = t;
        }
    }
    cout << sx << " " << sy << " ";
    cout << setiosflags(ios::fixed) << setprecision(9) << sqrt(r) << endl;
    return 0;
}
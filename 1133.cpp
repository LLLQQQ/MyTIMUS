#include <iostream>
using namespace std;
int s, e, n, fs, fe;
int f[2003];
int main()
{
    long long i, j, k, k1, k2, t;
    cin >> s >> fs >> e >> fe >> n;
    i = s;
    if (i > e)
    {
        i = e;
    }
    if (i > n)
    {
        i = n;
    }
    if (i < 0)
    {
        s -= i;
        e -= i;
        n -= i;
    }
    f[s] = fs;
    f[e] = fe;
    if (s > e)
    {
        i = s;
        s = e;
        e = i;
    }
    if (n == s || n == e)
    {
        cout << f[n] << endl;
        return 0;
    }
    if (s + 1 != e)
    {
        t = e - s - 1;
        i = 1;
        k1 = 0;
        for (j = 0; j < t; j++)
        {
            k = k1;
            k1 += i;
            i = k;
        }
        i = 0;
        k2 = 1;
        for (j = 0; j < t; j++)
        {
            k = k2;
            k2 += i;
            i = k;
        }
        f[s + 1] = (int)(((long long)f[e] - (long long)k1 * (long long)f[s]) / (long long)k2);
    }
    if (n > s)
    {
        i = f[s];
        j = f[s + 1];
        for (k = s + 1; k < n; k++)
        {
            t = j;
            j += i;
            i = t;
        }
    }
    else
    {
        i = f[s + 1];
        j = f[s];
        for (k = n; k < s; k++)
        {
            t = j;
            j = i - j;
            i = t;
        }
    }
    cout << j << endl;
    return 0;
}
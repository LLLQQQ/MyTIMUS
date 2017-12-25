#include <iostream>
using namespace std;
int n, i, x[10001], y[10001], nob[10001], max = 100000001, two = 0, mn, m, j;
double dydx[10001];
int change(int a, int b)
{
    int t;
    double j;
    t = nob[a];
    nob[a] = nob[b];
    nob[b] = t;
    j = dydx[a];
    dydx[a] = dydx[b];
    dydx[b] = j;
    return 0;
}
int downstair(int a)
{
    int t;
    if (a * 2 + 1 <= m)
    {
        if (dydx[a * 2] < dydx[a * 2 + 1])
        {
            t = a * 2;
        }
        else
        {
            t = a * 2 + 1;
        }
        if (dydx[t] < dydx[a])
        {
            change(t, a);
            downstair(t);
        }
    }
    else if (a * 2 == m)
    {
        if (dydx[a] > dydx[a * 2])
        {
            change(a, a * 2);
        }
    }
    return 0;
}
int main()
{
    cin >> n;
    m = n;
    for (i = 1; i <= n; i++)
    {
        scanf_s("%d%d", &x[i], &y[i]);
        if (max > x[i])
        {
            max = x[i];
            mn = i;
        }
        else if (max == x[i])
        {
            two = i;
        }
        nob[i] = i;
    }
    if (x[mn] == x[two] && two != 0)
    {
        if (y[mn] < y[two])
        {
            i = two;
            two = mn;
            mn = i;
        }
        x[0] = x[mn]; //mn's
        y[0] = y[mn];
        if (two == n)
        {
            nob[mn] = n - 1;
            x[mn] = x[n - 1];
            y[mn] = y[n - 1];
        }
        else
        {
            nob[mn] = n;
            x[mn] = x[n];
            y[mn] = y[n];
            if (two != n - 1)
            {
                nob[two] = nob[n - 1];
                x[two] = x[n - 1];
                y[two] = y[n - 1];
            }
        }
        m = n - 2;
        nob[n - 1] = two;
    }
    else
    {
        x[0] = x[mn]; //mn's
        y[0] = y[mn];
        m = n - 1;
        nob[mn] = n;
        x[mn] = x[n];
        y[mn] = y[n];
    }
    for (i = 1; i <= m; i++)
    {
        dydx[i] = (double)(y[i] - y[0]) / (double)(x[i] - x[0]);
    }
    //key:dydx[] and nob[]
    if (m == 1 || m == 0)
    {
        cout << "1 2";
        return 0;
    }
    //init heap
    j = m;
    if (m % 2 == 0)
    {
        if (dydx[m] < dydx[m / 2])
        {
            change(m, m / 2);
        }
        j--;
    }
    while (j > 1)
    {
        if (dydx[j] < dydx[j - 1])
        {
            i = j;
        }
        else
        {
            i = j - 1;
        }
        if (dydx[i] < dydx[i / 2])
        {
            change(i, i / 2);
            downstair(i);
        }
        j -= 2;
    }
    while (m > n / 2)
    {
        j = nob[1];
        nob[1] = nob[m];
        nob[m] = j;
        dydx[1] = dydx[m];
        m--;
        downstair(1);
    }

    cout << mn << " " << nob[1];
    return 0;
}
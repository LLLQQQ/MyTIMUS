#include <iostream>
using namespace std;
int main()
{
    int n, m, i, taken, take[1002]; //sure:wecansure which card has already been token;take0,1,2
    cin >> n >> m;
    if (m > n)
    {
        cout << "NO";
        return 0;
    }
    for (i = 0; i <= n + 1; i++)
    {
        take[i] = 0;
    }
    while (m > 0)
    {
        m--;
        cin >> taken;
        if (take[taken] == 0)
        {
            take[taken] = 1;
            if (taken == 0)
            {
                take[0] = 2;
                for (i = 1; i <= n; i++)
                {
                    if (take[i] == 1)
                    {
                        take[i] = 2;
                    }
                    else if (take[i] == 0)
                    {
                        take[i] = 1;
                        if (i == n)
                        {
                            take[n] = 2;
                        }
                        break;
                    }
                    else
                    { //take[i]==2
                        break;
                    }
                }
            }
            else if (taken == n)
            {
                take[n] = 2;
                for (i = n - 1; i >= 0; i--)
                {
                    if (take[i] == 1)
                    {
                        take[i] = 2;
                    }
                    else if (take[i] == 0)
                    {
                        take[i] = 1;
                        if (i == 0)
                        {
                            take[0] = 2;
                        }
                        break;
                    }
                    else
                    { //take[i]==2
                        break;
                    }
                }
            }
        }
        else if (take[taken] == 1)
        {
            take[taken] = 2;
            for (i = taken + 1; i <= n; i++)
            {
                if (take[i] == 1)
                {
                    take[i] = 2;
                }
                else if (take[i] == 0)
                {
                    take[i] = 1;
                    if (i == n)
                    {
                        take[n] = 2;
                    }
                    break;
                }
                else
                { //take[i]==2
                    break;
                }
            }
            for (i = taken - 1; i >= 0; i--)
            {
                if (take[i] == 1)
                {
                    take[i] = 2;
                }
                else if (take[i] == 0)
                {
                    take[i] = 1;
                    if (i == 0)
                    {
                        take[0] = 2;
                    }
                    break;
                }
                else
                { //take[i]==2
                    break;
                }
            }
        }
        else
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
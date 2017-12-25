#include <iostream>//dfs
using namespace std;
int n, num[21], s = 0, minh = 6300, die[21];
int gid(int i)
{
    return (i + n) % n;
}
int dfs(int h, int s2)
{
    int i, j, be, af;
    if (s2 == 0)
    {
        if (h < minh)
        {
            minh = h;
        }
        return 0;
    }
    for (i = 0; i < n; i++)
    {
        if (die[i] == 1)
        {
            be = die[gid(i - 1)];
            af = die[gid(i + 1)];
            j = be * num[gid(i - 1)] + num[i] + af * num[gid(i + 1)];
            if (h + s2 - j < minh)
            {
                s2 -= j;
                h += s2;
                die[i] = 0;
                die[gid(i - 1)] = 0;
                die[gid(i + 1)] = 0;
                dfs(h, s2);
                die[i] = 1;
                die[gid(i - 1)] = be;
                die[gid(i + 1)] = af;
                h -= s2;
                s2 += j;
            }
        }
    }
    return 0;
}
int main()
{
    int i;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> num[i];
        s += num[i];
        die[i] = 1;
    }
    dfs(0, s);
    cout << minh << endl;
    return 0;
}
#include <iostream>
#include <cstdio>
using namespace std;
char tip[1100001];
char str[100001];
int length = 0;
bool isNum(char a)
{
    if (a >= '0' && a <= '9')
    {
        return true;
    }
    return false;
}
int kdigitNum(int k)
{
    if (k > 0)
    {
        k--;
        return 10 * kdigitNum(k);
    }
    return 1;
}
int getdigit(int x)
{
    if (x > 0)
    {
        x /= 10;
        return 1 + getdigit(x);
    }
    return 0;
}
int inittip()
{
    int i, j;
    j = getdigit(length);
    for (i = 1; i < kdigitNum(j) + kdigitNum(j - 1); i++)
    {
        tip[i] = '0';
    }
    return 0;
}
int getNum(int s, int k)
{
    if (k > 0)
    {
        return (str[s] - '0') * kdigitNum(k - 1) + getNum(s + 1, k - 1);
    }
    return 0;
}
int main()
{
    int i, k, min = 1234567, j;
    char tmpc;
    //cin >> tmpc;
    tmpc = getchar();
    while (tmpc != '\n' && isNum(tmpc))
    {
        str[length] = tmpc;
        length++;
        tmpc = getchar();
    }
    /*
        for (i = 0; i < length; i++)
    {
        cout << str[i];
    }
    cout << endl;
    */
    inittip();
    for (k = getdigit(length); k > 0; k--)
    {
        for (i = 0; i < length - k + 1; i++)
        {
            if (str[i] != '0')
            {
                tip[getNum(i, k)] = '1';
            }
        }
        j = kdigitNum(k - 1);
        for (i = j; i < j + kdigitNum(k); i++)
        {
            if (tip[i] == '0')
            {
                min = i;
                break;
            }
        }
        if (i == j + kdigitNum(k))
        {
            break;
        }
    }
    cout << min << endl;
    return 0;
}
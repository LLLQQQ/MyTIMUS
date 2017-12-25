#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int digit(long long i)
{
    int d = 1;
    while (i > 9)
    {
        d++;
        i /= 10;
    }
    return d;
}
string isPrime(long long x)
{
    int half = int(sqrt(x)) + 1;
    for (int i = 2; i <= half; i++)
    {
        if (x % i == 0)
        {
            return "No";
        }
    }
    return "Yes";
}
int main()
{
    long long n, i, s = 0;
    cin >> n;
    i = 2;
    while (n != 1)
    {
        if (s == 19)
        {
            cout << isPrime(n);
            return 0;
        }
        if (s == 20)
        {
            cout << "No";
            return 0;
        }
        while (n % i == 0)
        {
            n /= i;
            s++;
            if (s > 20)
            {
                cout << "No";
                return 0;
            }
        }
        i++;
        if ((digit(i) - 1) * (20 - s) > digit(n))
        { //avoid 2*89789723478923984234789243(example)
            cout << "No";
            return 0;
        }
    }
    if (s == 20)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    return 0;
}
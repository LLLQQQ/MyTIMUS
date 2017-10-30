#include <iostream>
using namespace std;
char test[103];
int main()
{
    cin >> test;
    test[2] = '\0';
    cout << test << endl;
    return 0;
}
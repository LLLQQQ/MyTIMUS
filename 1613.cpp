#include <iostream>
#include <cstdio>
using namespace std;
int arr[70001], brr[70001];
int n, heapLength;

int print()
{
    int i;
    cout << "========start===========" << endl;
    for (i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    for (i = 1; i <= n; i++)
    {
        cout << brr[i] << " ";
    }
    cout << endl;
    cout << "========end=============" << endl;
    return 0;
}

int goDown(int x)
{
    int l = 2 * x, r = 2 * x + 1, i, t;
    if (r <= heapLength)
    {
        if (arr[l] > arr[r])
        {
            i = l;
        }
        else if (arr[l] < arr[r])
        {
            i = r;
        }
        else if (brr[l] > brr[r])
        {
            i = l;
        }
        else
        {
            i = r;
        }
    }
    else if (l == heapLength)
    {
        i = l;
    }
    else
    {
        return 0;
    }
    if (arr[i] > arr[x] || (arr[i] == arr[x] && brr[i] > brr[x]))
    {
        t = arr[x];
        arr[x] = arr[i];
        arr[i] = t;
        t = brr[x];
        brr[x] = brr[i];
        brr[i] = t;
        goDown(i);
    }
    return 0;
}

int bigRoot()
{
    int i;
    for (i = heapLength / 2; i > 0; i--)
    {
        goDown(i);
    }
    return 0;
}

int heapSort()
{
    int i, t;
    bigRoot();
    for (i = heapLength; i > 0; i--)
    {
        t = arr[1];
        arr[1] = arr[heapLength];
        arr[heapLength] = t;
        t = brr[1];
        brr[1] = brr[heapLength];
        brr[heapLength] = t;
        heapLength--;
        goDown(1);
    }
    return 0;
}

int quicksort(int l, int r)
{
    int i, j, tmp, t, key;
    if (l >= r)
    {
        return 0;
    }
    i = l;
    j = r;
    key = arr[l];
    tmp = brr[l];

    while (i < j)
    {
        while (j > i && (arr[j] > key || (arr[j] == key && brr[j] > tmp)))
        {
            --j;
        }
        if (j == i)
        {
            break;
        }
        else if (arr[j] < key)
        {
            t = arr[j];
            arr[j] = arr[i];
            arr[i] = t;
            t = brr[j];
            brr[j] = brr[i];
            brr[i] = t;
            i++;
            print();
        }
        else
        {
            //arr[j]==key
            t = arr[j];
            arr[j] = arr[i];
            arr[i] = t;
            t = brr[j];
            brr[j] = brr[i];
            brr[i] = t;
            i++;
            print();
        }
        while (i < j && (arr[i] < key || (arr[i] == key && brr[i] < tmp)))
        {
            ++i;
        }
        if (i == j)
        {
            break;
        }
        else if (arr[i] > key)
        {
            t = arr[j];
            arr[j] = arr[i];
            arr[i] = t;
            t = brr[j];
            brr[j] = brr[i];
            brr[i] = t;
            j--;
            print();
        }
        else
        {
            t = arr[j];
            arr[j] = arr[i];
            arr[i] = t;
            t = brr[j];
            brr[j] = brr[i];
            brr[i] = t;
            j--;
            print();
        }
    }
    quicksort(l, i - 1);
    quicksort(i + 1, r);
    return 0;
}

int main()
{
    int i, q, l, r, x, j, t, c;
    cin >> n;
    heapLength = n;
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
        brr[i] = i;
    }
    //quicksort(1, n);
    heapSort();
    //print();
    cin >> q;
    while (q > 0)
    {
        scanf("%d%d%d", &l, &r, &x);
        q--;
        c = 0;
        i = 1;
        j = n;
        t = (1 + n) / 2;
        if (arr[i] > x || (arr[i] == x && brr[i] > r) || arr[j] < x || (arr[j] == x && brr[j] < l))
        {
            cout << 0;
            continue;
        }
        while (i <= j)
        {
            if (arr[t] > x)
            {
                j = t - 1;
                t = (i + j) / 2;
            }
            else if (arr[t] < x)
            {
                i = t + 1;
                t = (i + j) / 2;
            }
            else if (brr[t] > r)
            {
                j = t - 1;
                t = (i + j) / 2;
            }
            else if (brr[t] < l)
            {
                i = t + 1;
                t = (i + j) / 2;
            }
            else
            {
                cout << 1;
                c = 1;
                break;
            }
        }
        if (c == 0)
        {
            cout << 0;
        }
    }
    return 0;
}
#include<iostream>
using namespace std;
int digit(long long i){
	int d = 1;
	while (i > 9)
	{
		d++;
		i /= 10;
	}
	return d;
}
int main(){
	long long n, i, s = 0;
	cin >> n;
	i = 2;
	while (n != 1)
	{
		if (s == 20)
		{
			cout << "NO";
			return 0;
		}
		while (n%i == 0)
		{
			n /= i;
			s++;
			if (s > 20){
				cout << "NO";
				return 0;
			}
		}
		i++;
		if (digit(i)*(20 - s) > digit(n)){
			cout << "NO";
			return 0;
		}
	}
	if (s == 20){
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}

	return 0;
}
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n, k, s[100][1000], a, b, c;
	cin >> n;
	cin >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		cin >> b;
		cin >> c;
		int x = -b / (2 * a);
		for (int count = 0; count < k; count++)
		{
			s[i][count] = a * x*x + b * x + c;
			count++;
			int temp = x - 1;
			x += count;
			s[i][count] = a * x*x + b * x + c;
			x = temp;
		}
	}
	int f[100000], num = 0;
	for (int i = 0; i < 10000; i++)
		f[i] = 1000000;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++)
			f[i*k + j] = s[i][j];
	int temp;
	for (int i = 0; i < n*k; ++i)
	{
		for (int j = i; j < n*k; ++j)
		{
			if (f[i] > f[j])
			{
				temp = f[i];
				f[i] = f[j];
				f[j] = temp;
			}
		}
	}
	for (int i = 0; i < k - 1; i++)
	{
		cout << f[i] << ' ';
	}
	cout << f[k];
	return 0;
}
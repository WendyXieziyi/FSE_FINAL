#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s[35], n;
	int k = 0;
	cin >> n;
	do
	{
		cin >> s[k];
		k++;
	} while (s[k - 1] != "@");
	for (int i = 0; i < k - 1; i++)
	{
		int j = 0;
		string a = s[i];
		int pos = 0;
		while ((pos = a.find(n)) != -1)
		{
			a.erase(pos, n.size());
		}
		s[i] = a;
	}
	string temp;
	for (int i = 0; i < k - 1; ++i)
	{
		for (int j = i; j < k - 1; ++j)
		{
			int min = (size(s[i]) < size(s[j])) ? size(s[i]) : size(s[j]);

			for (int m = 0; m < min; m++)
			{
				if (s[i][m] < s[j][m])
				{
					temp = s[i];
					s[i] = s[j];
					s[j] = temp;
				}
			}
		}
	}
	for (int i = k-2; i >=0; i--)
	{
		cout << s[i] << endl;
	}
	cout << s[k];
	return 0;
}
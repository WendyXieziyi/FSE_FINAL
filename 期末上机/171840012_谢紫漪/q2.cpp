#include <iostream>
#include <string>
using namespace std;

int main()
{
	double A[1000], B[1000], C[1000], D[1000];
	int n,count=0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
		cin >> B[i]; 
		cin >> C[i]; 
		cin >> D[i];
	}
	for (int a=0;a<n;a++)
		for (int b=0;b<n;b++)
			for(int c=0;c<n;c++)
				for (int d = 0; d < n; d++)
					if (A[a] + B[b] + C[c] + D[d] == 0)count++;
	cout << count;
	return 0;
}

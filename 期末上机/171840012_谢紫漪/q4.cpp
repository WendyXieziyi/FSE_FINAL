#include <iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
const int maxnum = 100;
const int maxint = 999999;
int dist[maxnum];
int pre[maxnum];
int c[maxnum][maxnum];
int n, line;
void Dijkstra(int n, int v, int *dist, int *prev, int c[maxnum][maxnum])
{
	bool s[maxnum];
	for (int i = 1; i <= n; ++i)
	{
		dist[i] = c[v][i];
		s[i] = 0;
		if (dist[i] == maxint)
			prev[i] = 0;
		else
			prev[i] = v;
	}
	dist[v] = 0;
	s[v] = 1;
	for (int i = 2; i <= n; ++i)
	{
		int tmp = maxint;
		int u = v;
		for (int j = 1; j <= n; ++j)
			if ((!s[j]) && dist[j] < tmp)
			{
				u = j;
				tmp = dist[j];
			}
		s[u] = 1;
		for (int j = 1; j <= n; ++j)
			if ((!s[j]) && c[u][j] < maxint)
			{
				int newdist = dist[u] + c[u][j];
				if (newdist < dist[j])
				{
					dist[j] = newdist;
					prev[j] = u;
				}
			}
	}
}
int main()
{
	cin >> n;
	cin >> line;
	int u, v, len;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			c[i][j] = maxint;
	for (int i = 1; i <= line; ++i)
	{
		cin >> u >> v >> len;
		if (len < c[u][v])
		{
			c[u][v] = len;
			c[u][v] = len;
		}
	}
	for (int i = 1; i <= n; ++i)
		dist[i] = maxint;
	Dijkstra(n, 1, dist, pre, c);
	cout << dist[n];
	return 0;
}
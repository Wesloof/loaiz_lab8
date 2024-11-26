// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <queue>

using namespace std;

int vis[5] = {0};
int dist[5] = { -1 };
queue <int> Q;

int** createG(int n)
{
	int** G = NULL;
	G = new int* [n];
	for (int i = 0; i < n; i++)
	{
		G[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			G[i][j] = rand() % 2;
			G[j][i] = G[i][j];
			if (i == j) G[i][j] = 0;
		}
	}
	return G;
}

void printG(int** G, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << G[i][j] << " ";
		}
		cout << endl;
	}
}

void bfs(int** G, int size, int s)
{
	Q.push(s);
	vis[s] = 1;
	cout << s << " ";
	while (!Q.empty())
	{
		s = Q.front();
		Q.pop();
		for (int i = 0; i < size; i++)
		{
			if (G[s][i] == 1 && vis[i] == 0)
			{
				Q.push(i);
				vis[i] = 1;
				cout << i << " ";
				//dist[i] = dist[s] + 1;
			}
		}
	}
	
}
int main()
{
	int nG1 = 5;
	 
	int** G1 = createG(nG1);
	printG(G1, nG1);
	bfs(G1, nG1, 1);
}


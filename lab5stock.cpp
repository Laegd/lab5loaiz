#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h> 
#include <iostream>

using namespace std;

int main()
{
	srand(time(NULL));
	int m = 5;
	int** G, * deg;
	deg = (int*)malloc(m * sizeof(int));
	for (int i = 0; i < m; i++)
	{
		deg[i] = 0;
	}

	G = (int**)malloc(m * sizeof(int*));
	for (int i = 0; i < m; i++)
	{
		G[i] = (int*)malloc(m * sizeof(int));
	}
	for (int i = 0; i < m; i++)
	{
		G[i][i] = 0;
		for (int j = i + 1; j < m; j++)
		{
			G[i][j] = rand() % 2;
			G[j][i] = G[i][j];
		}
	}
	cout << endl << "1-e zadanie" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << G[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << "2-e zadanie" << endl;
	int k = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (G[i][j] == 1)
			{
				k++;
			}
		}
	}
	cout << "Razmer grafa = " << k / 2 << endl << endl << "3-e zadanie" << endl;;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (G[i][j] == 1)
			{
				deg[i]++;
			}
		}
		cout << "Grafi: " << i + 1 << " = " << deg[i] << endl;
	}
	for (int i = 0; i < m; i++)
	{
		if (deg[i] == 0) cout << "Vershina " << i + 1 << " izolirovana" << endl;
		if (deg[i] == 1) cout << "Vershina " << i + 1 << " konzevaya" << endl;
		if (deg[i] == m) cout << "Vershina " << i + 1 << " dominiruyshaya" << endl;
	}
}
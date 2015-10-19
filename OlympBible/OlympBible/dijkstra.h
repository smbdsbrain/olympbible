/*
Pavel
Dijkstra's algorithm // Алгоритм Дейкстры
2015
*/

#pragma once

#include "cstdio"
#include "algorithm"
#include "cmath"
#include "queue"
using namespace std;

int dijkstra(int** graph, int n, int start, int finish)
{
	graph = new int*[n];
	int* cost = new int[n];
	bool* used = new bool[n];

	for (int i = 0; i < n; i++)
	{
		used[i] = false;
		cost[i] = INT_MAX;
	}

	queue<int> q;
	cost[start] = 0;
	q.push(start);

	while (!q.empty())
	{
		int v = q.front(); q.pop();
		used[v] = true;

		for (int i = 0; i < n; i++)
		{
			if (graph[v][i] > 0)
			{
				if (cost[i] > cost[v] + graph[v][i])
				{
					cost[i] = cost[v] + graph[v][i];
					q.push(i);
				}
			}
		}
	}

	return (cost[finish] != INT_MAX ? cost[finish] : -1);
}

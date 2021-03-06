// 1126. Eulerian Path (25).cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <queue>

bool bfs(int **graph, int n)
{
	queue<int> q;
	bool *collected = new bool[n];
	fill(collected, collected + n, false);
	q.push(0);
	collected[0] = 1;
	int count = 1;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int w = 0; w < n; w ++)
			if (graph[v][w] == 1 && !collected[w]) {
				q.push(w);
				collected[w] = 1;
				count++;
			}
	}
	return count == n;
}

int main()
{
	int n, m;
	cin >> n >> m;
	int **graph = new int *[n];
	for (int i = 0; i < n; i++)
		graph[i] = new int[n];
	int *degree = new int[n];
	fill(degree, degree + n, 0);
	for (int i = 0; i < m; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		v1--;
		v2--;
		graph[v1][v2] = graph[v2][v1] = 1;
		degree[v1] ++;
		degree[v2] ++;
	}
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (i != 0) putchar(' ');
		cout << degree[i];
		if (degree[i] % 2 == 1) count++;
	}
	cout << endl;
	if (bfs(graph, n)) {
		if (count == 0) cout << "Eulerian";
		else if (count == 2) cout << "Semi-Eulerian";
		else cout << "Non-Eulerian";
	}
	else
		cout << "Non-Eulerian";
	cout << endl;
    return 0;
}


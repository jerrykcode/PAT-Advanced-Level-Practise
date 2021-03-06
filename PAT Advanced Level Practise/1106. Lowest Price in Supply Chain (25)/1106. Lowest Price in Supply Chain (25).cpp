// 1106. Lowest Price in Supply Chain (25).cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <queue>

struct node {
	int k, *children;
};

void bfs(node *tree, int n, double p, double r)
{
	queue<int>q;
	int *collected = new int[n];
	int last = 0, tail = 0, level = 0, count = 0, flag = 0;
	double min = 0.0;
	q.push(0);
	collected[0] = 1;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		if (tree[v].k == 0) {
			min = p * pow((1 + r / 100.0), level);
			count++;
			flag = 1;
		}
		for (int i = 0; i < tree[v].k; i++) {
			if (collected[tree[v].children[i]] != 1) {
				q.push(tree[v].children[i]);
				collected[tree[v].children[i]] = 1;
				last = tree[v].children[i];
			}
		}
		if (v == tail) {
			tail = last;
			level++;
			if (flag == 1) {
				printf("%.4f %d", min, count);
				return;
			}
		}
	}
}

int main()
{
	int n;
	double p, r;
	cin >> n >> p >> r;
	node *tree = new node[n];
	for (int i = 0; i < n; i++) {
		int k, *children;
		cin >> k;
		children = new int[k];
		for (int j = 0; j < k; j++)
			cin >> children[j];
		tree[i] = { k, children };
	}
	bfs(tree, n, p, r);
    return 0;
}


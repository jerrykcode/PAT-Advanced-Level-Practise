// 1034. Head of a Gang (30)_4.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>

int graph[2001][2001];
int weight[2001];
map<string, int> name_to_id;
map<int, string> id_to_name;
int id_count = 1;

struct node {
	int head, n_members;
};

int get_id(string name)
{
	if (name_to_id[name] == 0) {
		name_to_id[name] = id_count;
		id_to_name[id_count++] = name;
	}
	return name_to_id[name];
}

vector<node> bfs(int n, int threshold)
{
	vector<node> gangs;
	int *collected = new int[n];
	fill(collected, collected + n, 0);
	for (int i = 1; i < n; i++) {
		if (collected[i])continue;
		queue<int> q;
		q.push(i);
		collected[i] = 1;
		int n_members = 1, total_weight = weight[i]/2, head = i;
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (int w = 1; w < n; w ++)
				if (!collected[w] && graph[v][w] != 0) {
					q.push(w);
					collected[w] = 1;
					n_members++;
					total_weight += weight[w]/2;
					if (weight[w] > weight[head]) head = w;
				}
		}
		if (n_members > 2 && total_weight > threshold) 
			gangs.push_back({ head, n_members });
	}
	return gangs;
}

bool compare(node a, node b)
{
	return id_to_name[a.head] < id_to_name[b.head];
}

int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		string name1, name2;
		int time;
		cin >> name1 >> name2 >> time;
		int id1 = get_id(name1), id2 = get_id(name2);
		graph[id1][id2] += time;
		graph[id2][id1] += time;
		weight[id1] += time;
		weight[id2] += time;
	}
	vector<node> gangs = bfs(id_count, k);
	cout << gangs.size() << endl;
	if (gangs.size() > 0) {
		sort(gangs.begin(), gangs.end(), compare);
		for (auto it = gangs.begin(); it != gangs.end(); it++) 
			cout << id_to_name[it->head] << " " << it->n_members << endl;
	}
    return 0;
}


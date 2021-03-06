// 1109. Group Photo (25).cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <algorithm>
#include <string>

struct node {
	string name;
	int height;
};

bool compare(node a, node b)
{
	return a.height != b.height ? a.height > b.height:a.name < b.name;
}

int main()
{
	int n, k;
	cin >> n >> k;
	node *formation = new node[n];
	for (int i = 0; i < n; i++) 
		cin >> formation[i].name >> formation[i].height;
	sort(formation, formation + n, compare);
	int m = n / k;
	int extra = n - m * k;
	int first = 0;
	for (int i = 0; i < k; i++) {
		int len = i ? m : m + extra;
		node *row = new node[len];
		int  center = len / 2;
		row[center] = formation[first];
		int left = 1, right = 1;
		for (int j = 1; j < len; j++) {
			if (j % 2) row[center - left++] = formation[first + j];
			else row[center + right++] = formation[first + j];
		}
		for (int j = 0; j < len; j++) {
			if (j != 0) putchar(' ');
			cout << row[j].name;
		}
		printf("\n");
		first += len;
	}
    return 0;
}


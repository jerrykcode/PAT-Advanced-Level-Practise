// 1121. Damn Single (25).cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main()
{
	int couple[100000];
	int flag[100000];
	fill(couple, couple + 100000, -1);
	fill(flag, flag + 100000, 0);
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int c1, c2;
		cin >> c1 >> c2;
		couple[c1] = c2;
		couple[c2] = c1;
	}
	cin >> m;
	int * guests = new int[m];
	for (int i = 0; i < m; i++) {
		cin >> guests[i];
		flag[guests[i]] = 1;
	}
	vector<int> single;
	for (int i = 0; i < m; i++) {
		if (couple[guests[i]] == -1 || flag[couple[guests[i]]] == 0)
			single.push_back(guests[i]);
	}
	cout << single.size() << endl;
	sort(single.begin(), single.end());
	for (auto it = single.begin(); it != single.end(); it++) {
		if (it != single.begin()) putchar(' ');
		printf("%05d", *it);
	}
    return 0;
}


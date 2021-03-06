// 1097. Deduplication on a Linked List (25)_2.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct node {
	int key, next;
};

int abs(int a)
{
	return a >= 0 ? a : -a;
}

int main()
{
	node list[100000];
	int flag[10001];
	int n, head, ad, key, next;
	cin >> head >> n;
	for (int i = 0; i < n; i++) {
		cin >> ad >> key >> next;
		list[ad] = {key, next};
	}
	ad = head;
	int removed_list_head = -1, removed_list_tail = removed_list_head;
	while (ad != -1) {
		if (flag[abs(list[ad].key)] == 1) {
			if (removed_list_head == -1) {
				removed_list_head = ad;
				removed_list_tail = ad;
			}
			else {
				list[removed_list_tail].next = ad;
				removed_list_tail = ad;
			}
		}
		else {
			flag[abs(list[ad].key)] = 1;
			if (ad != head)printf(" %05d\n", ad);
			printf("%05d %d", ad, list[ad].key);
		}
		ad = list[ad].next;
	}
	printf(" -1\n");
	ad = removed_list_head;
	while (ad != removed_list_tail) {
		printf("%05d %d %05d\n", ad, list[ad].key, list[ad].next);
		ad = list[ad].next;
	}
	if (ad != -1) printf("%05d %d -1\n", ad, list[ad].key);
    return 0;
}


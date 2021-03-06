// 1123. Is It a Complete AVL Tree (30).cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <queue>

typedef struct node {
	int data;
	int index;
	node * left, * right;
}* AVLT;

int max(int a, int b)
{
	return a > b ? a : b;
}

int getHeight(AVLT tree)
{
	if (tree == NULL)
		return 0;
	return max(getHeight(tree->left),getHeight(tree->right)) + 1;
}

AVLT LL(AVLT tree)
{
	AVLT b = tree->left;
	tree->left = b->right;
	b->right = tree;
	return b;
}

AVLT RR(AVLT tree)
{
	AVLT b = tree->right;
	tree->right = b->left;
	b->left = tree;
	return b;
}

AVLT LR(AVLT tree)
{
	tree->left = RR(tree->left);
	return LL(tree);
}

AVLT RL(AVLT tree)
{
	tree->right = LL(tree->right);
	return RR(tree);
}

AVLT insert(AVLT tree, int data)
{
	if (tree == NULL) {
		tree = new node;
		tree->data = data;
		tree->index = -1;
		tree->left = NULL;
		tree->right = NULL;
		return tree;
	}
	if (data < tree->data) { //Inserts on left
		tree->left = insert(tree->left, data);
		if (getHeight(tree->left) - getHeight(tree->right) >= 2) {
			if (data < tree->left->data)
				tree = LL(tree);
			else tree = LR(tree);
		}
	}
	else { //Inserts on right
		tree->right = insert(tree->right, data);
		if (getHeight(tree->right) - getHeight(tree->left) >= 2) {
			if (data > tree->right->data)
				tree = RR(tree);
			else
				tree = RL(tree);
		}
	}
	return tree;
}

void bfs(AVLT tree)
{
	queue<AVLT> q;
	q.push(tree);
	tree->index = 0;
	int flag[20];
	fill(flag, flag + 20, -1);
	flag[0] = 1;
	int tag = 0;
	while (!q.empty()) {
		AVLT t = q.front();
		q.pop();
		if (t != tree) putchar(' ');
		cout << t->data;
		if (t->index - 1 >= 0 && flag[t->index - 1] == -1)
			tag = 1;
		if (t->left != NULL) {
			t->left->index = t->index * 2 + 1;
			flag[t->left->index] = 1;
			q.push(t->left);
		}
		if (t->right != NULL) {
			t->right->index = t->index * 2 + 2;
			flag[t->right->index] = 1;
			q.push(t->right);
		}
	}
	cout << endl << (tag == 1 ? "NO" : "YES") << endl;
}

int main()
{
	int n;
	cin >> n;
	AVLT tree = NULL;
	for (int i = 0; i < n; i++) {
		int data;
		cin >> data;
		tree = insert(tree, data);
	}
	bfs(tree);
    return 0;
}


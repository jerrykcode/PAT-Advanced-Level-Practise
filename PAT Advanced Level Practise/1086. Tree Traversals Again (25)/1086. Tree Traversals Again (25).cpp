// 1086. Tree Traversals Again (25).cpp: 定义控制台应用程序的入口点。
//
/*
1086. Tree Traversals Again (25)

时间限制 200 ms

内存限制 65536 kB

代码长度限制 16000 B

判题程序 Standard

作者 CHEN, Yue
---------------------------------------------------------------------------------------------------


An inorder binary tree traversal can be implemented in a non-recursive way with a stack. For example,
suppose that when a 6-node binary tree (with the keys numbered from 1 to 6) is traversed, the stack
operations are: push(1); push(2); push(3); pop(); pop(); push(4); pop(); pop(); push(5); push(6); pop();
pop(). Then a unique binary tree (shown in Figure 1) can be generated from this sequence of operations.
Your task is to give the postorder traversal sequence of this tree.

http://nos.patest.cn/bs_n9mde9jcnyj.jpg

Figure 1
---------------------------------------------------------------------------------------------------


Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<=30)
which is the total number of nodes in a tree (and hence the nodes are numbered from 1 to N). Then 2N lines
follow, each describes a stack operation in the format: "Push X" where X is the index of the node being pushed
onto the stack; or "Pop" meaning to pop one node from the stack.
---------------------------------------------------------------------------------------------------


Output Specification:

For each test case, print the postorder traversal sequence of the corresponding tree in one line. A solution is
guaranteed to exist. All the numbers must be separated by exactly one space, and there must be no extra space at
the end of the line.
---------------------------------------------------------------------------------------------------


Sample Input:

6
Push 1
Push 2
Push 3
Pop
Pop
Push 4
Pop
Pop
Push 5
Push 6
Pop
Pop

Sample Output:

3 4 2 6 5 1
---------------------------------------------------------------------------------------------------


题意：

通过进栈出栈表示一颗树，求树的后序遍历结果

思路：

建立树结点，初始化结点current、root为NULL，对于 "Push X"操作：

若current == NULL，则current->data = X，然后current赋给根，即root = current

若current != NULL，则建立结点tmp，其data为X，若current的left不存在则tmp赋给current的left，(right同)，
若current的left、right都存在则current更新为current的父结点，再次判断其left、right是否存在，最后tmp
的left、right均为NULL，tmp的父指针parent为current，最后更新current为tmp，current进栈

对于 "Pop"操作：

栈顶元素赋给current，栈顶元素出栈

从root开始递归，后序遍历树
*/
#include "stdafx.h"
#include <iostream>
using namespace std;
#include <string>
#include <stack>

typedef struct node {
	int data;
	struct node * left, * right, *parent;
} tnode;
typedef tnode *tree;

void post(tree root)
{
	if (!root->left && !root->right)
		cout << root->data << " ";
	else {
		if (root->left) post(root->left);
		if (root->right) post(root->right);
		cout << root->data << " ";
	}
}

int main()
{
	int n;
	cin >> n;
	tree root = NULL;
	tree current = NULL;
	stack<tree> s;
	for (int i = 0; i < 2 * n; i++) {
		string cmd;
		cin >> cmd;
		if (cmd == "Push") {
			int data;
			cin >> data;
			if (current == NULL) {
				current = new tnode;
				current->data = data;
				current->left = current->right = NULL;
				root = current;
			}
			else {
				tree tmp = new tnode;
				tmp->data = data;
			PUSH: {
				if (!current->left)
					current->left = tmp;
				else if (!current->right)
					current->right = tmp;
				else {
					current = current->parent;
					goto PUSH;
				}
				}
				  tmp->left = tmp->right = NULL;
				  tmp->parent = current;
				  current = tmp;
			}
			s.push(current);
		}
		else {
			current = s.top();
			s.pop();
		}
	}
	if (root->left) post(root->left);
	if (root->right) post(root->right);
	cout << root->data;
    return 0;
}


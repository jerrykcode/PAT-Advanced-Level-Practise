#include <iostream>
using namespace std;

int *pre, *post, unique = 1;

typedef struct node {
	int data;
	node *left, *right;
} *tree;

tree getTree(int preLeft, int preRight, int postLeft,int postRight)
{
	if (preLeft > preRight)
		return NULL;
	tree T = new node;
	T->data = pre[preLeft];
	int left = preLeft + 1, right = left;
	for (int i = left; i <= preRight && pre[i] != post[postRight - 1]; i++)
		right++;
	if (right == left && preLeft != preRight)
		unique = 0;
	T->left = getTree(left, right - 1, postLeft, postLeft + right - left - 1);
	T->right = getTree(right, preRight, postRight - (preRight - right + 1), postRight - 1);
	return T;
}

void in(tree T)
{
	if (T->left) {
		in(T->left);
		putchar(' ');
	}
	printf("%d", T->data);
	if (T->right) {
		putchar(' ');
		in(T->right);
	}
}

int main()
{
	int n;
	cin >> n;
	pre = new int[n], post = new int[n];
	for (int i = 0; i < n; i++)cin >> pre[i];
	for (int i = 0; i < n; i++)cin >> post[i];
	tree T = getTree(0, n - 1, 0, n - 1);
	cout << (unique?"Yes":"No") << endl;
	in(T);
	cout << endl;
    return 0;
}
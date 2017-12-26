// 1004. Counting Leaves (30).cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

typedef struct Node *Position;
struct Node {
	int Data;
	Position Next;
};
typedef Position List;

void CountLeaves(List *Vector)
{
	int Root = 1;/* Root of the tree */
	int count = 0;
	int Tail, Last;
	queue<int> Q;
	Q.push(Root);
	Last = Root;
	while (!Q.empty()) {
		int n = Q.front();
		Q.pop();
		if (Vector[n]->Next == NULL) 
			count++;
		else {
			Position P = (Position)malloc(sizeof(struct Node));
			for (P = Vector[n]->Next; P; P = P->Next) {
				Q.push(P->Data);
				Tail = P->Data;
			}
		}
		if (n == Last) {
			if (n != Root)
				putchar(' ');
			printf("%d", count);
			count = 0;
			Last = Tail;
		}
	}
}

int main()
{
	int N, M; /* 0 < N < 100, the number of nodes in a tree, and M (< N), the number of non-leaf nodes */
	scanf("%d %d", &N, &M);
	List *Vector = (List *)malloc((N + 1) * sizeof(List)); /* 链表存储非叶子结点的子结点，叶子结点的链表为NULL */
	for (int i = 1; i <= N; i++) {
		Vector[i] = (List)malloc(sizeof(struct Node));
		Vector[i]->Next = NULL;
	}
	for (int i = 0; i < M; i++) {
		int id, K;
		scanf("%d %d", &id, &K);
		for (int j = 0; j < K; j++) {
			int idk;
			scanf("%d", &idk);
			Position P = (Position)malloc(sizeof(struct Node));
			P->Data = idk;
			P->Next = Vector[id]->Next;
			Vector[id]->Next = P;
		}
	}
	CountLeaves(Vector);
    return 0;
}


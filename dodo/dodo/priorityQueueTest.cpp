#include<cstdio>
#define MAX_SIZE 10000
void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
typedef struct priorityQueue {
	int heap[MAX_SIZE];
	int count;
}priorityQueue;

void push(priorityQueue *pq, int data) {
	if (pq->count >= MAX_SIZE)
		return;
	pq->heap[pq->count] = data;
	int now = pq->count;
	int parent = (pq->count - 1) / 2;

	while (now > 0 && pq->heap[now] > pq->heap[parent]) {
		swap(&pq->heap[now], &pq->heap[parent]);
		now = parent;
		parent = (parent - 1) / 2;
	}
	pq->count++;
}

int pop(priorityQueue *pq) {
	if (pq->count <= 0)
		return -9999;
	int res = pq->heap[0];
	pq->count--;
	pq->heap[0] = pq->heap[pq->count];
	int now = 0, leftChild = 1, rightChild = 2;
	int target = now;
	while (leftChild < pq->count) {
		if (pq->heap[target] < pq->heap[leftChild])
			target = leftChild;
		if (pq->heap[target] < pq->heap[rightChild] && rightChild < pq->count)
			target = rightChild;
		if (target == now)
			break;
		else {
			swap(&pq->heap[now], &pq->heap[target]);
			now = target;
			leftChild = now * 2 + 1;
			rightChild = now * 2 + 2;
		}
	}
	return res;
}
int main() {
	priorityQueue pq;
	pq.count = 0;
	push(&pq, 1);
	push(&pq, 2);
	while (pq.count != 0) {
		printf("%d\n", pop(&pq));
	}
	return 0;
}
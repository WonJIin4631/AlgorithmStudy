#include<iostream>
using namespace std;

struct node {
	int left;
	int right;
};
int N;
node tree[27];

void preorder(int cur) {
	char c = cur + 'A';
	cout << c;
	if (tree[cur].left > 0)
		preorder(tree[cur].left);
	if (tree[cur].right > 0)
		preorder(tree[cur].right);
}
void inorder(int cur) {
	char c = cur + 'A';
	if (tree[cur].left >0) 
		inorder(tree[cur].left);
	cout << c;
	if (tree[cur].right > 0)
		inorder(tree[cur].right);
}
void postorder(int cur) {
	char c = cur + 'A';
	if (tree[cur].left > 0)
		postorder(tree[cur].left);
	if (tree[cur].right > 0)
		postorder(tree[cur].right);
	cout << c;

}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		char root, left, right;
		cin >> root >> left >> right;
		tree[root - 'A'].left = left - 'A';
		tree[root - 'A'].right = right - 'A';
	}
	preorder(0);
	cout << '\n';
	inorder(0);
	cout << '\n';
	postorder(0);
	cout << '\n';
	return 0;
}
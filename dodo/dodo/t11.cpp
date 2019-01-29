#define _CRT_SECURE_NO_WARNINGS 
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> Card1;
int N, M;
void find(int n) {
	int left = 0, right = N - 1;
	bool existence=false;
	while (left<=right) {
		int mid = (left + right) / 2;
		if (Card1.at(mid) == n) {
			existence = true;
			break;
		}
		else if (Card1.at(mid) < n)
			left=mid+1;
		else 
			right=mid-1;
	}
	if (existence)
		printf("1 ");
	else
		printf("0 ");
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);
		Card1.push_back(num);
	}
	sort(Card1.begin(), Card1.end());
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int num;
		scanf("%d",&num);
		find(num);
	}
	
}
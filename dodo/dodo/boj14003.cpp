#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int N;
int arr[1000001];
int p[1000001];
int cnt=0;
vector<int> ans,print;
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++){
		scanf("%d", &arr[i]);
	}
	ans.push_back(arr[1]);
	for (int i = 2; i <= N; i++) {
		if (ans[cnt] < arr[i]) {
			ans.push_back(arr[i]);
			cnt++;
			p[i] = cnt;
		}
		else {
			int pos = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
			ans[pos] = arr[i];
			p[i] = pos;
		}
	}
	printf("%d\n", cnt + 1);
	for (int i = N; i >= 1 && cnt >= 0; i--) {
		if (p[i] == cnt) {
			print.push_back(arr[i]);
			cnt--;
		}
	}
	for (int i = print.size() - 1; i >= 0; i--) {
		printf("%d ", print[i]);
	}
	return 0;
}
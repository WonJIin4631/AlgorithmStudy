#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v;
/*
왕눈이는 체력 p를가지고 있고 p만큼 점프를 할 수 있다. 점프 후에는 p가 1씩 감소
왕눈이는 돌을 건너 뛸수 없다
돌의 위치는 오름차순으로 알려준다
현재돌과 전에있던 돌까지 거리와 몇번 뛰었는지 정보를 가지고 있고 거리+뛰었던횟수 값의 합이 최대인 것이 최소이다
*/
int main() {
	v.push_back(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	int ans = 0;
	for (int i = 1; i < v.size(); i++) {
		int dist = v[i] - v[i - 1];
		ans = max(ans, dist + i);
	}
	cout << ans-1 << '\n';
	return 0;
}
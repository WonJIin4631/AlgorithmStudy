#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<int> v;
/*
������� ���� �����ϴµ� �ʿ��� �ð������� �ּҷ� �Ǵ°��� ���
�ð��� ���� ������������ ����
��ù��° �ð��� N�� �ߺ� ���� 2��°�� N-1�� .... 

T��° �ð��� N-T+1�� �ߺ� �Ǵ°��� Ȯ���� �� ����

*/
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		v.push_back(n);
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans += v[i]*(N - i);
	}
	cout << ans << '\n';
	return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v;
/*
�մ��̴� ü�� p�������� �ְ� p��ŭ ������ �� �� �ִ�. ���� �Ŀ��� p�� 1�� ����
�մ��̴� ���� �ǳ� �ۼ� ����
���� ��ġ�� ������������ �˷��ش�
���絹�� �����ִ� ������ �Ÿ��� ��� �پ����� ������ ������ �ְ� �Ÿ�+�پ���Ƚ�� ���� ���� �ִ��� ���� �ּ��̴�
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
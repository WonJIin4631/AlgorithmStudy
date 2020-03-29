#include<iostream>
#include<string>
#include<vector>
#include<functional>
#include<algorithm>
#include<math.h>
using namespace std;
/*
A~Z �ִ� ���ĺ� ������ 10��
0~9���� ������ �ϳ��� ���ĺ��� �ٲ�

���ĺ��� ������ �ڸ����� �����Ͽ�
�ѹ��� ������ ���� ���ĺ��� �����ϰ� �������� �����Ͽ� 9���� �������Ѵ�.

*/
int N;
int check[27] = { 0 };
vector<int> v;
int ans = 0;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			check[s[j] - 'A'] += pow(10, s.length() - j - 1);
		}
	}
	for (char i = 'A'; i <= 'Z'; i++) {
		if (check[i - 'A'] != 0) {
			v.push_back(check[i - 'A']);
		}
	}
	sort(v.begin(), v.end(),greater<int>());
	int num = 9;
	for (int i = 0; i < v.size(); i++) {
		ans += v[i] * num;
		num--;
	}
	cout << ans << '\n';
	return 0;
}
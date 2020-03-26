#include<iostream>
#include<string>
#include<vector>
#include<functional>
#include<algorithm>
#include<math.h>
using namespace std;
/*
A~Z 최대 알파벳 개수가 10개
0~9까지 숫자중 하나의 알파벳과 바꿈

알파벳이 나오는 자리수를 저장하여
한번도 나오지 않은 알파벳을 제외하고 내림차순 정렬하여 9부터 대입을한다.

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
#include<iostream>
#include<algorithm>
#include<functional>
#include<string>
#include<string.h>
using namespace std;

string ans = "-1";

int main() {
	string num;
	cin >> num;
	int sum = 0;
	int zero_cnt=0;
	for (int i = 0; i<num.length(); i++) {
		if (num[i] == '0')
			zero_cnt++;
		else {
			sum += (num[i] - '0');
		}
	}
	if (num.length()!=1) {
		if (sum % 3 == 0&&zero_cnt>=1) {
			sort(num.begin(), num.end(),greater<>() );
			ans = num;
		}
	}
	cout << ans << '\n';
	return 0;
}
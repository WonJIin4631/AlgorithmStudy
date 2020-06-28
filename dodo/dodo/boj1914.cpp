#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int N;
string add(string num1, string num2)
{
	long long sum = 0;
	string result;

	while (!num1.empty() || !num2.empty() || sum) {
		if (!num1.empty()) {
			sum += num1.back() - '0';
			num1.pop_back();
		}
		if (!num2.empty()) {
			sum += num2.back() - '0';
			num2.pop_back();
		}
		result.push_back((sum % 10) + '0');
		sum /= 10;
	}
	reverse(result.begin(), result.end());

	return result;
}
void solve(int num, int f, int t,int nn) {
	if (num == 1) {
		cout << f << ' ' << t << '\n';
	}
	else {
		solve(num - 1, f, nn, t);
		cout << f << ' ' << t << '\n';
		solve(num - 1, nn, t, f);
	}
}
int main() {
	cin >> N;
	string num;
	string ans;
	if (N == 1) {
		ans = "1";
	}
	else {
		num = "2";
		for (int i = 0; i <N - 1; i++) {
			ans = add(num, num);
			num = ans;
		}
		int t = ans.back() - '0';
		ans.pop_back();
		t -= 1;
		ans.push_back(t + '0');
	}
	cout << ans << '\n';
	if (N <= 20) {
		if (N == 1)
			cout << 1 << ' ' << 3 << '\n';
		else
			solve(N, 1, 3, 2);
	}
	return 0;
}
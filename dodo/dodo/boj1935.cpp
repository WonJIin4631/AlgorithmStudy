#include<iostream>
#include<stack>
#include<string>
using namespace std;

int n;
int numlist[28] = { 0 };
int visit[28] = { 0 };
stack<double> num;
string s;
int main() {
	cin >> n;
	cin >> s;
	for (int i = 0; i < s.length(); i++){
		if (s[i] >= 'A'&&s[i] <= 'Z') {
			if (visit[s[i] - 'A'] == 0) {
				visit[s[i] - 'A'] = 1;
				cin >> numlist[s[i] - 'A'];
			}
		}
		else
			continue;
	}
	int idx = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'A'&&s[i] <= 'Z') {
			num.push(numlist[s[i]-'A']);
		}
		else {
			double temp1 = num.top();
			num.pop();
			double temp2 = num.top();
			num.pop();
			if (s[i] == '-') {
				num.push(temp2 - temp1);
			}
			else if(s[i]=='/') {
				num.push(temp2 / temp1);
			}
			else if (s[i] == '*') {
				num.push(temp2*temp1);
			}
			else if (s[i] == '+') {
				num.push(temp2 + temp1);
			}
		}
	}
	cout << fixed;
	double ans = num.top();
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout << ans << '\n';
}
#include<iostream>
#include<string>
#include<deque>
using namespace std;

deque<char> upper;
deque<char> lower;
int N;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	while (N--){
		string s;
		cin >> s;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] >= 'A'&&s[i] <= 'Z') {
				upper.push_back(s[i]);
			}
			else if (s[i] >= '0'&&s[i] < '9') {
				upper.push_back(s[i]);
			}
			else if (s[i] >= 'a'&&s[i] <= 'z') {
				upper.push_back(s[i]);
			}
			else if (s[i] == '<') {
				if (!upper.empty()) {
					char temp = upper.back();
					upper.pop_back();
					lower.push_front(temp);
				}
			}
			else if (s[i] == '>') {
				if (!lower.empty()) {
					char temp = lower.front();
					lower.pop_front();
					upper.push_back(temp);
				}
			}
			else if (s[i] == '-') {
				if (!upper.empty()) {
					upper.pop_back();
				}
			}
		}
		string ans;
		while (!upper.empty()) {
			cout << upper.front();
			upper.pop_front();
		}
		while (!lower.empty()) {
			cout << lower.front();
			lower.pop_front();
		}
		cout << '\n';
	}
	return 0;
}
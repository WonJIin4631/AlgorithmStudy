#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool compare(string a,string b) {
	if (a.length() == b.length()) {
			return (a < b);
	}
	return a.length() < b.length();
}
int main() {
	vector<string> v;
	vector<string> ::iterator start;
	vector<string> ::iterator end;
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		string ss;
		cin >> ss;
		v.push_back(ss);
	}
	sort(v.begin(), v.end(),compare);
	end = unique(v.begin(), v.end());

	for (start = v.begin(); start != end; start++) {
		cout << *start << endl;
	}
}
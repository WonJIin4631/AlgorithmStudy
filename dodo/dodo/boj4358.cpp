#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
map<string, int> Map;
int cnt = 0;
vector<string> v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	while (true) {
		getline(cin, s, '\n');
		if (cin.eof() == true)
			break;
		if (Map.find(s) != Map.end()) {
			Map.find(s)->second++;
		}
		else {
			Map.insert(make_pair(s, 1));
			v.push_back(s);
		}
		cnt++;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		int n = Map.find(v[i])->second;
		double val = (double)n / cnt;
		val *= 100;
		cout.setf(ios::fixed);
		cout.precision(4);
		cout << v[i] << ' ' << val << '\n';
	}
	return 0;
}
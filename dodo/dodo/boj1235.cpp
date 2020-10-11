#include<iostream>
#include<set>
#include<string>
#include<vector>
using namespace std;

int N;
vector<string> v;
set<string> Set;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	string s;
	for (int i = 0; i < N; i++) {
		cin >> s;
		v.push_back(s);
	}
	int MaxLen = s.length();
	for (int i = MaxLen-1; i >=0 ; i--) {

		bool flag = false;
		for (int j = 0; j < N; j++) {
			string str = v[j].substr(i, MaxLen - i);
			if (Set.find(str) == Set.end()) {
				Set.insert(str);
			}
			else {
				flag = true;
				break;
			}
		}
		if (flag) {
			Set.clear();
		}
		else {
			cout << MaxLen - i << '\n';
			break;
		}
	}
	return 0;
}
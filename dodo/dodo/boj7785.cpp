#include<iostream>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;

map<string, string> Map;
vector<string> v;
int N;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string name, act;
		cin >> name >> act;
		if (Map.find(name) == Map.end()) {
			v.push_back(name);
			Map.insert(make_pair(name, act));
		}
		else {
			Map.find(name)->second = act;
		}
	}
	sort(v.begin(), v.end(),greater<>());
	for (int i = 0; i < v.size(); i++) {
		if (Map.find(v[i])->second == "enter")
			cout << v[i] << '\n';
	}
	return 0;
}
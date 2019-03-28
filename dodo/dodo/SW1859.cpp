#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct cmp {
	bool operator() (const pair<int, int>& v1,const pair<int, int>& v2) {
		return v1.second > v2.second;
	}
};
int main() {
	int T;
	cin >> T;
	vector<int> v1;
	for (int i = 0; i < T; i++) {
		int num;
		vector<pair<int, int>> v;
		cin >> num;
		for (int j = 0; j < num; j++) {
			int n;
			cin >> n;
			v.push_back(make_pair(n, j));
		}
		sort(v.begin(), v.end(),cmp());
		int max = v.at(0).first;
		int cnt = 0;
		for (int j = 1; j < v.size(); j++) { 
			if (v.at(j).first >= max)
				max = v.at(j).first;
			else
				cnt += max - v.at(j).first;
		}
		v1.push_back(cnt);	
	}
	for (int i = 0; i < v1.size(); i++) {
		cout << "#" << i + 1 << " " << v1.at(i)<<"\n";
	}
}
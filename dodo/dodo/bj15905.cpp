#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int, int>> v;
int N; 
bool cmp(pair<int,int> v1, pair<int, int> v2) {
	if (v1.first < v2.first)
		return false;
	else if (v1.first == v2.first) {
		if (v1.second > v2.second)
			return false;
		else return false;
	}
	else
		return true;
}


int main() {
	cin >> N;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int scr , pen ;
		cin >> scr>> pen;
		v.push_back(make_pair(scr, pen));
	}
	sort(v.begin(), v.end(),cmp);
	int sc, pn;
	sc = v.at(4).first;
	pn = v.at(4).second;
	for (int i = 5; i < v.size(); i++) {
		if (sc != v.at(i).first)
			break;
		cnt++;
	}
	cout << cnt;
}
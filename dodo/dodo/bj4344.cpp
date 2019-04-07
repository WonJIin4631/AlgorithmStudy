#include<iostream>
#include<vector>
using namespace std;

int C, N;
vector<double> v[1000 + 1];

void solve() {
	for (int i = 0; i < C; i++) {
		double cnt=0;
		int avg = v[i].at(v[i].size() - 1);
		for (int j = 0; j < v[i].size() - 1; j++) {
			if (v[i].at(j) > avg)
				cnt++;
		}
		v[i].push_back(double(cnt /(v[i].size()-1))*100);
	}
	for (int i = 0; i < C; i++) {
		double ans = (v[i].at(v[i].size() - 1));
		cout.precision(3);
		cout <<fixed <<ans<<"%"<<endl;
	}
}
int main() {
	cin >> C;
	for (int i=0; i < C; i++) {
		cin >> N; 
		double sum = 0;
		for (int j = 0; j < N; j++){
			double n;
			cin >> n;
			sum += n;
			v[i].push_back(n);
		}
		v[i].push_back(sum / N);
	}
	solve();
}
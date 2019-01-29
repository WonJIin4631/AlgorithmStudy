#include<iostream>
#include<vector>
using namespace std;
vector<int> ar;
int tcount = 0;
int sum = 0;

void cal(int n) {
	int a;
	for (int i = 0; i < ar.size(); i++) {
		if (ar.at(i) == n) {
			tcount++;
			break;
		}
		else if (ar.at(i) < n) {
			a = n - ar.at(i);
			tcount++;
			cal(a);
			break;
		}
	}
}
int main() {
	int s = 64;
	do {
		ar.push_back(s);
		s = s / 2;
	} while (s >= 1);
	cin >> sum;
	cal(sum);
	cout << tcount <<endl;
}
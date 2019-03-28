#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<long long int> v;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		long long int sum = 0;
		cin >> num;
		for (int j = 1; j <= num; j++) {
			if (j % 2 == 1)
				sum += j;
			else
				sum -= j;
		}
		v.push_back(sum);
	}
	for (int i = 0; i < v.size(); i++) {
		cout << "#" << i + 1 << " " << v.at(i) << "\n";
	}
}
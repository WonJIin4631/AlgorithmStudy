#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	vector<int> first; 
	int find1, find2;
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		int num;
		cin >> num;
		first.push_back(num);
		sum += num;
	}
	sort(first.begin(), first.end());
	for (int i = 0; i < first.size(); i++) {	
		for (int j = 0; j < first.size(); j++) {
			if (sum - 100 == first.at(i) + first.at(j) && i!=j) {
				find1 = i;
				find2 = j;
				break;
			}

		}
	}
	
	for (int i = 0; i <  first.size(); i++) {
		if(i!=find1&&i!=find2)
		cout << first.at(i) << endl;
	}
}
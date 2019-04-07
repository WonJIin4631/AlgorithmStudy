#include<iostream>
#include<string>
#include<functional>
#include<algorithm>
using namespace std;

int main() {
	string s;
	cin >> s;
	int usedNum[10] = { 0, };//0 1 2 3 4 5 6 7 8 
	for (int i = 0; i < s.length(); i++) {
		if (s.at(i) == '0')
			usedNum[0]++;
		else if (s.at(i) == '1')
			usedNum[1]++;
		else if (s.at(i) == '2')
			usedNum[2]++;
		else if (s.at(i) == '3')
			usedNum[3]++;
		else if (s.at(i) == '4')
			usedNum[4]++;
		else if (s.at(i) == '5')
			usedNum[5]++;
		else if (s.at(i) == '6')
			usedNum[6]++;
		else if (s.at(i) == '7')
			usedNum[7]++;
		else
			usedNum[6]++;
	}
	if (usedNum[6] % 2 == 0) {
		usedNum[6] = usedNum[6] / 2;
	}
	else
		usedNum[6] = usedNum[6] / 2 + 1;
	sort(usedNum,usedNum+10,greater<int>());
	cout << usedNum[0];
}
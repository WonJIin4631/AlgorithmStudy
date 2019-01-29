#include<iostream>
#include<algorithm>
#include<functional>
#include<string>
using namespace std;
int main() {
	string str;
	cin >> str;
	sort(str.begin(), str.end(), greater<int>());
	cout << str << endl;
}
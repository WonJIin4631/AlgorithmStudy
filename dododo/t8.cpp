#include<iostream>
using namespace std;

int main() {
	bool find=true;
	int  n = 0;
	int start=1, end=1;
	int putn;
	cin >> putn;
	while (find) {
		if (start <= putn && end >= putn) {
			find = false;
		}
		else {
			n++;
			start = end + 1;
			end += (6 * n);
		}
	}
	cout << n+1 << endl;
}
	#include<iostream>

	using namespace std;

	int main() {
		int num; int count = 0;
		int pos[3] = { 0 };
		cin >> num;
		if (num >= 1 && num < 100) {
			count = num;
		}
		else {
			count = 99;
			for (int i = 100; i <= num; i++) {

				pos[0] = i/ 100;
				pos[1] = (i-pos[0]*100) / 10;
				pos[2] = i % 10;

				if ((pos[0] - pos[1]) == (pos[1] - pos[2])) {
					count++;
				}
			}
		}
		cout << count << endl;
	}
#include<iostream>
using namespace std;
int value[2+1][2+1];
int X;
int arr[10000 + 1] = { 0 };
int cnt = 0;
int findPos(int n) {
	for (int i = 0; i < X; i++) {
		if (arr[i] == n) {
			return i;
		}
	}
	return 0;
}
void reArr(int a, int b) {
	for ( a; a < b&&a!=b; a++,b--) {
		int cng = arr[a];
		arr[a] = arr[b];
		arr[b] = cng;
	}
}

void arrFind() {
	int a, b;
	if (cnt < 2) {
		for (int i = 0; i < X; i++) {
			if (arr[i] != i + 1) {
				a = i;
				b = findPos(i + 1);
				reArr(a, b);
				value[cnt][0] = a + 1;
				value[cnt][1] = b + 1;
				cnt++;
				arrFind();
			}
		}
	}
}

int main() {
	cin >> X;
	for (int i = 0; i < X; i++) {
		cin >> arr[i];
	}
	arrFind();

	if (cnt == 0) {
		cout << "1 1\n" << "1 1\n";
	}
	else if (cnt == 1) {
		cout << "1 1\n" << value[0][0] << " " << value[0][1] << endl;
	}
	else {
		cout << value[0][0] << " " << value[0][1] << endl;
		cout << value[1][0] << " " << value[1][1] << endl;
	}
}
#include<iostream>

using namespace std;

int main() {
	int arr[1000 + 1];
	int N;
	cin >> N;
	for (int i=0; i < N; i++) {
			int min, max, cur;
			cin >> min >> max >> cur;
			if (cur < min)
				arr[i] = min - cur;
			else if (cur >= min&&cur <= max)
				arr[i] = 0;
			else
				arr[i] = -1;
	}
	for (int i = 0; i < N; i++) {
		cout << "#" << i + 1 << " " << arr[i] << endl;
	}
}
#include <iostream>
#include <algorithm>
using namespace std;

int M, N;
int snack[1000001];
bool check(int n){

	int cnt = 0;
	
	for (int i = 0; i < N; i++)
		cnt += snack[i] / n;

	if (cnt >= M)
		return true;

	return false;
}

int main(){
	cin >> M >> N;
	int left = 1, right;
	for (int i = 0; i < N; i++){
		cin >> snack[i];
	}
	sort(snack, snack + N);
	right = snack[N - 1];
	int result = 0;

	while (left <= right){
		int mid = (left + right) / 2;
		if (check(mid)){
			result = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}

	cout << result << "\n";

	return 0;
}

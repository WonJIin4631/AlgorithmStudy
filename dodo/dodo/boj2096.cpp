#include<iostream>
#include<algorithm>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int maxDP[3];
	int minDP[3];
	int N;
	int maxTemp[3];
	int minTemp[3];
	cin >> N;
	cin >> maxDP[0] >> maxDP[1] >> maxDP[2];
	minDP[0] = maxDP[0], minDP[1] = maxDP[1], minDP[2] = maxDP[2];
	int n1, n2, n3;
	for (int i = 1; i < N; i++) {
		minTemp[0] = minDP[0], minTemp[1] = minDP[1], minTemp[2] = minDP[2];
		maxTemp[0] = maxDP[0], maxTemp[1] = maxDP[1], maxTemp[2] = maxDP[2];
		cin >> n1>> n2>>n3;
		maxDP[0] = max(maxTemp[1]+n1, maxTemp[0] + n1);
		int val = max(maxTemp[0] + n2, maxTemp[1] + n2);
		maxDP[1] = max(maxTemp[2] + n2, val);
		maxDP[2] = max(maxTemp[1] + n3, maxTemp[2] + n3);

		minDP[0] = min(minTemp[1] + n1, minTemp[0] + n1);
		 val = min(minTemp[0] + n2, minTemp[1] + n2);
		 minDP[1] = min(minTemp[2] + n2, val);
		 minDP[2] = min(minTemp[1] + n3, minTemp[2] + n3);
	}
	int maxAns = 0;
	int minAns = 987654321;
	for (int i = 0; i < 3; i++) {
		maxAns = max(maxAns, maxDP[i]);
		minAns = min(minAns, minDP[i]);
	}
	cout << maxAns << ' ' << minAns << '\n';
	return 0;
}
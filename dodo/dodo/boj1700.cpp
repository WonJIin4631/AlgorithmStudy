#include<iostream>
#include<algorithm>
using namespace std;

int N, K;
int multap[101];
int uselist[101];
int ans = 0;

int main() {
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		cin >> uselist[i];
	}
	for (int i = 0; i < K; i++) {
		bool isUsed = 0;
		for (int j = 0; j < N; j++) {
			if (multap[j] == uselist[i])
			{
				isUsed = 1;
				break;
			}
		}
		if (isUsed)
			continue;
		for (int j = 0; j < N; j++) {
			if (!multap[j]) {
				multap[j] = uselist[i];
				isUsed = 1;
				break;
			}
		}
		if (isUsed)
			continue;
		int idx, deviceidx = -1;
		for (int j = 0; j < N; j++) {
			int lastidx = 0;
			for (int k = i + 1; k < K; k++) {
				if (multap[j] == uselist[k])
					break;
				lastidx++;
			}
			if (lastidx > deviceidx) {
				idx = j;
				deviceidx = lastidx;
			}

		}
		ans++;
		multap[idx] = uselist[i];
	}
	cout << ans << '\n';

	return 0;
}
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> budgets, int M) {
	int answer = 0;
	long sum = 0;
	int old_mid;
	int mid = 50000;
	int right = 100000;
	int left = 0;
	sort(budgets.begin(), budgets.end());

	for (int i = 0; i < budgets.size(); i++) {
		sum += budgets[i];
	}
	if (sum <= M)
		return budgets[budgets.size() - 1];
	while (true) {
		sum = 0;
		for (int i = 0; i < budgets.size(); i++) {
			if (budgets[i] > mid) {
				sum += mid;
			}
			else {
				sum += budgets[i];
			}
		}
		if (M < sum) {
			right = mid;
		}
		else if (M > sum) {
			left = mid;
		}
		else {
			return mid;
		}
		old_mid = mid;
		mid = (left + right) / 2;
		if (mid == old_mid) {
			return mid;
		}
	}

	return answer;
}

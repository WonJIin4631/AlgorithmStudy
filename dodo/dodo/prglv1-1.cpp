#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 0;
	vector<int> list;
	for (int i = 1; i <= n; i++) {
		if (n%i == 0) {
			list.push_back(i);
		}
	}
	for (int i = 0; i < list.size(); i++) {
		answer += list[i];
	}
	return answer;
}
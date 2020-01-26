#include <string>
#include <vector>
using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;

	int i = 0;
	int j = people.size() - 1;
	for (; i < j; j--) {
		if (people[i] + people[j] > limit) {
			answer += 1;
		}
		else {
			answer += 1;
			i += 1;
		}

	}

	if (i == j) {
		answer += 1;
	}
	return answer;
}
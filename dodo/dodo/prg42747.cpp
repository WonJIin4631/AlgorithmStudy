#include <string>
#include <vector>
#include<algorithm>
#include<functional>
using namespace std;

int solution(vector<int> citations) {
	sort(citations.begin(), citations.end(),greater<int>());
	int answer = 0;
	for (int i = 0; i<citations.size(); i++) {
		int cmp = citations[i];
		if (cmp > answer) {
			answer += 1;
		}
		else if (answer > cmp) {
			break;
		}
	}
	return answer;
}
#include <string>
using namespace std;

int solution(string dartResult) {
	int answer = 0;
	string s = "";
	int score[3] = { 0 };
	int idx = 0;
	for (int i = 0; i < dartResult.length(); i++) {
		if (dartResult[i] >= '0'&&dartResult[i] <= '9') {
			s += dartResult[i];
		}
		else if (dartResult[i] == 'S') {
			int sc = stoi(s);
			s = "";
			score[idx] = sc;
			idx++;
		}
		else if (dartResult[i] == 'D') {
			int sc = stoi(s);
			s = "";
			score[idx] = sc*sc;
			idx++;
		}
		else if (dartResult[i] == 'T') {
			int sc = stoi(s);
			s = "";
			score[idx] = sc*sc*sc;
			idx++;
		}
		else if (dartResult[i] == '*') {

			for (int i = idx - 2; i <= idx - 1; i++) {
				score[i] *= 2;
			}
		}
		else if (dartResult[i] == '#') {
			score[idx - 1] *= -1;
		}
	}
	for (int i = 0; i < 3; i++) {
		answer += score[i];
	}
	return answer;
}
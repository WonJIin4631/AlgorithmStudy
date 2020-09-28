#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	int visit[7][7] = { 0 };
	int a, b, preA, preB;
	int dx[8] = { -1,-2,-2,-1,1,2,2,1 };
	int dy[8] = { -2,-1,1,2,-2,-1,1,2 };
	char input[37][3];
	string result = "Valid";

	for (int i = 0; i < 36; i++)
		cin >> input[i][0] >> input[i][1];

	for (int i = 0; i < 36; i++) {
		a = input[i][0] - 'A';
		b = input[i][1] - '1';
		preA = input[i - 1][0] - 'A';
		preB = input[i - 1][1] - '1';

		if (visit[a][b])
			break;
		visit[a][b] = 1;

		bool case3 = false;
		for (int j = 0; j < 8; j++) {
			int aa = preA + dx[j];
			int bb = preB + dy[j];
			if (aa < 0 || aa>5 || bb < 0 || bb>5)
				continue;
			if (aa == a && bb == b)
				case3 = true;
		}
		if (!case3 && i != 0) { break; }
	}

	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 6; j++)
			if (!visit[i][j])
				result = "Invalid";

	bool case4 = false;
	for (int j = 0; j < 8; j++) {
		int aa = (input[0][0] - 'A') + dx[j];
		int bb = (input[0][1] - '1') + dy[j];
		if (aa < 0 || aa>5 || bb < 0 || bb>5)
			continue;
		if (aa == (input[35][0] - 'A') && bb == (input[35][1] - '1'))
			case4 = true;
	}

	if (!case4)
		result = "Invalid";

	cout << result;
	return 0;
}

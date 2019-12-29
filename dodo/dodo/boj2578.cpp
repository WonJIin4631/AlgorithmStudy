#include<iostream>
using namespace std;
int map[6][6];
int check[6][6];
pair<int, int> numlist[26];
int callnum[26];
int ans = 0;
bool bingo() {
	int cnt = 0;
	for (int i = 0; i < 5; i++) {
		bool flaggaro = true;
		bool flagsero = true;
		for (int j = 0; j < 5; j++) {
			if (check[i][j] == 0)
				flaggaro = false;
			if (check[j][i] == 0)
				flagsero = false;
		}
		if (flaggaro)
			cnt++;
		if (flagsero)
			cnt++;
		if (cnt >= 3)
			return true;
	}
	bool flagdegak1 = true;
	bool flagdegak2 = true;
	for (int i = 0; i < 5; i++) {
		if (check[4 - i][4 - i] == 0)
			flagdegak1 = false;
		if (check[i][4-i] == 0)
			flagdegak2 = false;
	}
	if (flagdegak1)
		cnt++;
	if (flagdegak2)
		cnt++;
	if (cnt >= 3)
		return true;
	return false;
}

int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> map[i][j];
			numlist[map[i][j]].first = i;
			numlist[map[i][j]].second = j;
		}
	}
	for (int i = 0; i < 25; i++) {
		cin >> callnum[i];
	}
	for (int i = 0; i < 25; i++) {
		check[numlist[callnum[i]].first][numlist[callnum[i]].second] = 1;
		if (bingo()) {
			cout << i + 1 << '\n';
			break;
		}
	}
	return 0;
}
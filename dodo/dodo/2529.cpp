#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int visited[10] = { 0 };

char arr[9 + 1];
int K;
string s = "";
string ansMin="9999999999" , ansMax="-1";


void DFS(int prev, int current) {
	if (current==K+1) {
		ansMin = min(ansMin, s);
		ansMax = max(ansMax, s);
		return;
	}
	if (arr[current - 1] == '>') {
		for (int i = 0; i < prev; i++) {
			if (!visited[i]) {
				visited[i] = 1;
				s += (char)(i + '0');
				DFS(i, current + 1);
				visited[i] = 0;
				s.erase(current, 1);
			}
		}
	}
	else if (arr[current - 1] == '<') {
		for (int i = prev+1; i <= 9; i++) {
			if (!visited[i]) {
				visited[i] = 1;
				s += (char)(i + '0');
				DFS(i, current + 1);
				visited[i] = 0;
				s.erase(current, 1);
			}
		}
	}
	return;
}

int main() {
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i <= 9; i++) {
		visited[i] = 1;
		s += (char)(i + '0');
		DFS(i, 1);
		visited[i] = false;
		s.erase(0, 1);
	}
	cout << ansMax << endl << ansMin;
}

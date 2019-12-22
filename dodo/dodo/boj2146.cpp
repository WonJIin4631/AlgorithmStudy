#include<iostream>
using namespace std;

int map[101][101];
int divmap[101][101];
int N;



int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
}
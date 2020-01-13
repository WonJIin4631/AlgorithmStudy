#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

int solution(vector<vector<int>> triangle) {
	int answer = 0;
	for (int i = 0; i < triangle.size(); i++) {
		for (int j = 0; j < triangle[i].size(); j++) {
			cout << triangle[i][j] << ' ';
		}
		cout << '\n';
	}
	for (int i = triangle.size() - 2; i >= 0; i--) {
		for (int j = 0; j < triangle[i].size(); j++) {
			triangle[i][j] = max(triangle[i][j] + triangle[i + 1][j], triangle[i][j] + triangle[i + 1][j + 1]);
		}
	}
	for (int i = 0; i < triangle.size(); i++) {
		for (int j = 0; j < triangle[i].size(); j++) {
			cout << triangle[i][j] << ' ';
		}
		cout << '\n';
	}
	//answer = triangle[0][0];
	return answer;
}
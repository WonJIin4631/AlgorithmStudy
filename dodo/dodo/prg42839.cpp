#include <string>
#include <vector>
#include<set>
#include<iostream>
#include<algorithm>
using namespace std;

set<int> Set;
int strLen;
string strCpy;
int visit[8];
int cnt = 0;
int sosu[1000000];
int maxNum = 0;
vector<string> ansList;
void DFS(string s) {
	if (s != "") {
		int num = stoi(s);
		maxNum = max(maxNum, num);
		if (Set.find(num) == Set.end()) {
			Set.insert(num);
			ansList.push_back(s);
		}
	}
	for (int i = 0; i < strCpy.length(); i++) {
		if (visit[i] == 0) {
			visit[i] = 1;
			s.push_back(strCpy[i]);
			DFS(s);
			s.pop_back();
			visit[i] = 0;
		}
	}
}
void checkSosu() {
	for (int i = 2; i <= maxNum; i++)
		sosu[i] = i;
	for (int i = 2; i <= maxNum; i++) {
		if (sosu[i] == 0)
			continue;
		for (int j = i + i; j <= maxNum; j += i) {
			sosu[j] = 0;
		}
	}
}
bool checkNum(string s) {
	int num = stoi(s);
	if (sosu[num] == 0)
		return false;
	else
		return true;
}
int solution(string numbers) {
	int answer = 0;
	strCpy = numbers;
	DFS("");
	checkSosu();
	for (int i = 0; i < ansList.size(); i++) {
		if (checkNum(ansList[i]))
			answer++;
	}
	return answer;
}
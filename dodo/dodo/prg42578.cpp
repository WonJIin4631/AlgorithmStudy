#include <string>
#include <vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;
/*
Map�� �̿��Ͽ� �ǻ��� ������ �´� Idx ��ȣ�� �ο�
������ (�ǻ��� ����+1) ���ѵ� �������� 1�� ���� ������ ���� ����
*/
int solution(vector<vector<string>> clothes) {
	int answer = 1;
	vector<vector<string>> list;
	list.resize(30);
	map<string, int> Map;
	int idx = 0;
	for (int i = 0; i < clothes.size(); i++) {
		if (Map.find(clothes[i][1]) == Map.end()) {
			list[idx].push_back(clothes[i][0]);
			Map.insert(make_pair(clothes[i][1], idx++));
		}
		else {
			int pos = Map.find(clothes[i][1])->second;
			list[pos].push_back(clothes[i][0]);
		}
	}
	for (int i = 0; i < idx; i++) {
		answer *= (list[i].size() + 1);
	}
	answer -= 1;
	return answer;
}
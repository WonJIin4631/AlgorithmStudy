#include <string>
#include<string.h>
#include <vector>
#include<map>
#include<iostream>
using namespace std;

/*
ä�ù濡 ����, ����� �޽��� ���,
���� �г����� �ٲ�� �ٲ� �г������� ���
�г����� �ߺ� ����

map����� Ű�� �������̵� ���� �г���
���� �г����� �ٲ�� �г��Ӱ� ����
record���� �г��� ������ ���� �۾� �Ϸ���
�ٽ� �ݺ������� ����, ���忡 ���� �޽��� �� answer �� �߰�
��ɾ� ���� ��ó�� ���ĺ����� ����

*/
const string enter_string{ "���� ���Խ��ϴ�." };
const string out_string{ "���� �������ϴ�." };
vector<string> solution(vector<string> record) {
	vector<string> answer;
	map<string, string> Map;
	for (int i = 0; i < record.size(); i++) {
		if (record[i][0] == 'C') {
			int idx = 7;
			string uid = "";
			string nickName = "";
			for (int j = idx; j < record[i].length(); j++) {
				if (record[i][j] == ' ')
					break;
				else {
					uid += record[i][j];
				}
				idx++;
			}
			for (int j = idx; j < record[i].length(); j++) {
				nickName += record[i][j];
			}
			Map.find(uid)->second = nickName;
		}
		else if(record[i][0] == 'E') {
			int idx = 6;
			string uid = "";
			string nickName = "";
			for (int j = idx; j < record[i].length(); j++) {
				idx++;
				if (record[i][j] == ' ') 
					break;
				else {
					uid += record[i][j];
				}
			}
			for (int j = idx; j < record[i].length(); j++) {
				cout << record[i][j] << ":::";
				nickName += record[i][j];
			}
			cout << '\n';
			Map.insert(make_pair(uid, nickName));
			if (Map.find(uid) != Map.end()) {
				Map.find(uid)->second = nickName;
			}
			else {
				cout << uid << ' ' << nickName << '\n';
			}
		}
	}
	for (int i = 0; i < record.size(); i++) {
		if (record[i][0] == 'E') {
			int idx = 6;
			string uid = "";
			string message = "";
			for (int j = idx; j < record[i].length(); j++) {
				idx++;
				if (record[i][j] == ' ') {
					break;
				}
				else {
					uid += record[i][j];
				}
			}
			message += Map.find(uid)->second;
			message.append(enter_string);
			answer.push_back(message);
		}
		else if (record[i][0] == 'L') {
			int idx = 6;
			string uid = "";
			string message = "";
			for (int j = idx; j < record[i].length(); j++) {
				idx++;
				if (record[i][j] == ' ') {
					break;
				}
				else {
					uid += record[i][j];
				}
			}
			message += Map.find(uid)->second;
			message.append(out_string);
			answer.push_back(message);
		}
	}
	return answer;
}
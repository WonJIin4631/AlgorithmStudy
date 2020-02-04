#include <string>
#include<string.h>
#include <vector>
#include<map>
#include<iostream>
using namespace std;

/*
채팅방에 입장, 퇴장시 메시지 출력,
만약 닉네임이 바뀌면 바뀐 닉네임으로 출력
닉네임은 중복 가능

map을사용 키는 유저아이디 값은 닉네임
만약 닉네임이 바뀌면 닉네임값 수정
record에서 닉네임 수정에 대한 작업 완료후
다시 반복문으로 입장, 퇴장에 대한 메시지 값 answer 에 추가
명령어 구분 맨처음 알파벳으로 구분

*/
const string enter_string{ "님이 들어왔습니다." };
const string out_string{ "님이 나갔습니다." };
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
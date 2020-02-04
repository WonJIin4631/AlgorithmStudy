#include <string>
#include <vector>
#include<queue>
#include<cmath>
#include<iostream>
using namespace std;

/*
각 기능 100% 이상일 때 서비스 반영가능
기능 마다 개발속도 다름 뒤에있는 기능이 먼저 개발 되어도 앞에 기능이 개발될때까지 기달렷다 출시

큐로 첫번째 기능에 대한 정보를 넣음 끝날때까지 시간을 구하고 값을 유지->for문으로 가능할거같은데
다음 기능이 이전 개발속도 보다 빠르면 이전 개발속도에 갯수 추가
이전 개발속도 보다 느리면 시간 갱신, answer배열에 지금까지 쌓인 기능개수 넣기
*/
vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	int cnt = 1;
	double day = ceil((double)(100 - progresses[i]) / (double)speeds[i]);

	int prevVal = day;

	//cout<<prevVal<<'\n';
	for (int i = 1; i < progresses.size(); i++) {
		double val = ceil((double)(100 - progresses[i]) / (double)speeds[i]);
		cout << val << '\n';
		if (prevVal >= val) 
			cnt++;
		else {
			answer.push_back(cnt);
			prevVal = val;
			cnt = 1;
		}

		if (i == progresses.size() - 1) {
			answer.push_back(cnt);
		}
	}

	return answer;
}
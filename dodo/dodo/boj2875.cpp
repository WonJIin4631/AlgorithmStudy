#include<iostream>
#include<algorithm>
using namespace std;
/*
여학생 2,남학생 1이 한팀이다.
N명의 여학생과 M명의 남학생 
K명은 반드시 인턴쉽에 참여해야됨, 인턴쉽 참여하게 되면 학생은 대회에 참여 불가능
팀의 최대값 출력
최대 팀의값은 50팀임 여기서 0팀까지 값을 내려가면서 비교?
*/
int N, M, K;
int team = 50;
int main() {
	cin >> N >> M >> K;
	while (true){
		if (team * 2 <= N&&team <= M) {
			if (team * 2 + team <= N + M - K)
				break;
		}
		team--;
	}
	cout << team << '\n';
	return 0;
}
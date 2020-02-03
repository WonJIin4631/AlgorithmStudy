#include<iostream>
#include<string>
#include<string.h>
using namespace std;

/*
분해합은 자연수 N의 각자리수 와 N의 합을 나타냄

여러개일 경우 가장 작은 생성자를 출력

모든경우 구하기 N 9*N자리수 만큼 뺀 수 부터 시작부터 N 이하까지 
만약 분해합이 N과 같다면 반복문 중단 출력
N 보다 크게 나오면 반복문 중단 출력
*/
int list[1000002] = { 0 };
int main() {
	int num = 1;
	int N;
	cin >> N;
	if (N > 100) {
		string s = to_string(N);
		num = N - s.length() * 9;
	}
	while (true){
		string s = to_string(num);
		int temp = num;
		for (int i = 0; i < s.length(); i++) {
			int n = s[i] - '0';
			temp += n;
		}
		if(num>N)
			break;
		if (temp == N) {
			list[temp] = num;
			break;
		}
		num++;
	}
	cout << list[N] << '\n';
	return 0;
}

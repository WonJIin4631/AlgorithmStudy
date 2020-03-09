#include<iostream>
#include<cstring>
using namespace std;
/*
자연수 N개가 주어짐 질문은 M번 한다.
S번째 수 부터 E번까지 수가 팰린드롬을 이루는지 물어보는데 맞는지 아닌지 알려줌 (참 1 , 거짓 0)

자연수 개수가 1인것들은 무조건 팰린드롬이다
개수가 2인 것은 현재위치 S와 S+1의 위치 값이 같으면 팰린드롬이다.
3이상인것은 현재 위치와 S+(개수-1) 값이 같고 이전 기록 dp[s+1][s+j-1]이 팰린드롬이면 팰린드롬이다. 조건 2개가 참이여야지 팰린드롬이 된다.
질문에 대해서 따로 계산하면 중복되는 계산이 있어 중복 계산을 최소화 하기 위해서 DP를 활용하여 문제를 푼다.

*/

int N, M;
int arr[2001];
bool dp[2001][2001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	cin >> M;
	memset(dp, false, sizeof(dp));
	//길이 1
	for (int i = 1; i <= N; i++) 
		dp[i][i] = true;
	//길이 2
	for (int i = 1; i <= N; i++) {
		if (arr[i] == arr[i + 1])
			dp[i][i + 1] = true;
	}
	//길이 3이상
	for (int i = 2; i < N; i++) {
		for (int j = 1; j <= N - i; j++) {
			if (arr[j] == arr[i + j] && dp[j + 1][j + i - 1])
				dp[j][j + i] = true;
		}
	}
	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;
		cout << dp[s][e] << '\n';
	}
	return 0;
}
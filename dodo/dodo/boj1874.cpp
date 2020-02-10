#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/*
1~N까지 수를 스택에 넣었다가 뽑아 하나 수열을 만듬 push순서는 반드시 오름차순
1~N까지 순서대로 스택에 넣어짐
현재 값이 스택에 넣어질 값보다 작으면 그값까지 push하고 뽑기

현재값이  스택의 탑과 같으면 뽑기
결과적으로 스택에 남은게 없어야됨
현재 넣어야할 값보다 찾을값이 작으면 안되는경우 <- 안되는 경우 끝까지 탐색안하도록 시간단축 가능
*/

int n;
char ans[200001];
int list[100001];
stack<int> st;
int idx = 0;
int curNum = 1;
int ansIdx = 0;
int N;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &list[i]);
	}

	bool flag = true;
	while (true) {
		if (curNum <= N) {
			if (curNum < list[idx]) {
				st.push(curNum);
				curNum++;
				ans[ansIdx++] = '+';
			}
			else if (curNum == list[idx]) {
				ans[ansIdx++] = '+';
				ans[ansIdx++] = '-';
				curNum++;
				idx++;
			}
			else if (!st.empty()) {
				if (st.top() == list[idx]) {
					st.pop();
					ans[ansIdx++] = '-';
					idx++;
				}
				else if (curNum > list[idx]) {
					flag = false;
					break;
				}
			}
		}
		else {
			if (st.empty())
				break;
			if (st.top() == list[idx]) {
				st.pop();
				ans[ansIdx++] = '-';
				idx++;
			}
			else {
				flag = false;
				break;
			}
		}
	}
	if (!flag)
		printf("NO\n");
	else {
		for (int i = 0; i < ansIdx; i++) {
			printf("%c\n", ans[i]);
		}
	}
	return 0;
}
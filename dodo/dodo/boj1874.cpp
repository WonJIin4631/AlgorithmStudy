#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/*
1~N���� ���� ���ÿ� �־��ٰ� �̾� �ϳ� ������ ���� push������ �ݵ�� ��������
1~N���� ������� ���ÿ� �־���
���� ���� ���ÿ� �־��� ������ ������ �װ����� push�ϰ� �̱�

���簪��  ������ ž�� ������ �̱�
��������� ���ÿ� ������ ����ߵ�
���� �־���� ������ ã������ ������ �ȵǴ°�� <- �ȵǴ� ��� ������ Ž�����ϵ��� �ð����� ����
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
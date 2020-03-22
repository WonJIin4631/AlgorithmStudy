#include<iostream>
#include<string>
using namespace std;
/*
���� 1,2,3 ���θ� �̷���� ������ �ִ�. ���̰� N�� �������� ������ ������ ���� ���� ������ ������ ���� �����̴�.
���� ���� �� ���� ���� ���� ���� ������ ����Ѵ�.


DFS�� Ǭ�� 
������ ���� �ݱ��� ������ �ߺ��� ������ ã�´�.
ó�� ������ �Ǵ� ������ ���� ���� ���̴� -> 1,2,3 �̼����� �߰��߱� ����

*/
bool flag = false;
char numList[3] = {'1','2','3' };
int N;
string ans = "";
void DFS(int idx,char c) {
	if (idx-1 == N) {
		cout << ans << '\n';
		exit(0);
	}
	ans += c;
	for (int i = 1; i <= idx / 2; i++) {
		string temp1 = ans.substr(idx - i, i);
		string temp2 = ans.substr(idx - i * 2, i);
		if (temp1 == temp2) {
			ans.erase(idx - 1);
			return;
		}
	}
	for (int i = 0; i < 3; i++) {
		DFS(idx + 1, numList[i]);
	}
	ans.erase(idx-1);
}
int main() {
	cin >> N;
	for (int i = 0; i < 3; i++) {
		DFS(1,numList[i]);
	}
	return 0;
}
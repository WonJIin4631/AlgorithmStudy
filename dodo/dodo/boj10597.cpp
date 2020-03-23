#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
1~N���� ���� �̷���� ������ ���Ϸ� ������
������ �������� ������ �����ؾߵ�

DFS�� ��� �ִ�� ���� ������ 1~�ִ�� ���� ���� ���Դ��� Ȯ���Ѵ�.

*/
string s;
int n;
int num[51];

void dfs(int cnt, int pos, vector<bool> &v)
{
	if (cnt>n)
		return;
	if (cnt == n){
		bool flag = true;
		for (int i = 0; i < n; i++){
			if ( num[i] == 0){
				flag = false;
				return;
			}
		}

		if (flag){
			for (int i = 0; i < n; i++){
				cout << num[i] << " ";
			}
			cout << "\n";
			exit(0);
		}
	}

	string d = "";
	int temp;
	for (int i = pos; i <= pos + 1; i++){
		d += s[i];
		temp = stoi(d);
		if (temp <= n && !v[temp]){
			num[cnt] = temp;
			v[temp] = true;
			dfs(cnt + 1, i + 1, v);
			num[cnt] = 0;
			v[temp] = false;
		}
	}
}
int main() {
	cin >> s;
	if (s.size() < 10)	{
		n = s.size();
	}
	else{
		n = 9 + (s.size() - 9) / 2;
	}
	vector<bool> v(n + 1, false);
	dfs(0, 0, v);
	return 0;
}
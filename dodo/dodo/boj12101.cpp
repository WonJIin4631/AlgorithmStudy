#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
/*
DFS�� ��� ��츦 Ž���� N������ �����ԵǸ� vector�� ������� ������ ���ֱ�
�Էµ� K���� ������ ����� ������ �ʰ��Ұ��� -1 ���
�ƴϸ� ������ ���� K-1��° ���� ���

*/

int arr[3] = { 1,2,3 };
long long cnt = 0;
long long N, K;
vector<string> ans;
void DFS(int n, int m,string s) {
	if (n < m) {
		for (int i = 0; i < 3; i++) {
			n += arr[i];
			string temp = s;
			if (s.length() != 0) {
				temp += "+" + to_string(arr[i]);
			}
			else {
				temp += to_string(arr[i]);
			}
			DFS(n, m,temp);
			n -= arr[i];
		}
	}
	else if (n == m) {
		cnt++;
		ans.push_back(s);
	}
}

int main() {
	cin >> N >> K;
	DFS(0, N, "");
	if (cnt < K)
		cout << "-1\n";
	else {
		sort(ans.begin(), ans.end());
		cout << ans[K - 1] << '\n';
	}

}
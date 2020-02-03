#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

/*
1~N ������ ���� ���ű��� 2���� ��������
����
���ű��� ��� �Ѱ� �̻��� ������ �־����
���� ���ű��� ��� ����Ǿ� �ִ�

�ΰ� ���ű� ���� �ּҰ� ���
�������� �й� ������ 2���� ���ű��� �й�


*/
int N;
int citizen[12] = { 0 };
int connect[12][12] = { 0 };
int visit[12] = { 0 };
int ans = 987654321;
vector<int> gu1;
vector<int> gu2;

bool check_connect(vector<int> v1, vector<int> v2) {
	int city[12] = { 0 };
	queue<int> q;
	//������ 2���̻��϶� Ȯ��
	if (v1.size() > 1) {
		q.push(v1[0]);
		//1���� ��ó�� ���÷κ��� ���� Ž�� 
		while (!q.empty()){
			int cur = q.front();
			q.pop();
			//�湮�� ���ô� 1�������� ����
			city[cur] = 1;
			for (int i = 1; i <= N; i++) {
				//���� ���� ���ÿ��� ����Ǿ��ְ� 1�������� ����, �湮 ���� ���� ���� ť�� �ٽó��� 
				if (visit[i]==1 && connect[cur][i] == 1&& city[i]==0)
					q.push(i);
			}
		}
		// 1������ �ִ� ���õ� ���� 1�� �ƴϸ� ������ �ȵǾ�����
		for (int i = 0; i < v1.size(); i++) {
			if (city[v1[i]] != 1)
				return false;
		}
	}
	if (v2.size() > 1) {
		q.push(v2[0]);
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			city[cur] = 2;
			for (int i = 1; i <= N; i++) {
				if (visit[i] == 0 && connect[cur][i] == 1 && city[i] == 0)
					q.push(i);
			}
		}
		for (int i = 0; i < v2.size(); i++) {
			if (city[v2[i]] != 2)
				return false;
		}
	}
	return true;
}
void div_city(int cnt, int idx) {

	if (1 <= cnt) {
		vector<int> v1;
		vector<int> v2;
		for (int i = 1; i <= N; i++) {
			if (visit[i] == 1)
				v1.push_back(i);
			else
				v2.push_back(i);
		}

		//������ �Ѱ��� �������
		if (v1.size() != 0 && v2.size() != 0) {

			//����Ǿ� �ִ��� Ȯ��
			if (check_connect(v1, v2)) {
				int c1_sum = 0;
				int c2_sum = 0;
				// ���� �մ��ϱ�
				for (int i = 0; i < v1.size(); i++) {
					c1_sum += citizen[v1[i]];
				}
				for (int i = 0; i < v2.size(); i++) {
					c2_sum += citizen[v2[i]];
				}
				//�ּҰ� ���ϱ�
				ans = min(ans, abs(c1_sum - c2_sum));
			}
		}
	}
	for (int i = idx; i <= N; i++) {
		if (visit[i]==1)
			continue;
			visit[i] = 1;
			div_city(cnt + 1, i);
			visit[i] = 0;
	}
}
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> citizen[i];
	}
	for (int i = 1; i <= N; i++) {
		int n;
		cin >> n;
		for (int j = 0; j < n; j++) {
			int to;
			cin >> to;
			connect[i][to] = 1;
			connect[to][i] = 1;
		}
	}
	div_city(0, 1);
	if (ans == 987654321)
		ans = -1;
	cout << ans << '\n';
	return 0;
}
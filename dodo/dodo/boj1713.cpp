#include<iostream>
#include<algorithm>
using namespace std;

struct Info {
	int idx, time, cnt;
};

bool comp(Info &a, Info &b) {
	if (a.cnt == b.cnt)
		return a.time < b.time ;

	return a.cnt < b.cnt;
}

bool comp2(Info &a, Info &b) {
	return a.idx < b.idx;
}

Info p_list[100];
int main() {
	int N, M;
	cin >> N >> M;
	int num;
	int p_cnt = 0;
	for (int i = 0; i < M; i++) {
		cin >> num;

		int j;
		for (j = 0; j < N; j++) { 
			if (p_list[j].idx == num) {
				p_list[j].cnt++;
				break;
			}
		}
		if (j == N) { 
			if (p_cnt < N) {
				p_list[p_cnt].idx = num;
				p_list[p_cnt].cnt++;
				p_list[p_cnt++].time = i;
			}
			else {
				sort(p_list, p_list + N, comp);
				p_list[0].idx = num;
				p_list[0].cnt = 1;
				p_list[0].time = i;
			}
		}
	}
	sort(p_list, p_list + N, comp2);

	for (int i = 0; i < N; i++) {
		if (p_list[i].cnt != 0)
			cout << p_list[i].idx << " ";
	}

	return 0;
}
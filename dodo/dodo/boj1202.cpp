#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, K;
int bag[300000];
pair<int, int> jewel[300000];
priority_queue<int> pq; 

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> jewel[i].first >> jewel[i].second;
	for (int i = 0; i < K; i++)
		cin >> bag[i];
	sort(jewel, jewel + N);
	sort(bag, bag + K);

	long long result = 0;
	int idx = 0;

	for (int i = 0; i < K; i++){
		while (idx < N && jewel[idx].first <= bag[i])
			pq.push(jewel[idx++].second);

		if (!pq.empty()){
			result += pq.top();
			pq.pop();
		}
	}
	cout << result << "\n";
	return 0;

}
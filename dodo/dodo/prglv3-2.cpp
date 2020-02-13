#include <string>
#include <vector>
#include<functional>
#include<algorithm>
using namespace std;

int parent[101];

struct info{
	int val;
	int from;
	int to;
};
bool comp(info a,info b) {
	return a.val < b.val;
}
int getParent(int n) {
	if (parent[n] == n)
		return n;
	return getParent(parent[n]);
}
void unionP(int n1,int n2) {
	int p1 = getParent(n1);
	int p2 = getParent(n2);
	if (p1 < p2) {
		parent[p2] = p1;
	}
	else {
		parent[p1] = p2;
	}
}
bool findP(int n1,int n2) {
	int p1 = getParent(n1);
	int p2 = getParent(n2);
	if (p1 == p2)
		return true;
	else
		return false;
}
int solution(int n, vector<vector<int>> costs) {
	int answer = 0;
	for (int i = 0; i < n; i++)
		parent[i] = i;
	vector<info> list;
	for (int i = 0; i < costs.size(); i++) {
		info in;
		in.from = costs[i][0];
		in.to = costs[i][1];
		in.val = costs[i][2];
		list.push_back(in);
	}
	sort(list.begin(), list.end(),comp);
	for (int i = 0; i < list.size(); i++) {
		if (!findP(list[i].to, list[i].from)) {
			answer += list[i].val;
			unionP(list[i].to, list[i].from);
		}
	}
	return answer;
}
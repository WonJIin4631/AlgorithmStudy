#include<iostream>
#include<vector>
using namespace std;

vector<int> v;

int main() {
	while (true)
	{
		int L, P, V;
		cin >> L >> P >> V;
		if (L == 0 && P == 0 && V == 0)
			break;
		int day = (V / P);
		int ans = day*L;
		int leftday=V - P*day;
		if (L > leftday)
			ans += leftday;
		else
			ans += L;
		v.push_back(ans);
	}
	for (int i = 0; i < v.size(); i++) {
		cout << "Case " << i + 1 << ": " << v[i] << '\n';
	}
}
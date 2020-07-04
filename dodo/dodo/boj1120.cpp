#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string A;
string B;
int ans = 987654321;
int main() {
	cin >> A >> B;
	int diff = B.length() - A.length();
	for (int i = 0; i <= diff; i++) {
		int temp = 0;
		for (int j = 0; j<A.length(); j++) {
			if (A[j] != B[j + i])
				temp++;
		}
		ans = min(ans, temp);
	}
	cout << ans << '\n';
	return 0;
}
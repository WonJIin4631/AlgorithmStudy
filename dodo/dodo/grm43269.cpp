#include <iostream>
#include<stack>
using namespace std;

int lego[32];
int N;
int leftAns=1;
int rightAns = 1;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> lego[i];
	}
	stack<int> st;

	st.push(lego[0]);
	//왼쪽
	for (int i = 1; i < N; i++) {
		if (st.top() < lego[i]) {
			leftAns++;
			st.push(lego[i]);
		}
	}
	while (!st.empty()){
		st.pop();
	}
	st.push(lego[N - 1]);
	//오른쪽
	for (int i = N - 2; i >= 0; i--) {
		if (st.top() < lego[i]) {
			rightAns++;
			st.push(lego[i]);
		}
	}
	cout << leftAns << ' ' << rightAns << '\n';
	return 0;
}
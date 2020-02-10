#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
/*
양수 ,+,- 괄호 포함 길이가 50인 식을 만들고 괄호를 지움
식은 0~9 ,+,- 만으로 이루어져있다 가장처음 마지막 문자는 숫자, 연속해서 2개 연산자 X ,5자리보다 많은 숫자 X, 수는 0으로 시작가능

연산자 기준으로  값을 계산 DFS를 이용?
1.현재 연산자 좌,우측을 괄호를 포함
2.괄호 포함 하지않음
괄호를 포함 길이가 50초과하면 안됨

최소값이 나오려면 -이후 연산자가 -이 다시 나올때까지 괄호 만약 다음에 바로 나오면 괄호 안해도됨

괄호 포함해서 50이상이면 안되지 않나?
*/

vector<char> op;
vector<int> num;
int len;
int ans = 987654321;
void solve(int idx, int sum,int galho) {

	if (idx >= op.size()) {
		ans = min(ans, sum);
		return;
	}
	if (op[idx] == '-') {
		if (idx < op.size()-1) {
			if (op[idx + 1] != '-') {
				int ncnt = 0;
				int temp = num[idx+1];
				for (int i = idx + 1; i < op.size(); i++) {
					if (op[i] == '-')
						break;
					ncnt++;
				}
				for (int i = idx + 1; i < idx + 1 + ncnt ; i++) {
					temp += num[i+1];
				}
				solve(idx + ncnt+1, sum - temp, galho + 2);
			}
		}
		solve(idx + 1, sum - num[idx + 1], galho);
	}
	else {
		solve(idx + 1, sum + num[idx + 1], galho);
	}
}

int main() {
	string s;
	cin >> s;
	string sNum="";
	int opIdx = 0;
	int numIdx = 0;
	len = s.length();
	cout << len << '\n';
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '+' || s[i] == '-') {
			num.push_back(stoi(sNum));
			op.push_back(s[i]);
			sNum = "";
		}
		else {
			sNum += s[i];
		}
	}
	num.push_back(stoi(sNum));
	solve(0, num[0], 0);
	cout << ans << '\n';
	return 0;
}
#include <string>
#include <vector>

using namespace std;

string solution(int n, int t, int m, int p) {
	string answer = "";
	string val = "0";
	vector<string> numList = { "0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F" };
	bool flag;
	int cNum = 1;
	int cnt = 1;
	while (cnt < t*m) {
		flag = true;
		string temp = "";
		int num = cNum;
		while (flag) {
			if (num / n == 0)
				flag = false;
			temp.insert(0, numList[num%n]);
			num /= n;
		}
		cnt += temp.length();
		val += temp;
		cNum++;
	}
	for (int i = 0, j = 0; i < cnt&&j < t; i++) {
		if (i%m == p - 1) {
			answer += val[i];
			j++;
		}
	}
	return answer;
}
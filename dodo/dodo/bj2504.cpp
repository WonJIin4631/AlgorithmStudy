#include<iostream>
#include<string>
#include<stack>
using namespace std;


int main() {
	string str;
	cin >> str;
	stack<char> s;
	int  temp = 1, result = 0;
	bool imposible= false;
	for (int i = 0; i < str.length(); i++) {

		if (str[i] == '(') {
			s.push('(');
			temp *= 2;
		}
		else if (str[i] == '[') {
			s.push('[');
			temp *= 3;
		}

		else if ((str[i] == ')' && (s.empty() || s.top() != '('))) {
			imposible = true;
			break;
		}
		else if ((str[i] == ']' && (s.empty() || s.top() != '['))) {
			imposible = true;
			break;
		}
		else if (str[i] == ')') {
			if (str[i - 1] == '(')
				result += temp;
			s.pop();
			temp /= 2;
		}
		else if (str[i] == ']') {
			if (str[i-1] == '[')
				result += temp;
			s.pop();
			temp /= 3;
		}

	}
	
	if (imposible || !s.empty())
		cout << '0' << "\n";
	else
		cout << result << "\n";


}
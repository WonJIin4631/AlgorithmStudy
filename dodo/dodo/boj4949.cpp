#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int main() {

	while (true) {
		char input[101];
		cin.getline(input, 101);

		if (!strcmp(input, ".")) break;

		stack <char> st;
		int flag = 0;

		for (int i = 0; i < strlen(input); i++) {
			if (input[i] == '(' || input[i] == '[') 
				st.push(input[i]);

			else if (input[i] == ')') {
				if (!st.empty() && st.top() == '(') 
					st.pop();
				else { 
					cout << "no\n"; 
					flag = 1;
					break; }
			}

			else if (input[i] == ']') {
				if (!st.empty() && st.top() == '[') 
					st.pop();
				else { 
					cout << "no\n"; 
					flag = 1; break; 
				}
			}
		}

		if (flag) continue;

		if (!st.empty())
			cout << "no\n";
		else cout << "yes\n";
	}


	return 0;
}
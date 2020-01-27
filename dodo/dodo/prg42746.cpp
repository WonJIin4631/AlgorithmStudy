#include <string>
#include <vector>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;

bool cmp(string a, string b) {
	int num1 = stoi(a + b);
	int num2 = stoi(b + a);
	return num1 > num2;
}
string solution(vector<int> numbers) {
	string answer = "";
	vector<string> temp;
	for (int i = 0; i < numbers.size(); i++) {
		temp.push_back(to_string(numbers[i]));
	}
	sort(temp.begin(), temp.end(), cmp);
	if (temp[0] == "0")
		return "0";
	else {
		for (int i = 0; i < temp.size(); i++) {
			answer += temp[i];
		}
	}	
	return answer;
}
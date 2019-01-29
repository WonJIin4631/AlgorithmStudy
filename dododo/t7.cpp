#include<iostream>
#include<queue>
using namespace std;
queue<int> moveQ;
vector<int> value;

int N, M;
int inputN;
int totalC=0;


void cal(int a) {
	int moveC = 0;
	int m;
	while (moveQ.front()!=a)
	{
		moveC++;
		m = moveQ.front();
		moveQ.pop();
		moveQ.push(m);
	}
	if (moveC >= moveQ.size() - moveC)
		totalC += moveQ.size() - moveC;
	else if (moveC < moveQ.size() - moveC)
		totalC += moveC;
	moveQ.pop();
	
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M ; i++) {
		cin >> inputN;
		value.push_back(inputN);
	}
	for (int i = 1; i <= N; i++) {
		moveQ.push(i);
	}
	for (int i = 0; i < M; i++) {
		cal(value.at(i));
		
	}
	cout << totalC << endl;
}
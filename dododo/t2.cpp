#include<iostream>
#include<vector>
using namespace std;

class Fibo {
	vector<int> a;
public:
	Fibo() { a; }
	void play(int n);
};
void Fibo::play(int n) {
	int count = 2;
	int sum;
	a.push_back(0);
	a.push_back(1);
	while (count <= n) {
		sum = a.at(count - 2) + a.at(count - 1);
		a.push_back(sum);
		count++;
	}
	cout << a.at(n)<<endl;
}

int main() {
	Fibo f;
	int num;
	cin >> num;
	f.play(num);
}
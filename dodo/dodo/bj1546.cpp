#include<iostream>
using namespace std;


int main() {
	float score[1000 + 1];
	int N;
	float Max = 0;
	float sum = 0;


	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> score[i];
		if (Max < score[i])
			Max = score[i];
	}
	for (int i = 0; i < N; i++) {
			score[i]=score[i]/Max*100;
			sum += score[i];
	}
	cout << sum / N<<endl;
}

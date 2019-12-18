#include<iostream>
#include<math.h>
using namespace std;

int N;
int score[1001];
int cng_score[1001];

void change() {
	double sum = 0;
	for (int i = 0; i < N; i++) {
		if (score[i] >= 0 && score[i] < 10) {
			if (score[i] == 0 || score[i] == 6 || score[i] == 9)
				sum += 9;
			else
				sum += score[i];
		}
		else if (score[i] >= 10 && score[i] <= 99) {
			int n1, n2;
			n1 = score[i] / 10;
			n2 = score[i] - (n1 * 10);
			if (n1 == 0 || n1 == 6 || n1 == 9)
				n1 = 9;
			if (n2 == 0 || n2 == 6 || n2 == 9)
				n2 = 9;
			sum += n1 * 10 + n2;
		}
		else if (score[i] == 100) {
			sum += 100;
		}
	}
	sum = sum / N;
	cout << round(sum) << '\n';

}


int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> score[i];
	}
	change();
}
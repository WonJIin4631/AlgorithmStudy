#include<iostream>
using namespace std;
/*
B생명력에서 A공격력을 나눔 나머지가 0이 아니면 +1;
A생명력에서 B공격력을 나눔 나머지가 0이 아니면 +1;
적은 수의값이 나오는게 먼저 죽는카드
*/
struct card{
	int power;
	int health;
};
int main() {
	card A;
	card B;
	cin >> A.power >> A.health;
	cin >> B.power >> B.health;
	int Acnt;
	int Bcnt;
	if (B.health % A.power != 0) {
		Acnt = B.health / A.power + 1;
	}
	else
		Acnt = B.health / A.power;
	if (A.health % B.power != 0) {
		Bcnt = A.health / B.power + 1;
	}
	else
		Bcnt = A.health / B.power;
	if (Acnt == Bcnt)
		cout << "DRAW" << '\n';
	else if (Acnt < Bcnt)
		cout << "PLAYER A" << '\n';
	else
		cout << "PLAYER B" << '\n';
	return 0;
}
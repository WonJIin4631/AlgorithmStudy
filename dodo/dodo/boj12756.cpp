#include<iostream>
using namespace std;
/*
B����¿��� A���ݷ��� ���� �������� 0�� �ƴϸ� +1;
A����¿��� B���ݷ��� ���� �������� 0�� �ƴϸ� +1;
���� ���ǰ��� �����°� ���� �״�ī��
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
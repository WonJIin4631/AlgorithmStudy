#include<iostream>
#include<string>
using namespace std;

string s[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
int main() {
	int x, y;
	int year = 365;
	cin >> x >> y;
	int month = 1;
	int cntday = 0;
	while (month!=x)
	{
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 112)
			cntday += 31;
		else if (month == 2)
			cntday += 28;
		else
			cntday += 30;
		month++;
	}
	cntday += y;
	if (cntday < 7) {
		cout << s[cntday] << endl;
	}

	else {
	
		cntday = cntday % 7;
		
		cout << s[cntday] << endl;
	}

}
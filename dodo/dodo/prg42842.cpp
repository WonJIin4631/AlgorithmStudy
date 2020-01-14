#include <string>
#include <vector>
#include<iostream>
using namespace std;

vector<int> solution(int brown, int red) {
	vector<int> answer;
	int h = 1, w = 1;
	for (int h = 1; h <= red; h++) {
		for (int w = h; h <= red / w; w++) {
			if (w*h == red) {
				for (int i = 1; i <= 5000; i++) {
					if ((w + i * 2)*(h + i * 2) > brown*red)
						break;
					if ((w + i * 2)*(h + i * 2) == brown*red) {
						cout << w + i * 2 << ' ' << h + i * 2 << '\n';
						break;
					}
				}
			}
		}
	}
	return answer;
}
using namespace std;

long long solution(int w, int h)
{
	long long answer = 1;
	if (w == h) {
		answer = (w*h) - 1 - w;
	}
	else if (w == 1 || h == 1) {
		answer = 0;
	}
	return answer;
}
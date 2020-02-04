#include <string>
#include <vector>
#include<queue>
#include<cmath>
#include<iostream>
using namespace std;

/*
�� ��� 100% �̻��� �� ���� �ݿ�����
��� ���� ���߼ӵ� �ٸ� �ڿ��ִ� ����� ���� ���� �Ǿ �տ� ����� ���ߵɶ����� ��޷Ǵ� ���

ť�� ù��° ��ɿ� ���� ������ ���� ���������� �ð��� ���ϰ� ���� ����->for������ �����ҰŰ�����
���� ����� ���� ���߼ӵ� ���� ������ ���� ���߼ӵ��� ���� �߰�
���� ���߼ӵ� ���� ������ �ð� ����, answer�迭�� ���ݱ��� ���� ��ɰ��� �ֱ�
*/
vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	int cnt = 1;
	double day = ceil((double)(100 - progresses[i]) / (double)speeds[i]);

	int prevVal = day;

	//cout<<prevVal<<'\n';
	for (int i = 1; i < progresses.size(); i++) {
		double val = ceil((double)(100 - progresses[i]) / (double)speeds[i]);
		cout << val << '\n';
		if (prevVal >= val) 
			cnt++;
		else {
			answer.push_back(cnt);
			prevVal = val;
			cnt = 1;
		}

		if (i == progresses.size() - 1) {
			answer.push_back(cnt);
		}
	}

	return answer;
}
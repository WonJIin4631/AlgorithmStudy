#include <string>
#include <vector>

using namespace std;
int s_list[27] = { 0 };
int solution(string skill, vector<string> skill_trees) {
	int idx = 1;
	for (int i = 0; i < skill.length(); i++) {
		s_list[skill[i]-'A'] = idx++;
	}

	int answer = 0;
	for (int i = 0; i < skill_trees.size(); i++) {
		idx = 1;
		bool flag = true;
		for (int j = 0; j < skill_trees[i].length(); j++) {
			if (s_list[skill_trees[i][j] - 'A'] == 0)
				continue;
			else {
				if (s_list[skill_trees[i][j] - 'A'] == idx)
					idx++;
				else {
					flag = false;
					break;
				}
			}
		}

		if (flag)
			answer++;
	}
	return answer;
}
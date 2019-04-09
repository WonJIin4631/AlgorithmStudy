#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
bool map[26][26];
bool visited[26][26];
int dir_x[4] = { 1,0,-1,0 };
int dir_y[4]{ 0,1,0,-1 };
vector<int> a;

int dfs(int x, int y)
{
	visited[x][y] = 1;
	map[x][y] = 0;
	int result = 1;
	for (int i = 0; i < 4; i++)
	{
		int n_x = x + dir_x[i];
		int n_y = y + dir_y[i];
		if (map[n_x][n_y] && !visited[n_x][n_y])
			result += dfs(n_x, n_y);
	}
	return result;
}


int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%1d", &map[i][j]);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (map[i][j])
			{
				a.push_back(dfs(i, j));
			}
		}
	}

	cout << a.size() << endl;
	sort(a.begin(), a.end());
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << endl;

}

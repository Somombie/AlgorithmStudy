#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

int r, c;
char arr[10001][501];

int dx[] = { -1,0,1 };
int dy[] = { 1,1,1 };
bool check[10001][501] = { false };
int result = 0;
bool visited;

void dfs(int x, int y)
{
	if (y == c - 1)
	{
		result++;
		visited = true;
		return;
	}

	check[x][y] = true;


	for (int i = 0; i < 3; i++)
	{
		int nx = dx[i] + x;
		int ny = dy[i] + y;

		if (nx < 0 || nx >= r || ny < 0 || ny >= c)
			continue;
		if (check[nx][ny])
			continue;
		if (arr[nx][ny] == 'x')
			continue;

		if (visited)
			return;
		dfs(nx, ny);
	}
}

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> r >> c;

	for (int i = 0; i < r; i++)
	{
		string s;
		cin >> s;

		for (int j = 0; j < c; j++)
		{
			arr[i][j] = s[j];
		}
	}

	for (int i = 0; i < r; i++)
	{
		visited = false;
		dfs(i, 0);
	}
	cout << result;

	return 0;
}
#include <iostream>
using namespace std;
#include <vector>
#include <queue>

int n;
vector<pair<int, int>> v[10001];
bool check[10001];
int start = 0;
int answer = 0;

void reset()
{
	for (int i = 1; i <= n; i++)
		check[i] = false;

	answer = 0;
}

void dfs(int x)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, 0));
	check[x] = true;

	while (!q.empty())
	{
		int cx = q.front().first;
		int ccost = q.front().second;
		q.pop();
		
		if (answer < ccost)
		{
			answer = ccost;
			start = cx;
		}
		
		for (int i = 0; i < v[cx].size(); i++)
		{
			int nx = v[cx][i].first;
			int ncost = v[cx][i].second;

			if (!check[nx])
			{
				q.push(make_pair(nx, ncost + ccost));
				check[nx] = true;
			}
		}
	}
}

int main(void)
{
	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back(make_pair(to, cost));
		v[to].push_back(make_pair(from, cost));
	}

	reset();
	dfs(1);

	reset();
	dfs(start);

	cout << answer;

	return 0;
}
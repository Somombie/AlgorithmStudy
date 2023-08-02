#include <iostream>
using namespace std;
#include <vector>
#include <queue>

int n, m;
int node[32001];
vector<int> v[32001];

int main(void)
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int front, back;
		cin >> front >> back;
		v[front].push_back(back);
		node[back]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (node[i] == 0)
			q.push(i);
	}

	while (!q.empty())
	{
		int cx = q.front();
		q.pop();

		cout << cx << " ";

		for (int i = 0; i < v[cx].size(); i++)
		{
			int nx = v[cx][i];
			node[nx]--;

			if (node[nx] == 0)
				q.push(nx);
		}
	}

	return 0;
}
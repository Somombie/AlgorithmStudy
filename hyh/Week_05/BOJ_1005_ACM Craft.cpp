#include <iostream>
using namespace std;
#include <queue>

int d[1001];
vector<int> v[1001];
int node[1001];
int result[1001];

void reset()
{
	for (int i = 0; i <= 1000; i++)
	{
		d[i] = 0;
		v[i].clear();
		node[i] = 0;
		result[i] = 0;
	}
}

int main(void)
{
	int t;
	cin >> t;

	for (int z = 0; z < t; z++)
	{
		reset();

		int n, k;
		cin >> n >> k;

		for (int i = 1; i <= n; i++)
			cin >> d[i];
		for (int i = 1; i <= k; i++)
		{
			int front, back;
			cin >> front >> back;
			v[front].push_back(back);
			node[back]++;
		}

		int w;
		cin >> w;

		queue<int> q;
		int start = 0;
		for (int i = 1; i <= n; i++)
		{
			if (node[i] == 0)
			{
				q.push(i);
				result[i] = d[i];
			}
		}

		while (!q.empty())
		{
			int cx = q.front();
			q.pop();

			for (int i = 0; i < v[cx].size(); i++)
			{
				int nx = v[cx][i];
				result[nx] = max(result[nx], result[cx] + d[nx]);
				node[nx]--;

				if (node[nx] == 0)
					q.push(nx);
			}
		}

		cout << result[w] << "\n";
	}

	return 0;
}
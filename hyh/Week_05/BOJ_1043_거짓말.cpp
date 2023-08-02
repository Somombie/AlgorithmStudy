#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <set>

int n, m;
int parent[51];
vector<int> v;
int answer;
vector<int> party[51];

void reset()
{
	for (int i = 0; i <= 50; i++)
		parent[i] = i;
}

int Find(int x)
{
	if (parent[x] == x)
		return x;
	return parent[x] = Find(parent[x]);
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a != b)
		parent[a] = b;
}

int main(void)
{
	cin >> n >> m;
	reset();

	int trueP;
	cin >> trueP;
	for (int i = 0; i < trueP; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());
	if (v.size() > 1)
		for (int i = 0; i < v.size() - 1; i++)
			Union(v[i], v[i + 1]);

	for (int i = 0; i < m; i++)
	{
		int num;
		cin >> num;
		
		for (int j = 0; j < num; j++)
		{
			int partyNum;
			cin >> partyNum;
			party[i].push_back(partyNum);
		}

		sort(party[i].begin(), party[i].end());

		if (party[i].size() > 1)
			for (int j = 0; j < party[i].size() - 1; j++)
				Union(party[i][j], party[i][j + 1]);
	}

	if (v.size() == 0)
	{
		cout << m;
		return 0;
	}

	for (int i = 0; i < m; i++)
	{
		bool check = true;

		for (int j = 0; j < party[i].size(); j++)
		{
			int people = party[i][j];

			if (Find(parent[people]) == Find(parent[v[0]]))
				check = false;
		}

		if (check)
			answer++;
	}

	cout << answer;

	return 0;
}
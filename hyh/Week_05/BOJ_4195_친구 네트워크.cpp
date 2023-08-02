#include <iostream>
using namespace std;
#include <map>
#include <set>

int parent[200001];
int people[200001];
map<string, int> m;
set<string> s;

int Find(int x)
{
	if (x == parent[x])
		return x;
	return parent[x] = Find(parent[x]);
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a != b)
	{
		parent[a] = b;
		people[b] += people[a];
		people[a] = 1;
	}
}

void reset()
{
	for (int i = 0; i <= 200000; i++)
	{
		parent[i] = i;
		people[i] = 1;
	}

	m.clear();
	s.clear();
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	for (int test = 0; test < t; test++)
	{
		reset();

		int n;
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			string a, b;
			cin >> a >> b;

			s.insert(a);
			if (m[a] == 0)
				m[a] = s.size();

			s.insert(b);
			if (m[b] == 0)
				m[b] = s.size();

			Union(m[a], m[b]);

			cout << people[Find(m[a])] << "\n";
		}
	}

	return 0;
}
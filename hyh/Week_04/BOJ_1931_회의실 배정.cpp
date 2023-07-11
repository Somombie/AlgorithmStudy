#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

vector<pair<int, int>> v;
int n;

bool compare(pair<int, int> a, pair<int, int> b)
{
	if (a.second != b.second)
		return a.second < b.second;

	return a.first < b.first;
}

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int start, end;
		cin >> start >> end;
		v.push_back(make_pair(start, end));
	}
	
	sort(v.begin(), v.end(), compare);

	int result = 0;
	int time = 0;


	for (int i = 0; i < v.size(); i++)
	{
		if (time <= v[i].first)
		{
			result++;
			time = v[i].second;
		}
	}

	cout << result;

	return 0;
}
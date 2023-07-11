#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int n, m;
vector<int> crane;
vector<int> box;
bool boxCheck[10001] = { false };

bool compare(int a, int b)
{
	return a > b;
}

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int craneWeight;
		cin >> craneWeight;
		crane.push_back(craneWeight);
	}

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int boxWeight;
		cin >> boxWeight;
		box.push_back(boxWeight);
	}
	
	sort(crane.begin(), crane.end());
	sort(box.begin(), box.end(), compare);

	if (crane[crane.size() - 1] < box[0])
	{
		cout << -1;
		return 0;
	}

	int result = 0;
	while (true)
	{
		if (box.size() == 0)
			break;

		for (int i = 0; i < crane.size(); i++)
		{
			for (int j = 0; j < box.size(); j++)
			{
				if (crane[i] >= box[j])
				{
					box.erase(box.begin() + j);
					break;
				}
			}
		}

		result++;
	}

	cout << result;

	return 0;
}
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

vector<int> v;
int n, m;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		long long int height;
		cin >> height;
		v.push_back(height);
	}
	
	int low = 1;
	int high = 2000000000;

	while(low <= high)
	{
		int mid = (low + high) / 2;
		long long int sum = 0;
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] - mid > 0)
				sum += v[i] - mid;
		}

		if (sum >= m)
			low = mid + 1;
		else
			high = mid - 1;
	}

	cout << low - 1;

	return 0;
}
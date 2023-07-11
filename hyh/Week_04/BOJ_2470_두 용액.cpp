#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <math.h>

vector<int> v;
int n;
int result = 2000000000;
int rMin = 0;
int rMax = 0;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	int start = 0;
	int end = v.size() - 1;

	while (start < end)
	{
		int add = v[start] + v[end];

		if (abs(add) < result)
		{
			result = abs(add);
			rMin = start;
			rMax = end;
		}

		if (add < 0)
			start++;
		else if (add > 0)
			end--;
		else
			break;
	}


	cout << v[rMin] << " " << v[rMax];
	

	return 0;
}
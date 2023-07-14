#include <iostream>
using namespace std;

int arr[100001];
int sum[100001];
int result = 0;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}


	for (int i = 2; i < n; i++)
	{
		result = max(result, sum[n] - sum[1] + sum[n] - sum[i] - arr[i]);
	}

	for (int i = 2; i <= n - 1; i++)
	{
		result = max(result, sum[n - 1] - sum[1] + arr[i]);
	}

	for (int i = n - 1; i > 1; i--)
	{
		result = max(result, sum[n - 1] - sum[0] + sum[i - 1] - sum[0] - arr[i]);
	}

	cout << result;

	return 0;
}
#include <iostream>
using namespace std;

int arr[1025][1025];
int dp[1025][1025];
int n, m;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int sum = 0;
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[i][j];
			sum += arr[i][j];

			dp[i][j] = sum + dp[i - 1][j];
		}
	}

	for (int i = 0; i < m; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		cout << dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1] << "\n";
	}

	return 0;
}
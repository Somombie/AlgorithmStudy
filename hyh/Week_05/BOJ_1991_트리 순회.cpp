#include <iostream>
using namespace std;

char v[27][2];
int n;

void preOrder(char x)
{
	if (x == '.')
		return;

	cout << x;
	preOrder(v[x - 'A'][0]);
	preOrder(v[x - 'A'][1]);
}
void inOrder(char x)
{
	if (x == '.')
		return;

	inOrder(v[x - 'A'][0]);
	cout << x;
	inOrder(v[x - 'A'][1]);
}
void postOrder(char x)
{
	if (x == '.')
		return;

	postOrder(v[x - 'A'][0]);
	postOrder(v[x - 'A'][1]);
	cout << x;
}

int main(void)
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		char parent, child1, child2;
		cin >> parent >> child1 >> child2;

		v[parent - 'A'][0] = child1;
		v[parent - 'A'][1] = child2;
	}

	
	preOrder('A');
	cout << "\n";
	inOrder('A');
	cout << "\n";
	postOrder('A');


	return 0;
}
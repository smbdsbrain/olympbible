#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif

	int a, b;
	cin >> a >> b;
	cout << std::min(a, b);
}
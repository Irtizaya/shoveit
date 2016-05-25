#include<iostream>
using namespace std;

int main()
{
	char c;
	FILE *f;
	f = fopen("lvl1.txt", "r");
	while (c = getc(f)!=EOF)
	{
		cout << c;
	}

	return 0;
}
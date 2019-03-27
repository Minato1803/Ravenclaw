#include <iostream>
#include <iomanip>
#include <string.h>
#include <fstream>
using namespace std;

void Gan(char *a, char *b)
{
	int len = strlen(a);
	for (int i = 0; i < len; i++)
	{
		b[i] = a[i];
	}
}

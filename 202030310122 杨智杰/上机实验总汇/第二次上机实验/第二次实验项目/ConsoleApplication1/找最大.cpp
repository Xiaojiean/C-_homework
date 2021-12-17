//#include "ConsoleApplication1.cpp"

int max(int p[])
{
	int j = p[0];
	for (int i = 1; i <= 4; ++i)
		if (p[i] > j)
			j = p[i];
	return j;
}
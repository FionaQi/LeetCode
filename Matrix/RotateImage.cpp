#include<iostream>
using namespace std;

template <typename T>
void swap(T &a, T &b)
{
	const T temp = a;
	a = b;
	b = temp;
}
void rotate(vector<vector<int> > &matrix) {
	int h = matrix.size();
	if (h < 2)   return;

	for (int i = 0; i < h / 2; i++) {
		swap<vector<int>>(matrix[i], matrix[h - 1 - i]);
	}
	for (int i = 1; i < h; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			swap<int>(matrix[i][j], matrix[j][i]);
		}
	}
}

void main()
{
}
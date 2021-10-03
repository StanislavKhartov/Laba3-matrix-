#include <iostream>
#include <vector>
#include <random>
#include <iomanip>
#include <set>

using namespace std;

int getValue(const vector<vector<int>> &matrix, int x, int y)
{
	if (x + y >= matrix.size())
	{
		return matrix[matrix.size() - y - 1][matrix.size() - x - 1];
	}
	else
	{
		return matrix[x][y];
	}
}

void fillingWithConsole(vector<vector<int>> &matrix, const int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; i + j <n; j++)
		{
			int tmp = 0;
			cin >> tmp;
			matrix[i].push_back(tmp);
		}
	}
}

int fillingWithRandom(vector<vector<int>>& matrix, const int n)
{
	cout << "Please enter the lower bound and upper bound of random numbers\n";
	int lower_bound;
	int upper_bound;
	cin >> lower_bound;
	cin >> upper_bound;
	if (upper_bound < lower_bound)
	{
		cout << "wrong data\n";
		delete[]&matrix;
		return 1;
	}
	srand(NULL);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; i + j < n; j++)
		{
			matrix[i].push_back(rand() % (upper_bound - lower_bound + 1) + lower_bound);
		}
	}
}

void callMenu()
{
	cout << "Please choose the way of filling matrix\n";
	cout << "1 - Filling with random\n";
	cout << "2 - Filling with console\n";
}

void fillingMatrix(vector<vector<int>>& matrix, const int size)
{
	callMenu();
	int way = 0;
	cin >> way;
	switch (way)
	{
	case 1:
		fillingWithRandom(matrix, size);
		return;
	case 2:
		fillingWithConsole(matrix, size);
		return;
	default:
		cout << "wrong data";
		return;
	}
}

void showMatrix(const vector<vector<int>>& matrix)
{
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix.size(); j++)
		{
			cout <<setw(8) << getValue(matrix, i, j)<< " ";
		}
		cout << "\n";
	}
}

long long multiplication(const vector<vector<int>>& matrix, const int j)
{
	long long tmp = 1;
	for (int i = 0; i < matrix.size(); i++)
	{
		if (getValue(matrix, j, i))
		{
			return -1;
		}
		tmp = tmp * getValue(matrix, j ,i);
	}
	return tmp;
}

void showMultiplications(const vector<vector<int>>& matrix)
{
	cout << "Multiplications in strings without negativ numbers:\n";
	for (int i = 0; i < matrix.size(); i++)
	{
		long long tmp = multiplication(matrix, i);
		if (tmp >= 0)
		{
			cout << tmp << "\n";
		}
	}
}

void searchMinInDiagonal(const vector<vector<int>>& matrix)
{
	if (matrix.size() <= 1)
	{
		cout << "There are no interesting diagonals\n";
		return;
	}
	cout << "Min sum in diagonls Without main diagonal:\n";
	long long tmp = 0;
	set <long long> diagonals;
	for (int i = 1; i < matrix.size(); i++)
	{
		int j = 0;
		int k = i;
		do
		{
			tmp = tmp + getValue(matrix, k, j);
			j++;
			k++;
		} while (j < matrix.size() && k < matrix.size());
		diagonals.insert(tmp);
		tmp = 0;
	}
	for (int i = 1; i < matrix.size(); i++)
	{
		int j = 0;
		int k = i;
		do
		{
			tmp = tmp + getValue(matrix, j, k);
			j++;
			k++;
		} while (j < matrix.size() && k < matrix.size());
		diagonals.insert(tmp);
		tmp = 0;
	}
	cout << *diagonals.begin();
}



int main()
{
	int n;
	cout << "Please, enter size of quadratic matrix\n";
	cin >> n;
	vector <vector<int>> matrix (n, vector<int>());
	fillingMatrix(matrix, n);
	showMatrix(matrix);
	showMultiplications(matrix);
	searchMinInDiagonal(matrix);
	//for (int i = 0; i < matrix.size(); i++)
	//{
	//	delete[]&matrix[i];
	//}
	//delete[]&matrix);
	return 0;
}

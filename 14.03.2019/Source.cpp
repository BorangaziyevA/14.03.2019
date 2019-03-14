#include<iostream>
#include<iomanip>
#include<Windows.h>
#include<fstream>

using namespace std;

void add_first_column(int **&pp, int n, int &m)
{
	int **tmp = new int*[n];

	for (size_t i = 0; i < n; i++)
	{
		tmp[i] = new int[m + 1];
	}

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			tmp[i][j + 1] = pp[i][j];
		}
	}
	for (size_t i = 0; i < n; i++)
	{
		tmp[i][0] = 0;
	}

	for (size_t i = 0; i < n; i++)
	{
		delete[] pp[i];
	}
	delete[] pp;

	pp = tmp;
	m++;
}

void delete_line(int **&p, int &n, int m, int k)
{
	int **tmp;
	int flag = 0;

	tmp = new int*[n-1];

	for (size_t i = 0; i < n-1; i++)
	{
		if (i == k)
		{
			flag = 1;
		}

		if (flag == 0)
		{
			tmp[i] = p[i];
		}
		else
			tmp[i] = p[i+1];
	}


	delete[] p;

	p = tmp;

	n--;
}

//void add_k_o_line(int **&p, int &n, int m, int k, int o)
//{
//	int **tmp;
//	tmp = new int*[n + 10];
//
//	for (size_t i = 0; i < n; i++)
//	{
//		tmp[i] = p[i];
//	}
//	for (size_t i = k; i < n; i++)
//	{
//		tmp[i + o] = p[i];
//	}
//	for (size_t i = k; i < n; i++)
//	{
//		tmp[i + o] = new int[m];
//		for (size_t j = 0; j < m; j++)
//		{
//			tmp[i + o][j] = 0;
//		}
//	}
//
//	delete[] p;
//
//	p = tmp;
//
//	n = n+o;
//}

void add_k_line(int **&p, int &n, int m, int k)
{
	int **tmp;
	tmp = new int*[n + 1];

	for (size_t i = 0; i < n; i++)
	{
		tmp[i] = p[i];
	}
	for (size_t i = k; i < n; i++)
	{
		tmp[i + 1] = p[i];
	}
	tmp[k] = new int[m];

	for (size_t i = 0; i < m; i++)
	{
		tmp[k][i] = 0;
	}

	delete[] p;

	p = tmp;

	n++;
}

//Добавляем в матрицу +1 строку в начало
void add_f_line(int **&p, int &n, int m)
{
	int **tmp;
	int k = 1;
	tmp = new int*[n + 1];

	for (size_t i = 0; i < n; i++)
	{
		tmp[k] = p[i];
		k++;
	}

	tmp[0] = new int[m];

	for (size_t i = 0; i < m; i++)
	{
		tmp[0][i] = 0;
	}

	delete[] p;

	p = tmp;

	n++;
}

//Добавляем в матрицу +1 строку в конец
void add_line(int **&p, int &n, int m)
{
	int **tmp;
	//Выделили место для нового указателя на указатели, только с количеством строк +1
	tmp = new int*[n + 1];
	//Скопировали указатель П в указатель ТМП
	for (int i = 0; i < n; i++)
		tmp[i] = p[i];
	//Так как последняя строка не заполнена, заполняем её указателями с размером М
	tmp[n] = new int[m];
	
	for (size_t i = 0; i < m; i++)
	{
		tmp[n][i] = 0;
	}

	delete[] p;

	p = tmp;

	n++;

}

void fill_matrix(int **p, int n, int m)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			p[i][j] = 1 + rand() % 2;
		}

	}
}

void print_matrix(int **p, int n, int m)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			cout << p[i][j] << " ";

		}
		cout << endl;
	}

}

int main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));

	int **pp, n, m;

	cin >> n >> m;

	int k;

	cout << "Vvedite stroku" << endl;
	cin >> k;

	pp = new int*[n];
	for (size_t i = 0; i < n; i++)
	{
		pp[i] = new int[m];
	}

	fill_matrix(pp,n,m);
	print_matrix(pp,n,m);
	add_first_column(pp, n, m);
	cout << endl << endl;
	print_matrix(pp, n, m);

	for (size_t i = 0; i < n; i++)
	{
		delete[] pp[i];
	}
	delete[] pp;

	system("pause");
	return 0;

}

/*int *p, **pp;

pp = new int*[5];

for (size_t i = 0; i < 5; i++)
{
pp[i] = new int[i+1];
}

for (size_t i = 0; i < 5; i++)
{
delete[] pp[i];
}
delete[] pp;
*/
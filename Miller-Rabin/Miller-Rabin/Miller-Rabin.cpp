// Miller-Rabin.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <random>

using namespace std;

long long power(long long x,unsigned long long y, long long p)
{
	long long res = 1;
	x = x % p;

	while(y>0)
	{
		if (y & 1)
			res = (res * x) % p;

		y = y >> 1;
		x = (x * x) % p;
	}

	return res;
}

bool millerTest(long long d, long long n)
{
	std::random_device rd;
	std::mt19937 mersenne(rd());
	long long a = 2 + mersenne() % (n - 4);

	long long x = power(a, d, n);

	if (x == 1 || x == n - 1)
		return true;

	while(d!=n-1)
	{
		x = (x * x) % n;
		d *= 2;

		if (x == 1)
			return false;
		if (x == n - 1)
			return true;
	}

	return false;
}

bool isPrime(long long n, int k)
{
	if (n <= 1 || n == 4) return false;
	if(n<=3) return true;

	long long d = n - 1;
	while (d % 2 == 0)
		d >>= 1;

	for (int i = 0; i < k; ++i)
		if (!millerTest(d, n))
			return false;

	return true;
}

int main()
{
	int count = 0;
	for(int i=0;i<100;++i)
	{
		if (isPrime(121, 1))
			count++;
	}

	cout << count;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

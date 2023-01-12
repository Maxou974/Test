#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

void	shuffle(int *tab, int size)
{
	std::random_device l;

	for (int i = 0; i < size; i++)
	{
		int ind = l() % size;
		int tmp = tab[i];
		tab[i] = tab[ind];
		tab[ind] = tmp;
	}
}

int main(int argc, char **argv)
{

	int n = std::stoi(argv[1]);

	int tab[n];

	for (int i = 0; i <  n; i++)
		tab[i] = i;
	
	shuffle(tab, n);

	for (int i = 0; i <  n; i++)
		std::cout << tab[i] << " ";
	std::cout << '\n';
}
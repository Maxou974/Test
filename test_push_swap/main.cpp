#include <iostream>
#include <cstdlib>
#include <ctime>

void	shuffle(int *tab, int size)
{
	for (int i = 0; i < size; i++)
	{
		int ind = rand() % size;
		int tmp = tab[i];
		tab[i] = tab[ind];
		tab[ind] = tmp;
	}
}

int main(int argc, char **argv)
{
	srand(time(NULL));

	int n = std::stoi(argv[1]);

	int tab[n];

	for (int i = 0; i <  n; i++)
		tab[i] = i;
	
	shuffle(tab, n);

	for (int i = 0; i <  n; i++)
		std::cout << tab[i] << " ";
	std::cout << '\n';
}
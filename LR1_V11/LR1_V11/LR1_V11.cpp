
#include <iostream>
#include <iomanip>

int main()
{
	setlocale(LC_ALL, "Russian");
	int **mas;
	int n, m, ini , inj;
    std::cout << "Введите количество строк и столбцов." << std::endl;
	std::cout << "Количество строк = ";
	std::cin >> n;
	std::cout << "Количество столбцов = ";
	std::cin >> m;
	if (n > 0 && m > 0) {
		mas = new int*[n];
		for (int j = 0; j < n; j++)
			mas[j] = new int[m];
		std::cout << "Введите элементы в массив:" << std::endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++) {
				std::cout << "[" << i << "]" << "[" << j << "]" << " = ";
				std::cin >> mas[i][j];
			}
		}
		std::cout << std::endl;
		std::cout << "Двухмерный  массив:" << std::endl;
		for (int i = 0; i < n; i++)
		{
			std::cout << std::endl;
			for (int j = 0; j < m; j++)
				std::cout << std::setw(4) << mas[i][j];
		}
		std::cout << std::endl;
		int min;
		bool Positive = false;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if ((i % 2 == 0) && (j % 2 == 0) && (mas[i][j] > 0))
				{
					min = mas[i][j];
					Positive = true;
				}
			}
		}
		if (Positive) {
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if ((i % 2 == 0) && (j % 2 == 0) && (mas[i][j] <= min)) {
						if (mas[i][j] > 0) {
							min = mas[i][j];
							ini = i;
							inj = j;
						}
					}
				}
			}
			std::cout << std::endl;
			std::cout << "Минимальный положительный элемент - " << min << std::endl << "Индексы - " << "[" << ini << "]" << "[" << inj << "]";
		}
		else
		{
			std::cout << std::endl;
			std::cout << "Отсутствует минимальный положительный элемент, находящийся на четной позиции!!!";
		}
		return 0;

		for (int i = 0; i < n; i++)
			delete[]mas;
	}
	else {
		std::cout << "Неверный ввод: Число строк(столбцов) должно быть положительным!";
	}
}

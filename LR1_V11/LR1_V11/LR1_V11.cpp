
#include <iostream>
#include <iomanip>

int main()
{
	setlocale(LC_ALL, "Russian");
	int **mas;
	int n, m, ini , inj;
    std::cout << "������� ���������� ����� � ��������." << std::endl;
	std::cout << "���������� ����� = ";
	std::cin >> n;
	std::cout << "���������� �������� = ";
	std::cin >> m;
	if (n > 0 && m > 0) {
		mas = new int*[n];
		for (int j = 0; j < n; j++)
			mas[j] = new int[m];
		std::cout << "������� �������� � ������:" << std::endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++) {
				std::cout << "[" << i << "]" << "[" << j << "]" << " = ";
				std::cin >> mas[i][j];
			}
		}
		std::cout << std::endl;
		std::cout << "����������  ������:" << std::endl;
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
			std::cout << "����������� ������������� ������� - " << min << std::endl << "������� - " << "[" << ini << "]" << "[" << inj << "]";
		}
		else
		{
			std::cout << std::endl;
			std::cout << "����������� ����������� ������������� �������, ����������� �� ������ �������!!!";
		}
		return 0;

		for (int i = 0; i < n; i++)
			delete[]mas;
	}
	else {
		std::cout << "�������� ����: ����� �����(��������) ������ ���� �������������!";
	}
}

// (вариант 6) Дана целочисленная матрица {Aij}i=1..n,j=1..m (n,m<=100). 
// Найти строку с наибольшим произведением элементов и заменить все элементы этой строки этим произведением.

#include <iostream>
int main()
{
    int n, m;
    int matrix[100][100];

    std::cout << "razmer matricy: ";
    std::cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            std::cin >> matrix[i][j];

    int maxRow = 0;
    int maxMult = 1;
    for (int i = 0; i < n; i++) 
    {
        int mult = 1;
        for (int j = 0; j < m; j++) 
        {
            mult *= matrix[i][j];
        }
        if (mult > maxMult)
        {
            maxMult = mult;
            maxRow = i;
        }
    }

    for (int j = 0; j < m; j++) 
    {
        matrix[maxRow][j] = maxMult;
    }

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            std::cout << matrix[i][j] << " ";
        }
    }

}
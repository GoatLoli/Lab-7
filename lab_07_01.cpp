//(вариант 6) Дана последовательность натуральных чисел {aj}j=1...n (n<=10000). Если в последовательности нет ни одного простого числа, упорядочить последовательность по неубыванию.


#include <iostream>

int main()
{
    const int n_max = 1000;
    int mas[n_max];

    int n;
    bool hasPrime = false;//нет простого

    std::cout << "kol-vo chisel: "; std::cin >> n;

    std::cout << "chisla v mas: ";
    for (int i = 0; i < n; i++)
    {
        std::cin >> mas[i];
    }

    //проверка что число простое
    for (int i = 0; i < n; i++)
    {
        int x = mas[i];
        for (int div = 2; div <= sqrt(x); div++)
            if (x % div == 0)
            {
                hasPrime = true;
                std::cout << "est' prosoe chislo";
                break;
            }
    }

    if (hasPrime == false)
    {
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                if (mas[i] > mas[j])
                {
                    int tmp = mas[i];
                    mas[i] = mas[j];
                    mas[j] = tmp;
                }
        for (int i = 0; i < n; i++)
        {
            std::cout << mas[i] << ", ";
        }
    }
}


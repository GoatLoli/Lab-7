//(вариант 6) Ввести последовательность натуральных чисел {Aj}j=1...n (n<=1000). Упорядочить последовательность по неубыванию суммы цифр числа, 
// числа с одинаковыми суммами цифр дополнительно упорядочить по неубыванию произведения цифр числа, числа с одинаковыми суммами цифр и 
// одинаковыми произведениями цифр дополнительно упорядочить по неубыванию самого числа.


#include <iostream>

int main()
{
    const int n_max = 1000;
    int mas[n_max];
    int sum[n_max];
    int mult[n_max];

    int n;

    std::cout << "kol-vo chisel: "; std::cin >> n;

    std::cout << "chisla v mas: ";
    for (int i = 0; i < n; i++)
    {
        std::cin >> mas[i];
    }
    //sum
    for (int i = 0; i < n; i++)
    {
        int x = mas[i];
        sum[i] = 0;
        while (x > 0)
        {
            sum[i] += x % 10;
            x /= 10;
        }
    }
    //mult
    for (int i = 0; i < n; i++)
    {
        int x = mas[i];
        mult[i] = 1;
        while (x > 0)
        {
            mult[i] *= x % 10;
            x /= 10;
        }
    }
    //sort
    for (int i = 0; i < n - 1; i++)
        for (int j = i = 1; j < n; j++)
        {
            if ((sum[i] > sum[j]) || ((sum[i] == sum[j]) && (mult[i] > mult[j])) ||
                ((sum[i] == sum[j]) && (mult[i] == mult[j]) && (mas[i] > mas[j])))
            {
                std::swap(mas[i], mas[j]);
                std::swap(sum[i], sum[j]);
                std::swap(mult[i], mult[j]);
            }
        }

    std::cout << "chislo mas: ";

    for (int i = 0; i < n; i++)
    {
        std::cout << mas[i] << ", ";
    }
}


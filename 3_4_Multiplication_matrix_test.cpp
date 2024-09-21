#include <iostream>
using namespace std;
// Функция для вывода матрицы
void output_matrix(float matrix[4])
{
    for (int i = 0; i < 4; i++)
    {
        cout << matrix[i] << " ";
    }
    cout << "\n";
}
int main()
{
    cout << "\033[2J\033[1;1H";
    cout << "This programme takes two matrices and multiplicates them\n";
    float matrix[4][4] = {{1.5, 3.2, 7.6, 3.11},
                          {3, 4, 2, 3},
                          {5, 7, 4, 8},
                          {6, 3, 9, 1}};
    float array[4] = {1.2, 3.5, 7.8, 3.2};
    float result_vec[4];
    // Блок произведения матрицы на вектор
    float sum = 0;
    for (int i = 0; i < 4; i++)
    {
        sum = 0;
        for (int j = 0; j < 4; j++)
        {
            sum += matrix[i][j] * array[j];
        }
        result_vec[i] = sum;
    }
    cout << "After multiplication we have next vector:\n";
    output_matrix(result_vec);
}

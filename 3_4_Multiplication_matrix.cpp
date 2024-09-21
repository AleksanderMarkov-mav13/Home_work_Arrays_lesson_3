#include <iostream>
using namespace std;
// Функция для вывода результирующего вектора
void output_matrix(float matrix[4])
{
    for (int i = 0; i < 4; i++)
    {
            cout << matrix[i]<< " ";
        }
        cout << "\n";
}
int main()
{
    cout << "\033[2J\033[1;1H";
    cout << "This programme takes two matrices and multiplicates them\n";
    float matrix [4][4];
    float array[4];
    float result_vec[4];
    // Ввод данных матрицы
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << "Input element " << i << " " << j << " of matrix\n";
            cin >> matrix[i][j];
        }
    }
    cout << "We have such matrix: \n";
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << "\t" << matrix[i][j];
        }
        cout << "\n";
    }
    // Ввод данных вектора
    for (int i = 0; i < 4; i++)
    {
        cout << "Input element " << i << " of the vector\n";
        cin >> array[i];
    }
    cout << "We have such vector: \n";
    output_matrix(array);
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

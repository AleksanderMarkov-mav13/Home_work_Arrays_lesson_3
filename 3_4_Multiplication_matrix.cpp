#include <iostream>
using namespace std;
// Функция для вывода матрицы
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
    cout << "This programme takes two matrices and multiplikates them\n";
    float matrix [4][4] = {{1, 3, 7, 3},
                            {3, 4, 2, 3},
                            {5, 7, 4, 8},
                            {6, 3, 9, 1}};
    float array[4] = { 1.2, 3.5, 7.8, 3.2 };

    
}

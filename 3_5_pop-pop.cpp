#include <iostream>
using namespace std;
// Функция для вывода матрицы
void filling_matrix(bool matrix[12][12])
{
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++) 
        {
            matrix[i][j] = true;
        }
    }
}

// Функция для вывода матрицы и контроля ее заполненности
bool show_matrix(bool matrix[12][12])
{
    int count = 0;
    bool result = true;
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            if (matrix[i][j]) {
                cout << 'O' << "  ";
                count ++;
            } else {
                cout << 'X' << "  ";
            }
        }
        cout << "\n";
    }
    if (count == 0) {
        result = false;
    }
    return result;
}
int main()
{
    cout << "\033[2J\033[1;1H";
    cout << "You have got membrane with many bubles. It's demensions are 12 x 12\n";
    bool matrix[12][12];
    cout << "You can burst some of bubles. Just input coordinates a district, where you want to do it\n";
    filling_matrix(matrix);
    bool flag = show_matrix(matrix);
    cout << "Результат " << flag;
}

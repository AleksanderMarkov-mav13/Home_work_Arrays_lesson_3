#include <iostream>
using namespace std;
// Функция для вывода матрицы
void output_matrix(int matrix[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}
// Функция для обнуления всех элементов матрицы, кроме диагональных
void clean_matrix(int matrix[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i != j) { matrix[i][j] = 0;}
        }
        cout << "\n";
    }
}
// Функция для сравнения двух матриц размером 4 * 4
bool compare_matrixes(int matr_one[4][4], int matr_two[4][4])
{
    bool result = false;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++) {
            if (matr_one[i][j] != matr_two[i][j]) {
                return result;
            }
        }
    }
    result = true;
    return result;
}

int main()
{
    cout << "\033[2J\033[1;1H";
    cout << "This programme compares two matrices, and, if they match,\n";
    cout << "filles one of them with nulles, except diagonal\n";
    cout << "Do you want to input all matrix elements from keyboard or use already prepeared matrices?\n";
    char choice;
    do {
        cout << "Input K - if you want to use Keyboard, or R - if you want to ready matrices\n";
        cin >> choice;
        if (choice != 'R' & choice != 'r' & choice != 'K' & choice != 'k')
        { cout << "Wrong input!";
        }
    } while (choice != 'R' & choice != 'r' & choice != 'K' & choice != 'k');
    int matr_one[4][4] = {{1, 3, 7, 3},
                          {3, 4, 2, 3},
                          {5, 7, 4, 8},
                          {6, 3, 9, 1}};
    int matr_two[4][4] = {{1, 3, 7, 3},
                          {3, 4, 2, 3},
                          {5, 7, 4, 8},
                          {6, 3, 9, 1}};
    if (choice == 'K' || choice == 'k')
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++) {
                cout << "Input element " << i << " " << j << "matrix one\n";
                cin >> matr_one[i][j];
            }
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++)    {
                cout << "Input element " << i << " " << j << "matrix two\n";
                cin >> matr_two[i][j];
            }
        }
    }
    cout << "Now we have two matrixes.\n";
    cout << "THis is matrix ONE: \n";
    output_matrix(matr_one);
    cout << "THis is matrix TWO: \n";
    output_matrix(matr_two);
    cout << "Let's compare them! \n";
    bool coincidence = compare_matrixes(matr_one, matr_two);
    if (!coincidence) {
        cout << "The two matrices do not match!";
    } else
    {
        cout << "These two matrices are equel!";
        clean_matrix(matr_one);
        cout << "The result of our action is: \n";
        output_matrix(matr_one);
    }

}
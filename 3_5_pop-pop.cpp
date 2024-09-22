#include <iostream>
using namespace std;
// Функция для заполнения матрицы
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
// Функция ввода и контроля ввода
int check_input (int coordinate)
{
    do {
        cin >> coordinate;
        if (coordinate < 1 || coordinate > 12)
        {
            cout << "This coordinate is out the map! Repeate your input, please\n";
        
        }
    } while (coordinate < 1 || coordinate > 12);
    return coordinate;
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
// Функция для отражения разрывов в матрице
bool bursting(bool matrix[12][12], int vert_beg, int horiz_beg, int vert_fin, int horiz_fin)
{
    if (vert_beg > vert_fin)
    {
        vert_fin = vert_fin + vert_beg;
        vert_beg = vert_fin - vert_beg;
        vert_fin = vert_fin - vert_beg;
    }
    if (horiz_beg > horiz_fin)
    {
        horiz_fin = horiz_fin + horiz_beg;
        horiz_beg = horiz_fin - horiz_beg;
        horiz_fin = horiz_fin - horiz_beg;
    }
    for (int i = vert_beg - 1; i < vert_fin; i++)
    {
        for (int j = horiz_beg - 1; j < horiz_fin; j++)
        {
            if (matrix[i][j])
            {
                matrix[i][j] = false;
                cout << "Pop! \n";
            }
        }
    }
    return matrix;
}

int main()
{
    cout << "\033[2J\033[1;1H";
    cout << "You have got membrane with many bubles. It's demensions are 12 x 12\n";
    bool matrix[12][12];
    cout << "You can burst some of bubles. Just input coordinates a district, where you want to do it\n";
    filling_matrix(matrix);
    bool flag = show_matrix(matrix);
    int vert_beg = 0, horiz_beg = 0, vert_fin = 0, horiz_fin = 0;
    do  {
        cout << "Input coordinates of the point for start bursting\n";
        cout << "Vertical ";
        vert_beg = check_input(vert_beg);
        cout << "Horizontal ";
        horiz_beg = check_input(horiz_beg);
        cout << "\nInput coordinates of the point for finish bursting\n";
        cout << "Vertical ";
        vert_fin = check_input(vert_fin);
        cout << "Horizontal ";
        horiz_fin = check_input(horiz_fin);
        cout << "So, we start bursting from the point " << vert_beg << ' ' << horiz_beg << "\n";
        cout << "And finish bursting to the point " << vert_fin << ' ' << horiz_fin << "\n";
        cout << "Let's start! \n";
        bursting(matrix, vert_beg, horiz_beg, vert_fin, horiz_fin);
        flag = show_matrix(matrix);
    } while (flag);
    cout << "That's all! All the bubbles were bursted!";
}

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
int main()
{
    cout << "\033[2J\033[1;1H";
    cout << "You have got membrane with many bubles. It's demensions are 12 x 12\n";
    bool matrix[12][12];
    cout << "You can burst some of bubles. Just input coordinates a district, where you want to do it\n";
    filling_matrix(matrix);
    bool flag = show_matrix(matrix);
    int vert_beg = 0, horiz_beg = 0, vert_fin = 0, horiz_fin = 0;
    if (flag) {
        cout << "Input vertical coordinate of point for start bursting\n";
        vert_beg = check_input(vert_beg);
        cout << "Input horizontal coordinate of point for start bursting\n";
        horiz_beg = check_input(horiz_beg);
        cout << "Input vertical coordinate of point for finish bursting\n";
        vert_fin = check_input(vert_fin);
        cout << "Input horizontal coordinate of point for finish bursting\n";
        horiz_fin = check_input(horiz_fin);
    }
    cout << "Start bursting from point " << vert_beg << ' ' << horiz_beg << "\n";
    cout << "Finish bursting from point " << vert_fin << ' ' << horiz_fin << "\n";
}

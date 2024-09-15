#include <iostream>
using namespace std;
void output_array (char array [] [3]) {
    for (int i = 0; i < 3; ++i)
    { 
        for (int j = 0; j < 3; ++j)
        {
            cout << ' ' << array [i][j] << ' ';
            if (j != 2) { cout << '|';}
        }
        cout << endl;
        if (i != 2)
        {
            cout << "-----------";
        }
        cout << endl;
    }
}


int main()
{
    cout << "\033[2J\033[1;1H";
    cout << "Here you can play the game of tic tac toe\n";
    char field [3][3]; // объявление массива
    for (int i = 0; i < 3; ++i) {  // заполнение массива
        for (int j = 0; j < 3; ++j) {
            field [i][j] = ' ';
        }
    }
    output_array (field);
    bool que_step = false; // флаг - определяет, чей ход. По умолчанию - Х
    int vert, horiz;
    for (int i = 0; i < 9; ++i)
    { 
        cout << "This is the step of player ";
        if (!que_step) {
            cout << "X";
        } else {
        cout << "O";
        }
        do {
            cout << "Input a string number ";
            cin >> vert;
            cout << "Input a column number ";
            cin >> horiz;
            if (vert < 1 || vert > 3 || horiz < 1 || horiz > 3) {
                cout << "Wrong input!\n";
            }
        } while (vert < 1 || vert > 3 || horiz < 1 || horiz > 3);
    }
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
bool check_array(char array[][3])
{
    bool result = false;
    for (int i = 0; i < 3; ++i)
    {
        if (array[i][0] == array[i][1] && array[i][0] == array[i][2] && array[i][0] != ' ') 
        {
            result = true;
            return result;
        }
        if (array[0][i] == array[1][i] && array[0][i] == array[2][i] && array[0][i] != ' ')
        {
            result = true;
            return result;
        }
    }
    if (array[1][1] == array[0][0] && array[1][1] == array[2][2] && array[0][0] != ' ')
    {
        result = true;
        return result;
    }
    if (array[1][1] == array[0][2] && array[1][1] == array[2][0] && array[1][1] != ' ')
    {
        result = true;
        return result;
    }
    return result;
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
    // output_array (field);
    bool que_step = false; // флаг - определяет, чей ход. По умолчанию - Х
    int vert, horiz;
    bool win = false;
    for (int i = 0; i < 9; ++i)
    { 
        cout << "This is the step of player ";
        if (!que_step) {
            cout << "X";
        } else {
        cout << "O";
        }
        cout << "\n";
        do {
            cout << "Input a string number ";
            cin >> vert;
            cout << "Input a column number ";
            cin >> horiz;
            if (vert < 1 || vert > 3 || horiz < 1 || horiz > 3) {
                cout << "Wrong input!\n";
            }
        } while (vert < 1 || vert > 3 || horiz < 1 || horiz > 3);
        vert --;
        horiz --;
        if (field[vert][horiz] != ' ')
        {
            cout << "This place has been busy already!\n";
        }
        else
        {
            if (que_step == false) {
                field[vert][horiz] = 'X';
                que_step = true;
            } else {
                field[vert][horiz] = 'O';
                que_step = false;
            }
        }
        output_array(field);
        win = check_array(field);
        if (win) {
            cout << "The player ";
            if (que_step) {
                cout << "X has won !!!";
            } else {
                cout << "O has won !!!";
            }
            break;
        }
    }
    if (!win) {
    cout << "The result of the game is a draw! \n";
    }
}
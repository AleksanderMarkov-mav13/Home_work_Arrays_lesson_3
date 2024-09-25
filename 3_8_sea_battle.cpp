#include <iostream>
using namespace std;
// Функция для вывода матрицы
void show_matrix(bool matrix[10][10])
{
    cout << " ";
    for (int j = 0; j < 10; j++)
    {
        cout << " " << j << " ";
    }
    cout << "\n";
    for (int i = 0; i < 10; i++)
    {
        cout << i;
        for (int j = 0; j < 10; j++)
        {
            if (matrix[i][j])
            {
                cout << " # ";
            } else {
                cout << " _ ";
            }
        }
        cout << "\n";
    }
    
}

// Функция для заполнения матриц
void filling_matrix(bool matrix[10][10])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            matrix[i][j] = false;
        }
    }
}
// Функция - контроль параметрам поля
int check_field_parametr (int n) {
    if (n < 0 || n > 9) {
        cout << "Wrong input! Please, repeat ";
        cin >> n;
    }
    return n;
}
// Функция - контроль занятости полей
bool check_busy_place(bool matrix[10][10], int size, int vert, int vert_diff, int horiz, int horiz_diff)
{
    bool result = true;
    for (int j = 0; j < size; j++)
    {
        if (vert_diff > horiz_diff)
        {
            if (matrix[vert + j][horiz])
            {
                result = false;
                cout << "Sorry, but some of these places are busy with other ship! Please, repeat input coordinates\n";
                break;
            }
        }
        else
        {
            if (matrix[vert][horiz + j])
            {
                result = false;
                cout << "Sorry, but some of these places are busy with other ship! Please, repeat input coordinates\n";
                break;
            }
        }
    }
    return result;
}

// Функция для расстановки кораблей
bool arranging_ships(bool matrix[10][10])
{
    int list_ships [10] = {1, 1, 1, 1, 2, 2, 2, 3, 3, 4};
    // int list_ships[num_ships] = {2, 2, 2, 3, 3, 4};
    int vert, horiz;
    int vert_2, horiz_2;
    int vert_diff = 0, horiz_diff = 0;
    for (int i = 0; i < 10; i++)
    {
        cout << "Your ship number " << i + 1 << " should contain " << list_ships[i] << " cell";
            if (list_ships[i] > 1)
        {
            cout << "es\n";
        }
        cout << "\n";
        // Ввод кораблей в одну клетку
        if (list_ships[i] == 1) {
            cout << "Input coordinate your ship: \n";
            do
            {
                cout << "Vertical: ";
                cin >> vert;
                vert = check_field_parametr(vert);
                cout << "Horizontal: ";
                cin >> horiz;
                horiz = check_field_parametr(horiz);
                // Контроль занятости введенного поля
                if (matrix[vert][horiz])
                {
                    cout << "Sorry, but this place is busy with other ship! Please, repeat input coordinates\n";
                }
            } while (matrix[vert][horiz]);
            matrix[vert][horiz] = true;
            show_matrix(matrix);
        } 
        // Ввод кораблей в несколько клеток
        else {
            bool flag = true;
            do {
                cout << "Input coordinate the first sell of your ship: \n";
                cout << "Vertical: ";
                cin >> vert;
                vert = check_field_parametr(vert);
                cout << "Horizontal: ";
                cin >> horiz;
                horiz = check_field_parametr(horiz);
                cout << "Input coordinate the last sell of your ship: \n";
                cout << "Vertical: ";
                cin >> vert_2;
                vert_2 = check_field_parametr(vert_2);
                cout << "Horizontal: ";
                cin >> horiz_2;
                horiz_2 = check_field_parametr(horiz_2);
                if (vert > vert_2) swap(vert, vert_2);
                if (horiz > horiz_2) swap(horiz, horiz_2);
                // Контроль соответствия длины корабля параметрам
                vert_diff = abs (vert - vert_2);
                horiz_diff = abs(horiz - horiz_2);
                // cout << "Vertical: " << vert << " | " << vert_2 << " | " << vert_diff << "\n";
                // cout << "Horizontal: " << horiz << " | " << horiz_2 << " | " << horiz_diff << "\n";
                if (((vert_diff + horiz_diff) == list_ships[i] - 1) & (vert_diff == 0 || horiz_diff == 0 ))
                {
                    flag = true;
                } else {
                    flag = false;
                    cout << "Inputed data are not suitable parametres of your ship! Please, repeat input \n";
                }
                // Контроль занятости полей - через функцию
                if (flag)
                {
                    flag = check_busy_place(matrix, list_ships[i], vert, vert_diff, horiz, horiz_diff);
                }
            } while (!flag);
            // Заполнение матрицы - после всех контролей
            for (int j = 0; j < list_ships[i]; j++)
            {
                if (vert_diff > horiz_diff)
                {
                   matrix[vert + j][horiz] = true;
                }
                else
                {
                    matrix[vert][horiz + j] = true;
                }
            }
            show_matrix(matrix);
        }
    }
    return matrix;
}
int main()
{
    cout << "\033[2J\033[1;1H";
    cout << "You can play sea_battle with this programme\n";
    bool field_one[10][10];
    bool field_two[10][10];
    filling_matrix(field_one);
    filling_matrix(field_two);
    cout << "Player one, arrange your ships! \n";
    field_one[10][10] = arranging_ships(field_one);
    show_matrix(field_one);
}
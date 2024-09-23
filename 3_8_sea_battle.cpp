#include <iostream>
using namespace std;
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
// Функция для расстановки кораблей
bool arranging_ships(bool matrix[10][10])
{
    int list_ships [10] = {1, 1, 1, 1, 2, 2, 2, 3, 3, 4};
    int vert, horiz;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < list_ships[i]; j++)
        {
            cout << "Input coordinate your ships number " << i << "\n";
            cout << "It should contain  " << list_ships[i] << " cell";
            if (list_ships[i] > 1) {cout << "es";}
            cout << "\n";
            do {
            // Ввод координат и контроль соотвествия их параметрам поля
            do {cout << "Vertical: ";
            cin >> vert;
            if (vert < 0 || vert > 9) cout << "Wrong input! Please, repeat ";
            } while (vert < 0 || vert > 9);
            do {cout << "Horizontal: ";
            cin >> horiz;
            if (horiz < 0 || horiz > 9) cout << "Wrong input! Please, repeat ";
            } while (horiz < 0 || horiz > 9);
            // Контроль занятости введенного поля
            if (matrix[vert][horiz]) {
                cout << "Sorry, but this place is busy with other ship! Please, repeat input coordinates\n";
            }
            } while (matrix[vert][horiz]);
            matrix[vert][horiz] = true;
        }
    }
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

}
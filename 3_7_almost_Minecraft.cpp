#include <iostream>
using namespace std;
int main()
{
    cout << "\033[2J\033[1;1H";
    cout << "This programme can show you horizontal slice of our world\n";
    int matrix[5][5];
    // Заполнение матрицы
    cout << "Let's create our world! Fill the matrix with hights\n";
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> matrix[i][j];
        }
        cout << "\n";
    }
    cout << "It's our world - view from above:\n";
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << matrix[i][j];
            cout << " ";
        }
        cout << "\n";
    }
    
}
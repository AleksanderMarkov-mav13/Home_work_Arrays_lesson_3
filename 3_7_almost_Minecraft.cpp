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
            // Контроль ввода высот
            if (matrix[i][j] < 0 || matrix[i][j] > 10)
            {
                cout << "Incorrect hight: " << matrix[i][j] << ". It have to be from 0 to 9.\n ";
                cout << "Please, repeat your input ";
                cin >> matrix[i][j];
            }
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
    int slice;
    do {
        cout << "Input number of slice from that you want to see our world \n";
        cout << "If you want to stop review: input '-1' \n";
        cin >> slice;
        if (slice == -1) {
            break;
        }
        else if (slice < 0 || slice > 10)
        {
            cout << "Incorrect number of slice: " << slice << ". It have to be from 0 to 9.\n ";
            cout << "Please, repeat your input ";
            cin >> slice;
        }
        cout << "It's our world - view from slice " << slice << ":\n ";
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if ((matrix[i][j] - slice + 1) > 0)
                {
                    cout << '1';
                }
                else
                {
                    cout << '0';
                }
                cout << " ";
            }
            cout << "\n";
    }
    } while (true);
}
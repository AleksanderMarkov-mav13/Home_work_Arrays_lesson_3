#include <iostream>
using namespace std;
int main()
{
    cout << "\033[2J\033[1;1H";
    cout << "This programme filles matrix by the way, how snake passages\n";
    int matrix[5][5];
    int filler = 0; 
    // filling matrix
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matrix[i][j + (i%2 * (4-2*j))] = filler;
            filler ++;
        }
    }
    // showing matrix
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << "\t" << matrix[i][j] << ' ';
        }
        cout << "\n";
    }
}
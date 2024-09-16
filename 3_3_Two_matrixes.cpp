#include <iostream>
using namespace std;
int main()
{
    cout << "\033[2J\033[1;1H";
    cout << "This programm compares two matrixes\n";
    // объявление массивов
    int matr_one[4][4] = {{1, 2, 7, 3},
                          {3, 4, 2, 3},
                          {5, 7, 4, 8},
                          {6, 3, 9, 0}};
    int matr_two[4][4] = {{1, 2, 7, 3},
                          {3, 4, 2, 3},
                          {5, 7, 4, 8},
                          {6, 3, 9, 0}};
                          
}
#include <iostream>
using namespace std;
void output_matrix (int matrix[4][4]) 
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

bool compare_matrixes(int matr_one[4][4], int matr_two[4][4])
{
    bool result = false;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++) {
            if (matr_one[i][j] != matr_two[i][j]) {
                return result;
            }
        }
    }
    result = true;
    return result;
}
int main()
{
    cout << "\033[2J\033[1;1H";
    cout << "This programm compares two matrixes\n";
    // объявление массивов
    int matr_one[4][4] = {{1, 3, 7, 3},
                          {3, 4, 2, 3},
                          {5, 7, 4, 8},
                          {6, 3, 9, 0}};
    int matr_two[4][4] = {{1, 2, 7, 3},
                          {3, 4, 2, 3},
                          {5, 7, 4, 8},
                          {6, 3, 9, 0}};
    // for (int i = 0; i < 4; i++) {
    //    for (int j = 0; j < 4; j++) {
    //        cout << "Input element " << i << " " << j << "matrix one\n";
    //        cin >> matr_one[i][j];
    //    }
    // }
    //for (int i = 0; i < 4; i++) {
    //    for (int j = 0; j < 4; j++)    {
    //        cout << "Input element " << i << " " << j << "matrix two\n";
    //        cin >> matr_two[i][j];
    //    }
    //}
    cout << "Now we have two matrixes.";
    cout << "THis is matrix ONE: \n";
    output_matrix(matr_one);
    cout << "THis is matrix TWO: \n";
    output_matrix(matr_two);
    cout << "Let's compare them! \n";
    bool coincidence = compare_matrixes(matr_one, matr_two);
    cout << coincidence;
    // if (coincidence) {
    //    matr_one = clean_matrix(matr_one); }
}
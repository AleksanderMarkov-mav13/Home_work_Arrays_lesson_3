#include <iostream>
#include <vector>
using namespace std;
void input (int array[2][6])
{
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 6; j++) {
            cout << array[i][j] << " ";
        }
        cout << "\n";
    }
}
int main()
{
    cout << "\033[2J\033[1;1H";
    int tableware[2][6] = {{4, 3, 3, 3, 3, 3}, {4, 3, 3, 3, 3, 3}};
    int plates[2][6] = {{3, 2, 2, 2, 2, 2}, {3, 2, 2, 2, 2, 2}};
    int chaires[2][6] = {{1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1}};
    // Пришедшая на пятое место первого ряда дама привела с собой ребёнка, и поэтому на это место был приставлен ещё один стул.
    chaires[0][4] +=1;
    // С третьего места во втором ряду в неизвестном направлении была украдена ложка. Одна из VIP-персон (любая) поделилась своей ложкой с тем, кто остался без ложки, и стала есть суп десертной
    tableware[1][0] -= 1;
    // За ненадобностью официант забрал у VIP-гостя одну десертную тарелку
    plates[1][0] -= 1;
    cout << "In the finish of banquet we have:\n";
    cout << "Tableware\n";
    input (tableware);
    cout << "Plates\n";
    input(plates);
    cout << "Chaires\n";
    input(chaires);
}
//ітераційний спосіб
// Варіант 9


#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

// Оголошення функцій
void Create(vector<vector<int>>& R, const int Low, const int High);
void Print(const vector<vector<int>>& R);
void SortColumns(vector<vector<int>>& R);
void ChangeColumns(vector<vector<int>>& R, const int col1, const int col2);
void Calc(vector<vector<int>>& R, int& S, int& k);

int main()
{
    srand((unsigned)time(NULL));

    const int rowCount = 7;
    const int colCount = 5;

    const int Low = -6;
    const int High = 31;

    // Створення матриці
    vector<vector<int>> R(rowCount, vector<int>(colCount));

    // Заповнення матриці випадковими числами
    Create(R, Low, High);

    // Виведення початкової матриці
    cout << "Initial matrix:" << endl;
    Print(R);

    // Сортування стовпчиків матриці
    SortColumns(R);

    // Виведення відсортованої матриці
    cout << "Sorted matrix:" << endl;
    Print(R);

    // Обчислення суми та кількості елементів
    int S = 0;
    int k = 0;

    Calc(R, S, k);

    cout << "S = " << S << endl;
    cout << "k = " << k << endl;

    // Виведення матриці після заміни елементів нулями
    cout << "Modified matrix:" << endl;
    Print(R);

    return 0;
}

// Функція створення та заповнення матриці
void Create(vector<vector<int>>& R, const int Low, const int High)
{
    for (int i = 0; i < R.size(); i++)
        for (int j = 0; j < R[i].size(); j++)
            R[i][j] = Low + rand() % (High - Low + 1);
}

// Функція виведення матриці
void Print(const vector<vector<int>>& R)
{
    for (int i = 0; i < R.size(); i++)
    {
        for (int j = 0; j < R[i].size(); j++)
            cout << setw(4) << R[i][j];

        cout << endl;
    }

    cout << endl;
}

// Функція сортування стовпчиків матриці
void SortColumns(vector<vector<int>>& R)
{
    int colCount = R[0].size();

    for (int i = 0; i < colCount - 1; i++)
    {
        for (int j = 0; j < colCount - i - 1; j++)
        {
            if ((R[0][j] > R[0][j + 1])
                ||
                (R[0][j] == R[0][j + 1] &&
                 R[1][j] > R[1][j + 1])
                ||
                (R[0][j] == R[0][j + 1] &&
                 R[1][j] == R[1][j + 1] &&
                 R[2][j] < R[2][j + 1]))
            {
                ChangeColumns(R, j, j + 1);
            }
        }
    }
}

// Функція обміну двох стовпчиків
void ChangeColumns(vector<vector<int>>& R, const int col1, const int col2)
{
    for (int i = 0; i < R.size(); i++)
    {
        int tmp = R[i][col1];
        R[i][col1] = R[i][col2];
        R[i][col2] = tmp;
    }
}

// Функція обчислення суми та кількості
// і заміни потрібних елементів нулями
void Calc(vector<vector<int>>& R, int& S, int& k)
{
    S = 0;
    k = 0;

    for (int i = 0; i < R.size(); i++)
    {
        for (int j = 0; j < R[i].size(); j++)
        {
            if (R[i][j] > 0 && i % 3 != 0 && j % 3 != 0)
            {
                S += R[i][j];
                k++;
                R[i][j] = 0;
            }
        }
    }
}

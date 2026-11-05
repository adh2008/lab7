
// Lab_7_2.cpp
// Лабораторна робота № 7.1
// Варіант 9
// Рекурсивний спосіб

#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

// Оголошення функцій
void Create(vector<vector<int>>& R, const int Low, const int High);
void CreateRecursive(vector<vector<int>>& R, const int Low, const int High, int index);

void Print(const vector<vector<int>>& R);
void PrintRecursive(const vector<vector<int>>& R, int index);

void SortColumns(vector<vector<int>>& R);
void SortColumnsRecursive(vector<vector<int>>& R, int pass, int j);

void ChangeColumns(vector<vector<int>>& R, const int col1, const int col2);
void ChangeColumnsRecursive(vector<vector<int>>& R, int col1, int col2, int i);

void Calc(vector<vector<int>>& R, int& S, int& k);
void CalcRecursive(vector<vector<int>>& R, int index, int& S, int& k);

int main()
{
    srand((unsigned)time(NULL));

    const int rowCount = 7;
    const int colCount = 5;

    const int Low = -6;
    const int High = 31;

    // Створення матриці
    vector<vector<int>> R(rowCount, vector<int>(colCount));

    // Заповнення матриці
    Create(R, Low, High);

    // Виведення початкової матриці
    cout << "Initial matrix:" << endl;
    Print(R);

    // Сортування стовпчиків
    SortColumns(R);

    // Виведення відсортованої матриці
    cout << "Sorted matrix:" << endl;
    Print(R);

    // Обчислення суми та кількості
    int S = 0;
    int k = 0;

    Calc(R, S, k);

    cout << "S = " << S << endl;
    cout << "k = " << k << endl;

    // Виведення модифікованої матриці
    cout << "Modified matrix:" << endl;
    Print(R);

    return 0;
}

// Функція створення матриці
void Create(vector<vector<int>>& R, const int Low, const int High)
{
    CreateRecursive(R, Low, High, 0);
}

// Рекурсивне заповнення матриці
void CreateRecursive(vector<vector<int>>& R, const int Low, const int High, int index)
{
    int total = R.size() * R[0].size();

    if (index >= total)
        return;

    int i = index / R[0].size();
    int j = index % R[0].size();

    R[i][j] = Low + rand() % (High - Low + 1);

    CreateRecursive(R, Low, High, index + 1);
}

// Функція виведення матриці
void Print(const vector<vector<int>>& R)
{
    PrintRecursive(R, 0);
    cout << endl;
}

// Рекурсивне виведення матриці
void PrintRecursive(const vector<vector<int>>& R, int index)
{
    int total = R.size() * R[0].size();

    if (index >= total)
        return;

    int colCount = R[0].size();

    cout << setw(4) << R[index / colCount][index % colCount];

    if ((index + 1) % colCount == 0)
        cout << endl;

    PrintRecursive(R, index + 1);
}

// Функція сортування стовпчиків
void SortColumns(vector<vector<int>>& R)
{
    SortColumnsRecursive(R, 0, 0);
}

// Рекурсивне сортування стовпчиків
void SortColumnsRecursive(vector<vector<int>>& R, int pass, int j)
{
    int colCount = R[0].size();

    if (pass >= colCount - 1)
        return;

    if (j >= colCount - pass - 1)
    {
        SortColumnsRecursive(R, pass + 1, 0);
        return;
    }

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

    SortColumnsRecursive(R, pass, j + 1);
}

// Функція обміну двох стовпчиків
void ChangeColumns(vector<vector<int>>& R, const int col1, const int col2)
{
    ChangeColumnsRecursive(R, col1, col2, 0);
}

// Рекурсивний обмін стовпчиків
void ChangeColumnsRecursive(vector<vector<int>>& R, int col1, int col2, int i)
{
    if (i >= R.size())
        return;

    int tmp = R[i][col1];
    R[i][col1] = R[i][col2];
    R[i][col2] = tmp;

    ChangeColumnsRecursive(R, col1, col2, i + 1);
}

// Функція обчислення суми та кількості
void Calc(vector<vector<int>>& R, int& S, int& k)
{
    S = 0;
    k = 0;

    CalcRecursive(R, 0, S, k);
}

// Рекурсивне обчислення та заміна елементів
void CalcRecursive(vector<vector<int>>& R, int index, int& S, int& k)
{
    int total = R.size() * R[0].size();

    if (index >= total)
        return;

    int colCount = R[0].size();

    int i = index / colCount;
    int j = index % colCount;

    if (R[i][j] > 0 && i % 3 != 0 && j % 3 != 0)
    {
        S += R[i][j];
        k++;

        R[i][j] = 0;
    }

    CalcRecursive(R, index + 1, S, k);
}

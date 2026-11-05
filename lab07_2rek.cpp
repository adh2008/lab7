// Рекурсивний спосіб
// Варіант 9

#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Оголошення функцій
void Create(vector<vector<int>>& R, const int Low, const int High);
void CreateRecursive(vector<vector<int>>& R, const int Low, const int High, int index);

void Print(const vector<vector<int>>& R);
void PrintRecursive(const vector<vector<int>>& R, int index);

void FindRowMinimumRecursive(const vector<vector<int>>& R,
    int row, int col, int& minElement);

void SearchLargestMinRecursive(const vector<vector<int>>& R,
    int row, int& result, bool& found);

bool SearchLargestMin(const vector<vector<int>>& R, int& result);

int main()
{
    srand((unsigned)time(NULL));

    const int rowCount = 5;
    const int colCount = 4;

    const int Low = -20;
    const int High = 30;

    // Створення матриці
    vector<vector<int>> R(rowCount, vector<int>(colCount));

    // Заповнення матриці
    Create(R, Low, High);

    // Виведення матриці
    cout << "Initial matrix:" << endl;
    Print(R);

    // Пошук найбільшого з мінімальних елементів
    int result;

    if (SearchLargestMin(R, result))
        cout << "Largest of row minimums = " << result << endl;
    else
        cout << "There are no odd rows." << endl;

    return 0;
}

// Функція створення матриці
void Create(vector<vector<int>>& R, const int Low, const int High)
{
    CreateRecursive(R, Low, High, 0);
}

// Рекурсивне заповнення матриці
void CreateRecursive(vector<vector<int>>& R,
    const int Low, const int High, int index)
{
    int total = R.size() * R[0].size();

    if (index >= total)
        return;

    int colCount = R[0].size();

    int i = index / colCount;
    int j = index % colCount;

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

    cout << setw(5) << R[index / colCount][index % colCount];

    if ((index + 1) % colCount == 0)
        cout << endl;

    PrintRecursive(R, index + 1);
}

// Рекурсивний пошук мінімуму в одному рядку
void FindRowMinimumRecursive(const vector<vector<int>>& R,
    int row, int col, int& minElement)
{
    if (col >= R[row].size())
        return;

    if (R[row][col] < minElement)
        minElement = R[row][col];

    FindRowMinimumRecursive(R, row, col + 1, minElement);
}

// Рекурсивний пошук найбільшого серед мінімумів
void SearchLargestMinRecursive(const vector<vector<int>>& R,
    int row, int& result, bool& found)
{
    if (row >= R.size())
        return;

    int minElement = R[row][0];

    FindRowMinimumRecursive(R, row, 1, minElement);

    if (!found || minElement > result)
    {
        result = minElement;
        found = true;
    }

    SearchLargestMinRecursive(R, row + 2, result, found);
}

// Функція пошуку результату
bool SearchLargestMin(const vector<vector<int>>& R, int& result)
{
    if (R.empty())
        return false;

    bool found = false;

    SearchLargestMinRecursive(R, 0, result, found);

    return found;
}

// Ітераційний спосіб
// Варіант 9

#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Оголошення функцій
void Create(vector<vector<int>>& R, const int Low, const int High);
void Print(const vector<vector<int>>& R);
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
    // непарних рядків
    int result;

    if (SearchLargestMin(R, result))
        cout << "Largest of row minimums = " << result << endl;
    else
        cout << "There are no odd rows." << endl;

    return 0;
}

// Функція заповнення матриці
void Create(vector<vector<int>>& R, const int Low, const int High)
{
    for (int i = 0; i < R.size(); i++)
    {
        for (int j = 0; j < R[i].size(); j++)
        {
            R[i][j] = Low + rand() % (High - Low + 1);
        }
    }
}

// Функція виведення матриці
void Print(const vector<vector<int>>& R)
{
    for (int i = 0; i < R.size(); i++)
    {
        for (int j = 0; j < R[i].size(); j++)
        {
            cout << setw(5) << R[i][j];
        }

        cout << endl;
    }

    cout << endl;
}

// Функція пошуку найбільшого з мінімальних
// елементів непарних рядків
bool SearchLargestMin(const vector<vector<int>>& R, int& result)
{
    if (R.empty())
        return false;

    bool found = false;

    for (int i = 0; i < R.size(); i += 2)
    {
        int minElement = R[i][0];

        // Пошук мінімального елемента рядка
        for (int j = 1; j < R[i].size(); j++)
        {
            if (R[i][j] < minElement)
                minElement = R[i][j];
        }

        // Пошук найбільшого серед мінімумів
        if (!found || minElement > result)
        {
            result = minElement;
            found = true;
        }
    }

    return found;
}

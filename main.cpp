#include <iostream>
#include <cmath>
using namespace std;

// Завдання 1 (If37): 
// Для заданого дійсного x знайти значення функції q(x):
// q(x) = -2x, якщо x < 0
// q(x) = x^2 + 1, якщо 0 ≤ x ≤ 2
// q(x) = 5, якщо x > 2

void task_if37()
{
    cout << "Завдання 1 (If37)" << endl;
    double x;
    cout << "Введiть значення x: ";
    cin >> x;

    // Перевірка на коректність введення
    if (!cin) {
        cerr << "Помилка: введено нечислове значення!" << endl;
        return;
    }

    double q; // результат обчислення функції

    if (x < 0)
        q = -2 * x;
    else if (x <= 2)
        q = x * x + 1;
    else
        q = 5;

    cout << "Результат q(x) = " << q << endl;
}

// Завдання 2 (If15): 
// Дано три числа. Знайти суму двох найбiльших з них.

void task_if15()
{
    cout << "Завдання 2 (If15)" << endl;
    double a, b, c;
    cout << "Введiть три числа (a, b, c): ";
    cin >> a >> b >> c;

    if (!cin) {
        cerr << "Помилка: введено нечислове значення!" << endl;
        return;
    }

    double sum;
    // сума двох найбільших = (a + b + c) - мінімальне з трьох
    double min_val = a;
    if (b < min_val) min_val = b;
    if (c < min_val) min_val = c;

    sum = a + b + c - min_val;

    cout << "Сума двох найбiльших чисел = " << sum << endl;
}


// Завдання 3 (геометричне, 17 вар.)
// Перевірити, чи потрапляє точка (x, y) у заштриховану область

void task_geom()
{
    cout << "Завдання 3 (Геометричне, 17 вар.)" << endl;

    double x, y, R;
    
    // Додаємо введення радіуса
    cout << "Введiть радiус R: ";
    cin >> R;

    cout << "Введiть координати точки (x, y): ";
    cin >> x >> y;

    if (!cin) {
        cerr << "Помилка: введено нечислове значення!" << endl;
        return;
    }
  
    // 1. Перевірка нижньої частини (3-тя чверть)
    // x <= 0, y <= 0, та знаходиться всередині кола радіуса R
    bool part1 = (x <= 0 && y <= 0 && (x * x + y * y <= R * R));

    // 2. Перевірка верхньої частини (1-ша чверть)
    // x >= 0, всередині кола, та вище прямої лінії.
    // Пряма проходить через (0, R/2), рівняння: y = x + R/2
    bool part2 = (x >= 0 && (x * x + y * y <= R * R) && (y >= x + R / 2.0));

    // Якщо точка потрапляє хоча б в одну з частин
    bool inside = part1 || part2;

    if (inside)
        cout << "Точка (" << x << ", " << y << ") належить заштрихованiй областi." << endl;
    else
        cout << "Точка (" << x << ", " << y << ") НЕ належить заштрихованiй областi." << endl;
}


// Головна функція програми (меню вибору завдань)
int main()
{
    int menu;
    cout << "Меню" << endl;
    cout << "1 - Завдання 1 (If37)" << endl;
    cout << "2 - Завдання 2 (If15)" << endl;
    cout << "3 - Завдання 3 (Геометрiя)" << endl;
    cout << "Оберiть номер завдання: ";
    cin >> menu;

    if (!cin) {
        cerr << "Помилка введення!" << endl;
        return 1;
    }

    switch (menu) {
        case 1: task_if37(); break;
        case 2: task_if15(); break;
        case 3: task_geom(); break;
        default:
            cout << "Помилка: доступнi лише завдання 1–3!" << endl;
            break;
    }

    system("pause");
    return 0;
}

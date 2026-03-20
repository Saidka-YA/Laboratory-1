#include <iostream>
#include <cmath>

using namespace std;

double S; // глобальная переменная площади

int main() {
    setlocale(LC_ALL, "rus");
    double a, b, c, d;
    double h, P;

    cout << "Введите сторону a: ";
    cin >> a;
    while (cin.fail() || a <= 0) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Пожалуйста, введите число!: ";
        }
        else {
            cout << "Некорректное число, введите новое число: ";
        }
        cin >> a;
    }

    cout << "Введите сторону b: ";
    cin >> b;
    while (cin.fail() || b <= 0) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Пожалуйста, введите число!: ";
        }
        else {
            cout << "Некорректное число, введите новое число: ";
        }
        cin >> b;
    }

    cout << "Введите сторону c: ";
    cin >> c;
    while (cin.fail() || c <= 0) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Пожалуйста, введите число!: ";
        }
        else {
            cout << "Некорректное число, введите новое число: ";
        }
        cin >> c;
    }

    cout << "Введите сторону d: ";
    cin >> d;
    while (cin.fail() || d <= 0) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Пожалуйста, введите число!: ";
        }
        else {
            cout << "Некорректное число, введите новое число: ";
        }
        cin >> d;
    }

    
    if (a == 0 && b == 0 && c == 0 && d == 0) {
        cout << "ОШИБКА!!! СТОРОНЫ РАВНЫ 0" << endl;
    }

    
    bool valid = true;

    if (a == b) {
        cout << "ОШИБКА!!! ОСНОВАНИЯ НЕ МОГУТ БЫТЬ РАВНЫ!!!" << endl;
        valid = false;
    }

    double diff = (b > a) ? (b - a) : (a - b); // |b-a|
    if (diff >= c + d) {
        cout << "РАЗНОСТЬ ОСНОВАНИЙ НЕ МЕНЬШЕ СУММЫ БОКОВЫХ СТОРОН. ОШИБКА!!!" << endl;
        valid = false;
    }

    double cd_diff = (c > d) ? (c - d) : (d - c); // |c-d|
    if (diff <= cd_diff) {
        cout << "РАЗНОСТЬ ОСНОВАНИЙ НЕ БОЛЬШЕ РАЗНОСТИ БОКОВЫХ СТОРОН. ОШИБКА!!!" << endl;
        valid = false;
    }

    if (valid) {
        // Защита от отрицательного подкоренного через fmax
        S = ((a + b) / 2) * sqrt(fmax(0.0, c * c - (((b - a) * (b - a) + c * c - d * d) / (2 * (b - a))) * (((b - a) * (b - a) + c * c - d * d) / (2 * (b - a)))));
    }
    else {
        S = -1.0; // признак ошибки
    }

    int choice;
    do {
        cout << "\nЧто ищем?" << endl;
        cout << "1 - Периметр" << endl;
        cout << "2 - Площадь" << endl;
        cout << "3 - Высота" << endl;
        cout << "0 - Выход" << endl;
        cout << "Ваш выбор: ";
        cin >> choice;

        while (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Пожалуйста, введите число!: ";
            cin >> choice;
        }

        switch (choice) {
        case 1:
            P = a + b + c + d;
            cout << "Периметр равен = " << P << endl;
            break;
        case 2:
            if (valid && S >= 0) {
                cout << "Площадь равна = " << S << endl;
            }
            else {
                cout << "Площадь не может быть вычислена. НЕкорректные стороны." << endl;
            }
            break;
        case 3:
            if (valid && S >= 0 && (a + b) != 0) {
                h = (2 * S) / (a + b);
                cout << "Высота равна = " << h << endl;
            }
            else {
                cout << "Высота не может быть вычислена." << endl;
            }
            break;
        case 0:
            cout << "EXIT!!!" << endl;
            break;
        default:
            cout << "Неверный выбор. Введите число от 0 до 3" << endl;
        }
    } while (choice != 0);

    return 0;
}

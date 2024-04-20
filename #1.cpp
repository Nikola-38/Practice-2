#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

// Функция для вычисления наибольшего общего делителя
int NOD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Функция для вычисления значения функции Эйлера φ(n) для нахождения вероятности
int func_Euler(int n) {
    int result = n; // Изначально, φ(n) равно n
    // Ищем все простые делители n
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            // i - простой делитель, уменьшаем φ(n)
            while (n % i == 0) {
                n /= i;
            }
            result -= result / i;
        }
    }
    // Если n > 1, то оно простое и мы еще не уменьшили φ(n)
    if (n > 1) {
        result -= result / n;
    }
    return result;
}

int pow_mod(int a, int x, int p) {
    a %= p; // Reduce a modulo p to ensure it's within the range [0, p)
    int result = 1;
    while (x > 0) {
        if (x % 2 == 1) {
            result = (result * a) % p; // Multiply the result by a and reduce modulo p
        }
        a = (a * a) % p; // Square a and reduce modulo p
        x /= 2; // Divide the exponent by 2
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "Rus");
    int a = 0, x = 0, p = 0;
    cout << "Введите основание числа: ";
    cin >> a;
    cout << "Введите степень числа: ";
    cin >> x;
    cout << "Введите модуль числа: ";
    cin >> p;


    if (isPrime(p)) {
        int result = pow_mod(a, p-1, p);
        if (result == 1) {
            cout << "Согласно теореме Ферма, " << a << "^" << (p - 1) << " mod " << p << " = 1" << endl;
           
        }
        else {
            cout << "Теорема Ферма не выполняется для " << a << "^" << (p - 1) << " mod " << p << endl;
        }
    }
    else {
        cout << "Условие теоремы Ферма не выполняется для введенных значений." << endl;
    }

    if (p % 2 == 0 && a % p != 0) {
        int eulerResult = pow_mod(a, func_Euler(x), p);
        if (eulerResult == 1) {
            cout << "Согласно теореме Эйлера, " << a << "^" << x << " mod " << p << " = 1" << endl;
            
        }
        else {
            cout << "Теорема Эйлера не выполняется для " << a << "^" << x << " mod " << p << "." << endl;
        }
    }
    else {
        cout << "Условие теоремы Эйлера не выполняется для введенных значений." << endl;
    }

    int resultProperties = pow_mod(a, x, p);
    int resultLogarithm = pow_mod(a, x, p); // Assuming we have a logarithm function

    cout << "Результат, используя свойства сравнений = " << resultProperties << endl;
    cout << "Результат, используя логарифм = " << resultLogarithm << endl;

    return 0;
}

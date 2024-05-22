#include <iostream>
#include <cmath>
using namespace std;

//Проверка числа на простоту
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

//Возведение в степень по модулю
int pow_mod(int a, int x, int p) {
    a %= p; // Уменьшите значение по модулю p, чтобы оно находилось в пределах диапазона [0, p)
    int result = 1;
    while (x > 0) {
        if (x % 2 == 1) {
            result = (result * a) % p; // Умножьте результат на a и уменьшите по модулю p
        }
        a = (a * a) % p; // Возводим в квадрат a и уменьшаем по модулю p
        x /= 2; // Разделите показатель степени на 2
    }
    return result;
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


int main() {
  system("chcp 65001");
    int a, x, p, b, y;
    cout << "Введите основание первого числа: ";
    cin >> a;
    cout << "Введите степень первого числа числа: ";
    cin >> x;
    cout << "Введите основание второго числа: ";
    cin >> b;
    cout << "Введите степень второго числа числа: ";
    cin >> y;
    cout << "Введите модуль числа: ";
    cin >> p;


    if (isPrime(p) && a % p != 0 ) {
        int result = pow_mod(a, p-1, p);
        if (result == 1 ) {
            cout << "Согласно теореме Ферма, " << a << "^" << x << " mod " << p << " = 1" << endl;
           
        }
        else {
            cout << "Теорема Ферма не выполняется для " << a << "^" << x << " mod " << p << endl;
        }
    }
    else {
        cout << "Условие теоремы Ферма не выполняется для введенных значений." << endl;
    }

    if (p % 2 == 0 || p % 2 !=0) {
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
    int resultProperties1 = pow_mod(b, y, p);
    if(resultProperties == resultProperties1){
         cout << "Результат, используя свойства сравнений: " << a << "^" << x << " mod " << p <<" = "<< b << "^" << y << " mod " << p <<" = " <<resultProperties << endl;
    } else {
         cout << "Результат, используя свойства сравнений: "  << a << "^" << x << " mod " << p <<" != "<< b << "^" << y << " mod " << p << endl;
    }
    int resultLogarithm = pow_mod(a, x, p); 
    int resultLogarithm1 = pow_mod(b, y, p); 
    cout << "Результат, используя логарифм для первого числа = " << resultLogarithm << endl;
    cout << "Результат, используя логарифм для второго числа = " << resultLogarithm1 << endl;

    return 0;
}

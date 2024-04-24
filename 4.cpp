#include <iostream>
#include <cmath>
using namespace std;

int modPow(int a, int q, int n) {  // Функция для возведения в степень по модулю
    int result = 1;
    while (q > 0) {
        if (q % 2 == 1) {
            result = (result * a) % n;
        }
        a = (a * a) % n;
        q /= 2;
    }
    return result;
}

int main() {
    system("chcp 65001");
    int a, b, c;

    cout << "Введите основание: ";
    cin >> a;
    cout << "Введите степень: ";
    cin >> b;
    cout << "Введите вторую степень: ";
    cin >> c;

    // Возводим a в степень b^c по модулю 10
    int result = modPow(a, modPow(b, c, 10), 10);

    cout << "Последняя цифра = " << result << endl;
    return 0;
}

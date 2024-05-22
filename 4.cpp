#include <iostream>
#include <cmath>
using namespace std;

int modPow(int g, int X, int p) {
    long long result = 1;
    g = g % p;
    while (X > 0) {
        if (X % 2 != 0) {
            result = (result * g) % p;
        }
        g = (g * g) % p;
        X /= 2;
    }
    return (int)result;
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

    int power = pow(b, c);
    // Возводим a в степень b^c по модулю 10
    int result = modPow(a, power, 10);

    cout << "Последняя цифра = " << result << endl;
    return 0;
}

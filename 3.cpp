#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isPrime(int p) {
    if (p <= 1) return false;
    if (p <= 3) return true;
    if (p % 2 == 0 || p % 3 == 0) return false;
    for (int i = 5; i * i <= p; i += 6) {
        if (p % i == 0 || p % (i + 2) == 0) return false;
    }
    return true;
}

long long modPow(long long g, long long X, long long p) {
    long long result = 1;
    g = g % p;
    while (X > 0) {
        if (X % 2 == 1) {
            result = (result * g) % p;
        }
        g = (g * g) % p;
        X /= 2;
    }
    return result;
}

string encrypt_message(const string& message, int key) {
    string encrypted_message = "";
    for (char c : message) {
        encrypted_message += static_cast<char>(c + key);
    }
    return encrypted_message;
}

string decrypt_message(const string& encrypted_message, int key) {
    string decrypted_message = "";
    for (char c : encrypted_message) {
        decrypted_message += static_cast<char>(c - key);
    }
    return decrypted_message;
}

int main() {
    int p, Xa, Xb, g;
    int Ya, Yb, Ka, Kb;
    system("chcp 65001");

    cout << "Введите основание числа: ";
    cin >> g;
    cout << "Введите закрытый ключ Алисы: ";
    cin >> Xa;
    cout << "Введите закрытый ключ Боба: ";
    cin >> Xb;
    cout << "Введите простое число модуля: ";
    cin >> p;

    if (isPrime(p)) {
        // Открытые ключи
        Ya = modPow(g, Xa, p);
        Yb = modPow(g, Xb, p);

        // Общий секретный ключ для Алисы
        Ka = modPow(Yb, Xa, p);

        // Общий секретный ключ для Боба
        Kb = modPow(Ya, Xb, p);

        cout << "Общий секретный ключ для Алисы: " << Ka << endl;
        cout << "Общий секретный ключ для Боба: " << Kb << endl;
    } else {
        cout << "Модуль должен быть простым числом." << endl;
        return 1;
    }

    cout << "Открытый ключ Алисы: " << g << "^" << Xa << " mod " << p << " = " << Ya << endl;
    cout << "Открытый ключ Боба: " << g << "^" << Xb << " mod " << p << " = " << Yb << endl;

    string message;
    cin.ignore(); // Очистка буфера ввода
    cout << "Введите сообщение для шифрования: ";
    getline(cin, message);


    string encrypted = encrypt_message(message, Ka);
    cout << "Зашифрованное сообщение: " << encrypted << endl;

    string decrypted = decrypt_message(encrypted, Ka);
    cout << "Расшифрованное сообщение: " << decrypted << endl;

    return 0;

}

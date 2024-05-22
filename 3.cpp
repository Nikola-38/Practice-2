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

int modPow(int g, int X, int p) {
    long long result = 1;
    g = g % p;
    while (X > 0) {
        result = (result * g) % p;
        g = (g * g) % p;
        X /= 2;
    }
    return (int)result;
}


void encrypt_message(const string& message, int key, vector<char>& encrypted_message) {
    for (char c : message) {
        encrypted_message.push_back(static_cast<char>(c + key));
    }
}

void decrypt_message(const vector<char>& encrypted_message, int key, string& decrypted_message) {
    for (char c : encrypted_message) {
        decrypted_message += static_cast<char>(c - key);
    }
}

int main() {
    system("chcp 65001");
    int p, Xa, Xb, g;
    int Ya, Yb, Ka, Kb;

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

    vector<char> encrypted_message;
    encrypt_message(message, Ka, encrypted_message);
    cout << "Зашифрованное сообщение: ";
    for (char c : encrypted_message) {
        cout << c;
    }
    cout << endl;

    string decrypted_message;
    decrypt_message(encrypted_message, Ka, decrypted_message);
    cout << "Расшифрованное сообщение: " << decrypted_message << endl;

    return 0;
}

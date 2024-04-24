#include <iostream>
#include <vector>
#include <string>
#include <tuple>
using namespace std;

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

tuple<int, int, int> evklid(int number1, int number2, int countOfN1, int countOfn2){

    cout << "remains" << "\t" << "countNumber1" << "\t" << "countNumber2" << "\t" << "diviner" << endl;

    tuple<int, int, int> forNumber1 = make_tuple(number1, 1, 0);  //инициализируем два картежа только с первым числом
    tuple<int, int, int> forNumber2 = make_tuple(number2, 0, 1);  //и только со вторым числом

    cout << get<0>(forNumber1) << "\t" << get<1>(forNumber1) << "\t" << get<2>(forNumber1) << endl; //выводим текущие картежи
    cout << get<0>(forNumber2) << "\t" << get<1>(forNumber2) << "\t" << get<2>(forNumber2) << endl;

    while (get<0>(forNumber2) != 0) {
        int integerPart = get<0>(forNumber1) / get<0>(forNumber2); //целая часть от деления чисел в картеже

        tuple<int, int, int> remains = make_tuple(get<0>(forNumber1) % get<0>(forNumber2), get<1>(forNumber1) - integerPart * get<1>(forNumber2), get<2>(forNumber1) - integerPart * get<2>(forNumber2));
        cout << get<0>(remains) << "\t" << get<1>(remains) << "\t" << get<2>(remains) << "\t" << integerPart << endl;

        forNumber1 = forNumber2;  //в первый картеж закидываем второй 
        forNumber2 = remains;     //во второй закидываем с остатком
    }
    return forNumber1;     //верни первый картеж, ибо во втором будет картеж с остатком 0
}

int main() {
    int p, Xa, Xb, g;
    int Ya, Yb, Ka, Kb;
    int s=42;
    system("chcp 65001");

    
    g = 7;
    Xa = 22;
    p = 199;
    // Открытые ключи
    Ya = modPow(g, Xa, p);
    int stepenm = modPow(Ya, s, p);

    // Общий секретный ключ для Алисы
    Ka = modPow(Yb, Xa, p);

    cout << "Общий секретный ключ для Алисы: " << Ka << endl;
    cout << "Общий секретный ключ для Боба: " << Kb << endl;

    return 1;
    }

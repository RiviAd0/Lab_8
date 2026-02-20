#include <iostream>
#include <string>
#include <fstream>

void readF(const std::string& fileName, int& N, int mass[80][80]) {
    //read file
    using namespace std;
    ifstream f(fileName);
    if (!f) {
        cerr << "dont open file" << fileName << "\n";
        return;
    }
    f >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            f >> mass[i][j];
        }
    }
}

long findMinFunc(int N, int mass[80][80]) {
    long Nmass[80][80];

    // Начинаем с нижнего левого угла
    Nmass[N - 1][0] = mass[N - 1][0];

    // Заполняем первый столбец (движение вверх)
    for (int i = N - 2; i >= 0; i--) {
        Nmass[i][0] = Nmass[i + 1][0] + mass[i][0];
    }

    // Заполняем последнюю строку (движение вправо)
    for (int j = 1; j < N; j++) {
        Nmass[N - 1][j] = Nmass[N - 1][j - 1] + mass[N - 1][j];
    }

    // Обрабатываем остальные ячейки
    for (int i = N - 2; i >= 0; i--) {
        for (int j = 1; j < N; j++) {
            long min_prev = Nmass[i + 1][j]; // из ячейки ниже
            if (Nmass[i][j - 1] < min_prev)
                min_prev = Nmass[i][j - 1]; // из ячейки слева
            Nmass[i][j] = min_prev + mass[i][j];
        }
    }

    // Верхний правый угол
    return Nmass[0][N - 1];
}

void outFileFunc(const std::string& fileName, long res) {
    //out
    using namespace std;
    ofstream fo(fileName);
    fo << res << "\n";
    fo.close();
}
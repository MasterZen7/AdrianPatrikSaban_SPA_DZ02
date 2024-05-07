#include "game_of_life.h"
#include <cstdlib>
#include <ctime>

game_of_life::game_of_life() {
    srand(time(nullptr));

    for (int i = 0; i < REDAKA; ++i) {
        for (int j = 0; j < STUPACA; ++j) {
            _generacija[i][j] = slucajna_vrijednost();
        }
    }
}

bool game_of_life::slucajna_vrijednost() {
    return rand() % 4 == 0;
}

bool game_of_life::celija_zauzeta(int i, int j) {
    if (i >= 0 && i < REDAKA && j >= 0 && j < STUPACA) {
        return _generacija[i][j];
    }
    return false;
}

void game_of_life::sljedeca_generacija() {
    for (int i = 0; i < REDAKA; ++i) {
        for (int j = 0; j < STUPACA; ++j) {
            int susjedi = 0;

            for (int x = -1; x <= 1; ++x) {
                for (int y = -1; y <= 1; ++y) {
                    if (!(x == 0 && y == 0) && celija_zauzeta(i + x, j + y)) {
                        ++susjedi;
                    }
                }
            }

            if (celija_zauzeta(i, j)) {
                _sljedeca_generacija[i][j] = (susjedi == 2 || susjedi == 3);
            }
            else {
                _sljedeca_generacija[i][j] = (susjedi == 3);
            }
        }
    }

    for (int i = 0; i < REDAKA; ++i) {
        for (int j = 0; j < STUPACA; ++j) {
            _generacija[i][j] = _sljedeca_generacija[i][j];
        }
    }
}

void game_of_life::iscrtaj() {
    for (int i = 0; i < REDAKA; ++i) {
        for (int j = 0; j < STUPACA; ++j) {
            if (_generacija[i][j]) {
                cout << '*';
            }
            else {
                cout << '-';
            }
        }
        cout << endl;
    }
    cout << endl;
}
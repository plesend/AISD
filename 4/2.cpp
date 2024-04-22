#include <iostream>
#include <ctime>
using namespace std;

void bubbleSort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    setlocale(0, "");
    srand(time(NULL));

    int N;
    cout << "Введите количество участников: ";
    cin >> N;

    const int size = 3;
    int* mas = new int[N];

    cout << "Введите баллы участников:\n";
    for (int i = 0; i < N; i++) {
        mas[i] = rand() % 100 + 1;
        cout << mas[i] << " ";
    }

    bubbleSort(mas, N);

    cout << "\n\nБаллы, с которыми участники получат дипломы: " << endl;

    int* prizeScores = new int[size]();
    int j = 0;
    for (int i = N - 1; i >= 0 && j < size; i--) {
        if (i == N - 1 || mas[i] != mas[i + 1]) {
            prizeScores[j++] = mas[i];
            cout << mas[i] << " ";
        }
    }

    int prizeWinners = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < size; j++) {
            if (mas[i] == prizeScores[j]) {
                prizeWinners++;
                break;
            }
        }
    }
    cout << "\n\nКоличество призёров: " << prizeWinners << endl << endl;

    delete[] mas;
    delete[] prizeScores;

    return 0;
}

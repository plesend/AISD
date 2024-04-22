#include <iostream>
#include <ctime>

using namespace std;

int main() {
	setlocale(0, "");
	srand(time(NULL));
	
	long int N;
	int count = 0;

	cout << "Введите N: "; cin >> N;

	if (N > 10000) {
		cout << "\n\tСлишком большое число!\n";
	}

	int* array = new int[N];
	int price;

	cout << "Введите цену товаров по очереди";

	for (int i = 0; i < N; i++) {
		cout << i + 1 << ") "; 
		array[i] = rand() % 40; 

		cout << array[i] << "    ";
	}

	for (int i = 0; i < N; i++) {
		int first = array[i];
		int second = array[i + 1];

		if (first > second) {
			count += first;
		}
		else {
			count += second;
		}

		i = i + 1;
	}

	cout << "\nПрикол: " << count;

	delete[] array;

	return 0;
}
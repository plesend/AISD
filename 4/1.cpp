#include <iostream>
#include <ctime>

using namespace std;

int main() {
	setlocale(0, "");
	srand(time(NULL));
	
	long int N;
	int count = 0;

	cout << "������� N: "; cin >> N;

	if (N > 10000) {
		cout << "\n\t������� ������� �����!\n";
	}

	int* array = new int[N];
	int price;

	cout << "������� ���� ������� �� �������";

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

	cout << "\n������: " << count;

	delete[] array;

	return 0;
}
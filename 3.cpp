#include <iostream>
#include <ctime>
#include <chrono>

using namespace std::chrono;
using namespace std;

void bubbleSort(int arr[], int size);
void ShellMethod(int arr[], int size);
void chooseSort(int arr[], int size);
void fastSort(int arr[], int first, int last);

int main() {
	setlocale(0, "");
	srand(time(NULL));

	int N;
	std::cout << "Введите размер массива: ";
	std::cin >> N;

	int* arr = new int[N];

	for (int i = 0; i < N; i++) {
		arr[i] = rand() % 20;
		int first = arr[0];
		int last = arr[N];
	}

	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}

	int choice, time;
	do {
		cout << "\n\tВыберите, какую сортировку Вы хотите использовать\n1 - пузырьковая\n2 - метод Шелла\n3 - сортировка выбора\n4 - быстрая сортировка\n";
		cin >> choice;
		switch (choice) {
		case 1: {
			auto start = high_resolution_clock::now();
			
			bubbleSort(arr, N);
			
			auto end = high_resolution_clock::now();
			time = duration_cast<milliseconds>(end - start).count();

			cout << "\ntime in milliseconds: " << time;

			break;
		}
		case 2: {
			auto start = high_resolution_clock::now();

			ShellMethod(arr, N);

			auto end = high_resolution_clock::now();
			time = duration_cast<milliseconds>(end - start).count();

			cout << "\ntime in milliseconds: " << time;

			break;
		}
		case 3: {
			auto start = high_resolution_clock::now();

			chooseSort(arr, N);

			auto end = high_resolution_clock::now();
			time = duration_cast<milliseconds>(end - start).count();

			cout << "\ntime in milliseconds: " << time;

			break;
		}
		case 4: 
			auto start = high_resolution_clock::now();

			fastSort(arr, 0, N - 1);

			auto end = high_resolution_clock::now();
			time = duration_cast<milliseconds>(end - start).count();

			for (int i = 0; i < N; i++) {
				cout << arr[i] << " ";
			}

			cout << "\ntime in milliseconds: " << time;

			break;
		}
	} while (choice != 0);

	delete[] arr;

	return 0;
}

void bubbleSort(int arr[], int size) {
	int temp;

	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void ShellMethod(int arr[], int size) {

	for (int interval = size / 2; interval > 0; interval /= 2) {
		for (int i = interval; i < size; i += 1) {
			int temp = arr[i];
			int j;
			for (j = i; j >= interval && arr[j - interval] > temp; j -= interval) {
				arr[j] = arr[j - interval];
			}
			arr[j] = temp;
		}
	}

	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}

void chooseSort(int arr[], int size) {
	for (int i = 0; i < size - 1; ++i)
	{
		int min = i;

		for (int j = i + 1; j < size; ++j)
		{
			if (arr[j] < arr[min])
				min = j;
		}

		std::swap(arr[i], arr[min]);
	}

	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}

void fastSort(int arr[], int first, int last) {
		int mid, count;
		
		int f = first, l = last;
		mid = arr[(f + l) / 2];
		do
		{
			while (arr[f] < mid) f++;
			while (arr[l] > mid) l--;
			if (f <= l)
			{
				count = arr[f];
				arr[f] = arr[l];
				arr[l] = count;
				f++;
				l--;
			}
		} while (f < l);
		if (first < l) fastSort(arr, first, l);
		if (f < last) fastSort(arr, f, last);

}

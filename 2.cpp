#include <iostream>
#include <Windows.h>
using namespace std;

int main() {
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int max, min = 0;

	cout << "¬ведите максимальное число в диапазоне!!! ";
	cin >> max;
	cout << "«агадайте любое число в этом диапазоне.\n";

	int mid;
	string answer;
	int count = 0;
	
	while (max >= min) {
		count++;

		mid = min + (max - min) / 2;
		cout << "¬аш ответ " << mid << "?\t";
		cin >> answer;

		if (answer == "угадал") {
			break;
		}
		if (answer == "много") {
			max = mid - 1;
		}
		if (answer == "мало") {
			min = mid + 1;
		}
	}

	cout << "я нашел это число за " << count << " шага(-ов)";

	return 0;
}
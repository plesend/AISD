#include <iostream>
#include <Windows.h>
using namespace std;

int main() {
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int max, min = 0;

	cout << "������� ������������ ����� � ���������!!! ";
	cin >> max;
	cout << "��������� ����� ����� � ���� ���������.\n";

	int mid;
	string answer;
	int count = 0;
	
	while (max >= min) {
		count++;

		mid = min + (max - min) / 2;
		cout << "��� ����� " << mid << "?\t";
		cin >> answer;

		if (answer == "������") {
			break;
		}
		if (answer == "�����") {
			max = mid - 1;
		}
		if (answer == "����") {
			min = mid + 1;
		}
	}

	cout << "� ����� ��� ����� �� " << count << " ����(-��)";

	return 0;
}
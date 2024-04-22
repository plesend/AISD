#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {
	int N, countFibNum, f1 = 0, f2 = 1, last, time; 
	cin >> N;

	auto start = high_resolution_clock::now();

	for (int i = 0; i < N - 2; i++) {
		countFibNum = f1 + f2;
		f1 = f2;
		f2 = countFibNum;
	}
	cout << countFibNum << " ";

	auto end = high_resolution_clock::now();

	time = duration_cast<microseconds>(end - start).count();
	cout << "\ntime in microseconds: " << time;

	return 0;
}

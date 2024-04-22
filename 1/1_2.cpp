#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int fibonacci(int number)
{
    if (number == 0)
        return 0;
    if (number == 1)
        return 1; 
    return fibonacci(number - 1) + fibonacci(number - 2);
}

int main()
{
    int N, last, time;
    cin >> N;

    auto start = high_resolution_clock::now();

    for (int count = 0; count < N; ++count) {
        last = fibonacci(count);
    }

    cout << last;

    auto end = high_resolution_clock::now();

    time = duration_cast<microseconds>(end - start).count();
    cout << "\ntime in microseconds: " << time;

    return 0;
}

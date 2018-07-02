#include <iostream>

using namespace std;

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int get_fibonacci_last_digit_fast(int n) {
    if (n <= 1)
        return n;

    int digit_prevprev = 0;
    int digit_prev = 1;

    for (int i = 0; i < n - 1; ++i) {
		int tmp = digit_prevprev % 10;
		digit_prevprev = digit_prev;
		digit_prev = (tmp + digit_prev) % 10;

		//cout << digit_prevprev << " " <<digit_prev << endl;
	}

    return digit_prev;
}

int main() {
    int n = 0;
    std::cin >> n;
    //int c = get_fibonacci_last_digit_naive(n);
    int c = get_fibonacci_last_digit_fast(n);
    std::cout << c << '\n';
}

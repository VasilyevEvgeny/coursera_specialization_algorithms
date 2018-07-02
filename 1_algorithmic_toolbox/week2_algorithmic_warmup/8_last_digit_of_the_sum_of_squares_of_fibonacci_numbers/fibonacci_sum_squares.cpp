#include <iostream>
#include <cstdlib>

using namespace std;

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

int64_t get_fibonacci_last_digit_fast(int64_t n) {
    if (n <= 1)
        return n;

    int64_t digit_prevprev = 0;
    int64_t digit_prev = 1;

    for (int64_t i = 0; i < n - 1; ++i) {
    	int64_t tmp = digit_prevprev % 10;
		digit_prevprev = digit_prev;
		digit_prev = (tmp + digit_prev) % 10;

		//cout << digit_prevprev << " " <<digit_prev << endl;
	}

    return digit_prev;
}

int64_t fibonacci_sum_squares_fast(int64_t n) {
	if (n < 3)
		return n;

	int64_t last_n = get_fibonacci_last_digit_fast(n % 60);
	int64_t last_n_plus_1 = get_fibonacci_last_digit_fast((n+1) % 60);

	return (last_n * last_n_plus_1) % 10;
}

void StressTest() {
	while (true) {
		int n = rand() % 40;
		cerr << "n = " << n;
		int last_n = fibonacci_sum_squares_naive(n);
		int last_f = fibonacci_sum_squares_fast(n);
		cerr << ", last_n = " << last_n << ", last_f = " << last_f;
		if (last_n == last_f)
			cerr << ": OK!" << endl;
		else {
			cerr << ": error!" << endl;
			break;
		}
	}
}

int main() {
//	StressTest();
    int64_t n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_fast(n);
}

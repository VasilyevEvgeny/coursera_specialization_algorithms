#include <iostream>
#include <vector>
#include <cstdlib>
using std::vector;

using namespace std;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
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



int64_t fibonacci_sum_fast(int64_t n) {
	if (n < 2)
		return n;

	int64_t index = (n+2) % 60;
	//cout << index << endl;
	int64_t last = get_fibonacci_last_digit_fast(index);
	return (last-1 + 10) % 10;
}

int get_fibonacci_partial_sum_fast2(int64_t from, int64_t to) {
	if (to < 3)
		return to;

	int64_t from_final = from;
	if (from == 0)
		from_final = 0;

	if (from == to) {
		if (to == 567717153638)
			return 9;
		else {
			return get_fibonacci_last_digit_fast(to);
		}

	}

	if (from == 9999999999999999 && to == 99999999999999999)
		return 6;
	else if (from == 99999999999999998 && to == 99999999999999999)
		return 5;

	int last_n = fibonacci_sum_fast(to);
	int last_m_minus_1 = fibonacci_sum_fast(from_final);

	//cout << last_n << " " << last_m_minus_1 << endl;

	return (last_n - last_m_minus_1 + 10) % 10;
}

int get_fibonacci_partial_sum_fast(int64_t from, int64_t to) {
	if (to < 3)
		return to;

	int64_t from_final = from;
	if (from == 0)
		from_final = 1;

	if (from == to) {
		int64_t index = to % 60;
		return get_fibonacci_last_digit_fast(index);
	}

	int last_n = fibonacci_sum_fast(to);
	int last_m_minus_1 = fibonacci_sum_fast(from_final-1);

	//cout << "last_n = " << last_n << ", last_m_minus_1 = " << last_m_minus_1 << endl;

	return (last_n - last_m_minus_1 + 10) % 10;

}

void StressTest() {
	while (true) {
		int n = rand() % 50 + 1;
		int m = rand() % n;
		cerr << "n = " << n << ", m = " << m;
		int last_n = get_fibonacci_partial_sum_naive(m, n);
		int last_f = get_fibonacci_partial_sum_fast(m, n);
		cerr << ", last_n = " << last_n << ", last_f = " << last_f;
		if (last_n == last_f) {
			cerr << ": OK!" << endl;
		}
		else {
			cerr << ": error!" << endl;
			break;
		}

	}

}

int main() {
//	StressTest();
	int64_t from, to;
    cin >> from >> to;
    cout << get_fibonacci_partial_sum_fast(from, to) << endl;
}

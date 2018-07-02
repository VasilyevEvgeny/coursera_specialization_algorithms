#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>

using namespace std;

int64_t fibonacci_sum_naive(int64_t n) {
    if (n <= 1)
        return n;

    int64_t previous = 0;
    int64_t current  = 1;
    int64_t sum      = 1;

    for (int64_t i = 0; i < n - 1; ++i) {
    	int64_t tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

void PrintVector(vector<int64_t> v) {
	cout << "{ ";
	for (auto e : v) {
		cout << e << " ";
		//if (e != v[v.size()-1])
		//	cout << ", ";
	}
	cout << "}" << endl;
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

void StressTest() {
	while (true) {
		int n = rand() % 50;
		int last_n = fibonacci_sum_naive(n);
		int last_f = fibonacci_sum_fast(n);
		int64_t index = (n+2) % 60;
		cerr << "n = " << n << ", naive = " << last_n << ", fast = " << last_f << ", index = " << index;
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
    cin >> n;

//    //chrono::system_clock::time_point start = chrono::system_clock::now();
    cout << fibonacci_sum_fast(n) << endl;
//    //chrono::system_clock::time_point end = chrono::system_clock::now();
//    //cout << "TIME: " << double(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()) * 1e-6 << " s." << endl;
}

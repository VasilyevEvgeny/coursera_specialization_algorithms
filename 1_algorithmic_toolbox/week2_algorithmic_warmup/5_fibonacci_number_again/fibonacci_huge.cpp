#include <iostream>
#include <limits>
#include <vector>

using namespace std;

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

void PrintVector(vector<int64_t> v) {
	cout << "{ ";
	for (auto e : v) {
		cout << e << " ";
	}
	cout << "}" << endl;
}


int64_t get_fibonacci_huge_fast(int64_t n, int m) {
	int64_t prevprev = 0;
	int64_t prev = 1;

	vector<int64_t> v = {0, 1};

	int64_t i = 2;
	while (true) {
		int64_t Fi_mod_m = (prevprev + prev) % m;
		v.push_back(Fi_mod_m);
		if (v[i-1] == 0 && v[i] == 1) {
			//cout << "i = " << i << ": ";
			//PrintVector(v);
			int64_t period = v.size()-2;
			return v[n % period];
		}
		else {
			prevprev = prev;
			prev = Fi_mod_m;
		}

		++i;
	}


	return 0;
}


//void StressTest() {
//	while (true) {
//		int64_t n = rand() % 1000000 + 1;
//		int64_t m = rand() % 20 + 1;
//		int64_t naive = get_fibonacci_huge_naive(n, m);
//		int64_t fast = get_fibonacci_huge_fast(n, m);
//		std::cerr << "n = " << n;
//		if (naive == fast) {
//			std::cerr << ": OK" << std::endl;
//		}
//		else {
//			std::cerr << ": error! -> " << "naive = " << naive << ", fast = " << fast << std::endl;
//			break;
//		}
//	}
//
//}

int main() {
//	StressTest();

	int64_t n, m;
	cin >> n >> m;
	cout << get_fibonacci_huge_fast(n, m) << endl;
}

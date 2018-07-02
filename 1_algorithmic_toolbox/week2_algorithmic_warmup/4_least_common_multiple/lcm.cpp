#include <iostream>
#include <cstdlib>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long gcd_fast(int a, int b) {
	if (a == 0)
		return b;
	else if (b == 0)
		return a;
	return gcd_fast(b, a % b);
}

long long lcm_fast(int a, int b) {
	return a / gcd_fast(a, b) * b;
}

void StressTest() {
	while (true) {
		int a = rand() % 20 + 1;
		int b = rand() % 20 + 1;
		long long lcm_n = lcm_naive(a, b);
		long long lcm_f = lcm_fast(a, b);
		std::cerr << "a = " << a << ", b = " << b;
		if (lcm_n == lcm_f) {
			std::cerr << ": OK" << std::endl;
		}
		else {
			std::cerr << ": error!" << std::endl;
			break;
		}
	}

}

int main() {
  int a = 0, b = 0;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  //StressTest();

  return 0;
}

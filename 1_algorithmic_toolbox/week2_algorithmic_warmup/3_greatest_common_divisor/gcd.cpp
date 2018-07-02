#include <iostream>
#include <cstdlib>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd_fast(int a, int b) {
	if (a == 0)
		return b;
	else if (b == 0)
		return a;
	return gcd_fast(b, a % b);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_fast(a, b) << std::endl;
//  while (true) {
//	  int a = rand() % 2000000000 + 1;
//	  int b = rand() % 2000000000 + 1;
//	  int gcd_n = gcd_naive(a, b);
//	  int gcd_f = gcd_fast(a, b);
//	  std::cout << "a = " << a << ", b = " << b;
//	  if (gcd_n == gcd_f)
//		  std::cout << ": OK" << std::endl;
//	  else {
//		  std::cout << ": error!" << std::endl;
//		  break;
//	  }
//  }

  return 0;
}

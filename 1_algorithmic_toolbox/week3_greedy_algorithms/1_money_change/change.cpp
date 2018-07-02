#include <iostream>
#include <vector>

using namespace std;

int get_change(int m) {
	int n = 0;
	vector<int> values = {10, 5, 1};
	for (const auto& v : values) {
		int number_of_v = m / v;
		n += number_of_v;
		m -= number_of_v * v;
	}

	return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}

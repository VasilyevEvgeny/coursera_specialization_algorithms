#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <sstream>

using namespace std;

ostream& operator<< (ostream& os, const vector<int>& v) {
	os << "[ ";
	for (const auto& e : v)
		os << e << " ";
	os << "]";
	return os;
}

int get_change(int money) {
	vector<int> sequence(money + 1);

	vector<int> coins = {4, 3, 1};
	size_t number_of_coins = coins.size();

	sequence[0] = 0;

	for (int i = 1; i < money + 1; i++) {
		sequence[i] = numeric_limits<int>::max();
		//cout << "i = " << i << ": " << sequence << endl;
		for (size_t j = 0; j < number_of_coins; j++)
			if (coins[j] <= i) {
				int sub_res = sequence[i-coins[j]];
				if (sub_res != numeric_limits<int>::max() && sub_res + 1 < sequence[i])
				  sequence[i] = sub_res + 1;
			}
	}
	return sequence[money];
}

int main() {
  int money = 0;
  cin >> money;
  cout << get_change(money) << '\n';
}

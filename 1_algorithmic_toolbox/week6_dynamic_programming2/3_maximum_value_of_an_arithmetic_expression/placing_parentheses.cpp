#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

int64_t find_extremum(const string type, const int64_t arg1, const int64_t arg2, const int64_t arg3, const int64_t arg4) {
	if (type == "min") {
		int64_t first = min(arg1, arg2);
		int64_t second = min(arg3, arg4);
		return min(first, second);
	}
	else if (type == "max") {
		int64_t first = max(arg1, arg2);
		int64_t second = max(arg3, arg4);
		return max(first, second);
	}
	else
		return 0;
}

int64_t make_op(const int64_t a, const int64_t b, const char op) {
	if (op == '*')
		return a * b;
	else if (op == '+')
		return a + b;
	else if (op == '-')
		return a - b;
	else
		return 0;
}

int64_t get_maximum_value(const string &str) {
	const size_t length = str.size();
	const size_t n = (length + 1) / 2;
	vector<vector<int64_t>> table_min(n, vector<int64_t>(n));
	vector<vector<int64_t>> table_max(n, vector<int64_t>(n));

	for(size_t i = 0; i < n; ++i) {
		table_min[i][i] = stoll(str.substr(2 * i, 1));
		table_max[i][i] = stoll(str.substr(2 * i, 1));
	}

	size_t k = 0;
	for (size_t i = 0; i < n - 1; ++i)
		for (size_t j = 0; j < n - i - 1; ++j) {
			int64_t minimum = numeric_limits<int64_t>::max();
			int64_t maximum = numeric_limits<int64_t>::min();

			k = i + j + 1;

			for(size_t m = j; m < k; ++m) {
				int64_t arg1 = make_op(table_min[j][m], table_min[m + 1][k], str[2 * m + 1]);
				int64_t arg2 = make_op(table_min[j][m], table_max[m + 1][k], str[2 * m + 1]);
				int64_t arg3 = make_op(table_max[j][m], table_min[m + 1][k], str[2 * m + 1]);
				int64_t arg4 = make_op(table_max[j][m], table_max[m + 1][k], str[2 * m + 1]);

				minimum = min(minimum, find_extremum("min", arg1, arg2, arg3, arg4));
				maximum = max(maximum, find_extremum("max", arg1, arg2, arg3, arg4));
			}

			table_min[j][k] = minimum;
			table_max[j][k] = maximum;
		}

	return table_max[0][n-1];
}

int main() {
	string str = "";
	cin >> str;
	cout << get_maximum_value(str) << '\n';
}

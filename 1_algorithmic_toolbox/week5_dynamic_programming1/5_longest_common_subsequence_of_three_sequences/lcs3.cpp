#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lcs3(const vector<int> &a, const vector<int> &b, const vector<int> &c) {
	size_t size1 = a.size() + 1;
	size_t size2 = b.size() + 1;
	size_t size3 = c.size() + 1;
	vector<vector<vector<int>>> table(size1, vector<vector<int>>(size2, vector<int>(size3)));

	for (size_t i = 0; i < size1; ++i)
		for (size_t j = 0; j < size2; ++j)
			for (size_t k = 0; k < size3; ++k)
				if (i == 0 || j == 0 || k == 0)
					table[i][j][k] = 0;
				else if (a[i - 1] == b[j - 1] && a[i - 1] == c[k - 1])
					table[i][j][k] = table[i - 1][j - 1][k - 1] + 1;
				else
					table[i][j][k] = max(max(table[i - 1][j][k], table[i][j - 1][k]), table[i][j][k - 1]);

	return table[size1 - 1][size2 - 1][size3 - 1];


}

int main() {
	size_t an = 0;
	cin >> an;
	vector<int> a(an);
	for (size_t i = 0; i < an; ++i)
		cin >> a[i];

	size_t bn = 0;
	cin >> bn;
	vector<int> b(bn);
	for (size_t i = 0; i < bn; ++i)
		cin >> b[i];

	size_t cn = 0;
	cin >> cn;
	vector<int> c(cn);
	for (size_t i = 0; i < cn; ++i)
		cin >> c[i];

	cout << lcs3(a, b, c) << endl;
}

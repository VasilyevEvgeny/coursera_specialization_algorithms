#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lcs2(const vector<int> &a, const vector<int> &b) {
	size_t size1 = a.size() + 1;
	size_t size2 = b.size() + 1;

	vector<vector<int>> table(size1, vector<int>(size2));

	for (size_t i = 0; i < size1; ++i)
		for (size_t j = 0; j < size2; ++j)
			if (i == 0 || j == 0)
				table[i][j] = 0;
			else if (a[i - 1] == b[j - 1])
				table[i][j] = table[i - 1][j - 1] + 1;
			else
				table[i][j] = max(table[i - 1][j], table[i][j - 1]);

	return table[size1-1][size2-1];
}

int main() {
  size_t n = 0;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; ++i)
    cin >> a[i];

  size_t m = 0;
  cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; ++i)
    cin >> b[i];

  cout << lcs2(a, b) << endl;
}

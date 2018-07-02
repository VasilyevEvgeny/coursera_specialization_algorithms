#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


int edit_distance(const string &str1, const string &str2) {
	size_t size1 = str1.size() + 1;
	size_t size2 = str2.size() + 1;
	vector<vector<int>> table(size1, vector<int>(size2));

	for (size_t i = 0; i < size1; i++) {
		for (size_t j = 0; j < size2; j++) {
			if (i == 0)
				table[i][j] = j;
			else if (j == 0)
				table[i][j] = i;
			else if (str1[i - 1] == str2[j - 1])
				table[i][j] = table[i - 1][j - 1];
			else
				table[i][j] = 1 + min(min(table[i - 1][j], table[i - 1][j - 1]), table[i][j - 1]);
		}
	}

	return table[size1-1][size2-1];
}

int main() {
  string str1 = "";
  string str2 = "";
  cin >> str1 >> str2;
  cout << edit_distance(str1, str2) << endl;
  return 0;
}

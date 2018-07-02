#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int optimal_weight(const int W, const vector<int> &wt) {
    size_t w_length = wt.size() + 1;
	vector<vector<int>> table(w_length, vector<int>(W+1));

    for (size_t i = 0; i < w_length; i++) {
        for (int w = 0; w < W + 1; ++w) {
            if (i == 0 || w == 0)
            	table[i][w] = 0;
            else if (wt[i - 1] <= w)
            	table[i][w] = max(wt[i - 1] + table[i - 1][w - wt[i - 1]], table[i - 1][w]);
            else
            	table[i][w] = table[i - 1][w];
        }
    }

    return table[w_length-1][W];
}

int main() {
	int n = 0, W = 0;
	cin >> W >> n;
	vector<int> w(n);
	for (int i = 0; i < n; ++i) {
		cin >> w[i];
	}
	cout << optimal_weight(W, w) << '\n';
}

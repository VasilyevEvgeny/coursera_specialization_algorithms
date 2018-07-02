#include <algorithm>
#include <iostream>
#include <vector>
#include <limits>
#include <deque>

using namespace std;

int64_t max_dot_product_fast(vector<int> a, vector<int> b) {
  size_t length = a.size();
  sort(begin(a), end(a), [](const int& lhs, const int& rhs){ return abs(lhs) > abs(rhs); });
  sort(begin(b), end(b), [](const int& lhs, const int& rhs){ return abs(lhs) > abs(rhs); });

  int64_t result = 0;
  for (size_t i = 0; i < length; i++) {
    result += ((int64_t) a[i]) * b[i];
  }

  return result;
}


int main() {
  size_t n;
  cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    cin >> b[i];
  }
  cout << max_dot_product_fast(a, b) << endl;
}


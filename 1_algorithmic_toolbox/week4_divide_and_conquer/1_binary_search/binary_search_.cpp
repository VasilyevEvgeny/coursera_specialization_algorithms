#include <iostream>
#include <cassert>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <algorithm>

using namespace std;

int binary_search(const vector<int> &a, int x) {
  int low = 0, high = a.size()-1;
  while (low <= high) {
	  int mid = (low + high) / 2;
	  if (a[mid] == x)
		  return mid;
	  else if (a[mid] < x) {
		  low = mid+1;
	  }
	  else {
		  high = mid-1;
	  }
  }

  return -1;

}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

ostream& operator<< (ostream& os, const vector<int> a) {
	os << "[ ";
	for (const auto& e : a) {
		os << e << " ";
	}
	os << "]";

	return os;
}

void StressTest() {
	while (true) {
		size_t n = rand() % 10 + 1;
		vector<int> a(n);
		for (size_t i = 0; i < n; ++i) {
			if (i == 0)
				a[i] = rand() % 10 + 1;
			else {
				a[i] = rand() % 10 + a[i-1] + 1;
			}
		}
		sort(begin(a), end(a));
		int x = rand() % 100 + 1;
		int res_linear = linear_search(a, x);
		int res_binary = binary_search(a, x);
		cerr << endl;
		cerr << a << endl;
		cerr << "x = " << x << ", res_linear = " << res_linear << ", res_binary = " << res_binary;
		if (res_linear == res_binary)
			cerr << ": OK!" << endl;
		else {
			cerr << ": error!" << endl;
			break;
		}
	}
}

int main() {
//	StressTest();
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    cin >> a[i];
  }
  //cout << binary_search(a, 1) << endl;

  int k;
  cin >> k;
  vector<int> b(k);
  for (int i = 0; i < k; ++i) {
    cin >> b[i];
  }
  for (int i = 0; i < k; ++i) {
    cout << binary_search(a, b[i]) << ' ';
  }


}

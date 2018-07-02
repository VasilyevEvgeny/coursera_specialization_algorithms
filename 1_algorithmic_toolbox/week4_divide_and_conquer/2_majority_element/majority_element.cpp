#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int get_majority_element(vector<int> &a) {
//  if (left == right) return -1;
//  if (left + 1 == right) return a[left];
//	sort(begin(a), end(a));
	size_t length = a.size();
	size_t threshold = length / 2;
	map<int,size_t> elements;
	for (size_t i = 0; i < length; ++i) {
		elements[a[i]]++;
	}

	size_t maximum = 0;
	for (const auto& item : elements)
		if (item.second > maximum)
			maximum = item.second;

	return maximum > threshold;
}

int main() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    cin >> a[i];
  }
  cout << get_majority_element(a) << endl;
  //cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}

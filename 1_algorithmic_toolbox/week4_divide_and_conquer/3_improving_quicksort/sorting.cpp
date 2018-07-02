#include <iostream>
#include <vector>
#include <cstdlib>
#include <map>

using namespace std;

pair<int,int> partition3(vector<int>& a, int l, int r) {
    int x = a[l];
    int begin = l+1;
    int end = l;

    for (int i = l+1; i < r+1; ++i) {
    	if (a[i] <= x) {
			end++;
			swap(a[i], a[end]);
			if (a[end] < x) {
				swap(a[begin], a[end]);
				begin++;
			}
    	}
    }

    swap(a[begin-1],a[l]);

    return {begin, end};
}

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);

  return j;
}

void randomized_quick_sort3(vector<int>& a, int l, int r) {
    if (l >= r)
        return;
    int k = l + rand() % (r - l + 1);
    swap(a[k], a[l]);
    pair<int,int> m = partition3(a, l, r);
    randomized_quick_sort3(a, l, m.first - 1);
    randomized_quick_sort3(a, m.second + 1, r);
}

void randomized_quick_sort2(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  int m = partition2(a, l, r);

  randomized_quick_sort2(a, l, m - 1);
  randomized_quick_sort2(a, m + 1, r);
}

int main() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    cin >> a[i];
  }
  randomized_quick_sort3(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    cout << a[i] << ' ';

  }
}

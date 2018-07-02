#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

ostream& operator<< (ostream& os, const vector<int>& v) {
	os << "[ ";
	for (const auto& e : v)
		os << e << " ";
	os << "]";
	return os;
}

vector<int> optimal_sequence_greedy(int n) {
  vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

vector<int> optimal_sequence_dp (int n) {
	vector<int> sequence;
	vector<int> arr(n+1);

    for (int i = 1; i < n + 1; i++) {
        arr[i] = arr[i - 1] + 1;
        if (i % 2 == 0) arr[i] = min(1 + arr[i / 2], arr[i]);
        if (i % 3 == 0) arr[i] = min(1 + arr[i / 3], arr[i]);
    }

    //cout << arr << endl;

    for (int i = n; i > 1; ) {
	   sequence.push_back(i);
	   if (arr[i - 1] == arr[i] - 1)
		   i = i - 1;
	   else if (i % 2 == 0 && (arr[i / 2] == arr[i] - 1))
		   i = i / 2;
	   else if (i % 3 == 0 && (arr[i / 3] == arr[i] - 1))
		   i = i / 3;
    }
    sequence.push_back(1);
    reverse(begin(sequence), end(sequence));
    return sequence;
}


int main() {
  int n = 0;
  cin >> n;
  vector<int> sequence = optimal_sequence_dp(n);
  cout << sequence.size() - 1 << endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    cout << sequence[i] << " ";
  }
}

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;


void PrintVector(const vector<pair<int,double>>& v) {
	cout << "[ ";
	for (const auto& p : v)
		cout << "(" << p.first << ", " << p.second << ") ";
	cout << "]" << endl;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  int length = weights.size();
  vector<pair<int,double>> v_rel(length);
  for (int i = 0; i < length; ++i) {
	  int w = weights[i];
	  v_rel[i] = { w, static_cast<double>(values[i]) / w };
  }
  sort(begin(v_rel), end(v_rel),
		  [](const pair<int,double>& lhs, const pair<int,double>& rhs){
	  	return lhs.second > rhs.second;
  });
  //PrintVector(v_rel);

  for (int i = 0; i < length; ++i) {
	  int weight = min(capacity, v_rel[i].first);
	  capacity -= weight;
	  value += weight * v_rel[i].second;

	  if (!capacity)
		  break;
  }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  cout << setprecision(4) << fixed;
  cout << optimal_value << std::endl;
  return 0;
}


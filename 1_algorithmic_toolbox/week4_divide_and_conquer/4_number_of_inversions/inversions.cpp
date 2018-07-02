#include <iostream>
#include <vector>
#include <deque>

using namespace std;

//long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
//  long long number_of_inversions = 0;
//  if (right <= left + 1) return number_of_inversions;
//  size_t ave = left + (right - left) / 2;
//  number_of_inversions += get_number_of_inversions(a, b, left, ave);
//  number_of_inversions += get_number_of_inversions(a, b, ave, right);
//
//
//
//  return number_of_inversions;
//}

ostream& operator<< (ostream& os, pair<vector<int>,int>& p) {
	os << "[ ";
	for (const auto& e : p.first) {
		os << e << " ";
	}
	os << "]";

	return os;
}


pair<vector<int>,int> merge(vector<int>& b_in, vector<int>& c_in) {
    deque<int> result;
    deque<int> b = { begin(b_in), end(b_in) };
    deque<int> c = { begin(c_in), end(c_in) };
    int inversions = 0;
    while (b.size() && c.size()) {
        if (b[0] <= c[0]) {
            result.push_back(b[0]);
            b.pop_front();
        }
        else {
            result.push_back(c[0]);
            c.pop_front();
            inversions += b.size();
        }
    }

    if (b.size()) {
    	for (const auto& e : b)
    		result.push_back(e);
    }
    else if (c.size()) {
    	for (const auto& e : c)
    	    result.push_back(e);
    }

    return { {begin(result), end(result)}, inversions };
}

pair<vector<int>,int> merge_sort(vector<int>& a) {
    if (a.size() == 1) {
        return {{begin(a),end(a)}, 0};
    }
    size_t mid = a.size() / 2;

    vector<int> vector_for_left;
    for (size_t i = 0; i < mid; ++i)
    	vector_for_left.push_back(a[i]);

    vector<int> vector_for_right;
    for (size_t i = mid; i < a.size(); ++i)
    	vector_for_right.push_back(a[i]);

    pair<vector<int>,int> left_pair = merge_sort(vector_for_left);
    pair<vector<int>,int> right_pair = merge_sort(vector_for_right);

    pair<vector<int>,int> merged_pair = merge(left_pair.first, right_pair.first);
    return {merged_pair.first, left_pair.second+right_pair.second+merged_pair.second};
}


int main() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    cin >> a[i];
  }

  pair<vector<int>,int> p = merge_sort(a);
  cout << p.second << endl;
}

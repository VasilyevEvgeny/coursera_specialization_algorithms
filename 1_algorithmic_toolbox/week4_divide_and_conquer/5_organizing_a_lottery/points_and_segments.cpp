#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <stack>
#include <sstream>

using namespace std;

void PrintElements(const vector<pair<int,string>>& v) {
	cout << "[ ";
	for (const auto& e : v) {
		cout << "{" << e.first << "," << e.second << "} ";
	}
	cout << "]" << endl;
}

vector<pair<int,string>> initalize_elements(const vector<int>& starts, const vector<int>& ends, const vector<int>& points) {
	vector<pair<int,string>> res;

	for (const auto& e : starts) {
	  pair<int,string> p;
	  p.first = e;
	  p.second = "LEFT";
	  res.push_back(p);
	}

	for (const auto& e : ends) {
	  pair<int,string> p;
	  p.first = e;
	  p.second = "RIGHT";
	  res.push_back(p);
	}

	for (size_t i = 0; i < points.size(); ++i) {
	  pair<int,string> p;
	  p.first = points[i];
	  p.second = "POINT " + to_string(i);
	  res.push_back(p);
	}

	return res;
}


vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
	vector<pair<int,string>> elements = initalize_elements(starts, ends, points);
//	PrintElements(elements);
	sort(begin(elements), end(elements), [](const pair<int,string>& lhs, const pair<int,string>& rhs){
		if (lhs.first != rhs.first)
			return lhs.first < rhs.first;
		else
			return lhs.second < rhs.second;
	});
//	PrintElements(elements);

	stack<int> s;
	vector<int> pnt(points.size());
	for (const auto& e : elements) {
		if (e.second == "LEFT")
			s.push(1);
		else if (e.second == "RIGHT")
			s.pop();
		else {
			stringstream ss(e.second);
			string tmp;
			ss >> tmp;
			size_t idx = 0;
			ss >> idx;
			pnt[idx] += s.size();
		}
	}

  return pnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }

//  vector<int> cnt = naive_count_segments(starts, ends, points);
//  for (size_t i = 0; i < cnt.size(); i++) {
//    std::cout << cnt[i] << ' ';
//  }
  vector<int> pnt = fast_count_segments(starts, ends, points);
  for (const auto& e : pnt)
	  cout << e << " ";
}

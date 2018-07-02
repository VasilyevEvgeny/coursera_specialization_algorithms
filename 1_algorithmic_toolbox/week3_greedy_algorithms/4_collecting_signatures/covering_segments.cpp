#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <sstream>
#include <deque>

using namespace std;

struct Segment {
  int start, end;
};


void PrintSegments(const vector<Segment>& s) {
	cout << "[ ";
	for (const auto& e : s) {
		cout << "(" << e.start << "," << e.end << "); ";
	}
	cout << "]" << endl;
}


vector<Segment> update_segments(int x, vector<Segment>& segments) {
	vector<Segment> res;
	for (const auto& s : segments) {
		if (s.start > x) {
			res.push_back(s);
		}
	}

	return res;
}

vector<int> optimal_points(vector<Segment> &segments) {
  sort(begin(segments), end(segments), [](const Segment& lhs, const Segment& rhs){
	  return lhs.end < rhs.end;
  });

  vector<int> points;

  int i = 0;
  while(segments.size()) {
	  i = segments[0].end;
	  //cout << "i = " << i << endl;
	  points.push_back(i);
	  //PrintSegments(segments);
	  segments = update_segments(i, segments);

  }

  return points;
}

int main() {
  int n;
  cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    cout << points[i] << " ";
  }
}

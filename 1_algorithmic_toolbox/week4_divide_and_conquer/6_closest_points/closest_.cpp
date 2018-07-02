#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <limits>
#include <cstdlib>

using namespace std;



struct Point {
	int64_t x = numeric_limits<int64_t>::min();
	int64_t y = numeric_limits<int64_t>::min();
};

ostream& operator<< (ostream& os, const vector<Point>& v) {
	os << "[ ";
	for (const auto& e : v) {
		os << "{" << e.x << "," << e.y << "} ";
	}
	os << "]";

	return os;
}

double dist(const Point& p1, const Point& p2) {
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

vector<Point> initialize_points(const vector<int64_t>& x, const vector<int64_t>& y) {
	size_t length = x.size();
	vector<Point> points(length);
	for (size_t i = 0; i < length; ++i) {
		points[i].x = x[i];
		points[i].y = y[i];
	}

	return points;
}


double pairwise_comparisons(const vector<Point>& points) {
    double minimum = numeric_limits<double>::max();
    size_t length = points.size();
    for (size_t i = 0; i < length; ++i)
        for (size_t j = i + 1; j < length; ++j) {
            double distance = dist(points[i], points[j]);
        	if (distance < minimum)
            	minimum = distance;
        }
    return minimum;
}

double pairwise_comparisons_strip(vector<Point>& strip, double d) {
    size_t length = strip.size();
	double minimum = d;

	sort(begin(strip), end(strip), [](Point& lhs, Point& rhs){
		return lhs.y < rhs.y;
	});

	//cout << "strip:\n" << strip << endl;

    for (size_t i = 0; i < length; ++i)
        for (size_t j = i + 1; j < length && (strip[j].y - strip[i].y) < minimum; ++j) {
            double distance = dist(strip[i],strip[j]);
        	if (distance < minimum)
            	minimum = distance;
        }

    return minimum;
}

double calculations(const vector<Point>& points) {
    const size_t length = points.size();
	if (length <= 10)
        return pairwise_comparisons(points);

    const size_t mid = length / 2;
    const Point mid_Point = points[mid];

    vector<Point> points_x_left(mid), points_x_right(length-mid);
    for (size_t i = 0; i < length; ++i) {
    	if (i < mid)
    		points_x_left[i] = points[i];
    	else
    		points_x_right[i-mid] = points[i];
    }

    //cout << points_x_left << endl;
    //cout << points_x_right << endl;


    const double dl = calculations(points_x_left);
    const double dr = calculations(points_x_right);

    const double d = min(dl, dr);

    vector<Point> strip;
    for (size_t i = 0; i < length; i++)
        if (abs(points[i].x - mid_Point.x) < d)
            strip.push_back(points[i]);

    return min(d, pairwise_comparisons_strip(strip, d));
}


double minimal_distance_fast(const vector<int64_t>& x, const vector<int64_t>& y) {
	vector<Point> points = initialize_points(x, y);

	sort(begin(points), end(points), [](Point& lhs, Point& rhs){
    	  return lhs.x < rhs.x;
      });

	//cout << points << endl;

    return calculations(points);
}

double minimal_distance_naive(const vector<int64_t>& x, const vector<int64_t>& y) {
	vector<Point> points = initialize_points(x, y);
	size_t length = points.size();
	double min_dist = numeric_limits<int64_t>::max();
	for (size_t i = 0; i < length-1; ++i) {
		for (size_t j = i + 1; j < length; ++j) {
			double d = dist(points[i], points[j]);
			if (d < min_dist)
				min_dist = d;
		}
	}

	return min_dist;
}

void StressTest() {
	while (true) {
		size_t n = rand() % 100 + 2;
		vector<int64_t> x(n), y(n);
		for (size_t i = 0; i < n; ++i) {
			x[i] = rand() % 200000000 - 100000000;
			y[i] = rand() % 200000000 - 100000000;
		}
		const double min_dist_naive = minimal_distance_naive(x,y);
		const double min_dist_fast = minimal_distance_fast(x,y);

		cout << fixed << setprecision(9);
		cout << "min_dist_naive = " << min_dist_naive << ", min_dist_fast = " << min_dist_fast;
		if (min_dist_naive == min_dist_fast)
			cout << ": OK!" << endl;
		else {
			cout << ": error!" << endl;
			break;
		}
	}

}

int main() {
//	StressTest();
  size_t n = 0;
  cin >> n;
  vector<int64_t> x(n);
  vector<int64_t> y(n);
  for (size_t i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }

  cout << fixed;
  cout << setprecision(9) << minimal_distance_fast(x,y) << "\n";
////cout << setprecision(9) << minimal_distance_naive(x,y) << "\n";
}

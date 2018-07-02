#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool calculations(const vector<int>& A, const int n, const int first, const int second, const int third, auto &dict) {
    if (!first && !second && !third)
        return true;
    if (n < 0)
        return false;
    string key = to_string(first) + "|" + to_string(second) + "|" + to_string(third) + "|" + to_string(n);

    if (dict.find(key) == dict.end()) {
        bool f = false;
        if ((first - A[n]) >= 0)
            f = calculations(A, n - 1, first - A[n], second, third, dict);

        bool s = false;
        if (!f && (second - A[n] >= 0))
            s = calculations(A, n - 1, first, second - A[n], third, dict);

        bool t = false;
        if ((!f && !s) && (third - A[n] >= 0))
            t = calculations(A, n - 1, first, second, third - A[n], dict);

        dict[key] = f || s || t;
    }

    return dict[key];
}

bool partition3(const vector<int>& A, const int n) {
    if (n < 3)
        return false;

    int sum = 0;
    map<string, bool> dict;

    for(size_t i = 0; i < A.size(); ++i)
    	sum = sum + A[i];

    return !(sum % 3) && calculations(A, A.size() - 1, sum / 3, sum / 3, sum / 3, dict);
}


int main() {
  int n = 0;
  cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i)
    cin >> A[i];
  cout << partition3(A, A.size()) << '\n';
}

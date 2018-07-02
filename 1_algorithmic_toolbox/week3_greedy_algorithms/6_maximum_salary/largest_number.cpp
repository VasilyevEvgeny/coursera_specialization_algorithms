#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool IsGreaterOrEqual(string lhs, string rhs) {
    return (lhs + rhs) > (rhs + lhs); 
    
//     string lhs_copy = lhs;
//     string rhs_copy = rhs;
//     int lhs_length = lhs.size();
//     int rhs_length = rhs.size();
//     int delta = abs(lhs_length - rhs_length);
    
//     if (lhs_length > rhs_length) {
//         for (int i = 0; i < delta; ++i) {
//             rhs_copy += rhs[rhs_length-1];
//         }
//     }
//     else {
//         for (int i = 0; i < delta; ++i) {
//             lhs_copy += lhs[lhs_length-1];
//         }
//     }
    
//     if (lhs_copy == rhs_copy)
//         return min(lhs, rhs);
    
//     string maximum = max(lhs_copy, rhs_copy);
//     if (maximum == lhs_copy)
//         return lhs;
//     else 
//         return rhs;
}

vector<string> UpdateVector (vector<string>& a, string digit) {
    vector<string> res;
    bool flag = false;
    for (const auto& e : a) {
        if (e == digit && flag == false) {
            flag = true;
            continue;
        }
        else {
            res.push_back(e);
        }
    }
    
    return res;
}

string largest_number(vector<string> a) {
    string answer = "";
    while (a.size()) {
        string max_digit = "0";
        for (int i = 0; i < a.size(); ++i) {
            //string maximum = find_max(max_digit, a[i]);
            //cout << maximum << endl;
            if (IsGreaterOrEqual(a[i], max_digit))
                max_digit = a[i];
        }
        answer += max_digit;
        a = UpdateVector(a, max_digit);
    }
    
    return answer;
}

int main() {
  int n = 0;
  cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    cin >> a[i];
  }
  cout << largest_number(a);
// cout << find_max("10", "100") << endl;
}

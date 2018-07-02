#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void PrintVector(const vector<uint64_t>& v) {
	cout << "vector: ";
	for (const auto& e : v)
		cout << e << " ";
	cout << endl;
}

int main() {
    
    int N = 0;
    cin >> N;
    
    vector<uint64_t> v(N);
    
    for (int i = 0; i < N; ++i)
        cin >> v[i];
    
    sort(begin(v), end(v));
    
    //PrintVector(v);

    uint64_t res = v[N-2] * v[N-1];
    cout << res;
    
    return 0;
}

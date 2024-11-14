#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <cmath>
#include <iomanip>
#include <climits>
#include <bitset>
 
typedef unsigned long long ull;
typedef long long ll;
 
using namespace std;

void iterate(int *a, int i, int size, int n, ll &count) {
    int start = 0;
    if (i > 0) {
        start = a[i-1]+1;
    }
    for (a[i] = start; a[i] < size; a[i]++) {
        if (i == n-1) {
            vector<int> subset;
            for (int k = 0; k < n; k++) {
                subset.push_back(a[k]);
            }
            ll curcount = 0;
            for (int i = 0; i < n; i++) {
                for (int j = i+1; j < n; j++) {
                    for (int k = j+1; k < n; k++) {
                        for (int l = k+1; l < n; l++) {
                            int cur = 0;
                            cur ^= subset[i];
                            cur ^= subset[j];
                            cur ^= subset[k];
                            cur ^= subset[l];
                            if (cur == 0) {
                                curcount++;
                            }
                            count = max(count, curcount);
                        }
                    }
                }
            }
        }
        else {
            iterate(a, i+1, size, n, count);
        }
    }
}
 
int main() {
    int a[64];
    for (int i = 0; i < 64; i++) {
        a[i] = i;
    }
    cout << "DONE" << endl;
    // iterate(a, 0, 4, 4, count);
    // for (int i = 4; i < 64; i++) {
    //     ll count = 0;
    //     iterate(a, 0, 64, i, count);
    //     cout << count << endl;
    // }
}
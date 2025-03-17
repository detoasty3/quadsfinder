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

ll moserDeBrujin(ll n)
{ 
    ll ans;
    // n = 0
    if (n == 0) ans = 0;
    // n = 1
    else if (n == 1) ans = 1;
    // F(2n) = 4F(n)
    else if (n % 2 == 0) ans = 4 * moserDeBrujin(n / 2);
    // F(2n + 1) = 4F(n) + 1
    else if (n % 2 == 1) ans = 4 * moserDeBrujin(n / 2) + 1;
    return ans;
}

// Finds q(k, d); source: arXiv:2310.09695
int main() {
    // d is the number of "half" (has two attributes) dimensions (i.e., the number of card properties)
        // each "full" property (has four attributes) adds two to this total
    // k is the size of the subset of cards chosen from a deck of 2^{d} cards
    // Line 44 may be adjusted to go above 64 cards
    ll count = 1;
    cout << "Size of the subset: " << 4 << "\nMax number of quads (q(k, d)): " << 1 << endl;
    for (int i = 5; i <= 64; i++) {
        count += (i * i - moserDeBrujin(i)) / 4;
        cout << "Size of the subset: " << i << "\nMax number of quads (q(k, d)): " << count << endl;
    }
}

#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif
// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>

#define ll long long int
#define endl '\n'
#define f(i, n) for (ll i = 0; i < n; i++)
#define ff(i, x, n) for (ll i = x; i < n; i++)
#define vec vector<ll>
#define all(a) a.begin(), a.end()

using namespace std;

bool sortbysec(const pair<ll, ll> &a, const pair<ll, ll> &b) {
    return (a.second < b.second);
}

struct Pair
{
    ll min;
    ll max;
};

// comparing the pairs

Pair getMinMaxPair (vec & arr, ll n) {
    Pair minmax;
    ll i;

    if(n % 2 == 0) {
        minmax.max = max(arr[0], arr[1]);
        minmax.min = min(arr[0], arr[1]);

        i = 2;
    } else {
        minmax.max = minmax.min = arr [0];

        i = 1;
    }

    while(i < n - 1) {
        if(arr[i] > arr[i + 1]) {
            minmax.max = max(arr[i], minmax.max);
            minmax.min = min(arr[i + 1], minmax.min);
        } else {
            minmax.max = max(arr[i + 1], minmax.max);
            minmax.min = min(arr[i], minmax.min);
        }

        i += 2;
    }

    return minmax;

}


// divide and conqure
Pair getMinMax (vec & arr, ll low, ll high) {

    Pair minmax, mml, mmr;

    if(low == high) {
        minmax.max = arr[low];
        minmax.min = arr[high];
        return minmax;
    }

    if(high == low + 1) {
        if(arr[low] > arr[high]) {
            minmax.max = arr[low];
            minmax.min = arr[high];
        } else{
            minmax.max = arr[high];
            minmax.min = arr[low];
        }

        return minmax;
    }

    ll mid = (low + high) / 2;

    mml = getMinMax(arr, low, mid);
    mmr = getMinMax(arr, mid + 1, high);

    if (mml.min > mmr.min)
        minmax.min = mmr.min;
    else 
        minmax.min = mml.min;

    if (mml.max > mmr.max)
        minmax.max = mml.max;
    else 
        minmax.max = mmr.max;

    return minmax;
}

void solve() {
    ll n;
    cin >> n;
    vec a(n);
    f(i, n) cin >> a[i];

    // Pair ans = getMinMax(a, 0, n-1);
    Pair ans = getMinMaxPair(a, n);

    cout << "min: " << ans.min << endl;
    cout << "max: " << ans.max << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

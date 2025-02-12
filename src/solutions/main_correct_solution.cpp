#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
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
#include <cfenv>
#include <cinttypes>
#include <cstdint>
#include <cwchar>
#include <cwctype>
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
#include <type_traits>
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
using namespace std;

#define LMAX 9223372036854775807ll
#define IMAX 2147483647
#define LMIN -9223372036854775808ll
#define IMIN -2147483648
#define all(a) a.begin(), a.end()
#define read(x) for(auto &elem : x) cin >> elem;
#define forall(x) for(auto const& e : x)

typedef unsigned long long ull;
typedef long long ll;
typedef unsigned int ui;


void solve()
{
	
}

int main(int argc, char const** argv)
{
#ifdef ABESSE
	freopen("in.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	constexpr int  mult = 0;
	int x = 1;
	if (mult)
		std::cin >> x;
	for (size_t i = 1; i <= x; i++)
	{
		solve();
	}


	return 0;
}
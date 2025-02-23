#include "testlib.h"
#include "cmdparser.h"
#include <vector>
#include <valarray>

using namespace std;


#define llparam(name, min_value, max_value) \
    const auto min_##name = opt<long long>("min_" #name, min_value); \
    const auto max_##name = opt<long long>("max_" #name, max_value); 

int main(int argc, char* argv[])
{
    registerValidation(argc, argv);

    llparam(a, 1, 1'000'000'000);

    int const a = inf.readInt(min_a, max_a, "a");

    inf.readEoln();
    inf.readEof();

    return 0;
}

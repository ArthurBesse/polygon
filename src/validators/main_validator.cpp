#include "testlib.h"
#include "cmdparser.h"
#include <vector>
#include <valarray>

using namespace std;


int main(int argc, char* argv[]) 
{
    registerValidation(argc, argv);

    const auto min_a = opt<long long>("min_a", 1);
    const auto max_a = opt<long long>("max_a", 1'000'000'000);
	
	int const a = inf.readInt(min_a, max_a, "a");

    inf.readEoln();
    inf.readEof();

    return 0;
}
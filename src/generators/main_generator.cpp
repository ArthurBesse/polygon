#include <vector>
#include <vector>

#include "testlib.h"
#include "cmdparser.h"

using namespace std;

#define set_long_param(name, min_value, max_value) \
    parser.set_optional<long long> ("min_" #name, "min_" #name, min_value); \
    parser.set_optional<long long> ("max_" #name, "max_" #name, max_value);

#define get_long_param(name) \
    const auto min_##name = parser.get<long long>("min_" #name); \
    const auto max_##name = parser.get<long long>("max_" #name);

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    rnd.setSeed(argc, argv);

    cli::Parser parser(argc, argv);
    set_long_param(a, 1, 10);
    parser.set_optional<long long>("s", "seed", 42, "Random seed");
    parser.enable_help();
    parser.run_and_exit_if_error();
    get_long_param(a);

    long long a = rnd.next(min_a, max_a);

    println(a);

    return 0;
}
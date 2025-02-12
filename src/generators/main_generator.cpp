#include <vector>
#include <vector>

#include "testlib.h"
#include "cmdparser.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    rnd.setSeed(argc, argv);

    cli::Parser parser(argc, argv);
    parser.set_optional<long long>("s", "seed", 42, "Random seed");
    parser.enable_help();
    parser.run_and_exit_if_error();

    long long a = rnd.next(1, 10);

    println(a);

    return 0;
}
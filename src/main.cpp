#include "erathostenes.hpp"

using namespace std;

int main (int argc, char *argv[]) {
    
    const int Number = atoi(argv[1]);
    bool primo [Number];
    Sieve(primo, Number);
    printPrimo(primo, Number);
    return 0;
}
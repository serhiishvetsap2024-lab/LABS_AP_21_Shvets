#include <iostream>
#include <string>
#include <array>

#include "signal_generator.h"

using namespace std;

int main() {
    sig_gen generator;

    generator.print_all();

    generator.set_type(1, "RF");
    generator.set_max_freq_hz(1, 952.4);
    generator.set_mod_present(1, false);

    generator.print(1);

    generator.read(2);

    generator.print_all();

    return 0;
}

#pragma once
#include <iostream>
#include <string>
#include <array>

#define SIZE 5

using namespace std;

typedef struct {
    string type;
    double max_freq_hz;
    bool   mod_present;
} sig_gen_s_t;

class sig_gen {
    array<sig_gen_s_t, SIZE> container;
public:
    sig_gen();
    sig_gen(array<sig_gen_s_t, SIZE> reference);

    sig_gen_s_t* get(int index);
    void         set(sig_gen_s_t* value, int index);

    void set_type(int index, const string& value);
    void set_max_freq_hz(int index, double value);
    void set_mod_present(int index, bool value);

    const string& get_type(int index);
    double        get_max_freq_hz(int index);
    bool          get_mod_present(int index);

    void print(int index);
    void print_all();
    void read(int index);
    void read_all();
};
#pragma once

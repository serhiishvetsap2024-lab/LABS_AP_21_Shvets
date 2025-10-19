#include <iostream>
#include <string>
#include <array>

#include "signal_generator.h"

#define check_index if ( index >= SIZE ) { \
    throw "Index is outside of boundries of an array!"; \
}

using namespace std;

sig_gen::sig_gen() {
    for (int i = 0; i < SIZE; ++i) {
        this->container[i] = { "", 0, false };
    }
}

sig_gen::sig_gen(array<sig_gen_s_t, SIZE> reference) {
    for (int i = 0; i < SIZE; ++i) {
        this->container[i] = reference[i];
    }
}


sig_gen_s_t* sig_gen::get(int index) {
    check_index;
    return &(this->container[index]);
}

void sig_gen::set(sig_gen_s_t* value, int index) {
    check_index;
    this->container[index] = *value;
}

void sig_gen::set_type(int index, const string& value) {
    check_index;
    this->container[index].type = value;
}
void sig_gen::set_max_freq_hz(int index, double value) {
    check_index;
    this->container[index].max_freq_hz = value;
}
void sig_gen::set_mod_present(int index, bool value) {
    check_index;
    this->container[index].mod_present = value;
}

const string& sig_gen::get_type(int index) {
    check_index;
    return this->container[index].type;
}
double sig_gen::get_max_freq_hz(int index) {
    check_index;
    return this->container[index].max_freq_hz;
}
bool sig_gen::get_mod_present(int index) {
    check_index;
    return this->container[index].mod_present;
}

void sig_gen::print(int index) {
    check_index;
    cout << "=[" << index << "]======================\n";
    cout << " Signal Type:             " << this->container[index].type << "\n";
    cout << " Maximum Frequency (Hz):  " << this->container[index].max_freq_hz << "\n";
    cout << " Modulation Present:      " << this->container[index].mod_present << "\n";
    cout << "==========================\n";
}
void sig_gen::print_all() {
    for (int i = 0; i < SIZE; ++i) {
        this->print(i);
    }
}
void sig_gen::read(int index) {
    cout << "=[" << index << "]======================\n";
    cout << " Signal Type:             ";
    cin >> this->container[index].type;
    cout << " Maximum Frequency (Hz):  ";
    cin >> this->container[index].max_freq_hz;
    cout << " Modulation Present:      ";
    cin >> this->container[index].mod_present;
    cout << "==========================\n";
}
void sig_gen::read_all() {
    for (int i = 0; i < SIZE; ++i) {
        this->read(i);
    }
}

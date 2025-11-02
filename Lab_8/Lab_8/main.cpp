#include "SignalManager.h"
#include <iostream>
#include <limits>
#include <string>
#include <cctype>
#include <windows.h>


std::string readLine(const std::string& prompt) {
    std::string s;
    std::cout << prompt;
    std::getline(std::cin, s);
    return s;
}

double readDoubleNonNegative(const std::string& prompt) {
    while (true) {
        std::string line = readLine(prompt);
        try {
            size_t start = line.find_first_not_of(" \t\r\n");
            if (start == std::string::npos) throw std::invalid_argument("empty");
            size_t end = line.find_last_not_of(" \t\r\n");
            std::string trimmed = line.substr(start, end - start + 1);
            double val = std::stod(trimmed);
            if (val < 0.0) {
                std::cout << "Error: value cannot be negative.\n";
                continue;
            }
            return val;
        }
        catch (...) {
            std::cout << "Invalid number format. Try again.\n";
        }
    }
}

bool readYesNo(const std::string& prompt) {
    while (true) {
        std::string s = readLine(prompt + " (y/n): ");
        if (s.empty()) continue;
        char c = std::tolower(s[0]);
        if (c == 'y' || c == 't') return true;
        if (c == 'n' || c == 'f') return false;
        std::cout << "Enter 'y' or 'n'.\n";
    }
}



void demoInteractive();

int main() {
   
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cout << "=== Signal Generator ===\n";
    demoInteractive();
    return 0;
}

void demoInteractive() {
    SignalManager mgr;

    while (true) {
        std::cout << "\nMenu:\n"
            << "1. Add signal to the end\n"
            << "2. Insert signal at index\n"
            << "3. Remove signal by index\n"
            << "4. Swap two signals\n"
            << "5. Show all signals\n"
            << "6. Edit signal (reference demo)\n"
            << "0. Exit\n"
            << "Choice: ";

        int choice;
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::string dummy;
            std::getline(std::cin, dummy);
            std::cout << "Invalid choice.\n";
            continue;
        }
        std::string dummy;
        std::getline(std::cin, dummy);

        if (choice == 0) break;

        if (choice == 1 || choice == 2) {
            std::string type = readLine("Enter signal type (can contain spaces): ");
            double freq = readDoubleNonNegative("Enter max frequency (Hz, >=0): ");
            bool mod = readYesNo("Has modulation?");
            Signal s(type, freq, mod);

            if (choice == 1) {
                mgr.pushBack(s);
                std::cout << "Added to the end.\n";
            }
            else {
                std::cout << "Insert index (0.." << mgr.size() << "): ";
                size_t idx;
                if (!(std::cin >> idx)) {
                    std::cin.clear();
                    std::getline(std::cin, dummy);
                    std::cout << "Invalid index.\n";
                }
                else {
                    std::getline(std::cin, dummy);
                    if (mgr.insertAt(s, idx)) {
                        std::cout << "Inserted at position " << idx << ".\n";
                    }
                    else {
                        std::cout << "Invalid index.\n";
                    }
                }
            }
        }
        else if (choice == 3) {
            std::cout << "Index to remove: ";
            size_t idx;
            if (!(std::cin >> idx)) {
                std::cin.clear();
                std::getline(std::cin, dummy);
                std::cout << "Invalid index.\n";
            }
            else {
                std::getline(std::cin, dummy);
                if (mgr.removeAt(idx)) {
                    std::cout << "Removed.\n";
                }
                else {
                    std::cout << "Invalid index.\n";
                }
            }
        }
        else if (choice == 4) {
            std::cout << "First index: ";
            size_t i, j;
            if (!(std::cin >> i)) { std::cin.clear(); std::getline(std::cin, dummy); std::cout << "Invalid index.\n"; continue; }
            std::cout << "Second index: ";
            if (!(std::cin >> j)) { std::cin.clear(); std::getline(std::cin, dummy); std::cout << "Invalid index.\n"; continue; }
            std::getline(std::cin, dummy);
            if (mgr.swapPositions(i, j)) {
                std::cout << "Swap complete.\n";
            }
            else {
                std::cout << "Invalid indexes.\n";
            }
        }
        else if (choice == 5) {
            mgr.printAll();
        }
        else if (choice == 6) {
            std::cout << "Index to edit: ";
            size_t idx;
            if (!(std::cin >> idx)) { std::cin.clear(); std::getline(std::cin, dummy); std::cout << "Invalid index.\n"; continue; }
            std::getline(std::cin, dummy);
            Signal* sPtr = mgr.getSignalRef(idx);
            if (!sPtr) {
                std::cout << "No such element.\n";
                continue;
            }

            Signal& sRef = *sPtr;
            std::cout << "Current data:\n";
            sRef.printInfo();

            std::string newType = readLine("New type (leave empty to skip): ");
            if (!newType.empty()) {
                if (!sRef.setType(newType)) std::cout << "Type change failed.\n";
            }

            std::string freqLine = readLine("New max frequency (leave empty to skip): ");
            if (!freqLine.empty()) {
                try {
                    double newFreq = std::stod(freqLine);
                    if (!sRef.setMaxFreq(newFreq)) {
                        std::cout << "Invalid frequency (must be >=0).\n";
                    }
                }
                catch (...) {
                    std::cout << "Invalid number.\n";
                }
            }

            std::string modLine = readLine("Has modulation? (y/n, leave empty to skip): ");
            if (!modLine.empty()) {
                char c = std::tolower(modLine[0]);
                if (c == 'y' || c == 't') sRef.setModulation(true);
                else if (c == 'n' || c == 'f') sRef.setModulation(false);
                else std::cout << "Ignored invalid input.\n";
            }

            std::cout << "Updated:\n";
            sRef.printInfo();
        }
        else {
            std::cout << "Unknown command.\n";
        }
    }

    std::cout << "Exiting. Goodbye!\n";
}

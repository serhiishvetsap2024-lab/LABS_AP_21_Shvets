#include "SignalManager.h"
#include <algorithm> 
#include <iostream>

void SignalManager::pushBack(const Signal& s) {
    signals_.push_back(s);
}

bool SignalManager::insertAt(const Signal& s, size_t index) {
    if (index > signals_.size()) return false; 
    signals_.insert(signals_.begin() + index, s);
    return true;
}

bool SignalManager::removeAt(size_t index) {
    if (index >= signals_.size()) return false;
    signals_.erase(signals_.begin() + index);
    return true;
}

bool SignalManager::swapPositions(size_t i, size_t j) {
    if (i >= signals_.size() || j >= signals_.size()) return false;
    if (i == j) return true;    
    std::swap(signals_[i], signals_[j]);
    return true;
}

Signal* SignalManager::getSignalRef(size_t index) {
    if (index >= signals_.size()) return nullptr;
    return &signals_[index];
}

const Signal* SignalManager::getSignalConstRef(size_t index) const {
    if (index >= signals_.size()) return nullptr;
    return &signals_[index];
}

void SignalManager::printAll(std::ostream& os) const {
    os << "Signals (" << signals_.size() << "):\n";
    for (size_t i = 0; i < signals_.size(); ++i) {
        os << "[" << i << "]\n";
        signals_[i].printInfo(os);
        os << "----------------------\n";
    }
}

size_t SignalManager::size() const {
    return signals_.size();
}

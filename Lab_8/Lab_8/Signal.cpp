#include "Signal.h"
#include <stdexcept>


Signal::Signal()
    : type_("Undefined"), maxFreq_(0.0), modulation_(false)
{
   
}


Signal::Signal(const std::string& type, double maxFreq, bool modulation)
    : type_(type), maxFreq_(0.0), modulation_(modulation)
{
    
    if (maxFreq < 0.0) {
        throw std::invalid_argument("maxFreq не може бути від'ємним");
    }
    maxFreq_ = maxFreq;
}

Signal::~Signal()
{
    
}

const std::string& Signal::getType() const {
    return type_;
}

double Signal::getMaxFreq() const {
    return maxFreq_;
}

bool Signal::hasModulation() const {
    return modulation_;
}

bool Signal::setType(const std::string& newType) {
    if (newType.empty()) return false;
    type_ = newType;
    return true;
}

bool Signal::setMaxFreq(double newMaxFreq) {
    if (newMaxFreq < 0.0) return false;
    maxFreq_ = newMaxFreq;
    return true;
}

void Signal::setModulation(bool mod) {
    modulation_ = mod;
}

void Signal::printInfo(std::ostream& os) const {
    os << "Type: " << type_ << "\n";
    os << "Max frequency: " << maxFreq_ << " Hz\n";
    os << "Modulation: " << (modulation_ ? "yes" : "no") << "\n";
}

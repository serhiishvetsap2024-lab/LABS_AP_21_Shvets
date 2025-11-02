#ifndef SIGNAL_H
#define SIGNAL_H

#include <string>
#include <iostream>

class Signal {
private:
    std::string type_;  
    double maxFreq_;     
    bool modulation_;    

public:
    
    Signal();

    
    Signal(const std::string& type, double maxFreq, bool modulation);

   
    Signal(const Signal& other) = default;

  
    Signal& operator=(const Signal& other) = default;

    
    ~Signal();

   
    const std::string& getType() const;
    double getMaxFreq() const;
    bool hasModulation() const;

    
    bool setType(const std::string& newType);
    bool setMaxFreq(double newMaxFreq);
    void setModulation(bool mod);

    void printInfo(std::ostream& os = std::cout) const;
};

#endif 

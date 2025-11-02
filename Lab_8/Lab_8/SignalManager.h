#ifndef SIGNALMANAGER_H
#define SIGNALMANAGER_H

#include "Signal.h"
#include <vector>
#include <optional>

class SignalManager {
private:
    std::vector<Signal> signals_;

public:
    SignalManager() = default;
    ~SignalManager() = default;

    
    void pushBack(const Signal& s);

   
    bool insertAt(const Signal& s, size_t index);

   
    bool removeAt(size_t index);

   
    bool swapPositions(size_t i, size_t j);

   
    Signal* getSignalRef(size_t index);

   
    const Signal* getSignalConstRef(size_t index) const;

    
    void printAll(std::ostream& os = std::cout) const;

   
    size_t size() const;
};

#endif

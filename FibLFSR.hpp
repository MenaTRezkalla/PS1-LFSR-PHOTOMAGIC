// Copyright 2025 Mena Rezkalla
#pragma once

#include <iostream>
#include <string>
#include <bitset>

namespace PhotoMagic {
class FibLFSR {
 public:
    explicit FibLFSR(const std::string& seed);
    explicit FibLFSR(unsigned int seed);  // Optional

    static FibLFSR fromPassword(const std::string& password);  // Optional

    friend std::ostream& operator<<(std::ostream& out, const FibLFSR& lfsr);

    int step();
    int generate(int k);
 private:
    unsigned int reg;
    int size;
    int getBit(int seed, int i) const;
    int charToBit(char c) const;
    void checkValidConstructor(const std::string& seed);
    void checkValidInput(int input);
};

/*
int FibLFSR::getBit(int seed, int i) const {
    return (seed >> i) & 1;
}

int FibLFSR::charToBit(char c) const {
    if(c == '1')
        return 1;
    else if (c == '0')
        return 0;
    
    return -1;
}

void FibLFSR::checkValidConstructor(const std::string& seed) {
    int length = seed.length();
    if(length != 16)
        throw std::invalid_argument("Argument string is the wrong length");
    else
    {
        for(int i = 0; i < length; i++)
        {
            if(seed[i] != '0' && seed[i] != '1')
                throw std::invalid_argument("Argument string has characters other than '0' or '1'");
        }
    }
}

void FibLFSR::checkValidInput(int input) {
    if(input < 0)
        throw std::invalid_argument("Invalid number of steps");
}

FibLFSR::FibLFSR(const std::string& seed) {
    checkValidConstructor(seed);
    reg = 0;
    size = seed.length() - 1;
    for(int i = 0; i < size + 1; i++)
        reg |= charToBit(seed[i]) << (size - i); 
}

std::ostream& operator<<(std::ostream& out, const FibLFSR& lfsr) {
    for(int i = 0; i < lfsr.size + 1; i++)
        out << lfsr.getBit(lfsr.reg, lfsr.size - i);
    return out;
}

int FibLFSR::step() {
    int t13, t12, t10;
    int newBit;
    t13 = getBit(reg, 13);
    t12 = getBit(reg, 12);
    t10 = getBit(reg, 10);
    newBit = ((getBit(reg, size) ^ t13) ^ t12) ^ t10;
    reg = reg << 1;
    reg |= newBit << 0;
    return newBit;
}
    
int FibLFSR::generate(int k) {
    checkValidInput(k);
    int gen = 0;
    for(int i = 0; i < k; i++)
        gen = (gen * 2) + step();
    return gen;
}
*/

}  // namespace PhotoMagic

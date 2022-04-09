/*encode.h*/

#include <bitset>
#include <vector>

using namespace std;

#ifndef ENCODE_H
#define ENCODE_H

class Encode {
    public:
    vector<bitset<1>> encode(vector<bitset<1>> bits) {
        vector<bitset<1>> coded_bits;
        int position;
        
        //  -_-_-_setting the first bit-_-_-_
        coded_bits.push_back(0);    // cause we got only
                                    // 2 var-s 00 or 01

        if(bits[0] == 0) {
            coded_bits.push_back(0);
            position = 0;
        } else {
            coded_bits.push_back(1);
            position = 1;
        }

        for(int i = 1; i < bits.size(); i++) {
            if(position == 0) {
                if(bits[i] == 0) {      // 00 --> 11
                    coded_bits.push_back(1);
                    coded_bits.push_back(1);
                    position = 11;
                } else {                // 00 --> 01
                    coded_bits.push_back(0);
                    coded_bits.push_back(1);
                    position = 1;
                }
            } else if(position == 1) {
                if(bits[i] == 0) {      // 01 --> 11
                    coded_bits.push_back(1);
                    coded_bits.push_back(1);
                    position = 11;
                } else {                // 01 --> 10
                    coded_bits.push_back(1);
                    coded_bits.push_back(0);
                    position = 10;
                }
            } else if(position == 10) {
                if(bits[i] == 0) {      // 10 --> 00
                    coded_bits.push_back(0);
                    coded_bits.push_back(0);
                    position = 0;
                } else {                // 10 --> 01
                    coded_bits.push_back(0);
                    coded_bits.push_back(1);
                    position = 1;
                }
            } else if(position == 11) {
                if(bits[i] == 0) {      // 11 --> 00
                    coded_bits.push_back(0);
                    coded_bits.push_back(0);
                    position = 0;
                } else {                // 11 --> 10
                    coded_bits.push_back(1);
                    coded_bits.push_back(0);
                    position = 10;
                }
            }
        }
        return coded_bits;
    }
};

#endif
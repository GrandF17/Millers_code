/*decode.h*/

#include <bitset>
#include <vector>

using namespace std;

#ifndef DECODE_H
#define DECODE_H

class Decode {
    public:
    vector<bitset<1>> decode(vector<bitset<1>> bits) {
        vector<bitset<1>> decoded_bits;
        int position;

        //  -_-_-_setting the first 2 bits-_-_-_
        if(bits[0] == 0) {
            if(bits[1] == 0) {
                decoded_bits.push_back(0);
                position = 0;
            } else {
                decoded_bits.push_back(1);
                position = 1;
            }
        }

        for(int i = 2; i < bits.size(); i += 2) {
            if(position == 0) {
                if(bits[i] == 0) {      // --> 01
                    decoded_bits.push_back(1);
                    position = 1;
                } else {                // --> 11
                    decoded_bits.push_back(0);
                    position = 11;
                }
            } else if(position == 1) {
                if(bits[i + 1] == 0) {  // --> 10
                    decoded_bits.push_back(1);
                    position = 10;
                } else {                // --> 11
                    decoded_bits.push_back(0);
                    position = 11;
                }
            } else if(position == 10) {
                if(bits[i + 1] == 0) {  // --> 00
                    decoded_bits.push_back(0);
                    position = 0;
                } else {                // --> 01
                    decoded_bits.push_back(1);
                    position = 1;
                }
            } else if(position == 11) {
                if(bits[i] == 0) {      // --> 00
                    decoded_bits.push_back(0);
                    position = 0;
                } else {                // --> 10
                    decoded_bits.push_back(1);
                    position = 10;
                }
            }
        }

        return decoded_bits;
    }
};

#endif
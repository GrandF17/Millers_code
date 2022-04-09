#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "encode.h"
#include "decode.h"

using namespace std;

//  -_-_-_-_to transform string to vactor of bits-_-_-_-_
vector<bitset<1>> get_bits(string s) {
    vector<bitset<1>> bits;
    for(int i = 0; s[i] != '\0'; i++) {
        int c = s[i];

        for(int power = 7; power + 1; power--) {
            if(c >= (1 << power)) {
                c -= (1 << power); 
                bits.push_back(1);
            }
            else { bits.push_back(0); }
        }
    }
    return bits;
}

//  -_-_-_-_-_-to generate random bit sequences-_-_-_-_-_
vector<bitset<1>> gen_bits() {
    vector<bitset<1>> bits;

    srand(time(NULL));
    int size = rand() % 30;

    cout << "Size = " << size << endl;
    for(int i = 0; i < size; i++) {
        bits.push_back(rand());
    }
    return bits;
}

int main(){
    // string s = "abc";
    vector<bitset<1>> bits = gen_bits()  /* get_bits(s) */;
    /* {1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1} */ // <-- exaple like in the course work to test the correctness

    //  -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
    cout << "Initial sequence: \t";
    for(int i = 0; i < bits.size(); i++) {
        cout << bits[i] << "  ";
    }
    cout << "\n";
    //  -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

    //  -_-_-_Coding our sequence here-_-_-_
    Encode a;
    vector<bitset<1>> Mcode = a.encode(bits);

    //  -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
    cout << "Miller code sequence: \t";
    for(int i = 0; i < Mcode.size(); i++) {
        if(i % 2 == 0 && i != 0) {
            cout << ".";   
        }
        cout << Mcode[i];
    }
    cout << "\n";
    //  -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

    //  _-_-_Decoding our sequence here_-_-_
    Decode b;
    vector<bitset<1>> Mdecode = b.decode(Mcode);

    //  -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
    cout << "Result sequence: \t";
    for(int i = 0; i < Mdecode.size(); i++) {
        cout << Mdecode[i] << "  ";
    }
    cout << "\n";
    //  -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

    cout << "Two vectros are equal: " << (bits == Mdecode ? "\ttrue" : "\tfalse") << endl;
}
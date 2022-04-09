
#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

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

vector<bitset<1>> code(vector<bitset<1>> bits) {
    vector<bitset<1>> coded_bits;
    int position;
    coded_bits.push_back(0);
    if(bits[0] == 0) {
        position = 0;
        coded_bits.push_back(0);
    } else {
        position = 1;
        coded_bits.push_back(1);
    }

    for(int i = 1; i < bits.size(); i++) {
        if(position == 0) {
            if(bits[i] == 0) {
                coded_bits.push_back(1);
                coded_bits.push_back(1);
                position = 11;
            } else {
                coded_bits.push_back(0);
                coded_bits.push_back(1);
                position = 1;
            }
        } else if(position == 1) {
            if(bits[i] == 0) {
                coded_bits.push_back(1);
                coded_bits.push_back(1);
                position = 11;
            } else {
                coded_bits.push_back(1);
                coded_bits.push_back(0);
                position = 10;
            }
        } else if(position == 10) {
            if(bits[i] == 0) {
                coded_bits.push_back(0);
                coded_bits.push_back(0);
                position = 0;
            } else {
                coded_bits.push_back(0);
                coded_bits.push_back(1);
                position = 1;
            }
        } else if(position == 11) {
            if(bits[i] == 0) {
                coded_bits.push_back(0);
                coded_bits.push_back(0);
                position = 0;
            } else {
                coded_bits.push_back(1);
                coded_bits.push_back(0);
                position = 10;
            }
        }
    }
    return coded_bits;
}

vector<bitset<1>> decode(vector<bitset<1>> bits) {
    vector<bitset<1>> coded_bits;
    int position;

    if(bits[0] == 0) {
        if(bits[1] == 0) {
            coded_bits.push_back(0);
            position = 0;
        } else {
            coded_bits.push_back(1);
            position = 1;
        }
    }

    for(int i = 2; i < bits.size(); i += 2) {
        if(position == 0) {
            if(bits[i] == 0) {  // --> 01
                coded_bits.push_back(1);
                position = 1;
            } else {            // --> 11
                coded_bits.push_back(0);
                position = 11;
            }
        } else if(position == 1) {
            if(bits[i + 1] == 0) { // --> 10
                coded_bits.push_back(1);
                position = 10;
            } else {               // --> 11
                coded_bits.push_back(0);
                position = 11;
            }
        } else if(position == 10) {
            if(bits[i + 1] == 0) {  // --> 00
                coded_bits.push_back(0);
                position = 0;
            } else {                // --> 01
                coded_bits.push_back(1);
                position = 1;
            }
        } else if(position == 11) {
            if(bits[i] == 0) {  // --> 00
                coded_bits.push_back(0);
                position = 0;
            } else {            // --> 10
                coded_bits.push_back(1);
                position = 10;
            }
        }
    }

    return coded_bits;
}

int main(){
    string s = "abc";
    vector<bitset<1>> bits = get_bits(s) /*  */ /* {1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1} */;

    for(int i = 0; i < bits.size(); i++) { 
        cout << "( " << bits[i] << " )";
        if(i < bits.size() - 1) { cout << ", "; }
    }
    cout << "\n";

    vector<bitset<1>> Mcode = code(bits);
    for(int i = 0; i < Mcode.size(); i++) {
        if(i % 2 == 0 && i != 0) {
            cout << ".";   
        }
        cout << Mcode[i];
    }
    cout << "\n";

    vector<bitset<1>> Mdecode = decode(Mcode);
    for(int i = 0; i < Mdecode.size(); i++) { 
        cout << "( " << Mdecode[i] << " )";
        if(i < Mdecode.size() - 1) { cout << ", "; }
    }
    cout << "\n";
}

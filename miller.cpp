
#include <iostream>
#include <vector>

using namespace std;

vector<int> get_bits(string s) {
    vector<int> bits;
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

vector<int> code(vector<int> bits) {
    vector<int> coded_bits;
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

int main(){
    string s = "abcdefg";
    vector<int> bits = /* get_bits(s) */ {1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1};

    vector<int> Mcode = code(bits);

    for(int i = 0; i < Mcode.size(); i++) {
        if(i % 2 == 0 && i != 0) {
            cout << ".";   
        }
        cout << Mcode[i];
    }
}
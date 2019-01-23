#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class FullAdder {
    public:
        bitset<1> A;
        bitset<1> B;
        bitset<1> Cin;
        bitset<1> Cout;
        bitset<1> S;
        void add(){
            S = (A ^ B) ^ Cin;
            Cout = (A & B) | (Cin & (A ^ B));
        }
};


int main (int argc, char **argv){
    unsigned char number1;
    unsigned char number2;
    long sum = 0;

    FullAdder adder[16]; //8-bit adder

    if(argc < 3 ){
        cerr << "2 numbers are required" << endl;
        return -1;
    }

    number1 = (unsigned char) atoi(argv[1]);
    number2 = (unsigned char) atoi(argv[2]);
    
    for(unsigned char i=0;i<16;i++){
        // adder code
        if(i-1>-1)
            adder[i].Cin = adder[i-1].Cout;
        adder[i].A[0] = number1 & 0b0001;
        adder[i].B[0] = number2 & 0b0001;
        adder[i].add();
        number1 = number1>>1;
        number2 = number2>>1;
        sum = sum | (adder[i].S.to_ulong() << i);
    }
    
    
    cout << (unsigned int) sum;
}

#include <iostream>
#include <cctype>
#include <string> 
#include "caesar.h"
#include "vigenere.h"

char shiftChar(char c, int rshift) {
    char a; 
        if(isupper(c)){
            a = (c - 'A' + rshift) % 26 + 'A'; 
        }
        else if(islower(c)){
            a = (c - 'a' + rshift ) % 26 + 'a'; 
        }
     else {
        return c;
    }
    return a;

}

std::string encryptCaesar(std::string plaintext, int rshift) {
    std::string result = ""; 
    for (int i = 0; i < plaintext.length(); i++) {
        result += shiftChar(plaintext[i],rshift);
    }

return result; 
}
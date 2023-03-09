#include <iostream>
#include "test-ascii.h"
#include "caesar.h"
#include "vigenere.h"
#include "decrypt.h"


int main()
{
std::cout << encryptCaesar("Way to Go!",5) << '\n';  
std::cout << encryptVigenere("Hello, World!", "cake")<< '\n'; 
std::cout << decryptCaesar("Rovvy, Gybvn!", 10)<< '\n'; 
std::cout << decryptVigenere("Jevpq, Wyvnd!", "cake")<< '\n'; 


return 0;
}

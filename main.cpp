#include <iostream>
#include "test-ascii.h"
#include "caesar.h"
#include "vigenere.h"
#include "decryption.h"


int main()
{
std::cout << encryptCaesar("Way to Go!",5) << '\n';  
std::cout << encryptVigenere("Hello, World!", "cake")<< '\n'; 
std::cout << decryptCaesar("Rovvy, Gybvn!", 10)<< '\n'; 
std::cout << decryptVigenere("Jevpq, Wyvnd!", "cake")<< '\n'; 
std::cout << solve(encryptCaesar("I love cats and dogs", 5)) << std::endl;    
std::cout << solve(encryptCaesar("I love cats from the moon and back", 10)) << std::endl;

return 0;
}

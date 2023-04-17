#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "caesar.h"
#include "vigenere.h"
#include "decrypt.h"

TEST_CASE("encryptCaesar") {
  CHECK(encryptCaesar("Way to Go!",5) == "Bfd yt Lt!");
  CHECK(encryptCaesar("A Light-Year Apart",7) == "H Spnoa-Flhy Hwhya");
  CHECK(encryptCaesar("Hello, World!",10) == "Rovvy, Gybvn!");
  CHECK(encryptCaesar("I! love! you!", 20) == "C! fipy! sio!");
}

TEST_CASE("encryptVigenere") {
  CHECK(encryptVigenere("Hello, World!", "cake") == "Jevpq, Wyvnd!");
  CHECK(encryptVigenere("Big bakery", "helo") == "Imr phopff");
  CHECK(encryptVigenere("Tonight is the night", "quacker") == "Jinkqlk ym tjo rzwbt");
  CHECK(encryptVigenere("ILOVEYOU", "crack") == "KCOXOAFU");

}

TEST_CASE("decryptCaesar") {
  CHECK(decryptCaesar("Rovvy, Gybvn!", 10) == "Hello, World!");
  CHECK(decryptCaesar("Frgh Fdhvdu", 3) == "Code Caesar");
  CHECK(decryptCaesar("Travhf jvgubhg rqhpngvba vf yvxr fvyire va gur zvar.", 13) == "Genius without education is like silver in the mine.");
  CHECK(decryptCaesar("!Tjp vmz ocz xjjgzno!", 21) == "!You are the coolest!");
}

TEST_CASE("decryptVigenere") {
  CHECK(decryptVigenere("Jevpq, Wyvnd!", "cake") == "Hello, World!");
  CHECK(decryptVigenere("RIJVS KI JPSILN", "key") == "HELLO MY FRIEND");
  CHECK(decryptVigenere("DIEZI BSSUD ZFY TYERC", "break") == "CRAZY ABOUT YOU TODAY");
  CHECK(decryptVigenere("FYYRD IU NVZI", "cheetah") == "DRUNK IN LOVE");
}

TEST_CASE("letter frequency") {
  CHECK(letter_frequency("o", "ooooo") == 100);
  CHECK(letter_frequency("o", "ow") == 50);
  CHECK(letter_frequency('a', "Aopz pz qbza h alza.") == doctest::Approx(0.2));
}

TEST_CASE("distance vectors ") {
  std::vector<double> vec = {1, 2, 3};
  std::vector<double> vec1 = {1, 2};
  CHECK(distance(vec, vec1) == 0.0);
  CHECK(distance(vec1, vec) == -1.0);
}

TEST_CASE("solve") {
  CHECK(solve(encryptCaesar("I love cats and dogs", 5)) == "I love cats and dogs");    
  CHECK(solve(encryptCaesar("I love cats from the moon and back", 10)) == "I love cats from the moon and back");
}







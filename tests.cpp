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





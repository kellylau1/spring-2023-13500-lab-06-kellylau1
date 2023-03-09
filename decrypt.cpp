#include <iostream>
#include <string>
#include "decrypt.h"

char shift_back(char c, int rshift) {
  char a;
  if (isupper(c)) {
    a = (c - 'A' - rshift + 26) % 26 + 'A';
  } else if (islower(c)) {
    a = (c - 'a' - rshift + 26) % 26 + 'a';
  } else {
    return c;
  }
  return a;
}

std::string decryptCaesar(std::string ciphertext, int rshift) {
  std::string decrypted = "";
  for (int i = 0; i < ciphertext.length(); i++) {
    decrypted += shift_back(ciphertext[i], rshift);
  }
  return decrypted;
}

std::string decryptVigenere(std::string ciphertext, std::string keyword) {
  std::string decrypted = "";
  int arr[keyword.length()];
  int keyword_index = 0;
  for (int i = 0; i < keyword.length(); i++) {
    arr[i] = int(keyword[i]) - 97;
  }
  for (int i = 0; i < ciphertext.length(); i++) {
    if (!isalpha(ciphertext[i])) {
      decrypted += ciphertext[i];
    } else {
      decrypted = decrypted + shift_back(ciphertext[i],
      arr[keyword_index % keyword.length()]);
      keyword_index++;
    }
  }
  return decrypted;
}
#include <iostream>
#include <string>
#include "caesar.h"
#include "vigenere.h"

std::string encryptVigenere(std::string plaintext, std::string keyword) {
  int keyword_index = 0;
  std::string encrypted = "";
  int arr[keyword.length()];
  for (int i = 0; i < keyword.length(); i++) {
    arr[i] = int(keyword[i]) - 97;
  }
  for (int i = 0; i < plaintext.length(); i++) {
    if (!isalpha(plaintext[i])) {
      encrypted += plaintext[i];
    } else {
      encrypted = encrypted + shiftChar(plaintext[i],arr[keyword_index % keyword.length()]);
      keyword_index++;
    }
  }

  return encrypted;
}
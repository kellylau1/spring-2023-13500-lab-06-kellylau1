#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "decryption.h"

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


//calculate the distance using the distance formula between 2 arrays of 26 elements.
double distance_vectors(std::vector<double> vec1, std::vector<double> vec2) {
  double total_distance = 0.0;
  for (int i = 0; i < vec1.size(); i++) {
    total_distance += pow(vec2[i]- vec1[i],2.0); 
  }
return sqrt(total_distance); 
}

//A function that takes a string and returns a frequency string.
double letter_frequency(char letter, std::string sentence) {
  int occurences = 0; 
  for (int i = 0; i < sentence.length(); i++) { 
    if (tolower(sentence[i]) == tolower(letter)) {
      occurences++; 
    }
  }
  double occurence_percentage = occurences/(sentence.length()); 
return occurence_percentage; 
}

//A function that takes a string and returns a frequency string.
std::vector<double> string_frequency(std::string sentence) {
  std::vector <double> vec; 
  std::vector <char> alphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  for (int i = 0; i < alphabet.size(); i++) {
    vec.push_back(letter_frequency(alphabet[i], sentence)); 
  }
  return vec; 
}

std::string solve(std::string encrypted_string) {
  int counter = 0; 
  //frequency of each letter in encrypted string
  std::vector <double> encrypted_string_freq = string_frequency(encrypted_string);
  //alphabet frequencies 
  std::vector <double> alphabet_frequency = {8.2,1.5,2.8,4.3,13,2.2,2,6.1,7,.15,.77,4,2.4,6.7,7.5,1.9,.095,6,6.3,9.1,2.8,.98,2.4,.15,2,.074}; 
  double min_distance = distance_vectors(encrypted_string_freq, alphabet_frequency); 

  for (int i = 0; i < 26; i++) {
    if (distance_vectors(string_frequency(decryptCaesar(encrypted_string, i)), alphabet_frequency) < min_distance) {
      min_distance = distance_vectors(string_frequency(decryptCaesar(encrypted_string, i)), alphabet_frequency); 
      counter = i; 
    }
  }
  std::string result = decryptCaesar(encrypted_string, counter);
return result; 
}



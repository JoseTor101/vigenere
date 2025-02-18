#ifndef VIGENERE_H
#define VIGENERE_H


#include <iostream>
#include <vector>
using namespace std;

const string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890 ,!.¿?*+-/(){}[]=<>@#$%&:_;'";
const int ALPHABET_SIZE = ALPHABET.size();

vector<vector<char>> generateVigenereMatrix(const string& alphabet, int size);
void printMatrix(const vector<vector<char>>& matrix);

class Vigenere{
    private:
        char *key;
        char *alphabet;
        char *fileInputPath;
        int key_size;
        int alphabet_size;
        char *encrypt(char *text);
        char *decrypt(char *text);
        char *read_file(const char *filename);
        void write_file(const char *filename, char *content);
    public:
        Vigenere(char *key);
        void encrypt_file(const char *filename);
        void decrypt_file(const char *filename);
};

#endif
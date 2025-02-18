#include "vigenere.h"
#include <fcntl.h>
#include <unistd.h>
#include <cstring>

// Function to generate the Vigenere matrix using the given alphabet
vector<vector<char>> generateVigenereMatrix(const string& alphabet, int size) {
    vector<vector<char>> matrix(size, vector<char>(size));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = alphabet[(j + i) % size];
        }
    }
    return matrix;
}

// Function to print the Vigenere matrix
void printMatrix(const vector<vector<char>>& matrix) {
    for (const auto& row : matrix) {
        for (char c : row) {
            cout << c << " ";
        }
        cout << endl;
    }
}

// Constructor for the Vigenere class
Vigenere::Vigenere(char *key) {
    this->key = key;
    this->key_size = strlen(key);
    this->alphabet = new char[ALPHABET_SIZE];
    strcpy(this->alphabet, ALPHABET.c_str());
    this->alphabet_size = ALPHABET_SIZE;
}

// Method to encrypt a text
char* Vigenere::encrypt(char *text) {
    int text_size = strlen(text);
    char *encrypted = new char[text_size + 1];
    for (int i = 0; i < text_size; i++) {
        int key_index = i % key_size;
        int text_index = strchr(alphabet, text[i]) - alphabet;
        int shift = strchr(alphabet, key[key_index]) - alphabet;
        encrypted[i] = alphabet[(text_index + shift) % alphabet_size];
    }
    encrypted[text_size] = '\0';
    return encrypted;
}

// Method to decrypt a text
char* Vigenere::decrypt(char *text) {
    int text_size = strlen(text);
    char *decrypted = new char[text_size + 1];
    for (int i = 0; i < text_size; i++) {
        int key_index = i % key_size;
        //cout << "i: " << i << " KS: " << key_size << " KI:" << key_index << endl;
        int text_index = strchr(alphabet, text[i]) - alphabet;
        int shift = strchr(alphabet, key[key_index]) - alphabet;
        decrypted[i] = alphabet[(text_index - shift + alphabet_size) % alphabet_size];
    }
    decrypted[text_size] = '\0';
    return decrypted;
}

// Method to read a file using system calls
char* Vigenere::read_file(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        cerr << "Error opening file: " << filename << endl;
        return nullptr;
    }
    off_t file_size = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);
    char *text = new char[file_size + 1];
    read(fd, text, file_size);
    text[file_size] = '\0';
    close(fd);
    return text;
}

// Method to write to a file using system calls
void Vigenere::write_file(const char *filename, char *content) {
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }
    write(fd, content, strlen(content));
    close(fd);
}

// Method to encrypt a file
void Vigenere::encrypt_file(const char *filename) {
    char *text = read_file(filename);
    if (text) {
        char *encrypted = encrypt(text);
        write_file(filename, encrypted);
        delete[] text;
        delete[] encrypted;
    }
}

// Method to decrypt a file
void Vigenere::decrypt_file(const char *filename) {
    char *text = read_file(filename);
    if (text) {
        char *decrypted = decrypt(text);
        string new_filename = string("decrypted_") + filename;
        write_file(new_filename.c_str(), decrypted);
        delete[] text;
        delete[] decrypted;
    }
}
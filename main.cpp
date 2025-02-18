#include <iostream>
#include "vigenere.h"
#include <cstring>

int main(int argc, char* argv[]) {

    vector<vector<char>> vigenereMatrix = generateVigenereMatrix(ALPHABET, ALPHABET_SIZE);
    //printMatrix(vigenereMatrix);
    //char key[] = "KEY";
    char* key;
    
    for (int i = 0; i < argc; ++i) {
        if (std::string(argv[i])=="-h" || std::string(argv[i])=="--help") {

            std::cout << "-----------------------------------------------------------------" << std::endl;
            std::cout << "This program is intended to work EXCLUSEVELY with text files" << std::endl;
            std::cout << "-----------------------------------------------------------------" << std::endl;
            std::cout << "Usage: " << argv[0] << " [OPTION]... [FILE]... [KEY]" << std::endl;
            std::cout << "Encrypt or decrypt a file using the Vigenere cipher." << std::endl;
            std::cout << "Options:" << std::endl;
            std::cout << "  -h, --help\t\tDisplay this help and exit" << std::endl;
            std::cout << "  -e, --encrypt\t\tEncrypt the file" << std::endl;
            std::cout << "  -d, --decrypt\t\tDecrypt the file" << std::endl;
            return 0;
        }
        else if (std::string(argv[i])=="-e" || std::string(argv[i])=="--encrypt") {

            if (i + 2 < argc) {
                try{
                    key = argv[i+2];
                    Vigenere vigenere(key);
                    vigenere.encrypt_file(argv[i+1]);
                    std::cout << "File encrypted" << std::endl;
                }catch(...){
                    std::cout << "File not found" << std::endl;
                }
            } else {
                std::cout << "Insufficient arguments for decryption" << std::endl;
            }

        }
        else if (std::string(argv[i])=="-d" || std::string(argv[i])=="--decrypt") {

            if (i + 2 < argc) {
                try{
                    key = argv[i+2];
                    Vigenere vigenere(key);
                    vigenere.decrypt_file(argv[i+1]);
                    std::cout << "File decrypted" << std::endl;
                }catch(...){
                    std::cout << "File not found" << std::endl;
                }
            } else {
                std::cout << "Insufficient arguments for decryption" << std::endl;
            }

        }
    }

    return 0;
}
#include <iostream>
#include "vigenere.h"

int main(int argc, char* argv[]) {

    vector<vector<char>> vigenereMatrix = generateVigenereMatrix(ALPHABET, ALPHABET_SIZE);

    char key[] = "KEY";
    Vigenere vigenere(key);
    
    for (int i = 0; i < argc; ++i) {
        if (std::string(argv[i])=="-h" || std::string(argv[i])=="--help") {
            std::cout << "Usage: " << argv[0] << " [OPTION]... [FILE]..." << std::endl;
            std::cout << "Encrypt or decrypt a file using the Vigenere cipher." << std::endl;
            std::cout << "Options:" << std::endl;
            std::cout << "  -h, --help\t\tDisplay this help and exit" << std::endl;
            std::cout << "  -e, --encrypt\t\tEncrypt the file" << std::endl;
            std::cout << "  -d, --decrypt\t\tDecrypt the file" << std::endl;
            return 0;
        }
        else if (std::string(argv[i])=="-e" || std::string(argv[i])=="--encrypt") {

            try{
                vigenere.encrypt_file(argv[i+1]);
            }catch(...){
                std::cout << "File not found" << std::endl;
            }

            std::cout << "File encrypted" << std::endl;

        }
        else if (std::string(argv[i])=="-d" || std::string(argv[i])=="--decrypt") {

            try{
                vigenere.decrypt_file(argv[i+1]);
            }catch(...){
                std::cout << "File not found" << std::endl;
            }

            std::cout << "File decrypted" << std::endl;

        }
    }

    return 0;
}
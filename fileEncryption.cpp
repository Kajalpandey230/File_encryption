#include <iostream>
#include <fstream>
#include <string>

// Function to encrypt a character using Caesar cipher
char encryptChar(char ch, int shift) {
    if (isalpha(ch)) {  // Check if the character is an alphabet
        char offset = isupper(ch) ? 'A' : 'a';  // Determine if it's uppercase or lowercase
        return (ch - offset + shift) % 26 + offset;  // Apply shift
    }
    return ch;  // Return non-alphabet characters as they are
}

// Function to decrypt a character using Caesar cipher
char decryptChar(char ch, int shift) {
    if (isalpha(ch)) {  // Check if the character is an alphabet
        char offset = isupper(ch) ? 'A' : 'a';  // Determine if it's uppercase or lowercase
        return (ch - offset - shift + 26) % 26 + offset;  // Apply reverse shift
    }
    return ch;  // Return non-alphabet characters as they are
}

// Function to display the contents of a file
void displayFile(const std::string& filename) {
    std::ifstream inputFile(filename);  // Open input file for reading

    if (!inputFile.is_open()) {  // Check if the file is open
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string line;
    std::cout << "\nContents of " << filename << ":" << std::endl;
    while (std::getline(inputFile, line)) {  // Read the file line by line
        std::cout << line << std::endl;  // Print each line to the console
    }

    inputFile.close();  // Close the input file
}

// Function to encrypt the contents of a file and write to another file
void encryptFile(const std::string& inputFilename, const std::string& outputFilename, int shift) {
    std::ifstream inputFile(inputFilename);  // Open input file for reading
    std::ofstream outputFile(outputFilename);  // Open output file for writing

    if (!inputFile.is_open() || !outputFile.is_open()) {  // Check if files are open
        std::cerr << "Error opening file." << std::endl;
        return;
    }

    char ch;
    while (inputFile.get(ch)) {  // Read character by character from the input file
        outputFile.put(encryptChar(ch, shift));  // Encrypt each character and write to the output file
    }

    inputFile.close();  // Close the input file
    outputFile.close();  // Close the output file

    std::cout << "File encrypted successfully." << std::endl;
    displayFile(outputFilename);  // Display the encrypted content
}

// Function to decrypt the contents of a file and write to another file
void decryptFile(const std::string& inputFilename, const std::string& outputFilename, int shift) {
    std::ifstream inputFile(inputFilename);  // Open input file for reading
    std::ofstream outputFile(outputFilename);  // Open output file for writing

    if (!inputFile.is_open() || !outputFile.is_open()) {  // Check if files are open
        std::cerr << "Error opening file." << std::endl;
        return;
    }

    char ch;
    while (inputFile.get(ch)) {  // Read character by character from the input file
        outputFile.put(decryptChar(ch, shift));  // Decrypt each character and write to the output file
    }

    inputFile.close();  // Close the input file
    outputFile.close();  // Close the output file

    std::cout << "File decrypted successfully." << std::endl;
    displayFile(outputFilename);  // Display the decrypted content
}

// Main function to run the encryption and decryption program
int main() {
    std::string inputFilename = "sample.txt";  // Name of the input file to encrypt/decrypt
    std::string encryptedFilename = "sample2.txt";  // Name of the file to save encrypted content
    int choice;  // Variable to store the user's choice
    int shift = 0;  // Caesar cipher shift value

    do {
        // Display menu options
        std::cout << "\nFile Encryption/Decryption Menu\n";
        std::cout << "2. Encrypt File\n";
        std::cout << "3. Show File Content\n";
        std::cout << "4. Decrypt File\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;  // Get the user's choice

        switch (choice) {
            case 2: {
                // Encrypt the file
                std::cout << "Enter the shift value for Caesar cipher: ";
                std::cin >> shift;  // Get shift value from the user
                encryptFile(inputFilename, encryptedFilename, shift);  // Encrypt the file and display the encrypted content
                break;
            }
            case 3: {
                // Display the contents of the file
                std::cout << "Enter filename to display (sample.txt, sample2.txt): ";
                std::string filename;
                std::cin >> filename;
                displayFile(filename);  // Display the contents of the specified file
                break;
            }
            case 4: {
                // Decrypt the file
                std::cout << "Enter the shift value for Caesar cipher: ";
                std::cin >> shift;  // Get shift value from the user
                decryptFile(encryptedFilename, encryptedFilename, shift);  // Decrypt the file and display the decrypted content
                break;
            }
            case 0:
                // Exit the application
                std::cout << "Exiting the program." << std::endl;
                break;
            default:
                // Handle invalid menu choices
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    } while (choice != 0);  // Continue looping until the user chooses to exit

    return 0;2
}
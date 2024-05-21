#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#include <set>
#include <bits/stdc++.h>

/*
 *   //- GLOBAL VARIABLES
 * */
std::vector<int> primeStorage;
int PUBLIC_KEY;
int PRIVATE_KEY;
int N;

/*
 *   //- FUNCTION DECLARATIONS
 * */
void fillPrimes();
int selectPrime();
void setKeys();
long long int encryptMSG(double message);
long long int decryptMSG(int encryptedMSG);
std::vector<int> encode(std::string message);
std::string decode(std::vector<int> encodedMSG);

/*
 *   //- MAIN
 * */
int main() {
    fillPrimes();
    setKeys();
    std::string message;
    std::cout << "Enter Initial Message: ";
    std::getline(std::cin, message);
    std::cout << "\nInitial Message: " << message << std::endl;
    std::vector<int> coded = encode(message);
    std::cout << "\nEncoded Message: ";
    for (int i = 0; i < coded.size(); i++) {
        std::cout << coded[i];
    }
    std::cout << "\n\nDecoded Message: " << decode(coded) << std::endl;

    return 0;
}

// *****************************************************************
// * Function Name: fillPrimes()                                   *
// * Description: Fills the primeStorage vector of primes          *
// * Parameter Description: N/A                                    *
// * Date: 05/20/2024                                              *
// * Author: Cristhian Prado                                       *
// * References: GeeksForGeeks RSA-Algorithm-Cryptography          *
// *****************************************************************
void fillPrimes() {
    std::vector<bool> sieve(512, true);
    sieve[0] = sieve[1] = false;    // 0 and 1 are not prime
    // Removing all multiples of i, even numbers
    for (int i = 2; i < 512; i++) {
        for (int j = i * 2; j < 512; j += i) {
            sieve[j] = false;
        }
    }
    // As long as sieve[i] is true, insert [i] into the primeStorage
    for (int i = 0; i < sieve.size(); i++) {
        if (sieve[i]) {
            primeStorage.push_back(i);
        }
    }
}

// *****************************************************************
// * Function Name: selectPrime()                                  *
// * Description: Selects a prime number at random and returns it  *
// * Parameter Description: N/A                                    *
// * Date: 05/20/2024                                              *
// * Author: Cristhian Prado                                       *
// * References: GeeksForGeeks RSA-Algorithm-Cryptography          *
// *****************************************************************
int selectPrime() {
    int randIndex = rand() % primeStorage.size();
    int prime = primeStorage[randIndex];
    primeStorage.erase(primeStorage.begin() + randIndex);
    return prime;
}

// *****************************************************************
// * Function Name: setKeys()                                      *
// * Description: Sets the Primary and Private Keys                *
// * Parameter Description: N/A                                    *
// * Date: 05/20/2024                                              *
// * Author: Cristhian Prado                                       *
// * References: GeeksForGeeks RSA-Algorithm-Cryptography          *
// *****************************************************************
void setKeys() {
    int p = selectPrime();
    int q = selectPrime();
    N = p * q;
    int lambda = std::lcm(p-1, q-1);

    int e = 2;
    while (1) {
        if (std::gcd(e, lambda) == 1) {
            break;
        }
        e++;
    }
    PUBLIC_KEY = e;

    int d = 2;
    while (1) {
        // Private key is not simply e % lambda, but d * e % lambda
        if ((d * e) % lambda == 1) {
            break;
        }
        d++;
    }
    PRIVATE_KEY = d;
}

// *****************************************************************
// * Function Name: encryptMSG(double message)                     *
// * Description: Encrypts message passed in and returns as a long *
// * Parameter Description: Message passed in as a double          *
// * Date: 05/20/2024                                              *
// * Author: Cristhian Prado                                       *
// * References: GeeksForGeeks RSA-Algorithm-Cryptography          *
// *****************************************************************
long long int encryptMSG(double message) {
    int e = PUBLIC_KEY;
    long long int encryptedMSG = 1;
    while (e--) {
        encryptedMSG *= message;
        encryptedMSG %= N;
    }
    return encryptedMSG;
}

// *****************************************************************
// * Function Name: decryptMSG(int encryptedMSG)                   *
// * Description: Decrypts message and returns it as a long        *
// * Parameter Description: Encrypted message as an int            *
// * Date: 05/21/2024                                              *
// * Author: Cristhian Prado                                       *
// * References: GeeksForGeeks RSA-Algorithm-Cryptography          *
// *****************************************************************
long long int decryptMSG(int encryptedMSG) {
    int d = PRIVATE_KEY;
    long long int decryptedMSG = 1;
    while (d--) {
        decryptedMSG *= encryptedMSG;
        decryptedMSG %= N;
    }
    return decryptedMSG;
}

// *****************************************************************
// * Function Name: encode(std::string message)                    *
// * Description: Encodes the message passed in  char by char      *
// * Parameter Description: std::string message as message         *
// * Date: 05/20/2024                                              *
// * Author: Cristhian Prado                                       *
// * References: GeeksForGeeks RSA-Algorithm-Cryptography          *
// *****************************************************************
std::vector<int> encode(std::string message) {
    std::vector<int> encodedMSG;

    for (int i = 0; i < message.size(); i++) {
        encodedMSG.push_back(encryptMSG(int(message[i])));
    }

    return encodedMSG;
}

// *****************************************************************
// * Function Name: decode(std::vector<int> encodedMSG)            *
// * Description: Decodes vector encoded message into string       *
// * Parameter Description: Encoded vector message passed in       *
// * Date: 05/21/2024                                              *
// * Author: Cristhian Prado                                       *
// * References: GeeksForGeeks RSA-Algorithm-Cryptography          *
// *****************************************************************
std::string decode(std::vector<int> encodedMSG) {
    std::string s;
    for (int i = 0; i < encodedMSG.size(); i++) {
        s += decryptMSG(encodedMSG[i]);
    }
    return s;
}

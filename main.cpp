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

/*
 *   //- FUNCTION DECLARATIONS
 * */
void fillPrimes();
int selectPrime();
void setKeys();
long encryptMSG(double message);
std::vector<int> encode(std::string message);

/*
 *   //- MAIN
 * */
int main() {
    std::string message;
    std::cout << "Enter Initial Message: ";
    std::cin >> message;
    std::cout << "\nInitial Message: " << message << std::endl;
    // rsa encrypt
    // print encrypted message
    // print decrypted message

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

int selectPrime() {
    int randIndex = rand() % primeStorage.size();
    int prime = primeStorage[randIndex];
    primeStorage.erase(primeStorage.begin() + randIndex);
    return prime;
}

void setKeys() {

}

long encryptMSG(double message) {

}

std::vector<int> encode(std::string message) {
    std::vector<int> encodedMSG;

    for (int i = 0; i < message.size(); i++) {
        encodedMSG.push_back(encryptMSG(int(message[i])));
    }

    return encodedMSG;
}
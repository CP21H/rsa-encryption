### RSA-Encryption Implementation
This RSA-Encryption Implementation program serves as an introductory program for me to familiarize myself with the application of cryptographic systems that I had learned in Discrete Mathematics in University, which piqued my interest so I made this program. 

The program is originally written in `C++` and has then been converted into `JavaScript` in order to serve as the backend for a more user-friendly website experience. 

**Website Link:** 

---

### Notes
- Program leverages the `<numeric>` library in C++ for the `lcm` function
- Storage of prime numbers in the GeeksForGeeks implementation is done by using a `set`. I have opted in my implementation to use a `vector` since we are storing primes in a linear, ordered fashion, and the most we do with said data structure is make accessing calls to it. Due to this, instead of a `set` I opted for taking the **O(1)** accessing time of a `vector` to make prime selection a faster process.
- GeeksForGeeks implementation uses Euler's Totient Function, whereas I have opted to use the Carmichael's Totient Function. Using Carmichael's Totient Function provides smaller exponent values to speed up the encryption process, which for this example purpose, is preferred. Realistically, Euler's Totient Function should be used as it is less vulnerable with higher exponents at the cost of higher encryption time.

---

### References
The following are the references that I used to be able to implement the RSA algorithm:
- [RSA (cryptosystem)](https://en.wikipedia.org/wiki/RSA_(cryptosystem))
- [GeeksForGeeks](https://www.geeksforgeeks.org/rsa-algorithm-cryptography/)
>- Although the majority of the implementation is founded on this reference, I have made a few notable changes which have been listed above.

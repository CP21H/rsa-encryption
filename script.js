/*
    Global Variables
*/
PRIME_STORAGE = [];
let PUBLIC_KEY;
let PRIVATE_KEY;
let N;


function main() {
    let input = document.getElementById("initMSG");
    let encMSG = document.getElementById("encryptedMSG");
    let decMSG = document.getElementById("decryptedMSG");

    // vector representation encoding of message
    let encryptedMSG = encode(input.value);

    // encoded message: -> for loop printing out 
    //encMSG.innerHTML = 

    // decoded message 
}

/*
    // RSA Implementation
*/

function fillPrimes() {
    const sieve = new Array(512).fill(true);
    sieve[0] = sieve[1] = false;

    for (let i = 2; i < 512; i++) {
        for (let j = i * 2; j < 512; j += i) {
            sieve[j] = false;
        }
    }

    for (let i = 0; i < sieve.length; i++) {
        if (sieve[i]) {
            PRIME_STORAGE.push(i);
        }
    }
}

// Since JS does not provide a mt19937 implementation, we will revert to use of rand()
function selectPrime() {
    let randIndex = Math.floor(Math.random() * PRIME_STORAGE.length);
    let prime = PRIME_STORAGE[randIndex];
    PRIME_STORAGE.splice(randIndex, 1);
    return prime;
}

function setKeys() {
    let p = selectPrime();
    let q = selectPrime();
    N = p * q;
    let lambda = lcm(p-1, q-1);

    let e = 2;
    while (1) {
        if (gcd(e, lambda) == 1) {
            break;
        }
        e++;
    }
    PUBLIC_KEY = e;

    let d = 2;
    while (1) {
        if ((d * e) % lambda == 1) {
            break;
        }
        d++;
    }
    PRIVATE_KEY = d;
}

function encryptMSG(message) {

}

function decryptMSG(encryptedMSG) {

}

function encode(message) {

}

function decode(encodedMSG) {

}


// GCD and LCM functions referenced from GeeksForGeeks using Euclidean Algorithm
function gcd(a, b) {
    for (let temp = b; b !== 0;) {
        b = a % b; 
        a = temp;
        temp = b;
    }
    return a;
}

function lcm(a, b) {
    const gcdVal = gcd(a, b);
    return (a * b) / gcdVal;
}
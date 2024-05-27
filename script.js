/*
    Global Variables
*/
var PRIME_STORAGE = [];
var PUBLIC_KEY;
var PRIVATE_KEY;
var N;


function main() {
    fillPrimes();
    setKeys();

    let input = document.getElementById("initMSG");
    let encMSG = document.getElementById("encryptedMSG");
    let decMSG = document.getElementById("decryptedMSG");

    // vector representation encoding of message
    let encryptedMSG = encode(input.value);

    // encoded message: -> for loop printing out 
    encMSG.innerHTML = encryptedMSG.join("");

    // decoded message 
    let decryptedMSG = decode(encryptedMSG);
    decMSG.innerHTML = decryptedMSG;
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
    let e = PUBLIC_KEY;
    let encryptedMSG = 1;
    while (e--) {
        encryptedMSG *= message;
        encryptedMSG %= N;
    }
    return encryptedMSG;
}

function decryptMSG(encryptedMSG) {
    let d = PRIVATE_KEY;
    let decryptedMSG = 1;
    while (d--) {
        decryptedMSG *= encryptedMSG;
        decryptedMSG %= N;
    }
    return decryptedMSG;
}

function encode(message) {
    encodedMSG = [];

    for (let i = 0; i < message.length; i++) {
        let asciiVal = message.charCodeAt(i);
        encodedMSG.push(encryptMSG(asciiVal));
    }

    return encodedMSG;
}

function decode(encodedMSG) {
    let s = "";
    for (let i = 0; i < encodedMSG.length; i++) {
        let decryptedASCII = decryptMSG(encodedMSG[i]);
        s += String.fromCharCode(decryptedASCII);
    }
    return s;
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
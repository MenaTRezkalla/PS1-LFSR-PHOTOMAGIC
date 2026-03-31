# PS1: LFSR / PhotoMagic

## Contact
Name: Mena Rezkalla

Section: 201

Time to Complete: 10 Hours

## Description
The project implements and tests a data type that simulates the operation of a 16-bit Fibonacci LFSR, then uses that to encrypt and decrypt an image.

### Features
I used an unsigned integer to represent my 16-bit register, and used an integer to store its size. It allows me to easily shift the bits and insert new ones, as well as quickly see where the bits are at the three taps.

#### Part a and b
I used an unsigned integer to represent my 16-bit register for the LFSR class, and used an integer to store its size. It allows me to easily shift the bits and insert new ones, as well as quickly see where the bits are at the three taps.

Nothing was really changed when going from part A to part B. I used the LFSR from part A to implement a function for b.

### How to Run

1. Open a Linux terminal
2. Navigate to the project folder
3. Compile the program:

   ```bash
   make
   ```
4. Run it:

   ```bash
   ./Photomagic input.png output.png {bit string of '1's and '0's that is 16 bits long, or a string of exactly two characters}
   ```
You can replace the input and output png with any png of your choice. In order to encrypt and decrypt an image, you need to use the same password when encrypting and decrypting.

## Requirements

* Linux
* `make`
* C++ compiler and SFML


### Issues
I didn't come across any issues while testing. However, I didn't know if the program had to throw an exception if the string wasn't 16 bits long. As it is currently, my program is designed throw an exception if the length isn't exactly 16 bits long. Further in this document, you will see that I did the password extra credit, but since a string of two characters is 16 bits, the program will only work with password strings of 2. This is intentional because of the information above.

### Tests
Besides the two ones that are pre-included, I tested the constructor and the << operator, to see if it matches with the example in the project document. I also tested the exeptions that the constructor and the generate() function should throw. For example, in the constructor, if the string isn't 16 characters long, or has a character that isn't '1' or '0', it will throw an error. For the generate() function, if the user inputs a negative number of steps, it will throw an error. The tests check if the exceptions are thrown from these two functions. The function step() is tested, to see if it produces the correct register as well as returning the correct new bit from the XORs, compared to the examples in the document. Lastly, generate() is tested, to see if it can return the correct (k) bit integer simulating (k) steps of the LFSR, as well as produce the correct register after the function is run, compared to the examples in the document. I also added tests for my extra credit stuff.

### Extra Credit
I did the alphanumeric password extra credit, and the unsigned int constructor extra credit. The password one I did by taking each character in the string, converting it into its 8-bit ascii binary, and then adding all the 8-bit binary strings into one LFSR seed. The unsigned int constructor was easy since my implementation already stored it as an unsigned int. 

## Acknowledgements
BOOST website, Blackboard for the resources.

### Credits
Google for helping me with creating the BOOST tests.

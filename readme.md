***What is REA?***

REA is a encryption algortithm i wrote. It is able to encrypt text files that include alphanumeric characters. In its first version it only can encrypt ascii characters.

The way it works is similiar to that of the caesar cypher, it takes in a text file input, converts each character to its decimal value, then shifts the value via the decimal sum of the private key. However instead of shifting all of the words to one direction the program shifts in alternating opposite directions. for example: 

**X, Y, Z**
*How the algorithm works (technically)*
X shifts to the right as its the first value of the character array and as its index is zero and we calculate if its odd by using the mod operator and comparing the output to zero: we get 0 and the algortim is able to shift it to the right. Y then shifts to the left as its index value is odd. and then for Z it shifts left again as the index is even, this is repeated for each line in the file.


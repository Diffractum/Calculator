Calculator
==============
 


Calculator rules:

    - only malloc, free, read, write and ... nothing else
    - for is banned from the Calculator

## Calculator work like that:

echo "math expr" | ./calc "base" "operator" "size of expr"

    ex: echo "50*10+(32-5+(856/50))" | ./calc "0123456789" "()+-*/%" "21"

## Operator implantation 
	
    - Addition, with negativ possibillity
    - Subtraction, come soon 

## Installation 

Use the Makfile, write:

    -make all
    -make test

## TODO

- Clean code
- Add subtraction

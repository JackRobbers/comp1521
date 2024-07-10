0x0013 - 2's complement.

0b 0000 0000 0001 0011

19

----

0xFFFF - from 2's complement to decimal

0b 1111 1111 1111 1111

msb is 1, negate and add 1, write final answer as negative

0b 0000 0000 0000 0000 - negated

0b 0000 0000 0000 0001 - added 1

-1

----

0x8000 - from 2's complement to decimal

0b 1000 0000 0000 0000 - write as binary

0b 0111 1111 1111 1111 - negate

0b 1000 0000 0000 0000 - added 1

-65536

----

0xFFF3 - from 2's complement to decimal

0b 1111 1111 1111 0011 - write as binary

0b 0000 0000 0000 1100 - negate

0b 0000 0000 0000 1101 - add 1

-13

---- 

-5 - decimal to 2's complement

0b 0000 0000 0000 0101 - write as binary

0b 1111 1111 1111 1010 - negate

0b 1111 1111 1111 1011 - add 1

---- 

0b 1111 1111 1111 1011 - from 2's complement to decical

0b 0000 0000 0000 0100 - negate

0b 0000 0000 0000 0101 - add 1

-5. 

----

-100 - from decimal to 2's complement

0b 0000 0000 0110 0100 - write 100 as binary

0b 1111 1111 1001 1011 - negate

0b 1111 1111 1001 1100 - add 1

---- 

floats - IEEE 754

1 bits sign
8 bits for the exponent, unsigned 8 bit number
23 bits for the fraction / mantissa

----

0 01111111 10100000000000000000000

sign is 0

exponent is 127

frac 2^-1 + 2^-3 = 1/2 + 1/8 = 0.625

-1^0 * (1 + 0.625) * 2^0

1.625

----

1 10010100 10000000000000000000000

convert to decimal

-1^1 * (1 + 0.5) * 2^(148 - 127)
-1 * 1.5 * 2^21
-1 * 1.5 * 2097152
-3145728

---- 

0 01101110 10100000101000000000000

-1^0 * (1 + 1/2 + 1/8 + 1/512 + 1/2048) * 2^(110-127)

1 * 1.627441406 * 2^-17

0.000012416

----

2.5 from decimal to float

largest power of 2 that is less than 2.5, which is 2^1 = 2

2.5/2 = 1.25 - fractional part

frac = 01000000000000000000000

exponent 2^(largest power < our number)

2^(1)

2^(x - 127)

x - 127 = 1

x = 128

10000000

number is positive so sign is 0

----

27.0

16

27/16 = 1.6875 = 1 + 0.5 + 0.125
= 1 + 1/2 + 1/8 + 1/16
fraction is 10110000000000000000000

exponent 2^4
2^(x - 127)
x - 127 = 4
x = 131
exponent 10000011

sign is 0









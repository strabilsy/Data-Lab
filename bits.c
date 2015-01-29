/* 
 * CS:APP Data Lab 
 * 
 * Samier Trabilsy strabil1
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */
/*void print(const char* n, int x) {
char binary[33];
binary[32] = 0;
printf("%8s:\t%16d\t0x%08x\t", n, x, x);
int X = x;
int i;
for(i=0;i<32;i++) {
if (X & 1)
binary[31-i] = '1';
else
binary[31-i] = '0';
 
X >>= 1;
}
printf("%32s\n", binary);
}
*/
#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* 
 * bitNand -  using only ~ and | 
 *   return the NAND of the two numbers -- NAND is the logical complement of AND
 *   Example: bitNand(6, 5) = 0xfffffffb  (only the 4 bit is 1 in both numbers)
 *   Legal ops: ~ |
 *   Max ops: 6
 *   Rating: 1
 */
int bitNand(int x, int y) {
  return (~x|~y);
}
/*
 * isEqualThree - Returns 1 if all three numbers are equal otherwise 0
 *
 * Examples: isEqualThree(1, 2, 3) = 0
 *           isEqualThree(4, 4, 4) = 1
 *
 * Legal Ops: ! ~ & ^ | + << >>
 * Max Ops: 10
 * Rating: 2
 */
int isEqualThree(int x, int y, int z) {

  return !(x^y) & !(y^z);

}
/* 
 * swap30 -- switch the 0 and 3rd bits of every hex digit of the number
 *   Example: swap30(0) = 0
 *            swap30(8) = 1
              swap30(0x812) = 0x182
              swap30(0x12345678) = 0x82a4c6e1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 2
 */
int swap30(int x) {
   
  /* int m0 = 0x88;
    int m1 = m0<<8 | m0;
    int mask = m1<<16 | m1;
    printf("x:        0x%08x\n", x);	
    printf("mask:     0x%08x\n", mask);	
    int thirdBit = (x & mask)>>3; 
    printf("thirdBit: 0x%08x\n", thirdBit);
    int mt = 0x11;
    int mt2 = mt<<8 | mt;
    int mt3 = mt2<<16 | mt2;
    thirdBit = thirdBit & mt3;
    printf("thirdBit: 0x%08x\n", thirdBit);*/
    
    int shiftX = x>>3;    	
    int m0 = 0x11;
    int m1 = m0<<8 | m0;
    int mask = m1<<16 | m1;
    /* printf("x:        0x%08x\n", x);	
       printf("mask:     0x%08x\n", mask);*/
    int thirdBit = (shiftX & mask); 
    /* printf("thirdBit: 0x%08x\n", thirdBit);*/

    int m00 = 0x11;
    int m01 = m00<<8 | m00;
    int mask2 = m01<<16 | m01;
    /* printf("mask2:    0x%08x\n", mask2);*/	
    int zeroBit = (x & mask2)<<3; 
    /* printf("zeroBit:  0x%08x\n", zeroBit);*/

    int m000 = 0x66; 
    int m001 = m000<<8 | m000;
    int mask3 = m001<<16 | m001;
    /* printf("mask3:    0x%08x\n", mask3);*/	
    int otherBits = x & mask3; 
    /* printf("otherBits:0x%08x\n", otherBits);*/
    int swappedX = thirdBit|zeroBit|otherBits;

  return swappedX; 

}
/* 
 * logicalByteAdd - Add two bytes without using +.  Note that the sum may be bigger than 255
 *   Example: logicalByteAddBytes(0x20,0x30) = 0x50, logicalByteAddBytes(0xff,0xff) = 0x1fe
 *   Legal ops: ! ~ & ^ | << >>
 *   Max ops: 30
 *   Rating: 3
 */
int logicalByteAdd(int x, int y) {
    int sum = x^y;
    int carry = (x&y)<<1;
    int sum2 = sum^carry;
    int carry2 = (carry&sum)<<1;
    int sum3 = sum2^carry2;
    int carry3 = (carry2&sum2)<<1;
    int sum4 = sum3^carry3;
    int carry4 = (carry3&sum3)<<1;
    int sum5 = sum4^carry4;
    int carry5 = (carry4&sum4)<<1;
    int sum6 = sum5^carry5;
    int carry6 = (carry5&sum5)<<1;
    int sum7 = sum6^carry6;
    int carry7 = (carry6&sum6)<<1;
    int sum8 = sum7^carry7;
    int carry8 = (carry7&sum7)<<1;
    int sum9 = sum8^carry8;
  return sum9;
}
/* 
 * rotateNibbleLeft - Rotate x to the left by n
 *   Can assume that 0 <= n <= 7
 *   Examples: rotateNibbleLeft(0x87654321,1) = 0x76543218
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3 
 */
int rotateNibbleLeft(int x, int n) {
    int temp = 1+~(n<<2);
    int rotatedBits = x>>(32+temp);
    int m0 = 0x8<<28;
    int mask =~(m0>>(31+temp));
    int otherBits = x<<(~temp+1);
    rotatedBits = rotatedBits & mask;
  return (rotatedBits | otherBits);
}
/*
 * bitBurstSize - returns count of number of consective 1's in
 *     left-hand (most significant) end of word.
 *   Examples: bitBurstSize(-1) = 32, bitBurstSize(0xFFF0F0F0) = 12
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 50
 *   Rating: 4
 *   Shift copy to right and add
 */
int bitBurstSize(int x) {
    int shifted1, shifted2, shifted3, shifted4, shifted5;
    int store1, store2, store3, store4;
    int shift, answer, isFull;

    shift = 16;

    isFull = !(~x);

    shifted1 = !(~(x >> shift));
    answer = shifted1 << 4;

    shift = answer;

    store1 = x << shift;
    shifted2 = !(~(store1 >> 24));
    shift = shifted2 << 3;
    answer = answer + shift;

    store2 = store1 << shift;
    shifted3 = !(~(store2 >> 28));
    shift = shifted3 << 2;
    answer = answer + shift;

    store3 = store2 << shift;
    shifted4 = !(~(store3 >> 30));
    shift = shifted4 << 1;
    answer = answer + shift;

    store4 = store3 << shift;
    shifted5 = !(~(store4 >> 31));
    shift = shifted5 << 0;
    answer = answer + shift;

    return answer + isFull;  				      
}
/* 
 * isNegatable - Check whether x is a number that is not its own negative (which is any number other than zero and Tmin)
 *   Examples: isNonNegatable(3) = 0, isNonNegatable(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 2 
 */
int isNegatable(int x) {
  int tMin = 0x80<<24;	
  int isTmin = !(x^tMin);	
  int zero = 0x0;
  int isZero = !(x^zero);
  return ((isZero)|(isTmin));
}
/* 
 * sign - return 1 if positive, 0 if zero, and -1 if negative
 *  Examples: sign(130) = 1
 *            sign(-23) = -1
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 2
 */
int sign(int x) {
	return (x >> 31) | (!(!x));
}
/*
 * maxOfThree - Returns the maximum of three integers.
 * NOTE: x, y, z are all in the range [0, TMax].
 *
 * Examples: maxOfThree(1, 2, 3) = 3
 *           maxOfThree(4, 4, 4) = 4
 *
 * Legal Ops: ! ~ & ^ | + << >>
 * Max Ops: 25
 * Rating: 4
 */
int maxOfThree(int x, int y, int z) {
  int bigger = (((~y+x)>>31) & y) | ((~((~y+x)>>31)) & x);
  int maxOfThree = (((~z+bigger)>>31) & z) | (~((~z+bigger)>>31) & bigger);
  return maxOfThree;
}
/* 
 * isInRange - return 1 if the first argument is in the range between
 * the second and third arguments (inclusive), 0 otherwise.
 * Note that if the second argument is larger than the third, you should return 0
 * Arguments take the range of unsigned characters (0 to 255)
 *   Example: isInRange(0x35,0x00,0x45) = 1.
 *            isInRange(0x3a,0x40,0x30) = 0.
 *            isInRange(0x05,0x00,0x05) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int isInRange(int x, int lbound, int ubound) {
  int bigger = ((~x+lbound)>>31);
  int smaller = ((~ubound+x)>>31);
  return !!(bigger & smaller);
}
/*
 * ezThreeSixteenths - multiplies by 3/16 rounding toward 0.
 *   Should exactly duplicate effect of C expression (x*3/8),
 *   including overflow behavior.
 *   Examples: ezThreeSixteenths(77) = 14
 *             ezThreeSixteenths(-22) = -4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 */
int ezThreeSixteenths(int x) {
  int mult3 = (x<<1)+x;

  int addNum = 15 & (mult3 >> 31);
  int divSixteen = (mult3 + addNum) >> 4;
  
  return divSixteen;
}
/* 
 * sm2tc - Convert from sign-magnitude to two's complement
 *   where the MSB is the sign bit
 *   Example: sm2tc(0x80000005) = -5.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 4
 */
int sm2tc(int x) {
  int sign = x>>31;
  int positive = x+(1<<31);
  return (sign & (~positive + 1)) | (~sign & x);
}
/* binarySize - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: binarySize(12) = 5
 *            binarySize(298) = 10
 *            binarySize(-5) = 4
 *            binarySize(0)  = 1
 *            binarySize(-1) = 1
 *            binarySize(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int binarySize(int x) {
  int sign = x >> 31;
  int negOne = ~ 0;
  int count = 0;
  int temp;
  x  = (x & ~sign) | ((~x)  & sign);
  
  x |= x >> 1;
  x |= x >> 2;
  x |= x >> 4;
  x |= x >> 8;
  x |= x >> 16;
  
  temp = x >> 16;
  count += (temp << 4) & 16;
  x = temp | ((temp + negOne) & x);

  temp = x >> 8;
  count += (temp << 3) & 8;
  x = temp | ((temp + negOne) & x);

  temp = x >> 4;
  count += (temp << 2) & 4;
  x = temp | ((temp + negOne) & x);

  temp = x >> 2;
  count += (temp << 1) & 2;
  x = temp | ((temp + negOne) & x);

  temp = x >> 1;
  count += temp & 1;
  x = temp | ((temp + negOne) & x);

  count += x;
  return count + 1;
}
/* 
 * float_abs - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_abs(unsigned uf) {
  unsigned x = uf & 0x7fffffff;
  if(x > 0x7f800000)
	return uf;
	else return x;
}
/* 
 * float_exp - Return the exponent value for f.  If x is inifinity or NaN, return Tmax
 *   f is to be interpreted as the bit-level representations of
 *   single-precision floating point values.  You need to remove the appropriate value for the bias.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 8
 *   Rating: 2
 */
int float_exp(unsigned uf) {
  // printf("\n\n");
  unsigned exp = (uf & (0x7F800000));
  //print("uf", uf);
  //print("exp", exp);
  if(exp == 0x00000000){
	return (0xFFFFFF82);
	}
    else if (exp == 0x7F800000){
        return (0x7FFFFFFF);
	}
    else{
	return ((exp>>23)-127);
	}
}
/* 
 * float_half_denorm - If the input number is denormalized, return
 *   bit-level equivalent of expression 0.5*f for floating point
 *   argument f.  Both the argument and result are passed as unsigned
 *   int's, but they are to be interpreted as the bit-level
 *   representation of single-precision floating point values.  When
 *   argument is not denormalized, return it as is 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while 
 *   Max ops: 15 
 *   Rating: 3
 */

unsigned float_half_denorm(unsigned uf) {
  // printf("\n\n");
  unsigned exp = (uf & (0x7F800000));
  int sign = uf & 0x80000000;
  int frac = uf & 0x007FFFFF; 
  //print("uf", uf);
  //print("exp", exp);
  if(exp == 0x00000000){
	 frac = frac | exp;
     frac = (uf & 0x00FFFFFF) >> 1;
     frac += ((uf & 3) >> 1) & (uf & 1);
     return sign | frac;;
	}
    else{
	return uf;
	}
}


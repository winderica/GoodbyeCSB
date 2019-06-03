/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
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
/* Copyright (C) 1991-2014 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */
/* 
 *   lsbZero - set 0 to the least significant bit of x 
 *   Example: lsbZero(0x87654321) = 0x87654320
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 1
 */
int lsbZero(int x) {
  /*
   * 要将一个数的LSB置零，可以先将其右移1位，再左移1位
   */
  return (x >> 1) << 1;
}

/*
 * byteNot - bit-inversion to byte n from word x  
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByteNot(0x12345678,1) = 0x1234A978
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int byteNot(int x, int n) {
  /*
   * 要将x的第n个字节取非，可以将其第n个字节与0xff异或，
   * 亦即将其与0xff左移n个字节后的值异或。
   * 由于1个字节为8位，故0xff左移n个字节可通过左移n*8，即n<<3位来实现。
   */
  return x ^ (0xff << (n << 3));
}

/*
 *   byteXor - compare the nth byte of x and y, if it is same, return 0, if not, return 1

 *   example: byteXor(0x12345678, 0x87654321, 1) = 1

 *			  byteXor(0x12345678, 0x87344321, 2) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 2 
 */
int byteXor(int x, int y, int n) {
  /*
   * 为比较x与y第n个字节的值，可以将x与y右移n个字节，再比较二者的最低字节
   * 右移n个字节可通过右移n<<3位实现；
   * 取最低字节可通过和0xff按位与实现；
   * 比较可通过异或实现。
   * 为了返回0与1，可通过两次逻辑非实现。
   */
  return !!(((x >> (n << 3)) & 0xff) ^ ((y >> (n << 3)) & 0xff));
}

/*
 *   logicalAnd - x && y
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalAnd(int x, int y) {
  /*
   * 为实现逻辑与，可以将x的真值与y的真值进行按位与，
   * 而x与y的真值可通过两次逻辑非得到。
   */
  return (!!x) & (!!y);
}

/*
 *   logicalOr - x || y
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalOr(int x, int y) {
  /*
   * 为实现逻辑或，可以将x的真值与y的真值进行按位或，
   * 而x与y的真值可通过两次逻辑非得到。
   */
  return (!!x) | (!!y);
}

/*
 * rotateLeft - Rotate x to the left by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateLeft(0x87654321,4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3 
 */
int rotateLeft(int x, int n) {
  /*
   * x循环左移n位可以分三个步骤执行：
   *  1. 将x左移n位
   *  2. 将x无符号右移32-n位
   *    a. 32-n可通过31与n异或后加1实现
   *    b. 无符号右移可通过 带符号右移后的结果 与 111...11（n个1，二进制） 按位与实现，
   *      而n个1组成的二进制(2**n - 1)可以通过1左移n位后减1实现。-1即为0按位非的结果
   *  3. 将1.与2.按位或，即可得到所求结果
   */
  return (x << n) | ((x >> ((31 ^ n) + 1)) & ((1 << n) + ~0));
}

/*
 * parityCheck - returns 1 if x contains an odd number of 1's
 *   Examples: parityCheck(5) = 0, parityCheck(7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int parityCheck(int x) {
  /*
   * 对于按位异或操作：
   *    比较的两位均为1或均为0时，产生0，即抵消偶数个1；
   *    比较的两位一个是1，另一个是0时，产生1，即保留奇数个1。
   * 由此，一个数的高位与低位异或后1的个数的奇偶性与这个数的1的个数的奇偶性相同。
   */
  int a = x ^ (x >> 16); // 将32位x的高16位与低16位异或，结果的高16位无影响，即可视a为16位
  int b = a ^ (a >> 8); // 将16位a的高8位与低8位异或，结果的高8位无影响，即可视b为8位
  int c = b ^ (b >> 4); // 将8位b的高4位与低4位异或，结果的高4位无影响，即可视c为4位
  int d = c ^ (c >> 2); // 将4位c的高2位与低2位异或，结果的高2位无影响，即可视d为2位
  int e = d ^ (d >> 1); // 将2位d的高1位与低1位异或，结果的高1位无影响，即可视e为1位
  return e & 1; // 为了消除无影响的高位，需将e与1按位与。由此得到的结果的1的个数的奇偶性与x中1的个数的奇偶性相同。
}

/*
 * mul2OK - Determine if can compute 2*x without overflow
 *   Examples: mul2OK(0x30000000) = 1
 *             mul2OK(0x40000000) = 0
 *         
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 2
 */
int mul2OK(int x) {
  /*
   * 当x在0x40000000到0xC0000000-1之间时，乘以2会溢出，故只需判断其第30位与第31位是否为10或01
   *    若是，说明乘以2会溢出，返回0
   *    若不是，说明乘以2不会溢出，返回1
   * x的第30位与第31位可通过向右移位获得，考虑到应作无符号右移，需将移位的结果和1按位与
   * 通过二者异或判断是否为01或10
   * 之后再与1异或，即可返回所需的值
   */
  return (((x >> 30) & 1) ^ ((x >> 31) & 1)) ^ 1;
}

/*
 * mult3div2 - multiplies by 3/2 rounding toward 0,
 *   Should exactly duplicate effect of C expression (x*3/2),
 *   including overflow behavior.
 *   Examples: mult3div2(11) = 16
 *             mult3div2(-9) = -13
 *             mult3div2(1073741824) = -536870912(overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int mult3div2(int x) {
  /*
   * 乘以3可以通过x左移1位后再加上x得到。
   */
  int y = (x << 1) + x;
  /*
   * 除以2可通过带符号右移1位得到。
   * 但是注意到要朝0取整，则当y>=0时，直接右移即可，当y<0时，需要加1再右移。
   * 判断y是否为负，可以通过比较y的MSB是否为1，即y和2**31按位与后是否为0。
   */
  return (y + !!(y & (1 << 31))) >> 1;
}

/*
 * subOK - Determine if can compute x-y without overflow
 *   Example: subOK(0x80000000,0x80000000) = 1,
 *            subOK(0x80000000,0x70000000) = 0, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int subOK(int x, int y) {
  /*
   * 当x与y符号位不同，且x减去y后的结果符号位与x不同时，说明产生溢出，此时返回0。
   *    1. 比较x与y的符号位，可通过x与y异或；
   *    2. 比较x-y与x的符号位，可通过x加上y的补码后再和x异或。补码可通过取反加1得到。
   * 将1.与2.得到的结果按位与后右移31位，若为0，说明不满足溢出条件，即能够相减，返回1；否则产生溢出，返回0。
   */
  return !(((x ^ y) & ((x + ~y + 1) ^ x)) >> 31);
}

/*
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int absVal(int x) {
  /*
   * 为实现绝对值操作，则当x>=0时需返回x，当x<0时需返回-x。
   * 注意到：
   *    正数的补码为其本身；
   *    负数的补码为其相反数按位取反后加1，则其相反数为补码减1后按位取反，而按位取反可通过和-1异或得到。
   * 对x进行符号扩展，即右移31位。若x>=0，则结果为0，否则为-1。
   */
  int y = x >> 31;
  /*
   * 当x>=0时，将x与0异或，即可返回x本身；
   * 当x<0时，将x-1与-1异或，即可返回-x。
   */
  return (x + y) ^ y;
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
  /*
   * 对于浮点数uf，当其MSB为1，即uf和2**31按位与不为0时，则说明其为负数，否则为正数。
   *    对于负数，求绝对值可通过MSB置零实现，即将uf减去2**31；
   *    对于正数，其绝对值为其本身，即uf减去0；
   *    对于NaN：
   *        若为qNaN（0x7fc00000），由于其本身为正，无需特殊处理；
   *        若为sNaN（0xffc00000），由于其本身为负，需特殊处理，直接返回。
   */
  return uf == 0xffc00000 ? uf : uf - (uf & 0x80000000);
}

/*
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int float_f2i(unsigned uf) {
  /*
   * 符号位为其MSB，带符号右移31位后为0则说明为正，否则为负
   */
  int sign = (uf >> 31) ? -1 : 1;
  /*
   * 指数部分为第23~30位，可通过带符号右移31位后取低8位获取。
   * 取低8位可通过和0xff按位与实现。
   */
  unsigned exponent = (uf >> 23) & 0xff;
  /*
   * 有效数位为低23位，可通过和0x7fffff按位与获取。
   */
  unsigned fraction = uf & 0x7fffff;

  if (exponent < 127) {
    /*
     * 当指数部分小于127时，其值的绝对值小于1，故取整后返回0
     */
    return 0;
  } else if (exponent - 127 >= 31) {
    /*
     * 当指数部分减去127后的值大于等于31，即2**(e-127)>=2**31时（包括了无穷与NaN的情况），
     * 则发生溢出，返回0x80000000
     */
    return 0x80000000;
  } else {
    /*
     * 按照转换规则计算其对应的整数。
     * 考虑到整数运算会舍弃小于1的部分以及精度丢失的问题，所以要进行如下转换：
     *    value = sign * 2**(exponent - 127) * (1 + fraction / 2**23)
     *          = sign * 2**(exponent - 127) + sign * (2**(exponent - 127) * fraction / 2**23)
     *          = sign * 2**(exponent - 127) + sign * (2**8 * fraction / 2**(158 - exponent))
     */
    return sign * (1 << (exponent - 127)) + sign * ((fraction << 8) >> (158 - exponent));
  }
}

// clang -target mips-unknown-linux-gnu -c ch9_7.cpp -emit-llvm -o ch9_7.bc
// ~/llvm/test/cmake_debug_build/Debug/bin/llc -march=cpu0 -mcpu=cpu032I -relocation-model=pic -filetype=asm ch9_7.bc -o -

/// start
#include "debug.h"

long long test_longlong_shift1()
{
  long long a = 4;
  long long b = 0x12;
  long long c;
  long long d;
  
  c = (b >> a);  // cc = 0x1
  d = (b << a);  // cc = 0x120

  return (c+d); // 0x121 = 289
}

long long test_longlong_shift2()
{
  long long a = 48;
  long long b = 0x001666660000000a;
  long long c;
  
  c = (b >> a);

  return c; // 22
}

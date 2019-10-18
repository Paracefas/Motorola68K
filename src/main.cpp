#include <iostream>
#include "../lib/cpu_m68k.hpp"

int main(int argc, char const** argv)
{
    paracefas::cpu::Register<> reg;
    reg.word = 0x12341234;
    printf("Word: %x\n H = %x, L = %x", reg.word, reg.bytes.H, reg.bytes.L);
}
#ifndef CPU_M68K_HPP
#define CPU_M68K_HPP

#include <cstdint>

namespace paracefas::cpu
{
    /**
     * Register is a generic union type that allows safe access to a register
     * of sifeof(uintx_t) bits or to its individual components of sifeof(uinthx_t) bits.
     * @param uintx_t is the size of entire register.
     * @param uinthx_t is the half of entire register.
     * Example of use:
     *  Register<> it create a Register of 32 bits and Register<>::byte::L and H have 16 bits.
     *  Register<uint16_t, uint8_t> allowed
     *  Register<uint32_t, uint8_t> fail at compile time uinthx_t has not the half of uintx_t's size.
     * */ 
    template<typename uintx_t = uint32_t, typename uinthx_t = uint16_t>
    union Register
    {
        static_assert(sizeof(uintx_t)/2 == sizeof(uinthx_t), "uinthx_t is not the half of uintx_t");
        uintx_t word;           
        struct
        {
            uinthx_t L, H;
        }bytes;  
    };

    /**
     * Simple alias for a register that can't have the behavior of access to it by his components.
     * In other words a alias for a register of 8 bit.
     * */
    using Register8b = uint8_t;

    struct  Bank
    {
        Register<> D0, D1, D2, D3, D4, D5, D6, D7; //< Data registers.
        Register<> A0, A1, A2, A3, A4, A5, A6;     //< Address registers.
        Register<> A7;                             //< Address register and User Stack Pointer (USP).
        Register<> PC;                             //< Program Counter (PC).
        Register8b CCR;                            //< Condition Code Register (CCR).
    };
    
    class Motorola68K
    {
        Bank m_bank;
    public:

    };
}

#endif
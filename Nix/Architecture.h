#pragma once
    
#if _MSC_VER < 1800
#   error "Nix math lib requires Visual C++ 12 - 2013 or higher"
#endif  //_MSC_VER


#define NIX_VERBOSE_ARCH

///////////////////////////////////////////////////////////////////////////////////
// Instruction sets

#define NIX_ARCH_IX86_FLAG        0x00000001
#define NIX_ARCH_SSE2_FLAG        0x00000002
#define NIX_ARCH_SSE3_FLAG        0x00000004
#define NIX_ARCH_SSSE3_FLAG        0x00000008
#define NIX_ARCH_SSE41_FLAG        0x00000010
#define NIX_ARCH_SSE42_FLAG        0x00000020
#define NIX_ARCH_AVX_FLAG        0x00000040
#define NIX_ARCH_AVX2_FLAG        0x00000080
#define NIX_ARCH_AVX512_FLAG    0x00000100 // Skylake-X core subset instructNIX


#define NIX_ARCH_X86        NIX_ARCH_IX86_FLAG
#define NIX_ARCH_SSE2        (NIX_ARCH_SSE2_FLAG | NIX_ARCH_X86)
#define NIX_ARCH_SSE3        (NIX_ARCH_SSE3_FLAG | NIX_ARCH_SSE2)
#define NIX_ARCH_SSSE3        (NIX_ARCH_SSSE3_FLAG | NIX_ARCH_SSE3)
#define NIX_ARCH_SSE41        (NIX_ARCH_SSE41_FLAG | NIX_ARCH_SSSE3)
#define NIX_ARCH_SSE42        (NIX_ARCH_SSE42_FLAG | NIX_ARCH_SSE41)
#define NIX_ARCH_AVX        (NIX_ARCH_AVX_FLAG | NIX_ARCH_SSE42)
#define NIX_ARCH_AVX2        (NIX_ARCH_AVX2_FLAG | NIX_ARCH_AVX)
#define NIX_ARCH_AVX512        (NIX_ARCH_AVX512_FLAG | NIX_ARCH_AVX2) // Skylake-X core subset instruction


#if defined(__AVX512BW__) || defined(__AVX512CD__) || defined(__AVX512DQ__) || defined(__AVX512F__) || defined(__AVX512VL__)
#   define NIX_ARCH     NIX_ARCH_AVX512
#   include <immintrin.h>
#   if defined(NIX_VERBOSE_ARCH)
#      pragma message("Supported architecture: AVX 512 - Skylake-X core subset instruction")
#   endif
#elif defined(__AVX2__)
#   define NIX_ARCH     NIX_ARCH_AVX2
#   include <immintrin.h>
#   if defined(NIX_VERBOSE_ARCH)
#      pragma message("Supported architecture: AVX 2")
#   endif
#elif defined(__AVX__)
#   define NIX_ARCH     NIX_ARCH_AVX
#   include <immintrin.h>
#   if defined(NIX_VERBOSE_ARCH)
#      pragma message("Supported architecture: AVX")
#   endif
#elif defined(__SSE4_2__)
#   define NIX_ARCH     NIX_ARCH_SSE42
#   include <nmmintrin.h>
#   if defined(NIX_VERBOSE_ARCH)
#      pragma message("Supported architecture: SSE 4.2")
#   endif
#elif defined(__SSE4_1__)
#   define NIX_ARCH     NIX_ARCH_SSE41
#   include <smmintrin.h>
#   if defined(NIX_VERBOSE_ARCH)
#      pragma message("Supported architecture: SSE 4.1")
#   endif
#elif defined(__SSSE3__)
#   define NIX_ARCH     NIX_ARCH_SSSE3
#   include <tmmintrin.h>
#   if defined(NIX_VERBOSE_ARCH)
#      pragma message("Supported architecture: SSSE 3")
#   endif
#elif defined(__SSE3__)
#   define NIX_ARCH     NIX_ARCH_SSE3
#   include <pmmintrin.h>
#   if defined(NIX_VERBOSE_ARCH)
#      pragma message("Supported architecture: SSE 3")
#   endif
#elif defined(__SSE2__) || defined(_M_X64)
#   define NIX_ARCH     NIX_ARCH_SSE2
#   include <emmintrin.h>
#   if defined(NIX_VERBOSE_ARCH)
#      pragma message("Supported architecture: SSE 2")
#   endif
#elif defined(_M_IX86_FP)
#   if _M_IX86_FP >= 2
#   define NIX_ARCH     NIX_ARCH_SSE2
#       include <emmintrin.h>
#       if defined(NIX_VERBOSE_ARCH)
#           pragma message("Supported architecture: SSE 2 on 32-Bit code Machine")
#       endif
#   else
#       error "Nix architecture support only SIMD >= SSE2"
#   endif
#else
#   error "Nix architecture support only SIMD >= SSE2"
#endif
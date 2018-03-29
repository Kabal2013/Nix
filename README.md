# Nix
Tiny optimized math framework game oriented

> Nix is an ancient greek word means Darkness.

This would be a tiny math library for game purpose (just to be clear, the inverse of the matrix would be game oriented, with the 3x3 describes rotation and scaling and the 4th lane the translation, and not a generic transform)

It implement SSE2, SSE3, SSSE3, SSE4, SSE4.2, AVX and AVX2; as well as my free time, so something is not implemented in the proper way, I just taken the lazy one.

I had started to implement also the AVX512, for the skylake subset, but I'm unable to test it, hence I left it for further implementation.


`NOTE: I made this library also to learn and to try to add many base math functions, if you need something SOLID please refer to other lib!`


> Why I did such effort?
> The answer is easy: I want a lightweight math library with low overhead, with NO vtable call, optimized as good as I need, full SIMD (no scalar) and easy to use.


# Build Status

| Platform | Build Status |
|:--------:|:------------:|
| Windows (Visual Studio 2015) | [![Windows Build Status](https://ci.appveyor.com/api/projects/status/github/kabalmcblade/Nix?branch=master&svg=true)](https://ci.appveyor.com/project/kabalmcblade/Nix) |

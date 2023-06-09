# Absolute Jump Detour Once (C++ lambda)
This example uses the intel-x86_64 instruction set to perform an absolute jump  
to a given function. In this case, we are detouring the target to a lambda  
function that exists on the stack and only executes onces, before restoring  
the original function.

This example is just a POC meandering, **it is completely inefficient and utter  
garbage**

## Build (Parent Repository WSL2+Docker Environment Recommended)
`make`

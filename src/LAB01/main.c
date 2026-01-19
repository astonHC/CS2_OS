// COPYRIGHT (C) HARRY CLARK 2026
// CS2_OS LAB AND TUTORIAL CONTENTS

// THIS FILE PERTAINS TOWARDS THE MAIN FUNCTIONALITY OF LAB 01

// SYSTEM INCLUDES

#include <stdio.h>

int 
main(int argc, char** argv)
{
    printf("Hello, %s\n", argc > 1 ? argv[1] : "World!");
    return 0;
}
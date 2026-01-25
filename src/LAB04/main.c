// COPYRIGHT (C) HARRY CLARK 2026
// CS2_OS LAB AND TUTORIAL CONTENTS

// THIS FILE PERTAINS TOWARDS THE MAIN FUNCTIONALITY OF LAB 04

// NESTED INCLUDES  

#define EXERCISE_4_1
#include "LAB04.h"

#define         FILENAME        "input.txt"

int main(void)
{
    long FILE_SIZE = 0;

    LAB_FILE_DISPLAY(FILENAME, 512, FILE_SIZE);

    if(FILE_SIZE > 0)
    {
        printf("\nSUCCESSFULLY LOADED -> %s WITH SIZE: %ld%s\n",
            FILENAME, 
            FORMAT_SIZE(FILE_SIZE),
            FORMAT_UNIT(FILE_SIZE));
    }

    return 0;
}

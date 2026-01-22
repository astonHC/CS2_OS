// COPYRIGHT (C) HARRY CLARK 2026
// CS2_OS LAB AND TUTORIAL CONTENTS

// THE FOLLOWING FILE PERTAINS TOWARDS THE MAIN FUNCTIONALITY ENCOMPASSING
// EXERCISE 3.1.B FROM LAB_03 
//
// THE FOLLOWING IMPLEMENTATION IS ADJACENT FROM THE LAB03 FOLDER ITSELF
// TO AVOID ALL OF THE FUNCTIONALITY BECOMING OVERLY CROWDED 

#ifndef CS2_OS_LAB_03_CBUFFER_H
#define CS2_OS_LAB_03_CBUFFER_H

// SYSTEM INCLUDES

#include <stdio.h>
#include <stdlib.h>

typedef size_t UNK;

// DEFINE THE BASIS FOR HOW THE CIRCULAR BUFFER
// IS PRESENTED - THROUGH IT'S RELATED FIELDS

#define             BUFFER_SIZE        23
#define             BUFFER_WRAP_INDEX(INDEX, SIZE)      ((INDEX) % (SIZE))

typedef struct
{
    int* DATA;
    UNK CAPACITY;
    UNK WRITE;
    UNK COUNT;

} CIRCULAR_BUFFER;

        #define         BUFFER_DATA(BASE)         ((BASE)->DATA)
        #define         BUFFER_CAP(BASE)          ((BASE)->CAPACITY)
        #define         BUFFER_WRITE(BASE)        ((BASE)->WRITE)
        #define         BUFFER_COUNT(BASE)        ((BASE)->COUNT)

        // DEFINE THE BASIS FOR CREATING THE BUFFER ITSELF
        #define         BUFFER_INIT(BASE)                               \
            do {                                                        \
                (BASE)->DATA = (int*)malloc(BUFFER_SIZE * sizeof(int)); \
                (BASE)->WRITE = 0;                                      \
                (BASE)->COUNT = 0;                                      \
                (BASE)->CAPACITY = BUFFER_SIZE;                         \
            } while(0)

        // DEFINE THE BASIS FOR HOW WE ARE ABLE TO WRTE
        // A POINTER NOTATION TO A SINGULAR POSITION WITHIN
        // THE BUFFER 
        //
        // ASSUME THE OFFSET OF THE TOTAL SIZE OF THE BUFFER
        #define         BUFFER_WRITE_PTR(BUFFER, VALUE)                                             \
            do {                                                                                    \
                    int* INDEX = BUFFER_DATA(BUFFER) + BUFFER_WRITE(BUFFER);                          \
                    *INDEX = (VALUE);                                                               \
                                                                                                    \
                    BUFFER_WRITE(BUFFER) = BUFFER_WRAP_INDEX(BUFFER_WRITE(BUFFER) + 1, BUFFER_SIZE);  \
                                                                                                    \
                    if(BUFFER_COUNT(BUFFER) < BUFFER_SIZE) BUFFER_COUNT(BUFFER)++;                      \
            } while(0)

#endif

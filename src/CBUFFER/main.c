// COPYRIGHT (C) HARRY CLARK 2026
// CS2_OS LAB AND TUTORIAL CONTENTS

// THE FOLLOWING FILE PERTAINS TOWARDS THE MAIN FUNCTIONALITY ENCOMPASSING
// EXERCISE 3.1.B FROM LAB_03 

// NESTED INCLUDES  

#include "CBUFFER.h"

int main(void)
{
    CIRCULAR_BUFFER* CB = (CIRCULAR_BUFFER*)malloc(sizeof(CIRCULAR_BUFFER));
    BUFFER_INIT(CB);
    
    for(int i = 0; i < 5000; i++)
    {
        BUFFER_WRITE_PTR(CB, i);
    }

    for(UNK i = 0; i < BUFFER_SIZE; i++)
    {
        printf("[%zu] = %d\n", i, CB->DATA[i]);
    }

    free(CB->DATA);
    free(CB);
    return 0;
}
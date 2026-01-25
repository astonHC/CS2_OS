// COPYRIGHT (C) HARRY CLARK 2026
// CS2_OS LAB AND TUTORIAL CONTENTS

// THIS FILE PERTAINS TOWARDS THE MAIN FUNCTIONALITY OF LAB 03
// FOCUSSING ON PROVIDING SOME SORT OF MODULARISATION OF FUNCTIONALITY

#ifndef CS2_OS_LAB_04
#define CS2_OS_LAB_04

// SYSTEM INCLUDES

#include <stdio.h>
#include <stdlib.h>

// AS AN EXTRA SO TO SPEAK, I WANT TO BE ABLE TO ACCESS
// THE CONCURRENT FILE SIZE AND THE SIZE OF THE CONTENTS
// WITHIN THE FILE

#define KB_TO_BYTES      1024
#define FORMAT_SIZE(SIZE) \
     ((SIZE) >= KB_TO_BYTES ? (SIZE)/KB_TO_BYTES : (SIZE))

#define FORMAT_UNIT(SIZE) \
     ((SIZE) >= KB_TO_BYTES ? "KB" : "B")

#if defined(EXERCISE_4_1)
    #include <assert.h>
    #include <fcntl.h>
    #include <sys/sendfile.h>
    #include <sys/stat.h>
    #include <unistd.h>

    #define     LAB_STDIN               0
    #define     LAB_STDOUT              1
    #define     LAB_STDERR              2

    #define     LAB_MAX_BYTES           1024

    // PRE-PROCESSORS FOR HANDLING DESCRIPTOR OPERATIONS
    // LEVERAGE BASE SYSTEM CALL IMPLEMENTATIONS AS PER
    // LAB REQUIREMENTS

    #define     LAB_FILE_OPEN(FILENAME, FLAGS)              open(FILENAME, FLAGS)
    #define     LAB_FILE_CLOSE(DESC)                        close(DESC)
    
    #define     LAB_FILE_SEND(OUT, IN, OFFSET, COUNT)       \
            sendfile(OUT, IN, OFFSET, COUNT)

    #define     LAB_ASSERT()        assert(LAB_MAX_BYTES <= 512 && "BYTES CANNOT EXCEED 512");

    // ACCESS THE CURRENT FILE SIZE AND IT'S RESPECTIVE CONTENTS
    // BY THE ACCESS OF SYSTEM CALLS
    #define     LAB_FILE_SIZE(DESC, SIZE)                   \
        do                                                  \
        {                                                   \
            struct stat FILE_STATS;                         \
            if(fstat(DESC, &FILE_STATS) == 0)               \
            {                                               \
                SIZE = FILE_STATS.st_size;                  \
            }                                               \
                                                            \
            else                                            \
            {                                               \
                SIZE = -1;                                  \
            }                                               \
                                                            \
        } while(0)

    // DISPLAY THE CONTENTS OF THE SUPPOSED FILE
    // PASSED THROUGH STDIN

    #define     LAB_FILE_DISPLAY(FILENAME, BYTES, SIZE)                 \
        do                                                              \
        {                                                               \
            int DESCRIPTOR = LAB_FILE_OPEN(FILENAME, O_RDONLY);         \
            if(DESCRIPTOR < 0)                                          \
            {                                                           \
                perror("ERROR OPENING FILE");                           \
                break;                                                  \
            }                                                           \
                                                                        \
            LAB_FILE_SIZE(DESCRIPTOR, SIZE);                            \
            LAB_FILE_SEND(LAB_STDOUT, DESCRIPTOR, 0, BYTES);            \
            LAB_FILE_CLOSE(DESCRIPTOR);                                 \
                                                                        \
        } while(0)

    #endif

#endif

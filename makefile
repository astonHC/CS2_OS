## COPYRIGHT (C) HARRY CLARK 2025
## CS2_OS LAB AND TUTORIAL CONTENTS

#####################################
##             PREFIXES
#####################################

CC              := gcc
IINC            := -I inc
CSTD            := --std=c99
CFLAGS          := -fPIC -fno-common -D_GNU_SOURCE
WARNINGS        := -Wall -Wextra -Wpedantic -Wunused-value -Wunused-parameter -O3

#####################################
##            DIRECTORIES
#####################################

SRC_DIR         := src

#####################################
##              TARGETS
#####################################

.PHONY: clean

%:
	@mkdir -p build/$@
	$(CC) $(CSTD) $(IINC) $(WARNINGS) $(CFLAGS) $(SRC_DIR)/$@/*.c -o build/$@/$@

clean:
	rm -rf build

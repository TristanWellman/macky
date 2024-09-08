/*
C-Ware License

Copyright (c) 2024, Tristan Wellman
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

3. Redistributions of modified source code must append a copyright notice in
   the form of 'Copyright <YEAR> <NAME>' to each modified source file's
   copyright notice, and the standalone license file if one exists.

A "redistribution" can be constituted as any version of the source code
that is intended to comprise some other derivative work of this code. A
fork created for the purpose of contributing to any version of the source
does not constitute a truly "derivative work" and does not require listing.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * */
#ifndef MACKY_H
#define MACKY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MKY_ARRLEN(x) \
		(sizeof(x)/sizeof(x[0]))

typedef struct maky_data {
	FILE *file;
	char *filebuf; /* malloc to size of all data in file */
	int fsize;
} mky_data;

void mky_free();
mky_data *mky_init(char *filename);
int mky_getIntAt(char *section, char *itemName);
float mky_getFloatAt(char *section, char *itemName);
char *mky_getStrAt(char *section, char *itemName);

#endif

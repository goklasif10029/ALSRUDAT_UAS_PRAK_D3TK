/*
NIM : 43324039
Nama : Dionisius Sidabutar
Prodi : D3 Teknologi Komputer
*/
#include <stdio.h>
#include <stdlib.h>

#define Error(Str)      FatalError(Str)
#define FatalError(Str) fprintf(stderr, "%s\n", Str), exit(1)
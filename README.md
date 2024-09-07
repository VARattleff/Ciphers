# caesar.c opg 

## Kompilering

For at kompilere dette projekt på en ARM-baseret Mac M2, kan du bruge følgende kommando i terminalen:

```bash
mkdir -p bin
gcc \
-Iinclude \
src/core/caesar.c \
src/core/cipher.c \
-o bin/caesar
```
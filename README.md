# caesar.c opg 

## Kompilering

For at kompilere dette projekt på en ARM-baseret Mac M2, kan du bruge følgende kommando i terminalen:

```bash
mkdir -p build
gcc \
-Iinclude \
src/caesar.c \
src/cipher.c \
-o build/caesar
```
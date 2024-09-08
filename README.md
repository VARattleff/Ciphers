# caesar.c opg 

## Kompilering

For at kompilere dette projekt på en ARM-baseret Mac M2, kan du bruge følgende kommando i terminalen:

```bash
mkdir -p build
gcc \
src/caesar.c \
src/cipher.c \
-o build/caesar
```

## Demonstration og Introduktion

1. Vælg først, om du vil kryptere eller dekryptere.
2. Vælg derefter skiftværdien.

### Opgave

Prøv at dekryptere følgende værdi med en shiftvalue på 2:

```bash
VGORNGQU
```
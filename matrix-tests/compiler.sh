#!/bin/bash
set -e

RISCV_HOME=$RISCV
if [ "$#" -lt 1 ]; then
    echo "Usage: $0 <source_file.c>"
    exit 1
fi

SOURCE_FILE=$(basename -- "$1")

OUTPUT_DIR="out"
OUTPUT_FILE="${OUTPUT_DIR}/${SOURCE_FILE%.c}.out"

mkdir -p "$OUTPUT_DIR"

clang -Wno-everything --sysroot="$RISCV_HOME/riscv64-unknown-elf" --target=riscv64-unknown-elf -march=rv64gv0p10zfh0p1 -menable-experimental-extensions -DPREALLOCATE=1 -mcmodel=medany -static -std=gnu99 -O2 -ffast-math -fno-common -fno-builtin-printf -mabi=lp64d -c -o tmp.o "$1" $2 $3 $4

if [ $? -ne 0 ]; then
    echo "Compilation failed for '$1'."
    exit 1
fi

riscv64-unknown-elf-ld --sysroot="$RISCV_HOME/riscv64-unknown-elf" -melf64lriscv -L"$RISCV_HOME"/lib/gcc/riscv64-unknown-elf/12.2.0 -L"$RISCV_HOME"/lib/gcc -L"$RISCV_HOME"/lib/gcc/lib -L"$RISCV_HOME"/riscv64-unknown-elf/lib tmp.o a-syscalls.o a-crt.o -lm -lgcc -T ./test.ld -o "$OUTPUT_FILE"

if [ $? -ne 0 ]; then
    echo "Linking failed for 'tmp.o'."
    exit 1
fi

rm tmp.o

echo "Compilation and linking successful. Output file: '$OUTPUT_FILE'"

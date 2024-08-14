#!/bin/bash

WORK_DIR=$(pwd)
COMPILE_SCRIPT="$WORK_DIR/compiler.sh"
RUN_SCRIPT="$WORK_DIR/run.sh"
OUT_DIR="$WORK_DIR/out"

if [ -d "$OUT_DIR" ]; then
  rm -f "$OUT_DIR"/*
else
  mkdir -p "$OUT_DIR"
fi

for file in "$WORK_DIR/isa"/*.c; do
  filename=$(basename "$file")
  echo "Compiling $filename..."
  "$COMPILE_SCRIPT" "$file"
  if [ $? -ne 0 ]; then
    echo "Compilation failed for $filename"
    continue
  fi
done

for out_file in "$OUT_DIR"/*.out; do
  filename=$(basename "$out_file")
  if [ -f "$out_file" ]; then
    "$RUN_SCRIPT" "$out_file"
    if [ $? -ne 0 ]; then
      echo "Running failed for $filename"
    fi
  fi
done
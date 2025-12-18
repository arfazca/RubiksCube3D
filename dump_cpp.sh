#!/bin/bash

ROOT_DIR="${1:-.}"

find "$ROOT_DIR" \
    -type f \
    \( \
        -name "*.cpp" -o \
        -name "*.cc"  -o \
        -name "*.cxx" -o \
        -name "*.h"   -o \
        -name "*.hpp" \
    \) \
    ! -path "*/build/*" \
    | sort | while IFS= read -r file; do

    relpath="${file#./}"

    echo "// ============================================================================"
    echo "// File: $relpath"
    echo "// ============================================================================"
    cat "$file"
    echo
done

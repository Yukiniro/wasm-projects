#!/bin/bash

# 创建 dist 目录（如果不存在）
mkdir -p dist

# 编译 hello_world.c
emcc hello_world.c -o dist/hello_world.html -s WASM=1 -msimd128 -O3

echo "Build complete!"

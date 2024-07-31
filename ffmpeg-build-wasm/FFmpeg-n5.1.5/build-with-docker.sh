#!/bin/bash -x

docker pull emscripten/emsdk
docker run \
  -v $PWD:/src \
  -v $PWD/cache-wasm:/emsdk_portable/.data/cache/wasm \
  emscripten/emsdk \
  sh -c 'bash ./build.sh'
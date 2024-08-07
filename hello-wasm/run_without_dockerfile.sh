docker pull emscripten/emsdk
docker run -w /app -v /Users/zhanghao/Documents/wasm-projects/hello-wasm:/app \
    emscripten/emsdk sh -c "bash /app/run_hello_world.sh"

@echo off
setlocal enabledelayedexpansion

REM 拉取 emscripten 镜像
docker pull trzeci/emscripten

REM 运行 Docker 容器并执行构建脚本
docker run ^
  -v %cd%:/src ^
  -v %cd%\cache-wasm:/emsdk_portable/.data/cache/wasm ^
  trzeci/emscripten ^
  sh -c "bash ./build-with-wasm.sh"

endlocal
@echo off
setlocal enabledelayedexpansion

REM 拉取指定版本的 Emscripten 镜像
docker pull trzeci/emscripten:1.39.18-upstream

REM 运行 Docker 容器并执行构建脚本
docker run ^
  -v %cd%:/src ^
  -v %cd%\cache-wasm:/emsdk_portable/.data/cache/wasm ^
  trzeci/emscripten:1.39.18-upstream ^
  sh -c "bash ./build-with-wasm.sh"

endlocal
# 使用官方的 emscripten 镜像
FROM emscripten/emsdk:latest


# 设置工作目录
WORKDIR /app

# 复制当前目录的所有文件到工作目录
COPY . .

# 运行 run_hello_world.sh 脚本
CMD ["sh", "-c", "/app/run_hello_world.sh"]

# Source (Host):             E:\GitHub\wasm-projects\hello-wasm\
# Destination (Container):   /app/
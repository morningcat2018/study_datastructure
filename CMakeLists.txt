# 设置最低的CMake版本号
cmake_minimum_required(VERSION 3.10)

# 设置项目名称和版本号
project(myproject VERSION 1.0)

# 添加可执行文件
add_executable(main binary_search_tree_test.cpp)

# 设置安装目标路径
install(TARGETS main DESTINATION bin)
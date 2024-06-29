# 360HuaBao-Killer
 专门检查、删除360壁纸的工具
 
你可以用这个工具来删除在不经过你同意，自动给你下载的360壁纸，在未来我可能会增加更多的杀手，例如: 360browser-Killer等

# 构建指南

在构建之前你需要去安装[MinGW编译器](https://github.com/skeeto/w64devkit/releases)，并且配置环境变量(自己去网上搜);

接着你需要安装[CMake](https://cmake.org/download/)

然后开始构建:
 
* 打开这个cmd，然后打开存储库的根目录

* 输入:mkdir build

* cd build

* cmake -G "MinGW Makefiles" ..

* cmake --build .

* 然后去build文件夹点击360HuaBao-Killer.exe运行! 

# 其它

运行之后它会自动检查360壁纸的默认目录，并且删除，建议每天启动一次检查一下

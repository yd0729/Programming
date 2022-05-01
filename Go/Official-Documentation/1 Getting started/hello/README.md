go mod init 'Getting-started/hello'

初始化一个 go 模块，生成一个 go.mod 文件，这个文件里会保存全部的依赖．

在真实的开发环境中，这个路径应该是 repo 的地址，比如 github.com/mymodule ．

go run .

运行当前的模块．

go help

go mod tidy

添加依赖模块

go mod edit -replace Getting-Started/greetings=../greetings

但是现在不是真实的开发环境，所以要手动设置添加的模块的位置．
# FastIO

## 一、模板类别

​	数据结构：快速输入输出

## 二、模板功能

备注：

1. 只要将本模板放在文件中，就可以通过宏定义将原有的 `cin` 、`cout` 替换掉，之后可以使用 `cin` 和 `cout` 符号进行快速的读写。

2. 本地调试的输入输出文件路径默认为执行目录下的 `in.txt` 和 `out.txt`。

3. 支持 `getchar` ，`putchar` 函数。

4. 由于输入输出是以自定义类的形式实现，所以不仅仅可以用于单文件输入、单文件输出。比如，想要对比一下标准程序和自己的程序的输出结果，那么可以再声明一个

   ```
   outputHelper cout2("out2.txt")
   ```

   将自己的结果通过 `cout​` 输出到 `out.txt`，将标准程序的结果通过 `cout2` 输出到 `out2.txt` 。

## 三、模板示例

```c++
#include "IO/fastIO.h"

int main() {

    //读入一个整数 123
    int x;
    cin >> x;
    cout << x << '\n';

    //读入一个字符串 "abc"
    std::string s;
    cin >> s;
    cout << s << '\n';

    //读入一行字符串，失败，只读了 "this"
    std::string line;
    cin >> line;
    cout << line << '\n';

    //读入一行字符串，成功，" is a line"
    getline(cin, line);
    cout << line << '\n';

    //读入一行字符串，成功，"this is another line"
    getline(cin, line);
    cout << line << '\n';

    if (cin >> s)
        cout << "still have input\n";
    else
        cout << "no more input\n";

    // 一个额外的日志功能函数，可以用来打印多个参数，中间用逗号做间隔
    log("abc", 123, 4.56, std::string("def"));
}
```

```
#以下为 "in.txt" 中的内容
123
abc
this is a line
this is another line
```

```
#以下为程序运行之后， "out.txt" 中的内容
123
abc
this
 is a line
this is another line
no more input
abc, 123, 4.560000, def
```

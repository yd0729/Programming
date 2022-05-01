整型类型

i/u 6/16/32/64/128
i/u size 架构决定 32/64 一般在需要索引时使用

字面值

57u8 后缀
_ 分隔符
0 x/0/b 前缀
b 前缀代表 Byte ，等于 u8 后缀

整型溢出

debug 作为异常
release 会发生 two's complement wrapping

明确处理溢出

- wrapping_* ，比如 wrapping_add
- checked_* ，溢出时返回 None
- overflowing_* ，会返回一个 bool 作为是否溢出的判断
- staturating_* ，不会溢出，而是会饱和

浮点类型

f 32/64

布尔类型

只有 1 位

字符类型

4 字节，表示 Unicode

复合类型

tuple

`()`  是没有任何值的 tuple， 它的值是 unit value ，它的类型是 unit type ．

如果表达式不返回任何其它的值，就会返回 unit value ．

array

固定长度

array 会在栈中分配内存，而不是堆 ．

**访问下标越界时会引发运行时错误．**
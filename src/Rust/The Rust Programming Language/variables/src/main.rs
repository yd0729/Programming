fn main() {
    // let mut
    ///////////////////////////////////////////
    let mut x = 5; // 变量默认是不可变的，要加上 mut 关键字
    println!("The value of x is: {}", x);
    x = 6;
    println!("The value of x is: {}", x);
    
    // const
    ///////////////////////////////////////////
    // const 被用来声明一个常量
    // const 一定要指明类型
    // 常量只能被常量表达式（编译时能算出来的）赋值
    const THREE_HOURS_IN_SECONDS: u32 = 60 * 60 * 3;
    println!("THREE_HOURS_IN_SECONDS: {}", THREE_HOURS_IN_SECONDS);
    
    // shadowing
    ///////////////////////////////////////////
    let x = 5;
    let x = x + 1; // shadowing 可以在同一作用域重复定义一个变量

    {
        let x = x * 2;
        println!("The value of x in the inner scope is: {}", x);
    }

    println!("The value of x is: {}", x);

    let spaces = "   "; // let 虽然不可变
    let spaces = spaces.len(); // 但是可以重复定义，也可以在重复定义时改变类型
    println!("spaces: {}", spaces);
    // let mut spaces = "   ";
    // spaces = spaces.len();  // 可变变量不可以改变类型
}

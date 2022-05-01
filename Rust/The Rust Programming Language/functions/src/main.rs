fn main() {
    another_function(5);
    print_labeled_measurement(5, 'h');
    // let x = (let y = 6);  // 无法编译，因为语句没有返回值
    let y = {
        // scope 是有返回值的
        let x = 3;
        x + 1 // 没有分号，是一个表达式
    };

    println!("The value of y is: {}", y);

    let y = {
        // scope 是有返回值的
        let x = 3;
        let _ = x + 1; // 有分号，是一个语句
    }; // 这会导致这个 scope 返回 () ，因为没有其它的值可以返回

    println!("The value of y is: {:?}", y);

    let x = five();
    println!("The value of x is: {}", x);
    let x = three();
    println!("The value of x is: {}", x);
}

fn another_function(x: i32) {
    println!("The value of x is: {}", x);
}

fn print_labeled_measurement(value: i32, unit_label: char) {
    println!("The measurement is: {}{}", value, unit_label);
}

fn five() -> i32 {
    5
}

fn three() -> i32 {
    return 3;  // return 可以提前返回，是一个语句
    // 5
}
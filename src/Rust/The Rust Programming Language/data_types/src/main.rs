use std::io;

fn main() {
    // addition
    let _sum = 5 + 10;
    println!("sum: {}", _sum);
    // subtraction
    let _difference = 95.5 - 4.3;
    println!("difference: {}", _difference);
    // multiplication
    let _product = 4 * 30;
    println!("product: {}", _product);
    // division
    let _quotient = 56.7 / 32.2;
    println!("quotient: {}", _quotient);
    let _floored = 2 / 3; // Results in 0
    println!("floored: {}", _floored);
    // remainder
    let _remainder = 43 % 5;
    println!("remainder: {}", _remainder);
    let t = true;
    println!("t: {}", t);
    let f: bool = false; // with explicit type annotation
    println!("f: {}", f);
    let c = 'z';
    println!("c: {}", c);
    let z = 'ℤ';
    println!("z: {}", z);
    let heart_eyed_cat = '😻';
    println!("heart_eyed_cat: {}", heart_eyed_cat);
    let tup: (i32, f64, u8) = (500, 6.4, 1);
    println!("tup: {:?}", tup);
    
    let (x, y, z) = tup;
    println!("The value of x, y, z is: {}, {}, {}",x, y, z);

    let x: (i32, f64, u8) = (500, 6.4, 1);
    let five_hundred = x.0;
    println!("five_hundred: {}", five_hundred);

    let six_point_four = x.1;
    println!("six_point_four: {}", six_point_four);

    let one = x.2;
    println!("one: {}", one);

    let a: [i32; 5] = [1, 2, 3, 4, 5];
    println!("a: {:?}", a);

    let a = [3; 5];
    println!("a: {:?}", a);

    let a = [1, 2, 3, 4, 5];
    println!("Please enter an array index.");

    let mut index = String::new();

    io::stdin()
        .read_line(&mut index)
        .expect("Failed to read line");

    let index: usize = index
        .trim()
        .parse()
        .expect("Index entered was not a number");

    let element = a[index];

    println!(
        "The value of the element at index {} is: {}",
        index, element
    );
}

# P4 MINI PROJECT: Newton Mini Market

## 1. Project Description
The Mini Market Management System is a simple program developed using the C programming language. It helps manage products, stock, member points, and purchases. It uses structs, arrays, pointers, and functions.

## 2. Features
- View all products and their prices.
- View registered members and their points.
- Buy products and update stock.
- Update product names.
- Redeem member points for a 10% discount.
- Use an interactive menu to select operations.
- Exit the program when finished.

## 3. Tasks Completed

### Task 2: Update Product Name
The program allows the user to change a product's name using pointers and the `strcpy()` function. The new name is saved in the product array.

### Task 3: Redeem Points for Discount
Members with at least 1,000 points can receive a 10% discount on their purchase. After using the discount, 1,000 points are deducted from their balance.

### Bonus Challenge: Interactive Menu
The program uses a `while` loop to keep running until the user chooses Exit. It uses `scanf()` to receive input and `switch-case` to perform the selected operation.

## 4. C Programming Terms Used

| Term | Simple Explanation |
|---|---|
| `struct` | Groups related information together. |
| Array | Stores several products or members. |
| Pointer | Stores the address of data in memory. |
| `->` operator | Accesses a struct member through a pointer. |
| `&` operator | Gets the address of a variable or array element. |
| Function | Performs a specific task in the program. |
| `while` loop | Repeats the menu until the user exits. |
| `switch-case` | Selects an operation based on the user's choice. |
| `strcpy()` | Copies a new name into a character array. |
| `scanf()` | Reads input entered by the user. |

## 5. How to Run the Project

1. Download or clone this repository to your computer.
2. Open the project folder in a C compiler, such as Code::Blocks or Dev-C++.
3. Open the `main.c` file.
4. Compile and run the program.
5. Select an option from the menu and follow the instructions displayed.
6. Choose Exit when you finish.

You can also compile the program using GCC from a terminal:

```bash
gcc main.c -o minimarket
```

Then run it:

**Windows:**
```bash
minimarket.exe
```

**Linux:**
```bash
./minimarket
```

## 6. Program Results
The program successfully displays product and member information, processes purchases, updates product names, applies discounts for eligible members, and allows users to navigate through an interactive menu.


## 8. Author
Ishmael Newton Museka

**Project:** Mini Market Management System  
**Language:** C

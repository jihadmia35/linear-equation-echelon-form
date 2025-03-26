# Linear Equation Solver using Echelon Form

This program solves a system of linear equations using the echelon form approach. It determines whether the system has no solution, a unique solution, or multiple solutions. The program uses matrix row operations to reduce the system to echelon form and then applies back-substitution to find the solutions.

## Features
- Converts the given system of equations into echelon form.
- Detects whether the system has:
  - **No solution** (inconsistent system)
  - **A unique solution**
  - **Multiple solutions** (dependent system)
- Computes the solution if it is unique.

## How to Use
### **Input Format**
- The first line contains two integers: `n` (number of variables) and `eq` (number of equations).
- The next `eq` lines contain `n+1` integers, where the first `n` values are the coefficients of the variables, and the last value is the constant term.

### **Example Input**
```
3 3
2 1 -1 8
-3 -1 2 -11
-2 1 2 -3
```
This represents the following system of equations:
```
2x +  y -  z =  8
-3x - y + 2z = -11
-2x + y + 2z = -3
```

### **Example Output**
```
Reduce to echelon form:
2 1 -1 = 8
0 -0.5 0.5 = 1
0 0 1 = 2
Unique solution
x1 = 2
x2 = 3
x3 = 4
```

## Understanding the Input & Output
Below are images that explain the input structure and how the program processes it:

**Input Representation:**
![Input Example](https://github.com/user-attachments/assets/c90f0abb-9396-4bba-9665-d2cceb2c3664)

**Mathematical Representation:**
![Math Representation](https://github.com/user-attachments/assets/a4e22e54-3466-44dd-ae32-e452b02e6519)

## Installation & Running the Program
1. Clone the repository:
   ```sh
   git clone https://github.com/yourusername/linear-equation-echelon-form.git
   ```
2. Navigate to the project folder:
   ```sh
   cd linear-equation-echelon-form
   ```
3. Compile the C++ program:
   ```sh
   g++ -o solver solver.cpp
   ```
4. Run the program:
   ```sh
   ./solver
   ```
5. Enter the number of variables and equations, followed by the coefficients and constants.

## Contribution
If you're interested, feel free to contribute to this project by improving the code, optimizing performance, or adding new features. Pull requests are welcome!

## License
This project is open-source and free to use.

---
Let me know if you need any changes or improvements! 🚀


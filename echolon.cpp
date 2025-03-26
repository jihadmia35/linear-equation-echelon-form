#include <bits/stdc++.h>
using namespace std;

/**
 * Function to reduce the system of equations to echelon form.
 * It eliminates variables step by step to create an upper triangular matrix.
 * 
 * @param n Number of variables.
 * @param eq Number of equations.
 * @param v 2D vector representing the augmented matrix of coefficients and constants.
 */
void reduce(int n, int eq, vector<vector<int>> &v) {
    for (int it = 0; it < eq - 1; it++) {
        for (int i = it + 1; i < eq; i++) {
            vector<int> temp1(n + 1);
            vector<int> temp2(n + 1);
            vector<int> final(n + 1);
            
            // Make coefficients of v[it][it] equal for elimination
            for (int j = 0; j <= n; j++) {
                temp1[j] = (v[i][j] * v[it][it]); 
                temp2[j] = (v[it][j] * v[i][it]); 
                final[j] = temp1[j] - temp2[j]; // Row transformation
            }
            v[i] = final; // Replace row i with the transformed row
        }
    }
}

/**
 * Function to check if the system has a solution.
 * It detects inconsistent equations where all coefficients are zero, but the constant is nonzero.
 * 
 * @param n Number of variables.
 * @param eq Number of equations.
 * @param v 2D vector representing the augmented matrix.
 * @return true if a solution exists, false if inconsistent.
 */
bool sol(int n, int eq, vector<vector<int>> &v) {
    for (int i = 0; i < eq; i++) {
        bool allZero = true;
        for (int j = 0; j < n; j++) {
            if (v[i][j] != 0) {
                allZero = false;
                break;
            }
        }
        if (allZero && v[i][n] != 0) return false; // Inconsistent equation
    }
    return true;
}

/**
 * Function to check if the system has a unique solution.
 * A system has a unique solution if the number of nonzero rows after reduction equals the number of variables.
 * 
 * @param n Number of variables.
 * @param eq Number of equations.
 * @param v 2D vector representing the augmented matrix.
 * @return true if the system has a unique solution, false otherwise.
 */
bool haveUniqueSol(int n, int eq, vector<vector<int>> &v) {
    int nonZeroRow = 0;
    for (int i = 0; i < eq; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j] != 0) {
                nonZeroRow++;
                break;
            }
        }
    }
    return (nonZeroRow == n); // Unique solution exists only if the number of independent equations equals n
}

/**
 * Function to find and print the unique solution of the system.
 * It uses back-substitution to compute the values of the variables.
 * 
 * @param n Number of variables.
 * @param eq Number of equations.
 * @param v 2D vector representing the augmented matrix.
 */
void uniqueSol(int n, int eq, vector<vector<int>> &v) {
    vector<double> values(n, 1); // Solution vector, initially set to 1
    int ind = n - 1;

    // Compute last variable directly
    values[ind--] = (1.0 * v[eq - 1][n] / v[eq - 1][n - 1]);

    // Back-substitution to compute other variables
    for (int i = eq - 2; i >= 0; i--) {
        int sum = 0;
        for (int j = n - 1; j > i; j--) {
            sum += (v[i][j] * values[j]);
        }
        sum *= -1;
        sum += v[i][n];
        values[ind--] = sum / v[i][i];
    }

    // Print the solution
    for (int i = 0; i < values.size(); i++) {
        cout << "x" << i + 1 << " = " << values[i] << endl;
    }
}

int main() {
    int n, eq;
    cin >> n >> eq; // Read number of variables and equations

    vector<vector<int>> v(eq, vector<int>(n + 1)); // Augmented matrix

    // Read the coefficients and constants of equations
    for (int i = 0; i < eq; i++) {
        for (int j = 0; j <= n; j++) cin >> v[i][j];
    }
    
    cout << "Reduce to echelon form:" << endl;
    reduce(n, eq, v);

    // Print the reduced echelon form
    for (int i = 0; i < eq; i++) {
        for (int j = 0; j <= n; j++) {
            if (j == n) cout << "= " << v[i][j];
            else cout << v[i][j] << " ";
        }
        cout << endl;
    }

    // Check for solutions
    if (!sol(n, eq, v)) 
        cout << "No solution" << endl;
    else if (haveUniqueSol(n, eq, v)) {
        cout << "Unique solution" << endl;
        uniqueSol(n, eq, v);
    } else 
        cout << "Multiple solutions" << endl;

    return 0;
}

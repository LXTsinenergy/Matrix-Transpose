#pragma region Usings

#include <iostream>
#include <string>
#include "Matrix.h"
#include "Validator.cpp"
using namespace std;

#pragma endregion

int main()
{
    Validator validator; 
    string rows_count_input, columns_count_input; // variables for rows and columns count input

    char continue_flag; // flag of continue or exit
    do {
        cout << "Enter rows count: ";
        cin >> rows_count_input;
        while (!validator.validate(rows_count_input)) { // validation of the entered rows count value
            cout << "Wrong value! Try again: ";
            cin >> rows_count_input;
        }
        int rows_count = stoi(rows_count_input); // string to int if the value is valid

        cout << "Enter columns count: ";
        cin >> columns_count_input;
        while (!validator.validate(columns_count_input)) { // validation of the entered columns count value
            cout << "Wrong value! Try again: ";
            cin >> columns_count_input;
        }
        int columns_count = stoi(columns_count_input); // string to int if the value is valid

        Matrix matrix = Matrix::create_matrix(rows_count, columns_count); // create matrix with static method
        matrix.print_matrix(); // print untransported matrix
        matrix.transpose_matrix(); // transpose matrix
        matrix.print_matrix(); // print transported matrix

        // continue or exit choose
        cout << endl << "Continue?" << endl;
        cout << "0) No" << endl << "1) Yes" << endl;
        cin >> continue_flag;

        // invalid input checking
        while (!(continue_flag == '0' || continue_flag == '1')) {
            cout << endl << "Wrong input. Try again:" << endl;
            cout << "0) No" << endl << "1) Yes" << endl;
            cin >> continue_flag;
        }
    } while (continue_flag == '1');
}

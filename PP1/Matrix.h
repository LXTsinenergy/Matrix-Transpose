#pragma once
#include <iostream>
#include <vector>
#include "Validator.cpp"
using namespace std;

/// <summary>
/// Matrix
/// </summary>
class Matrix
{
private:
	int rows_count, columns_count, max_count;
	string* matrix;

public:
	/// <summary>
	/// Create matrix by user input
	/// </summary>
	/// <param name="rows_count">Numbers of rows</param>
	/// <param name="columns_count">Numbers of columns</param>
	/// <returns>Created matrix</returns>
	static Matrix create_matrix(int rows_count, int columns_count) {
		Matrix matrix; // new matrix
		Validator validator;

		// initialize matrix size
		matrix.rows_count = rows_count;
		matrix.columns_count = columns_count;
		matrix.max_count = max(rows_count, columns_count);
		matrix.matrix = new string[matrix.max_count * matrix.max_count];

		// create matrix by user input
		for (int i = 0; i < rows_count; i++) {
			for (int j = 0; j < columns_count; j++) {
				cout << "Enter value on position " << "(" << i + 1 << "; " << j + 1 << "): ";
				string value;
				getline(cin, value); // value on position (i; j) in matrix
				while (!validator.validate(value)) {
					cout << "Wrong value! Try again: ";
					getline(cin, value);
				}
				matrix.matrix[i * matrix.max_count + j] = value; // add value on position: maximum size of column or row + current index in column
			}
		}

		return matrix;
	}
	
	/// <summary>
	/// Transpose matrix
	/// </summary>
	void transpose_matrix() {
		for (int i = 0; i < max_count; i++) {
			for (int j = i + 1; j < max_count; j++) { // j = i + 1 -> next element in column
				swap(matrix[i * max_count + j], matrix[j * max_count + i]); // swap elements in matrix
			}
		}
		swap(rows_count, columns_count); // swap M x N size on N x M
	}

	/// <summary>
	/// Print matrix
	/// </summary>
	void print_matrix() {
		cout << endl << "Matrix:" << endl;
		// enumeration of all matrix elements
		for (int i = 0; i < rows_count; i++) {
			for (int j = 0; j < columns_count; j++) {
				cout << matrix[i * max_count + j] << " "; // element in matrix in position (i; j)
			}
			cout << endl; // enter after every row
		}
	}
};


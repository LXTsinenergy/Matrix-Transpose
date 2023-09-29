#pragma once
#include <iostream>
#include <vector>
using namespace std;

/// <summary>
/// Matrix
/// </summary>
class Matrix
{
public:
	int rows_count, columns_count;
	vector<vector<string>> matrix;

	/// <summary>
	/// Create matrix by user input
	/// </summary>
	/// <param name="rows_count">Count of rows</param>
	/// <param name="columns_count">Count of columns</param>
	/// <returns>Created matrix</returns>
	static Matrix create_matrix(int rows_count, int columns_count) {
		Matrix matrix; // new matrix

		// initialize matrix size
		matrix.rows_count = rows_count;
		matrix.columns_count = columns_count;

		// create matrix by user input
		for (int i = 0; i < rows_count; i++) {
			vector<string> row; // row of matrix
			for (int j = 0; j < columns_count; j++) {
				cout << "Enter value on position " << "(" << i + 1 << "; " << j + 1 << "): ";
				string value; // value on position (i; j) in matrix
				cin >> value;
				row.push_back(value);
			}
			matrix.matrix.push_back(row); // add filled row in matrix
		}

		return matrix;
	}
	
	/// <summary>
	/// Transpose matrix
	/// </summary>
	void transpose_matrix() {
		int maximum_size = max(rows_count, columns_count); // maximum size of matrix by columns and rows
		matrix.resize(maximum_size); // resize columns by maximum value
		for (vector<string>& row : matrix) {
			row.resize(maximum_size); // resize rows by maximum value
		}
		for (int i = 0; i < maximum_size; i++) {
			for (int j = i + 1; j < maximum_size; j++) { // j = i + 1 -> next element in column
				swap(matrix[i][j], matrix[j][i]); // swap elements in matrix
			}
		}
		swap(rows_count, columns_count); // swap size of matrix
		matrix.resize(rows_count); // resize columns by count of rows 
		for (vector<string>& row : matrix) {
			row.resize(columns_count); // resize rows by count of columns
		}
	}

	/// <summary>
	/// Print matrix
	/// </summary>
	void print_matrix() {
		cout << endl << "Matrix:" << endl;
		// enumeration of all matrix elements
		for (int i = 0; i < rows_count; i++) {
			for (int j = 0; j < columns_count; j++) {
				cout << matrix[i][j] << " "; // element in matrix in position (i; j)
			}
			cout << endl;
		}
	}
};


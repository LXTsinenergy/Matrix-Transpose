#pragma once
#include <string>
using namespace std;

/// <summary>
/// Validator of strings
/// </summary>
class Validator
{
public:
    /// <summary>
    /// Validate string
    /// </summary>
    /// <param name="value">String for validation</param>
    /// <returns>Result of validation</returns>
    bool validate(string value) {
        if (check_digits(value)) {
            double double_value = stod(value);
            int int_value = stoi(value);

            // check if the value is an integer and value > 0
            if (double_value / int_value == 1 && int_value > 0) {
                return true;
            }
        }
        return false;
    }

private:
    /// <summary>
    /// Check if string is digit
    /// </summary>
    /// <param name="str">String for checking</param>
    /// <returns>Result of checking</returns>
    bool check_digits(string str) {
        for (char ch : str) {
            int v = ch; // Convert to ASCII
            if (!isdigit(ch)) return false; // Check if symbol is digit by ASCII code
        }
        return true;
    }
};


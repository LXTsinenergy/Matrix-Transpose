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
    /// <param name="str">String to validate</param>
    /// <returns>Result of validation</returns>
    bool validate(string str) {
        int counter = 0;
        for (char sym : str) {
            if (isdigit(sym)) counter += 1;
        }
        if (counter == str.size()) {
            return true;
        }
        return false;
    }
};


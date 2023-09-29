#pragma once
#include <string>
using namespace std;

class Size
{
public:
    int rows_count;
    int columns_count;

    bool validate_size(string value) {
        if (check_digits(value)) {
            double double_value = stod(value);
            int int_value = stoi(value);

            if (double_value / int_value == 1 && int_value > 0) {
                return true;
            }
        }
        return false;
    }

private:
    bool check_digits(string str) {
        for (char ch : str) {
            int v = ch; // Convert to ASCII
            if (!isdigit(ch)) return false; // Check if symbol is digit by ASCII code
        }
        return true;
    }
};


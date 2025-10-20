#pragma once
#include <string>

using namespace std;

string intWithCommas(int n) {
    string result = to_string(n); // Convert integer 'n' to a string and store it in 'result'

    // Loop to insert commas for thousands separators in the string
    for (int i = result.size() - 3; i > 0; i -= 3) {
        result.insert(i, ","); // Insert a comma after every three digits from the end
    }

    return result; // Return the formatted string
}//end intwithcommas

#include <vector>
#include <string>

using namespace std;

class Spreadsheet {
private:
    vector<vector<int>> grid;
    int numRows;

    // Helper function to convert cell reference string to 0-indexed coordinates
    pair<int, int> parseCell(const string& cell) {
        char colChar = cell[0];
        int col = colChar - 'A';
        int row = 0;
        for (size_t i = 1; i < cell.length(); ++i) {
            row = row * 10 + (cell[i] - '0');
        }
        return {row - 1, col};
    }

    // Helper function to get the value of a formula component
    int parseValue(const string& s) {
        if (s.empty()) {
            return 0; // Handle empty string case for safety
        }
        if (isalpha(s[0])) {
            // It's a cell reference
            pair<int, int> coords = parseCell(s);
            int row = coords.first;
            int col = coords.second;
            if (row >= 0 && row < numRows && col >= 0 && col < 26) {
                return grid[row][col];
            }
            return 0; // Out-of-bounds cell value is 0
        } else {
            // It's a number
            return stoi(s);
        }
    }

public:
    Spreadsheet(int rows) {
        numRows = rows;
        grid.assign(rows, vector<int>(26, 0));
    }

    void setCell(string cell, int value) {
        pair<int, int> coords = parseCell(cell);
        int row = coords.first;
        int col = coords.second;
        if (row >= 0 && row < numRows && col >= 0 && col < 26) {
            grid[row][col] = value;
        }
    }

    void resetCell(string cell) {
        setCell(cell, 0);
    }

    int getValue(string formula) {
        // Find the position of the '+' operator
        size_t plus_pos = formula.find('+');
        if (plus_pos == string::npos) {
            // Formula is not in the expected format, return 0 or handle error
            return 0;
        }

        string part1 = formula.substr(1, plus_pos - 1);
        string part2 = formula.substr(plus_pos + 1);

        int val1 = parseValue(part1);
        int val2 = parseValue(part2);

        return val1 + val2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
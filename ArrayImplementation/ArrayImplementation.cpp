#include <iostream>
#include <vector>

class SparseMatrix {
private:
    std::vector<std::vector<int>> compactMatrix;

public:
    void addElement(int row, int col, int value) {
        if (value != 0) {
            compactMatrix.push_back({row, col, value});
        }
    }

    void display() {
        std::cout << "Row Column Value\n";
        for (const auto& element : compactMatrix) {
            std::cout << element[0] << " " << element[1] << " " << element[2] << "\n";
        }
    }
};

int main() {
    SparseMatrix matrix;
    int row, col, value;

    std::cout << "Enter elements in 'row column value' format. Enter '-1 -1 -1' to end.\n";
    while (true) {
        std::cin >> row >> col >> value;
        if(row == -1 && col == -1 && value == -1) {
            break;
        }
        matrix.addElement(row, col, value);
    }

    matrix.display();

    return 0;
}

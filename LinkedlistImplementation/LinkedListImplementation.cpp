#include <iostream>

struct Node {
    int row;
    int col;
    int value;
    Node *next;
};

Node* createNode(int row, int col, int value) {
    Node* newNode = new Node();
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = nullptr;
    return newNode;
}

void insertNode(Node** start, int row, int col, int value) {
    Node* newNode = createNode(row, col, value);
    newNode->next = *start;
    *start = newNode;
}

void printList(Node* start) {
    Node* ptr = start;
    std::cout << "Row Position, Column Position, Value\n";
    while (ptr != nullptr) {
        std::cout << ptr->row << ", " << ptr->col << ", " << ptr->value << "\n";
        ptr = ptr->next;
    }
}

int main() {
    int m, n;
    std::cout << "Enter the number of rows and columns of the sparse matrix:\n";
    std::cin >> m >> n;

    Node* start = nullptr;

    std::cout << "Enter the elements in the form 'row column value'. Enter -1 -1 -1 to end.\n";
    while (true) {
        int row, col, value;
        std::cin >> row >> col >> value;
        if (row == -1 && col == -1 && value == -1) {
            break;
        }
        if (value != 0) {
            insertNode(&start, row, col, value);
        }
    }

    std::cout << "Sparse Matrix Representation:\n";
    printList(start);

    Node* ptr;
    while (start) {
        ptr = start;
        start = start->next;
        delete ptr;
    }

    return 0;
}


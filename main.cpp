#include "DiscussionList.h"
#include <iostream>

int main() {
    DiscussionList forum;
    char choice;
    std::string content, parentContent, responseContent;

    do {
        std::cout << "DISCUSSION TREE\n";
        std::cout << "Choose one of the following:\n";
        std::cout << "n: New discussion tree\n";
        std::cout << "s: Add a new response\n";
        std::cout << "d: Delete a sub-discussion\n";
        std::cout << "p: Print all discussion trees\n";
        std::cout << "r: Print a sub-tree\n";
        std::cout << "w: Search a string in all discussion trees\n";
        std::cout << "e: exit\n";
        std::cin >> choice;

        switch (choice) {
        case 'n':
            std::cout << "Enter the discussion title (with no space): ";
            std::cin >> content;
            forum.createNewTree(content);
            break;
        case 's':
            std::cout << "Enter the discussion title (with no space): ";
            std::cin >> parentContent;
            std::cout << "Enter the last message (with no space): ";
            std::cin >> responseContent;
            std::cout << "Enter the new response: ";
            std::cin >> content;
            for (auto tree : forum.trees) {
                if (tree->findNode(tree->root, parentContent)) {
                    tree->addResponse(responseContent, content);
                    break;
                }
            }
            break;
        case 'd':
            std::cout << "Enter the discussion title (with no space): ";
            std::cin >> parentContent;
            std::cout << "Enter the last message (with no space): ";
            std::cin >> content;
            for (auto tree : forum.trees) {
                if (tree->findNode(tree->root, parentContent)) {
                    tree->deleteSubtree(content);
                    break;
                }
            }
            break;
        case 'p':
            forum.printAllTrees();
            break;
        case 'r':
            std::cout << "Enter the discussion title (with no space): ";
            std::cin >> parentContent;
            std::cout << "Enter the last message (with no space): ";
            std::cin >> content;
            for (auto tree : forum.trees) {
                Node* node = tree->findNode(tree->root, content);
                if (node) {
                    tree->printTree(node);
                    break;
                }
            }
            break;
        case 'w':
            std::cout << "Enter a string (with no space): ";
            std::cin >> content;
            forum.searchString(content);
            break;
        case 'e':
            std::cout << "Bye!\n";
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 'e');

    return 0;
}
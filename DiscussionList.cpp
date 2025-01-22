#include "DiscussionList.h"
#include <iostream>

// בנאי
DiscussionList::DiscussionList() {}

// הורס
DiscussionList::~DiscussionList() {
    for (auto tree : trees) {
        delete tree; // מחיקת כל העצים
    }
}

// יצירת עץ חדש
void DiscussionList::createNewTree(const std::string& content) {
    DiscussionTree* newTree = new DiscussionTree();
    newTree->createRoot(content);
    trees.push_back(newTree);
}

// מחיקת עץ
void DiscussionList::deleteTree(DiscussionTree* tree) {
    trees.remove(tree);
    delete tree;
}

// הדפסת כל העצים
void DiscussionList::printAllTrees() const {
    int treeNumber = 1;
    for (auto tree : trees) {
        std::cout << "Tree #" << treeNumber++ << std::endl;
        tree->printTree(tree->root);
        std::cout << std::endl;
    }
}

// חיפוש מחרוזת בכל העצים
void DiscussionList::searchString(const std::string& content) const {
    for (auto tree : trees) {
        Node* foundNode = tree->findNode(tree->root, content);
        if (foundNode) {
            std::cout << content << std::endl;
            tree->printTree(foundNode);
            std::cout << "Path to root: ";
            tree->printPathToRoot(foundNode);
            std::cout << std::endl;
        }
    }
}
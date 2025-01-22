#include "DiscussionList.h"
#include <iostream>

// ����
DiscussionList::DiscussionList() {}

// ����
DiscussionList::~DiscussionList() {
    for (auto tree : trees) {
        delete tree; // ����� �� �����
    }
}

// ����� �� ���
void DiscussionList::createNewTree(const std::string& content) {
    DiscussionTree* newTree = new DiscussionTree();
    newTree->createRoot(content);
    trees.push_back(newTree);
}

// ����� ��
void DiscussionList::deleteTree(DiscussionTree* tree) {
    trees.remove(tree);
    delete tree;
}

// ����� �� �����
void DiscussionList::printAllTrees() const {
    int treeNumber = 1;
    for (auto tree : trees) {
        std::cout << "Tree #" << treeNumber++ << std::endl;
        tree->printTree(tree->root);
        std::cout << std::endl;
    }
}

// ����� ������ ��� �����
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
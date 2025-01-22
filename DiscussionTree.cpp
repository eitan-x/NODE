#include "DiscussionTree.h"
#include <iostream>

// ����
DiscussionTree::DiscussionTree() : root(nullptr) {}

// ����
DiscussionTree::~DiscussionTree() {
    delete root; // ����� �� ���
}

// ����� ���� ���
void DiscussionTree::createRoot(const std::string& content) {
    if (root) {
        delete root; // ����� ��� ����� �� ����
    }
    root = new Node(content);
}

// ����� ������ ��� ����
Node* DiscussionTree::findNode(Node* current, const std::string& content) {
    if (!current) return nullptr;
    if (current->content == content) return current;

    for (auto response : current->responses) {
        Node* found = findNode(response, content);
        if (found) return found;
    }

    return nullptr;
}

// ����� �����
bool DiscussionTree::addResponse(const std::string& parentContent, const std::string& responseContent) {
    Node* parentNode = findNode(root, parentContent);
    if (!parentNode) return false;

    parentNode->responses.push_back(new Node(responseContent));
    return true;
}

// ����� ��-��
bool DiscussionTree::deleteSubtree(const std::string& content) {
    if (!root) return false;
    if (root->content == content) {
        delete root;
        root = nullptr;
        return true;
    }

    for (auto& response : root->responses) {
        if (response->content == content) {
            delete response;
            response = nullptr;
            return true;
        }
    }

    return false;
}

// ����� �������
void DiscussionTree::printTree(Node* node, int depth) const {
    if (!node) return;

    for (int i = 0; i < depth; i++) {
        std::cout << "   "; // ���� �� 3 ������ ��� ��� ����
    }
    std::cout << node->content << std::endl;

    for (auto response : node->responses) {
        printTree(response, depth + 1);
    }
}

// ����� ����� �� �����
void DiscussionTree::printPathToRoot(Node* node) const {
    if (!node) return;

    // ����� ����� �� ������� ������
    std::cout << node->content;

    // �� ������� ������ ��� �� �����, ����� ����� �����
    if (node != root) {
        std::cout << "=>";

        // ����� ����� �� ������� ������
        Node* parent = nullptr;
        for (auto treeNode : root->responses) {
            if (treeNode == node) {
                parent = root;
                break;
            }
            for (auto response : treeNode->responses) {
                if (response == node) {
                    parent = treeNode;
                    break;
                }
            }
        }

        // �������: ����� ������ ������ �� �����
        printPathToRoot(parent);
    }
}
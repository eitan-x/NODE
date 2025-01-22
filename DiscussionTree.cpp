#include "DiscussionTree.h"
#include <iostream>

// בנאי
DiscussionTree::DiscussionTree() : root(nullptr) {}

// הורס
DiscussionTree::~DiscussionTree() {
    delete root; // מחיקת כל העץ
}

// יצירת שורש חדש
void DiscussionTree::createRoot(const std::string& content) {
    if (root) {
        delete root; // מחיקת העץ הקודם אם קיים
    }
    root = new Node(content);
}

// חיפוש קודקוד לפי תוכן
Node* DiscussionTree::findNode(Node* current, const std::string& content) {
    if (!current) return nullptr;
    if (current->content == content) return current;

    for (auto response : current->responses) {
        Node* found = findNode(response, content);
        if (found) return found;
    }

    return nullptr;
}

// הוספת תגובה
bool DiscussionTree::addResponse(const std::string& parentContent, const std::string& responseContent) {
    Node* parentNode = findNode(root, parentContent);
    if (!parentNode) return false;

    parentNode->responses.push_back(new Node(responseContent));
    return true;
}

// מחיקת תת-עץ
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

// הדפסה היררכית
void DiscussionTree::printTree(Node* node, int depth) const {
    if (!node) return;

    for (int i = 0; i < depth; i++) {
        std::cout << "   "; // הזחה של 3 רווחים לכל רמת עומק
    }
    std::cout << node->content << std::endl;

    for (auto response : node->responses) {
        printTree(response, depth + 1);
    }
}

// הדפסת מסלול עד השורש
void DiscussionTree::printPathToRoot(Node* node) const {
    if (!node) return;

    // הדפסת התוכן של הקודקוד הנוכחי
    std::cout << node->content;

    // אם הקודקוד הנוכחי הוא לא השורש, נמשיך לעלות למעלה
    if (node != root) {
        std::cout << "=>";

        // חיפוש ההורה של הקודקוד הנוכחי
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

        // רקורסיה: הדפסת המסלול מההורה עד השורש
        printPathToRoot(parent);
    }
}
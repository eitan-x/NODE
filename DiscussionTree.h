#ifndef DISCUSSIONTREE_H
#define DISCUSSIONTREE_H

#include "Node.h"
#include <list>
#include <string>

class DiscussionTree {
public:
    Node* root; // ���� ���

    DiscussionTree(); // ����
    ~DiscussionTree(); // ����

    void createRoot(const std::string& content); // ����� ���� ���
    Node* findNode(Node* current, const std::string& content); // ����� ������ ��� ����
    bool addResponse(const std::string& parentContent, const std::string& responseContent); // ����� �����
    bool deleteSubtree(const std::string& content); // ����� ��-��
    void printTree(Node* node, int depth = 0) const; // ����� �������
    void printPathToRoot(Node* node) const; // ����� ����� �� �����
};

#endif
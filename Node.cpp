#include "Node.h"
#include <iostream>

// ����
Node::Node(const std::string& content) : content(content) {}

// ���� (����� �� ��-���)
Node::~Node() {
    for (auto response : responses) {
        delete response; // ����� �� �������
    }
}
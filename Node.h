
#ifndef NODE_H
#define NODE_H

#include <string>
#include <list>

class Node {
public:
    std::string content; // ���� �����
    std::list<Node*> responses; // ����� �� ������ (����)

    Node(const std::string& content); // ����
    ~Node(); // ���� (����� �� ��-���)
};

#endif


#ifndef NODE_H
#define NODE_H

#include <string>
#include <list>

class Node {
public:
    std::string content; // תוכן הדיון
    std::list<Node*> responses; // רשימה של תגובות (בנים)

    Node(const std::string& content); // בנאי
    ~Node(); // הורס (מחיקת כל תת-העץ)
};

#endif

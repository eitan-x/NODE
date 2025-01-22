#include "Node.h"
#include <iostream>

// בנאי
Node::Node(const std::string& content) : content(content) {}

// הורס (מחיקת כל תת-העץ)
Node::~Node() {
    for (auto response : responses) {
        delete response; // מחיקת כל התגובות
    }
}
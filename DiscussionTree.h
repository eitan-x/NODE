#ifndef DISCUSSIONTREE_H
#define DISCUSSIONTREE_H

#include "Node.h"
#include <list>
#include <string>

class DiscussionTree {
public:
    Node* root; // שורש העץ

    DiscussionTree(); // בנאי
    ~DiscussionTree(); // הורס

    void createRoot(const std::string& content); // יצירת שורש חדש
    Node* findNode(Node* current, const std::string& content); // חיפוש קודקוד לפי תוכן
    bool addResponse(const std::string& parentContent, const std::string& responseContent); // הוספת תגובה
    bool deleteSubtree(const std::string& content); // מחיקת תת-עץ
    void printTree(Node* node, int depth = 0) const; // הדפסה היררכית
    void printPathToRoot(Node* node) const; // הדפסת מסלול עד השורש
};

#endif
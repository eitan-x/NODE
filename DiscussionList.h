#ifndef DISCUSSIONLIST_H
#define DISCUSSIONLIST_H

#include "DiscussionTree.h"
#include <list>

class DiscussionList {
public:
    std::list<DiscussionTree*> trees; // רשימה של עצי דיונים

    DiscussionList(); // בנאי
    ~DiscussionList(); // הורס

    void createNewTree(const std::string& content); // יצירת עץ חדש
    void deleteTree(DiscussionTree* tree); // מחיקת עץ
    void printAllTrees() const; // הדפסת כל העצים
    void searchString(const std::string& content) const; // חיפוש מחרוזת בכל העצים
};

#endif
#ifndef DISCUSSIONLIST_H
#define DISCUSSIONLIST_H

#include "DiscussionTree.h"
#include <list>

class DiscussionList {
public:
    std::list<DiscussionTree*> trees; // ����� �� ��� ������

    DiscussionList(); // ����
    ~DiscussionList(); // ����

    void createNewTree(const std::string& content); // ����� �� ���
    void deleteTree(DiscussionTree* tree); // ����� ��
    void printAllTrees() const; // ����� �� �����
    void searchString(const std::string& content) const; // ����� ������ ��� �����
};

#endif
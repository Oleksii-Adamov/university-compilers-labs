#include "ASTNode.hh"
#include <initializer_list>

ASTNode::ASTNode(std::string name_, std::initializer_list<ASTNode*> sons_) {
    name = name_;
    for (ASTNode* son: sons_) {
        sons.push_back(son);
    }
}

ASTNode::~ASTNode() {
    for (std::size_t i = 0; i < sons.size(); i++) {
        delete sons[i];
    }
}
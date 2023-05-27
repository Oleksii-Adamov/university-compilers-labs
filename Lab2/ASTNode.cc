#include "ASTNode.hh"
#include <initializer_list>

ASTNode::ASTNode() {
}

ASTNode::ASTNode(std::string name_, std::string val_) {
    name = name_;
    val = val_;
}

ASTNode::ASTNode(std::string name_, std::initializer_list<ASTNode*> sons_) {
    name = name_;
    for (ASTNode* son: sons_) {
        sons.push_back(son);
    }
}

ASTNode::~ASTNode() {
//    for (std::size_t i = 0; i < sons.size(); i++) {
//        delete sons[i];
//    }
}

std::ostream& operator<<(std::ostream& out, ASTNode const& node) {
    out << "(" << node.name << ", ";
    if (node.val.size() != 0) {
        out << node.val;
    } else {
        for (std::size_t i = 0; i < node.sons.size(); i++) {
            out << "\n" << node.sons[i];
        }
    }
    out << ")";
    return out;
}
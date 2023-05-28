#include "ASTNode.hh"
#include <initializer_list>

ASTNode::ASTNode() {
}

ASTNode::ASTNode(ASTNodeType type_, std::string val_) {
    type = type_;
    val = val_;
}

ASTNode::ASTNode(ASTNodeType type_, std::initializer_list<ASTNode*> sons_) {
    type = type_;
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
    out << "(" << node.type << ", ";
    if (node.sons.size() == 0) {
        out << node.val;
    } else {
        for (std::size_t i = 0; i < node.sons.size(); i++) {
            if (node.sons[i] != nullptr)
                out << "\n" << *node.sons[i];
        }
    }
    out << ")";
    return out;
}

void ASTNode::print(std::ostream& out, const std::string& prefix, bool isLast)
{
    out << prefix;

    out << (isLast ? "└──" : "├──");

    // print the value of the node
    if (val.size() == 0) {
        out << type << "\n";
    } else {
        out << "(" << type << ", " << val << ")\n";
    }

    // enter the next tree level
    for (std::size_t i = 0; i < sons.size(); i++) {
        if (sons[i] != nullptr)
            sons[i]->print(out, prefix + (isLast ? "    " : "│   "), i == sons.size() - 1);
    }
}
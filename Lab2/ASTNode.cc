#include "ASTNode.hh"
#include <initializer_list>
#include <utility>

ASTNode::ASTNode() {
}

ASTNode::ASTNode(ASTNodeType type_, std::string val_)
{
    type = type_;
    val = std::move(val_);
}

ASTNode::ASTNode(ASTNodeType type_, std::initializer_list<ASTNode*> sons_) {
    type = type_;
    for (ASTNode* son: sons_) {
        if (son != nullptr && type == ASTNodeType::Statements && son->type == ASTNodeType::Statements) {
            sons.insert(sons.end(), son->sons.begin(), son->sons.end());
            delete son;
        } else
            sons.push_back(son);
    }
}

ASTNode::~ASTNode() {
//    for (std::size_t i = 0; i < sons.size(); i++) {
//        delete sons[i];
//    }
}

void ASTNode::free_tree() {
    for (std::size_t i = 0; i < sons.size(); i++) {
        sons[i]->free_tree();
        delete sons[i];
    }
}

std::ostream& operator<<(std::ostream& out, ASTNode const& node) {
    out << "(" << node.type << ", ";
    if (node.sons.empty()) {
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
    if (val.empty()) {
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
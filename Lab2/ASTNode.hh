#ifndef LAB2_ASTNODE_HH
#define LAB2_ASTNODE_HH

#include <vector>
#include <string>
#include <iostream>
#include "ASTNodeType.hh"

class ASTNode {
private:
    std::vector<ASTNode*> sons;
    ASTNodeType type;
    // value (for tokens)
    std::string val = "";
public:
    ASTNode();
    ASTNode(ASTNodeType type_, std::string val_ = "");
    ASTNode(ASTNodeType type_, std::initializer_list<ASTNode*> sons_);
    ~ASTNode();
    friend std::ostream& operator<<(std::ostream& out, const ASTNode& node);
    void print(std::ostream& out, const std::string& prefix, bool isLast);
    void clean_tree();
};


#endif //LAB2_ASTNODE_HH

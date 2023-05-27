#ifndef LAB2_ASTNODE_HH
#define LAB2_ASTNODE_HH

#include <vector>
#include <string>

class ASTNode {
private:
    std::vector<ASTNode*> sons;
    std::string name;
    std::string val = "";
public:
    ASTNode(std::string name_, std::string val_);
    ASTNode(std::string name_, std::initializer_list<ASTNode*> sons_);
    ~ASTNode();
    friend std::ostream& operator<<(std::ostream& out, ASTNode const& node);
};


#endif //LAB2_ASTNODE_HH

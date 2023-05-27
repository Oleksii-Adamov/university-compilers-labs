#ifndef LAB2_ASTNODE_HH
#define LAB2_ASTNODE_HH

#include <vector>

class ASTNode {
private:
    std::vector<ASTNode*> sons;
    std::string name;
public:
    ASTNode(std::string name, std::initializer_list<ASTNode*> sons);
    ~ASTNode();
};


#endif //LAB2_ASTNODE_HH

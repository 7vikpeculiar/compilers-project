#include <bits/stdc++.h>
#include <string>
using namespace std;

// Visitor class

class ASTvisitor
{
    // public virtual void push_back(){}
};

// AST Node class
class ASTnode
{
    public:
        string value;
        virtual ~ASTnode()
        {}

        string get_value()
        {

        }

        virtual void pb(ASTnode* a)
        {}

        virtual void visit()
        {

        }
    // virtual void accept(ASTvisitor & V) = 0;
};

//Literal

class IntLiteral: public ASTnode
{
public:
    int value;

    IntLiteral(int inp)
    {
        value = inp;
    }

    virtual int get_value()
    {
        return value;
    }

    virtual void visit()
    {
        cout << "IntLiteral:: " << value << endl;
    }
};

class CharLiteral: public ASTnode
{
public:
    char value;

    CharLiteral(char inp)
    {
        value = inp;
    }

    virtual char get_value()
    {
        return value;
    }

    virtual void visit()
    {
        cout << "CharLiteral:: " << value << endl;
    }
};

class BoolLiteral:  public ASTnode
{
public:
    string value;

    BoolLiteral(string  inp)
    {
        value = inp;
    }

    virtual string get_value()
    {
        return value;
    }

    virtual void visit()
    {
        cout << "BoolLiteral:: " << value << endl;
    }
};

class UintLiteral:  public ASTnode
{
public:
    string value;

    UintLiteral(string  inp)
    {
        value = inp;
    }

    virtual string get_value()
    {
        return value;
    }

    virtual void visit()
    {
        cout << "UintLiteral:: " << value << endl;
    }
};
// Expression ------------------------------------------------------------------

class BiExprNode : public ASTnode
{
public:
    string operand;
    ASTnode* left;
    ASTnode* right;

    BiExprNode(ASTnode* l, ASTnode* r, string opr)
    {
        left = l;
        right = r;
        operand  = opr;
    }

    virtual string get_value()
    {
        return operand;
    }

    virtual void visit()
    {
        cout << "BiExprNode:: " << operand << endl;
        cout <<  "|-" ;
        left->visit();
        cout <<  "|-"; right->visit(); cout << endl;
    }
};

class UniExprNode : public ASTnode
{
public:
    string operand;
    ASTnode* uno;

    UniExprNode(ASTnode* nd, string opr)
    {
        uno = nd;
        operand  = opr;
    }

    virtual string get_value()
    {
        return operand;
    }

    virtual void visit()
    {
        cout << "UniExprNode:: " << operand << endl;
        cout << "|-";
        uno->visit();
        cout << endl;
    }
};

// ------ Location --------------------------

class SingleId : public ASTnode
{
public:
    string value;

    SingleId(string inp)
    {
        value = inp;
    }

    virtual void visit()
    {
        cout << "SingleId:: " << value << endl;
    }

    string get_value()
    {
        return value;
    }
};

class OneDArray : public ASTnode
{
public:
    ASTnode * id;
    ASTnode * row;

    OneDArray(ASTnode* inp, ASTnode* exp)
    {
        id   = inp;
        row =  exp;
    }

    virtual void visit()
    {
        cout << "OneDArray:: " ;
        id->visit(); cout << "[";
        row->visit();
        cout << "]";
        cout << endl;
    }
};

class TwoDArray : public ASTnode
{
public:
    ASTnode * id;
    ASTnode * row;
    ASTnode * col;

    TwoDArray(ASTnode* inp, ASTnode* exp1, ASTnode* exp2)
    {
        id = inp;
        row  = exp1;
        col = exp2;
    }

    virtual void visit()
    {
        cout << "TwoDArray:: " ;
        id->visit(); cout << "[";
        row->visit(); cout << " , ";
        col->visit();
        cout << "]";
        cout << endl;
    }
};

// MethodCall
class MethodCallNode : public ASTnode
{
public:
    ASTnode * id;
    ASTnode * params;

    MethodCallNode(ASTnode* inp, ASTnode* extra = NULL)
    {
        id = inp;
        params = extra;
    }

    virtual void visit()
    {
        cout << "MethodCallNode:: ";
        id->visit();
        cout << "(";
        if(params != NULL)
        {params->visit();}
        cout << ")";
    }
};

// Variable Declaration
class SingleInitNode : public ASTnode
{
public:
    ASTnode* id;
    string type;

    SingleInitNode(ASTnode* inp, string typ)
    {
        type = typ;
        id = inp;
    }

    virtual void visit()
    {
        cout << "SingleInitNode:: ";
        id->visit();
        cout  << " " << type << endl;
    }

};

class OneDInitNode : public ASTnode
{
public:
    ASTnode* id;
    string type;
    ASTnode * row;

    OneDInitNode(ASTnode* inp, ASTnode* exp, string typ)
    {
        type = typ;
        id   = inp;
        row  = exp;
    }

    virtual void visit()
    {
        cout << "OneDInitNode:: ";
        cout << type << " " ;
        id->visit();
        cout << "[" ;
        row->visit();
        cout << "]";
    }
};

class TwoDInitNode : public ASTnode
{
public:
    ASTnode* id;
    string type;
    ASTnode * row;
    ASTnode * col;
    TwoDInitNode(ASTnode* inp, ASTnode* exp1, ASTnode* exp2, string typ)
    {
        type = typ;
        id = inp;
        row  = exp1;
        col = exp2;
    }

    virtual void visit()
    {
        cout << "TwoDInitNode:: ";
        cout << type << " ";
        id->visit();
        cout << "[" ;
        row->visit();cout << ",";
        col->visit();
        cout << "]";
    }

};

class AssignmentNode : public ASTnode
{
public:
    ASTnode* location;
    string asgn_op;
    ASTnode* expr;
    AssignmentNode(ASTnode* loc, string op, ASTnode* exp)
    {
        location = loc;
        asgn_op = op;
        expr = exp;
    }
    virtual void visit()
    {
        cout << "AssignmentNode:: ";
        location->visit();
        cout << " " << asgn_op << " ";
        expr->visit();
    }
};

class InitAssignmentNode : public ASTnode
{
public:
    string type;
    ASTnode* location;
    string asgn_op;
    ASTnode* expr;
    InitAssignmentNode(ASTnode* loc, string op, ASTnode* exp, string ty)
    {
        location = loc;
        asgn_op = op;
        expr = exp;
        type = ty;
    }

    virtual void visit()
    {
        cout << "InitAssignmentNode:: ";
        cout << type << " " ; location->visit();
        cout << " " << asgn_op;
        expr->visit();
    }
};
// Statement
class StatementsNode: public ASTnode
{
public:
    vector<class ASTnode *> statements_list;
    void pb(ASTnode* a)
    {
        statements_list.push_back(a);
    }
    StatementsNode(ASTnode* a)
    {
        statements_list.push_back(a);
    }

    virtual void visit()
    {
        cout << "StatementsNode:: " << endl;
        for(int i=0; i<statements_list.size(); i++)
        {
            cout << i+1 << ":: ";
            statements_list[i]->visit();
            cout << endl;
        }
    }
};

//Method Call
class ListExprsNode: public ASTnode
{
public:
    vector<class ASTnode *> exprs_list;
    void pb(ASTnode* a)
    {
        exprs_list.push_back(a);
    }
    ListExprsNode(ASTnode* a)
    {
        exprs_list.push_back(a);
    }
    virtual void visit()
    {
        cout << "ListExprsNode:: " << endl;
        for(int i=0; i<exprs_list.size(); i++)
        {
            cout << i+1 << ":: ";
            exprs_list[i]->visit();
            cout << endl;
        }
    }
};

//Condition
class ConditionNode: public ASTnode
{
public:
    ASTnode * if_expr, * code_block, * else_block;
    ConditionNode(ASTnode* a, ASTnode* b, ASTnode* c=NULL)
    {
        if_expr     = a;
        code_block  = b;
        else_block  = c;
    }
    virtual void visit()
    {
        cout << "ConditionNode:: " << endl;
        cout << "Ifcond::" << endl;
        if_expr->visit();
        cout << "Ifcode -- " ; code_block->visit();
        if(else_block != NULL)
        {   cout << "Elsepat:: " << endl;
            else_block->visit();}
        cout << endl;
    }
};

class ElseBlockNode: public ASTnode
{
public:
    vector<class ASTnode*> elseif_list;
    ASTnode* else_block;
    ElseBlockNode(ASTnode* a=NULL)
    {
        // cout << "Else Is there" << endl;
        else_block = a;
    }
    void pb(ASTnode* a)
    {
        // ElseBlock is right recursive
        elseif_list.insert(elseif_list.begin(),a);
    }
    virtual void visit()
    {
        cout << "ElseBlockCode:: " << endl;
        for(int i=0; i<elseif_list.size(); i++)
        {
            cout << i+1 << ":: ";
            elseif_list[i]->visit();
        }
        if(else_block != NULL)
        {
         cout << "Else: " << endl;
            else_block->visit();
        }
    }
};

class ElseIfNode: public ASTnode
{
public:
    ASTnode * expr;
    ASTnode * block;
    ElseIfNode(ASTnode* expr_,ASTnode* block_)
    {
        expr = expr_;
        block = block_;
    }
    virtual void visit()
    {
        cout << "ElseIfNode::" << endl;
        cout << " Elif-Cond: " ;
        expr->visit();
        cout << "ElseIfCode -- " ; block->visit();
        cout << endl;
    }
};

class ElseNode: public ASTnode
{
public:
    ASTnode* block;
    ElseNode(ASTnode* block_)
    {
        block = block_;
    }
    virtual void visit()
    {
        cout << "ElseNode:: ";
        block->visit();
        cout << endl;
    }
};

class VoidNode: public ASTnode
{
public:
    VoidNode()
    {

    }
    virtual void visit()
    {
        cout << "VoidNode:: void" << endl;
    }
};

class WhileNode : public ASTnode
{
public:
    ASTnode* expr, * block;
    WhileNode(ASTnode* expr_,ASTnode* block_)
    {
        expr = expr_;
        block = block_;
    }
    virtual void visit()
    {
        cout << "WhileNode:: " << endl;
        cout << "WhileExp:: ";
        expr->visit();
        cout << "WhileBlock:: ";
        block->visit();
    }
};

class ForNode : public ASTnode
{
public:
    ASTnode* init, * cond, *incr, *block;
    ForNode(ASTnode* init_, ASTnode* cond_, ASTnode* incr_, ASTnode* block_)
    {
        init = init_;
        cond = cond_;
        incr = incr_;
        block = block_;
    }
    virtual void visit()
    {
        cout << "ForNode:: " << endl;
        cout << "ForExp:: ";
        cout << "ForInit :" ; initfvisit(); cout << endl;
        cout << "ForCond :"; cond->visit(); cout << endl;
        cout << "ForIncr :";
        incr->visit(); cout << endl;
        cout << "ForBlock:: ";
        block->visit();
    }
};

class TernaryNode : public ASTnode
{
public:
    ASTnode* cond, *ifpart,  *elsepart;
    TernaryNode(ASTnode* cond_, ASTnode* ifpart_, ASTnode* elsepart_)
    {
        cond = cond_;
        ifpart = ifpart_;
        elsepart = elsepart_;
    }
    virtual void visit()
    {
        cout << "TernaryNode:: " << endl;
        cout << "TernaryCond:: ";
        cond->visit();
        cout << "IfPart:: ";
        ifpart->visit();
        cout << "ElsePart:: ";
        elsepart->visit();
    }
};

class BreakNode: public ASTnode
{
public:
    BreakNode()
    {
    }
    virtual void visit()
    {
        cout << "BreakNode:: break" << endl;
    }
};

class ReturnNode : public ASTnode
{
public:
    ASTnode * expr_block;
    ReturnNode(ASTnode* block_)
    {
        expr_block = block_;
    }
    virtual void visit()
    {
        cout << "ReturnNode::";
        expr_block->visit();
    }
};

class CodesNode : public ASTnode
{
public:
    vector<class ASTnode*> codes_list;
    CodesNode(ASTnode* a)
    {
        codes_list.push_back(a);
    }

    void pb(ASTnode* a)
    {
        codes_list.push_back(a);
    }

    virtual void visit()
    {
        cout << "CodesNode:: ";
        for(int i=0; i<codes_list.size(); i++)
        {
            cout << i+1 << ": ";
            codes_list[i]->visit();
            cout <<  endl;
        }
        cout << endl;
    }
};

class ArgListNode: public ASTnode
{
public:
    vector <class ASTnode*> arg_list;
    ArgListNode(ASTnode* a)
    {
        arg_list.push_back(a);
    }
    void pb(ASTnode* a)
    {
        arg_list.push_back(a);
    }
    virtual void visit()
    {
        cout << "ArgListNode:: ";
        for(int i=0; i<arg_list.size(); i++)
        {
            cout << i+1 << ": ";
            arg_list[i]->visit();
            cout << endl;
        }
    }
};

class FunctionNode : public ASTnode
{
public:
    ASTnode* id;
    ASTnode* args;
    ASTnode* code;
    FunctionNode(ASTnode* id_, ASTnode* args_, ASTnode* code_)
    {
        id = id_;
        args = args_;
        code =  code_;
    }
    virtual void visit()
    {
        cout << "FunctionNode:: "; id->visit();
        cout << "FunctionArgs--" << endl; args->visit();
        cout << "FunctionCode--" << endl; code->visit();
    }
};

class FunctionListNode : public ASTnode
{
public:
    vector <class ASTnode*> functions_list;
    FunctionListNode(ASTnode* a)
    {
        functions_list.push_back(a);
    }
    void pb(ASTnode* a)
    {
        functions_list.push_back(a);
    }
    virtual void visit()
    {
        cout << "FunctionsNode:: " << endl;
        for(int i=0; i < functions_list.size(); i++)
        {
            cout << i+1 << ": ";
            functions_list[i]->visit();
            cout << endl;
        }
    }
};

class ImportsListNode: public ASTnode
{
public:
    vector<ASTnode*> modules_list;
    ImportsListNode(ASTnode* a)
    {
        modules_list.push_back(a);
    }
    void pb(ASTnode* a)
    {
        modules_list.push_back(a);
    }
    virtual void visit()
    {
        cout << "Imports:: ";
        for(int i=0; i< modules_list.size(); i++)
        {
            cout << i+1 << ": ";
            modules_list[i]->visit();
            cout << endl;
        }
    }
};

class FileNode: public ASTnode
{
public:
    ASTnode * imports;
    ASTnode * block;
    ASTnode * functions;

    FileNode(ASTnode * imports_, ASTnode* block_, ASTnode* functions_)
    {
        imports = imports_;
        block = block_;
        functions = functions_;
    }
    void visit()
    {
        cout << "FileNode:: " << endl;
        if(imports != NULL)
        {
            imports->visit();
        }
        if(block != NULL){
        block->visit();
        }
        functions->visit();
    }
};

#ifndef MYCLASS_H_  // #include guards
#define MYCLASS_H_

#include <bits/stdc++.h>
#include <string>
using namespace std;
#include  <map>
// AST Node class
enum var_type {null, tint, tbool, tchar, tuint};
void genError(string);
void invalidTypeError();
var_type stot(string);
struct node
{
    var_type type;
    union
    {
        int i;
        char c;
        bool b;
        unsigned int ui;
    };
    // Initializer
    node()
    {
        type = null;
        i = 0;
    }
    node(int num) : type(tint),i(num){}
    node(bool boo): type(tbool),b(boo){}
    node(char ch) : type(tchar),c(ch){}
    node(unsigned int uin): type(tuint),ui(uin){}

    node operator+(const node &obj)
    {
        node result;
        if(type == obj.type)
        {
            switch(type)
            {
                case tint:
                result.i = i + obj.i; result.type=tint;break;
                case tuint:
                result.ui = ui + obj.ui; result.type=tuint;break;
                default:
                genError("Addition got an invalid type");
            }
        }
        else
        {
            invalidTypeError();
        }
    return result;
    }
    node operator-(const node &obj)
    {
        node result;
        if(type == obj.type)
        {
            switch(type)
            {
                case tint:
                result.i = i - obj.i; result.type=tint;break;
                case tuint:
                result.ui = ui - obj.ui; result.type=tuint;break;
                default:
                genError("Subtaction got an invalid type");
            }
        }
        else
        {
            invalidTypeError();
        }
    return result;
    }
    node operator*(const node &obj)
    {
        node result;
        if(type == obj.type)
        {
            switch(type)
            {
                case tint:
                result.i = i * obj.i; result.type=tint;break;
                case tuint:
                result.ui = ui * obj.ui; result.type=tuint;break;
                default:
                genError("Multiplication got an invalid type");
            }
        }
        else
        {
            invalidTypeError();
        }
    return result;
    }
    node operator/(const node &obj)
    {
        node result;
        if(type == obj.type)
        {
            switch(type)
            {
                case tint:
                result.i = i / obj.i; result.type=tint;break;
                case tuint:
                result.ui = ui / obj.ui; result.type=tuint;break;
                default:
                genError("Division got an invalid type");
            }
        }
        else
        {
            invalidTypeError();
        }
    return result;
    }
    node operator%(const node &obj)
    {
        node result;
        if(type == obj.type)
        {
            switch(type)
            {
                case tint:
                result.i = i % obj.i; result.type=tint;break;
                case tuint:
                result.ui = ui % obj.ui; result.type=tuint;break;
                default:
                genError("Division got an invalid type");
            }
        }
        else
        {
            invalidTypeError();
        }
    return result;
    }
    node operator<(const node &obj)
    {
        node result;
        if(type == obj.type)
        {
            switch(type)
            {
                case tint:
                result.b = i < obj.i; result.type=tbool;break;
                case tuint:
                result.b = ui < obj.ui; result.type=tbool;break;
                case tchar:
                result.b = c < obj.c; result.type=tbool;break;
                default:
                genError("LT got an invalid type");
            }
        }
        else
        {
            invalidTypeError();
        }
    return result;
    }
    node operator>(const node &obj)
    {
        node result;
        if(type == obj.type)
        {
            switch(type)
            {
                case tint:
                result.b = i > obj.i; result.type=tbool;break;
                case tuint:
                result.b = ui > obj.ui; result.type=tbool;break;
                case tchar:
                result.b = c > obj.c; result.type=tbool;break;
                default:
                genError("GT got an invalid type");
            }
        }
        else
        {
            invalidTypeError();
        }
    return result;
    }
    node operator<=(const node &obj)
    {
        node result;
        if(type == obj.type)
        {
            switch(type)
            {
                case tint:
                result.b = i <= obj.i; result.type=tbool;break;
                case tuint:
                result.b = ui <= obj.ui; result.type=tbool;break;
                case tchar:
                result.b = c <= obj.c; result.type=tbool;break;
                default:
                genError("LEQ got an invalid type");
            }
        }
        else
        {
            invalidTypeError();
        }
    return result;
    }
    node operator>=(const node &obj)
    {
        node result;
        if(type == obj.type)
        {
            switch(type)
            {
                case tint:
                result.b = i >= obj.i; result.type=tbool;break;
                case tuint:
                result.b = ui >= obj.ui; result.type=tbool;break;
                case tchar:
                result.b = c >= obj.c; result.type=tbool;break;
                default:
                genError("GEQ got an invalid type");
            }
        }
        else
        {
            invalidTypeError();
        }
    return result;
    }
    node operator==(const node &obj)
    {
        node result;
        if(type == obj.type)
        {
            switch(type)
            {
                case tint:
                result.b = i == obj.i; result.type=tbool;break;
                case tuint:
                result.b = ui == obj.ui; result.type=tbool;break;
                case tchar:
                result.b = c == obj.c; result.type=tbool;break;
                case tbool:
                result.b = b = obj.b; result.type=tbool;break;
                default:
                genError("EEQ got an invalid type");
            }
        }
        else
        {
            invalidTypeError();
        }
    return result;
    }
    bool operator==(const bool &bool_val)
    {
        if(type == tbool)
        {
            if(b == bool_val){return true;}
            else{return false;}
        }
        else{genError("Invalid bool - node comparision");}
    }
    node operator!=(const node &obj)
    {
        node result;
        if(type == obj.type)
        {
            switch(type)
            {
                case tint:
                result.b = i != obj.i; result.type=tbool;break;
                case tuint:
                result.b = ui != obj.ui; result.type=tbool;break;
                case tchar:
                result.b = c != obj.c; result.type=tbool;break;
                case tbool:
                result.b = b != obj.b; result.type=tbool;break;
                default:
                genError("NEQ got an invalid type");
            }
        }
        else
        {
            invalidTypeError();
        }
    return result;
    }
    node operator&&(const node &obj)
    {
        node result;
        if(type == obj.type)
        {
            switch(type)
            {
                case tbool:
                result.b = b && obj.b; result.type=tbool;break;
                default:
                genError("Or got an invalid type");
            }
        }
        else
        {
            invalidTypeError();
        }
        return result;
    }
    node operator||(const node &obj)
    {
        node result;
        if(type == obj.type)
        {
            switch(type)
            {
                case tbool:
                result.b = b || obj.b; result.type=tbool;break;
                default:
                genError("Or got an invalid type");
            }
        }
        else
        {
            invalidTypeError();
        }
        return result;
    }
    node & operator -(void)
    {
        switch(type)
        {
            case tint:
            i = -i; break;
            case tuint:
            ui = -ui;break;
            default:
            genError("Unary Minus got an invalid type");
        }
        return *this;
    }
    node& operator !(void)
    {
        switch(type)
        {
            case tbool:
            b = !b;break;
            default:
            genError("Unary Minus got an invalid type");
        }
        return *this;
    }
    node& operator+=(const node& obj)
    {
        if(type == obj.type)
        {
            switch(type)
            {
                case tint:
                i += obj.i;break;
                case tuint:
                ui += obj.ui;break;
                default:
                genError("PE got an invalid type");
            }
        }
        else
        {
            invalidTypeError();
        }
    return *this;
    }
    node& operator-=(const node& obj)
    {
        if(type == obj.type)
        {
            switch(type)
            {
                case tint:
                i -=  obj.i; break;
                case tuint:
                ui -= ui + obj.ui;break;
                default:
                genError("PE got an invalid type");
            }
        }
        else
        {
            invalidTypeError();
        }
        return *this;
    }
    node& operator=(const node& obj)
    {
        if(type == obj.type)
        {
            switch(type)
            {
                case tint:
                i =  obj.i;break;
                case tuint:
                ui = obj.ui;break;
                case tbool:
                b = obj.b;break;
                case tchar:
                c = obj.c; break;
                default:
                genError("PE got an invalid type");
            }
        }
        else
        {
            invalidTypeError();
        }
        return *this;
    }
    friend ostream& operator<<(ostream& os, const node& item);
};
node get_empty_node(var_type);

class Symbol_table
{
public:
    std::map <string, node> table;
    std::map <string, pair<int, node*>> array_table; 
    Symbol_table()
    {}
    //Array table
    bool check_var(string val)
    {
        map<string,node>::iterator it;
        it = table.find(val);
        if(it == table.end())
        {return false;}
        return true;
    }
    bool check_arr(string val)
    {
        map<string,pair<int, node*>>::iterator it;
        it = array_table.find(val);
        if(it == array_table.end())
        {return false;}
        return true;
    }
    void create_var(string var_name,var_type ty)
    {
        map<string,node>::iterator it;
        it = table.find(var_name);
        if (it != table.end())
        {
            genError("Variable being reinitialized");
        }
        else
        {            
        table.insert(pair<string, node>(var_name,get_empty_node(ty)));
        }
    }
    void create_array(string var_name,var_type ty, int array_size)
    {
        if(array_size == 0){genError("Array of size 0 initializes");}

        map<string,pair<int,node*>>::iterator it;
        it = array_table.find(var_name);
        if (it != array_table.end())
        {
            genError("Array being reinitialized");
        }
        else
        {   
            node * array_struct = new node[array_size];
            for(int i=0; i < array_size; i++) 
            {
                array_struct[i].type = ty;
                array_struct[i].i = 0;
            }  
            array_table.insert(pair<string, pair<int,node*>>
                    (var_name,
                    (pair<int,node*>(array_size,array_struct)
                    )
                    ));
        }
    }
    node get_var(string var_name)
    {
        map<string,node>::iterator it;
        it = table.find(var_name);
        if (it == table.end())
        {
            genError("Uninitialized Variable Accessed");
        }
        else
        {
            return it->second;
        }
    }
    node get_array(string var_name, int pos)
    {
        map<string,pair<int,node*>>::iterator it;
        it = array_table.find(var_name);
        if (it == array_table.end())
        {
            genError("Uninitialized Variable Accessed");
        }
        else
        {
            if(pos >= it->second.first)
            {
                genError("Array bounds exceeded");
            }
            return it->second.second[pos];
        }
    }
    node update_var(string var_name,node value)
    {
        map<string,node>::iterator it;
        it = table.find(var_name);
        if (it == table.end())
        {
            genError("Accessing an uninitialized array");
        }
        else
        {
            it->second = value;
            return this->get_var(var_name);
        }
    }
    node update_array(string var_name,node value, int pos)
    {
        map<string,pair<int,node*>>::iterator it;
        it = array_table.find(var_name);
        if (it == array_table.end())
        {
            genError("Accessing an uninitialized array");
        }
        else
        {
            if(pos >= it->second.first)
            {
                genError("Array index out of binds");
            }
            it->second.second[pos] = value;
            return this->get_array(var_name,pos);
        }
    }
    void print()
    {
        for (auto& x: table)
        {
            std::cout << x.first << ": " << x.second << '\n';
        }
    }
    void array_print()
    {
        for (auto& x: array_table)
        {
            std::cout << x.first << ": ";
            for(int i = 0; i < x.second.first;i++){cout << x.second.second[i];} 
            cout << '\n';
        }
    }
    void create_and_update(string var_name,node value)
    {
        map<string,node>::iterator it;
        it = table.find(var_name);
        if (it != table.end())
        {
            genError("Reinitialized variable");
        }
        else
        {
            table.insert(pair<string, node>(var_name,value));
        }
    }
    
};

extern Symbol_table global_table;

// struct pointer_type
// {
//     int  * pi;
//     char * pc;
//     bool * pb;
//     unsigned int * pui;
//     char type[10];
// };
//
// struct symb_type
// {
//   char type[10];
//   int row; // array
//   int col; // array
//   out_type value;
//   pointer_type point;
// };

// // void print(out_type);
// // void print_map(map <string, symb_type> &);

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

        virtual node interpret()
        {}
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

    virtual node interpret();

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

    virtual node interpret();
};

class BoolLiteral:  public ASTnode
{
public:
    bool value;

    BoolLiteral(bool  inp)
    {
        value = inp;
    }

    virtual void visit()
    {
        cout << "BoolLiteral:: " << value << endl;
    }

    virtual node interpret();

};

class UintLiteral:  public ASTnode
{
public:
    unsigned int value;

    UintLiteral(string  inp)
    {
        value = stoi(inp.substr(2));
    }

    virtual void visit()
    {
        cout << "UintLiteral:: " << value << endl;
    }

    virtual node interpret();
};
// Expression ------------------------------------------------------------------

class BiExprNode : public ASTnode
{
public:
    string operator_symbol;
    ASTnode* left;
    ASTnode* right;

    BiExprNode(ASTnode* l, ASTnode* r, string opr)
    {
        left = l;
        right = r;
        operator_symbol  = opr;
    }

    virtual string get_value()
    {
        return operator_symbol;
    }

    virtual void visit()
    {
        cout << "BiExprNode:: " << operator_symbol << endl;
        cout <<  "|-" ;
        left->visit();
        cout <<  "|-"; right->visit(); cout << endl;
    }

    virtual node interpret();
};

class UniExprNode : public ASTnode
{
public:
    string operator_symbol;
    ASTnode* uno;

    UniExprNode(ASTnode* nd, string opr)
    {
        uno = nd;
        operator_symbol  = opr;
    }

    virtual string get_value()
    {
        return operator_symbol;
    }

    virtual void visit()
    {
        cout << "UniExprNode:: " << operator_symbol << endl;
        cout << "|-";
        uno->visit();
        cout << endl;
    }

    virtual node interpret();

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

    virtual node interpret();
    // virtual out_type interpret()
    // {
    //   out_type ret;
    //   map <string, symb_type>::iterator iter;
    //   iter = Symbol_table.find(this->value);
    //   if(iter != Symbol_table.end())
    //   {
    //     //Element exists;
    //     if(iter->second.type == string("single"))
    //     {
    //       return iter->second.value;
    //     }
    //   }
    //   else
    //   {
    //     cout << "No Variable available";
    //   }
    // }
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
    virtual node interpret();
    virtual void visit()
    {
        cout << "OneDArray :: " << endl;
        id->visit();
        cout << "[";
        row->visit();
        cout << "]";
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
    virtual node interpret();
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

    virtual node interpret();

    // virtual out_type interpret()
    // {
    //   out_type ret;
    //   strcpy(ret.type,"bool");
    //   ret.b = true;
    //   map <string, symb_type>::iterator iter;
    //   SingleId *pd = dynamic_cast<SingleId*>(this->id);
    //   iter = Symbol_table.find(pd->value);
    //   if(iter != Symbol_table.end())
    //   {
    //     cout << "Re Init Error";
    //   }
    //   else
    //   {
    //      symb_type tmp;
    //      strcpy(tmp.type,"single");
    //      tmp.value.i = 0;
    //      tmp.value.b = false ;
    //      tmp.value.ui = 0;
    //      tmp.value.c = 0;
    //      strcpy(tmp.value.type,this->type.c_str());
    //      Symbol_table.insert(pair<string, symb_type>(pd->value,tmp));
    //   }
    //   return ret;
    // }

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

    virtual node interpret();
  //   virtual out_type interpret()
  //   {
  //     out_type ret;
  //     out_type row;
  //     strcpy(ret.type,"bool");
  //     ret.b = true;
  //     map <string, symb_type>::iterator iter;
  //     SingleId *pd = dynamic_cast<SingleId*>(this->id);
  //     iter = Symbol_table.find(this->id->value);
  //     if(iter != Symbol_table.end())
  //     {
  //       cout << "Re Init Error";
  //     }
  //     else
  //     {
  //        symb_type tmp;
  //        strcpy(tmp.type,"oned");
  //        row = this->row->interpret();
  //        int row_size;
  //        if(row.type == string("int"))
  //        {
  //          row_size = row.i;
  //        }
  //        else if(row.type == string("uint"))
  //        {
  //          row_size = (int) row.ui;
  //        }
  //        tmp.value.i = 0;
  //        tmp.value.b = false ;
  //        tmp.value.ui = 0;
  //        tmp.value.c = 0;
  //
  //        if(row_size <= 0)
  //        {throw "error : row size";}
  //        tmp.row = row_size;
  //        strcpy(tmp.value.type,this->type.c_str());
  //        cout << tmp.value.type << endl;
  //        if(tmp.value.type == string("int"))
  //        {    cout << "INT" << endl;
  //             tmp.point.pi = new int[tmp.row];}
  //        else if(tmp.value.type == string("char"))
  //        { tmp.point.pc = new char[tmp.row];}
  //        else if(tmp.value.type == string("uint"))
  //        { tmp.point.pui = new unsigned int[tmp.row];}
  //        else if(tmp.value.type == string("bool"))
  //        {   cout << "BOOL" << endl;
  //            tmp.point.pb = new bool[tmp.row];}
  //
  //        Symbol_table.insert(pair<string, symb_type>(pd->value,tmp));
  //     }
  //     return ret;
  // }
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

    // virtual out_type interpret()
    // {
    //   out_type ret;
    //   out_type row;
    //   out_type col;
    //   strcpy(ret.type,"bool");
    //   ret.b = true;
    //   map <string, symb_type>::iterator iter;
    //   iter = Symbol_table.find(this->id->value);
    //   if(iter != Symbol_table.end())
    //   {
    //     cout << "Re Init Error";
    //   }
    //   else
    //   {
    //      symb_type tmp;
    //      strcpy(tmp.type,"twod");
    //
    //      row = this->row->interpret();
    //      col = this->col->interpret();
    //
    //      int row_size;
    //      int col_size;
    //
    //      if(row.type == string("int"))
    //      {
    //        row_size = row.i;
    //      }
    //      else if(row.type == string("uint"));
    //      {
    //        row_size = row.ui;
    //      }
    //      if(col.type == string("int"))
    //      {
    //        col_size = row.i;
    //      }
    //      else if(col.type == string("uint"));
    //      {
    //        col_size = row.ui;
    //      }
    //      tmp.value.i = 0;
    //      tmp.value.b = false ;
    //      tmp.value.ui = 0;
    //      tmp.value.c = 0;
    //      if(row_size <= 0 || col_size <= 0)
    //      {throw "error : row size";}
    //
    //      tmp.row = row_size;
    //      tmp.col = col_size;
    //
    //      if(tmp.value.type == "int")
    //      { tmp.point.pi = new int[tmp.row*tmp.col];}
    //      else if(tmp.value.type == "char")
    //      { tmp.point.pc = new char[tmp.row*tmp.col];}
    //      else if(tmp.value.type == "uint")
    //      { tmp.point.pui = new unsigned int[tmp.row*tmp.col];}
    //      else if(tmp.value.type == "bool")
    //      { tmp.point.pb = new bool[tmp.row*tmp.col];}
    //
    //      strcpy(tmp.value.type,this->type.c_str());
    //      Symbol_table.insert(pair<string, symb_type>(this->id->value,tmp));
    //   }
    //   return ret;
    // }
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
    virtual node interpret();
    // virtual out_type interpret()
    // {
    //   // a = exp;
    //   out_type ret;
    //   out_type exp_res;
    //   strcpy(ret.type,"bool");
    //   ret.b = true;
    //   exp_res = this->expr->interpret();
    //   if(this->location->type == string("single"))
    //   {
    //       SingleId *pd = dynamic_cast<SingleId*>(this->location);
    //       iter = Symbol_table.find(pd->id);
    //       if(iter == Symbol_table.end())
    //       {
    //         throw "No Symbol";
    //       }
    //       else
    //       {
    //         if(this->asgn_op == string("="))
    //         {Symbol_table[iter->first] = exp_res;}
    //         else if(this->asgn_op == string("+="))
    //         {Symbol_table[iter->first] = add_out(iter->second,exp_res);}
    //         else if(this->asgn_op == string("-="))
    //         {Symbol_table[iter->first] = sub_out(iter->second,exp_res);}
    //       }
    //   }
    //   else if(this->location->type == string("oned"))
    //   {
    //       SingleId *pd = dynamic_cast<OneDArray*>(this->location);
    //
    //       iter = Symbol_table.find(pd->id);
    //       if(iter == Symbol_table.end())
    //       {
    //         throw "No Symbol";
    //       }
    //       else
    //       {
    //         if(this->asgn_op == string("="))
    //         {
    //             Symbol_table[iter->first] = exp_res;
    //         }
    //         else if(this->asgn_op == string("+="))
    //         {
    //             ;
    //             Symbol_table[iter->first] = iter->second,exp_res);
    //
    //         }
    //         else if(this->asgn_op == string("-="))
    //         {
    //             Symbol_table[iter->first] = sub_array(iter->second,exp_res);
    //         }
    //       }
    //   }
    //   return ret;
    // }


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

    virtual node interpret();
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

    virtual node interpret();
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
    virtual node interpret();
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
    virtual node interpret();
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
    virtual node interpret();  
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
    virtual node interpret();
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
    virtual node interpret();
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
    virtual node interpret();
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
        cout << "ForInit :" ; init->visit(); cout << endl;
        cout << "ForCond :"; cond->visit(); cout << endl;
        cout << "ForIncr :";
        incr->visit(); cout << endl;
        cout << "ForBlock:: ";
        block->visit();
    }
    virtual node interpret();
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
    virtual node interpret();
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
    virtual node interpret();
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
    virtual node interpret();
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
    vector<string> get_param_names()
    {
        vector<string> all_vars;
        bool nonvoidparamexist = true;
        if(arg_list.size() == 1)
        {
            VoidNode* vd = dynamic_cast<VoidNode*>(arg_list[0]); 
            if(vd != NULL){nonvoidparamexist = false;}
        }
        if(nonvoidparamexist)
        {
            for(auto x: arg_list)
            {
                // Single Init Node -- x
                SingleInitNode* init_node = dynamic_cast<SingleInitNode*>(x);
                SingleId *pd = dynamic_cast<SingleId*>(init_node->id);
                all_vars.push_back(pd->value);
            }
        }
        return all_vars;
    } 
    virtual node interpret();
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
    virtual node interpret();
    node special_interpret();
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
    virtual node interpret();
};

class Function_table 
{
    public:
    std::map <string, FunctionNode*> table;
    bool check_function(string val)
    {
        map<string,FunctionNode*>::iterator it;
        it = table.find(val);
        if(it == table.end())
        {return false;}
        return true;
    }
    
    FunctionNode* get_function(string var_name)
    {
        map<string,FunctionNode*>::iterator it;
        it = table.find(var_name);
        if (it == table.end())
        {
            genError("Undefined function Accessed");
        }
        else
        {
            return it->second;
        }
    }

    void print()
    {
        for (auto& x: table)
        {
            std::cout << x.first << ": " << "Function" << '\n';
        }
    }

    void create_and_update(string var_name,FunctionNode* func_name)
    {
        map<string,FunctionNode*>::iterator it;
        it = table.find(var_name);
        if (it != table.end())
        {
            genError("Redeclared function");
        }
        else
        {
            table.insert(pair<string, FunctionNode*>(var_name,func_name));
        }
    }

    FunctionNode* get_main()
    {
        map<string,FunctionNode*>::iterator it;
        it = table.find("main");
        if (it == table.end())
        {
            genError("No Main function");
        }
        else
        {
            return it->second;
        }
    }
};
extern Function_table method_table;

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
    virtual node interpret();
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
    virtual node interpret();
};

#endif

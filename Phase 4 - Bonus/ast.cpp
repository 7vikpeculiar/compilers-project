#include "ast.h"

using namespace std;

// Ast related code
void genError(string a)
{
    cout << a << endl;
}

void invalidTypeError()
{
    cout << "Invalid types are being operated on" << endl;
}

ostream& operator<<(ostream& os, const node& item)
{
    switch(item.type)
    {
        case tint:
        os << item.i << " "; break;
        case tuint:
        os << item.ui << " "; break;
        case tbool:
        os << (item.b ? "True" : "False") << " "; break;
        case tchar:
        os << item.c << " "; break;
        default:
        os << "null ";
    }
    return os;
}

var_type stot(string a)
{
    if(a == string("int")){return tint;}
    else if(a == string("bool")){return tbool;}
    else if(a == string("char")){return tchar;}
    else if(a == string("uint")){return tuint;}
    else{return null;}
}

node get_empty_node(var_type type)
    {
        if(type == tint)
        {return node((int) 0);}
        else if(type == tbool)
        {return node(false);}
        else if(type == tchar)
        {return node((char) 0);}
        else if(type == tuint)
        {return node((unsigned int) 0);}
        return node();
    }

// void print(out_type a)
// {
//     if(a.type == string("int"))
//     {
//         cout << a.type << " " << a.i << endl;
//     }
//     if(a.type == string("uint"))
//     {
//         cout << a.type << " " << a.ui << endl;
//     }
//     if(a.type == string("bool"))
//     {
//         string tmp = (a.b)? "True ":"False ";
//         cout << a.type << " " << a.b << " " << tmp << endl;
//     }
//     if(a.type == string("char"))
//     {
//         cout << a.type << " " << a.c << endl;
//     }
// }
//
// void print_arr(string type, pointer_type a, int val)
// {
//     if(type == "int")
//     {
//         cout << "int ";
//         for(int i=0; i < val; i++)
//         {
//             cout << a.pi[i] << " ";
//         }
//         cout << endl;
//      }
//     else if(type == "uint")
//     {
//         cout << "uint ";
//         for(int i=0; i < val; i++)
//         {
//             cout << a.pui[i] << " ";
//         }
//         cout << endl;
//     }
//     else if(type == "char")
//     {
//         cout << "char ";
//         for(int i=0; i < val; i++)
//         {
//             cout << a.pc[i] << " ";
//         }
//         cout << endl;
//     }
//     else if(type == "bool")
//     {
//         cout << "bool ";
//         for(int i=0; i < val; i++)
//         {
//             string tmp = (a.pb[i])? "True":"False";
//             cout << tmp << " ";
//         }
//         cout << endl;
//     }
// }
//
// void print_map(map <string, symb_type> &table)
// {
//     int i = 0;
//     for(auto it = table.cbegin(); it != table.cend(); ++it)
//     {
//     cout << i << ": " << it->first << " | " << it->second.type << " | ";
//         if(it->second.type == string("single"))
//         {print(it->second.value);}
//         else if(it->second.type == string("oned"))
//         {print_arr(it->second.value.type,it->second.point,it->second.row);}
//         else if(it->second.type == "twod")
//         {print_arr(it->second.value.type,it->second.point,it->second.row*it->second.col);}
//     cout  << " "  << "\n";
//     ++i;
//     }
// }
//
//
// void add_array()
// {}

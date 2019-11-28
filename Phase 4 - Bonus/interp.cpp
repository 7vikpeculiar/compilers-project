#include "ast.h"
#include <map>

Symbol_table global_table;
Function_table method_table;

node IntLiteral::interpret()
{
      return node(value);
}

node CharLiteral::interpret()
{
      return node(value);
}

node BoolLiteral::interpret()
{
      return node(value);
}

node UintLiteral::interpret()
{
      return node(value);
}

node BiExprNode::interpret()
{
      node left_val  = left->interpret();
      node right_val = right->interpret();

      if(this->operator_symbol == string("add"))
      {
        return left_val + right_val;
      }
      else if(this->operator_symbol == string("sub"))
      {
        return left_val - right_val;
      }
      else if(this->operator_symbol == string("mult"))
      {
        return left_val * right_val;
      }
      else if(this->operator_symbol == string("div"))
      {
        return left_val / right_val;
      }
      else if(this->operator_symbol == string("mod"))
      {
        return left_val % right_val;
      }
      else if(this->operator_symbol == string("leq"))
      {
        return left_val <= right_val;
      }
      else if(this->operator_symbol == string("geq"))
      {
        return left_val >= right_val;
      }
      else if(this->operator_symbol == string("lt"))
      {
        return left_val < right_val;
      }
      else if(this->operator_symbol == string("gt"))
      {
        return left_val > right_val;
      }
      else if(this->operator_symbol == string("eq"))
      {
        return left_val == right_val;
      }
      else if(this->operator_symbol == string("neq"))
      {
        return left_val != right_val;
      }
      else if(this->operator_symbol == string("and"))
      {
        return left_val && right_val;
      }
      else if(this->operator_symbol == string("or"))
      {
        return left_val || right_val;
      }
}

node UniExprNode::interpret()
{
  node expr_val = uno->interpret();
  if(operator_symbol == string("uminus"))
  {
    return - expr_val;
  }
  else if(operator_symbol == string("not"))
  {
    return ! expr_val;
  }
}

node SingleId::interpret()
{
  if(global_table.check_var(value))
  {
    return global_table.get_var(value);
  }
  else
  {
    global_table.create_var(value,null);
  }
}

node SingleInitNode::interpret()
{
  SingleId *pd = dynamic_cast<SingleId*>(this->id);
  string var_name = pd->value;
  global_table.create_var(var_name,stot(type));
  return global_table.get_var(var_name);
}

node InitAssignmentNode::interpret()
{
     if(asgn_op != string("="))
    {genError("+=, -= used for an unintialized variable");}

    SingleId *pd = dynamic_cast<SingleId*>(location);
    node expr_val = expr->interpret();
    global_table.create_and_update(pd->value,expr_val);
    return global_table.get_var(pd->value);

}

node AssignmentNode::interpret()
{ 
  SingleId *pd = dynamic_cast<SingleId*>(location);
  node expr_val = expr->interpret();
  if(pd!= NULL)
  {
    if(asgn_op == string("="))
    {
      global_table.update_var(pd->value,expr_val);
      return global_table.get_var(pd->value);
    }
    if(asgn_op == string("+="))
    {
      node var_value = global_table.get_var(pd->value);
      var_value += expr_val;
      global_table.update_var(pd->value,var_value);
      return global_table.get_var(pd->value);
    }
    if(asgn_op == string("-="))
    {
      node var_value = global_table.get_var(pd->value);
      var_value -= expr_val;
      global_table.update_var(pd->value,var_value);
      return global_table.get_var(pd->value);
    }
  }

  OneDArray * ad = dynamic_cast<OneDArray*>(location);
  if(ad!= NULL)
  {
    node row_val = ad->row->interpret();
    if(row_val.type != tint)
    {
      genError("Invalid array index");
    }
    SingleId *pd = dynamic_cast<SingleId*>(ad->id);
    if(asgn_op == string("="))
    {
      global_table.update_array(pd->value,expr_val,row_val.i);
      return global_table.get_array(pd->value,row_val.i);
    }
    if(asgn_op == string("+="))
    {
      node var_value = global_table.get_array(pd->value,row_val.i);
      var_value += expr_val;
      global_table.update_array(pd->value,var_value,row_val.i);
      return global_table.get_var(pd->value);
    }
    if(asgn_op == string("-="))
    {
      node var_value = global_table.get_array(pd->value,row_val.i);
      var_value -= expr_val;
      global_table.update_array(pd->value,var_value,row_val.i);
      return global_table.get_var(pd->value);
    }
  }
  return node();
}

node StatementsNode::interpret()
{
  for(auto x: statements_list)
  {
    x->interpret();
  }
  return node();
}

node VoidNode::interpret()
{
  return node(false);
}

node ForNode::interpret()
{
  init->interpret();
  while(cond->interpret() == true)
  {
    block->interpret();
    incr->interpret();
  } 
  return node();
}

node WhileNode::interpret()
{
  while(expr->interpret() == true)
  {
    block->interpret();
  } 
  return node();
}

node CodesNode::interpret()
{
   for(auto x: codes_list)
  {
    x->interpret();
  }
  return node();
}

node TernaryNode::interpret()
{
  if(cond->interpret() == true)
  {
    return ifpart->interpret();
  }
  else
  {
    return elsepart->interpret();
  }
}

node ConditionNode::interpret()
{
  if(if_expr->interpret() == true)
  {
    code_block->interpret();
  }
  else
  { 
    if(else_block != NULL)
    {
      else_block->interpret();
    }
  }
  return node();
}

node ElseBlockNode::interpret()
{
  bool used_up_elif = false;
  for(auto x: elseif_list)
  {
    if(x->interpret() == true) //Block evaled
    {used_up_elif = true; break;}
  }
  if(!used_up_elif)
  {
    if(else_block != NULL)
    {
      else_block->interpret();
    }
  }
}

node ElseIfNode::interpret()
{
  node if_cond_output = expr->interpret(); 
  if(if_cond_output == true)
  {block->interpret();}
  return if_cond_output;
}

node ElseNode::interpret()
{
  return block->interpret();
}

node FunctionListNode::interpret()
{
    for(auto x: functions_list)
    {
      x->interpret();
    } 
    return node();
}

node FileNode::interpret()
{
    if(imports != NULL)
    {
      imports->interpret();
    }
    if(block != NULL)
    {
      block->interpret();
    }
    functions->interpret();
    // Function table is filled
    // Main method called
    FunctionNode* main_method = method_table.get_main();
    return main_method->code->interpret();
    
}

node FunctionNode::interpret()
{
   SingleId *pd = dynamic_cast<SingleId*>(this->id);
   method_table.create_and_update(pd->value, dynamic_cast<FunctionNode*>(this));
   return node();
}

node FunctionNode::special_interpret()
{
  CodesNode* cd = dynamic_cast<CodesNode*>(code);
  for(auto x:cd->codes_list)
  {
    ReturnNode* rd = dynamic_cast<ReturnNode*>(x);
    if(rd == NULL){x->interpret();}
    else
    {
      return rd->interpret();
      break;
    }
  }
  return node();
}

node ReturnNode::interpret()
{
  VoidNode* rd = dynamic_cast<VoidNode*>(expr_block);
  if(rd == NULL)
  {
    //Not a void node
    return expr_block->interpret();
  }
  else{return node();}
}
node ImportsListNode::interpret()
{
  return node();
}

node ArgListNode::interpret()
{
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
      x->interpret();
    }
  }
  int sz = arg_list.size();
  return node(sz);
}

node MethodCallNode::interpret()
{
  SingleId *pd = dynamic_cast<SingleId*>(id);
  Symbol_table temp_table = global_table;
  vector <node> param_vector;
  if(params != NULL)
  {
    ListExprsNode* parameters = dynamic_cast<ListExprsNode*>(params);
   
    for(auto x: parameters->exprs_list)
    {
      param_vector.push_back(x->interpret());
    }  
  }
  if(pd->value == string("print"))
  {
    cout << "Print Output : ";
    for(int i=0; i < param_vector.size();i++)
    {
      cout << param_vector[i] << " ";
    }
    cout << endl;
    return node();
  }
   FunctionNode* method = method_table.get_function(pd->value);
  global_table.table.clear(); 

  node lengthofargs = method->args->interpret();
  // cout << "Lenght of args " << lengthofargs << endl;
  // cout << "Param vector size" << param_vector.size() << endl;
  if(lengthofargs.i != param_vector.size())
  {
    genError("Incorrect usage of function");
  }
  
  ArgListNode* arg_list = dynamic_cast<ArgListNode*>(method->args);
  vector<string> arg_names = arg_list->get_param_names();
 
  auto ItA = arg_names.begin();
  auto ItB = param_vector.begin();
  while(ItA != arg_names.end() || ItB != param_vector.end())
  {
    global_table.update_var(*ItA, *ItB);
    ++ItA;++ItB;
  }
  node result = method->special_interpret();

  cout << "End of function call" << endl;
  cout << "--------------" << endl;
  global_table.print();
  cout << "--------------" << endl;
  // cout << "Global Function" << endl;
  global_table = temp_table;
  cout << "..............." << endl;
  global_table.print();
  cout << "--------------" << endl;
  return result;
}

node OneDArray::interpret()
{
  SingleId *pd = dynamic_cast<SingleId*>(id);
  node row_expr = row->interpret();
  if(row_expr.type != tint)
  {
    genError("Invalid array Index");
  }
  return global_table.get_array(pd->value,row_expr.i);
  //return node();
}

node OneDInitNode::interpret()
{
  SingleId *pd = dynamic_cast<SingleId*>(id);
  node row_val = row->interpret();
  if(row_val.type != tint)
  {
    genError("Invalid Index");
  }
  global_table.create_array(pd->value,stot(type),row_val.i);
  return node();
}

// virtual out_type OneDArray::interpret()
// {
//   // out_type ret;
//   // out_type row;
//   // iter = Symbol_table.find(this->id);
//   // if(iter != Symbol_table.end())
//   // {
//   //   //Element exists;
//   //   if(iter->type == str("oned"))
//   //   {
//   //     iter = row->interpret();
//   //     return iter->second.value;
//   //   }
//   // }
// }

// virtual out_type InitAssignmentNode::interpret()
// {
//
// }

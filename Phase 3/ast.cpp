#include "ast.h"
using namespace std;

LLVMContext Context;
Module *TheModule = new Module("Bayla Compiler", Context); // Contains all functions and variables
IRBuilder<> Builder(Context); // helps to generate LLVM IR with helper functions
map <string, AllocaInst*>NamedValues; // keeps track of all the values defined in the current scope like a symbol table
std::vector<std::string> FunArgs;
// stack<loopInfo *> *loops = new stack<loopInfo*>();
// Value *ErrorV(const char *Str) { Error(Str); return 0; }
Function *createFunc(IRBuilder<> &Builder, std::string Name)
{
	std::vector<Type *> Integers(FunArgs.size(), Type::getInt32Ty(Context));
	FunctionType *funcType = llvm::FunctionType::get(Builder.getInt32Ty(),false);
	Function *fooFunc = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, Name, TheModule);
	return fooFunc;
}

void setFuncArgs(Function *fooFunc, std::vector<std::string> FunArgs) {
unsigned Idx = 0;
Function::arg_iterator AI, AE;
for (AI = fooFunc->arg_begin(), AE = fooFunc->arg_end(); AI != AE;++AI, ++Idx)
AI->setName(FunArgs[Idx]);
}

BasicBlock *createBB(Function *fooFunc, std::string Name) {
	return BasicBlock::Create(Context, Name, fooFunc);
}

GlobalVariable *createGlob(IRBuilder<> &Builder, std::string Name) {
	TheModule->getOrInsertGlobal(Name, Builder.getInt32Ty());
	GlobalVariable *gVar = TheModule->getNamedGlobal(Name);
	gVar->setLinkage(GlobalValue::CommonLinkage);
	gVar->setAlignment(4);
	return gVar;
}

Value *createArith(IRBuilder<> &Builder, Value *L, Value *R) {
return Builder.CreateMul(L, R, "multmp");
}

Value *IntLiteral::Codegen() {
  // return ConstantFP::get(getGlobalContext(), APFloat(Val));
  return ConstantInt::get(Context, APInt(32, value));
}

Value *CharLiteral::Codegen() {
  // return ConstantFP::get(getGlobalContext(), APFloat(Val));
  return ConstantInt::get(Context, APInt(8, static_cast<uint64_t>(value)));
}

Value *BoolLiteral::Codegen() {
	int int_typecast = value ? 1 : 0;
  return ConstantInt::get(Context, APInt(1, int_typecast));
}

Value *UintLiteral::Codegen() {
  int uint_val = stoi(value.substr(2));
  return ConstantInt::get(Context, APInt(32, uint_val));
}

Value *BiExprNode::Codegen() {
  Value * left_expr = left->Codegen();
  Value * right_expr =  right->Codegen();
  if(left_expr == 0 || right_expr == 0)
  {
		return nullptr;
  }
	Value * v = nullptr;
  if(operator_symbol == string("add"))
  {v  =  Builder.CreateAdd(left_expr, right_expr, "addition");}
  else if(operator_symbol == string("sub"))
  { v  =  Builder.CreateSub(left_expr, right_expr, "subtraction");}
  else if (operator_symbol == string("mult"))
  { v  =  Builder.CreateMul(left_expr, right_expr, "multiplication");}
  else if (operator_symbol == string("div"))
  { v  =  Builder.CreateSDiv(left_expr, right_expr, "division");}
	else if (operator_symbol == string("mod"))
  { v  =  Builder.CreateSRem(left_expr, right_expr, "reminder");}
	else if (operator_symbol == string("leq"))
	{ v  = Builder.CreateICmpSLE(left_expr, right_expr, "leq");}
	else if (operator_symbol == string("geq"))
	{ v  = Builder.CreateICmpSGE(left_expr, right_expr, "geq");}
	else if (operator_symbol == string("gt"))
	{ v  = Builder.CreateICmpSGT(left_expr, right_expr, "gt");}
	else if (operator_symbol == string("lt"))
	{ v  = Builder.CreateICmpSLT(left_expr, right_expr, "lt");}
	else if (operator_symbol == string("eq"))
	{ v  = Builder.CreateICmpEQ(left_expr, right_expr, "eq");}
	else if (operator_symbol == string("neq"))
	{ v  = Builder.CreateICmpNE(left_expr, right_expr, "neq");}
	else if(operator_symbol == string("or"))
	{return Builder.Insert(BinaryOperator::Create(Instruction::Or, left_expr, right_expr, "doubleor"));}
	else if(operator_symbol == string("and"))
	{return Builder.Insert(BinaryOperator::Create(Instruction::And, left_expr, right_expr, "doubleand"));}
	return v;
}

Value * UniExprNode::Codegen()
{
	Value * expr_val = uno->Codegen();
	if(expr_val == 0)
  {
		return nullptr;
  }
	Value * v = nullptr;
  if(operator_symbol == string("uminus"))
  { v = Builder.CreateNeg(expr_val, "negation");}
  else if(operator_symbol == string("not"))
  { v  =  Builder.CreateNot(expr_val, "not");}
	return v;
}

AllocaInst *CreateEntryBlockAlloca(Function *TheFunction, string VarName, string type) {
    IRBuilder<> TmpB(&TheFunction->getEntryBlock(), TheFunction->getEntryBlock().begin());
    AllocaInst *alloca_instruction = nullptr;
    if (type == "int") {
        alloca_instruction = TmpB.CreateAlloca(Type::getInt32Ty(Context), 0, VarName);
    } else if (type == "bool") {
        alloca_instruction = TmpB.CreateAlloca(Type::getInt1Ty(Context), 0, VarName);
    }
		else if (type == "char") {
        alloca_instruction = TmpB.CreateAlloca(Type::getInt8Ty(Context), 0, VarName);
    }
		else if (type == "uint") {
        alloca_instruction = TmpB.CreateAlloca(Type::getInt32Ty(Context), 0, VarName);
    }
    return alloca_instruction;
}

Value *SingleInitNode::Codegen(map<string, AllocaInst *> &Old_vals)
{
	Value * V_get;
  llvm::Function *TheFunction = Builder.GetInsertBlock()->getParent();
	llvm::Value *init_val = nullptr;
	llvm::AllocaInst *Alloca = nullptr;
	SingleId *pd = dynamic_cast<SingleId*>(this->id);

	string var = pd->value;

	if(type == string("int"))
	{
		V_get = NamedValues[var];
		init_val = ConstantInt::get(Context, APInt(32,0));
		Alloca =  CreateEntryBlockAlloca(TheFunction,var,"int");
	}
 else if (type == string("bool"))
 {
	 V_get = NamedValues[var];
	 init_val = ConstantInt::get(Context, APInt(1,0));
	 Alloca =  CreateEntryBlockAlloca(TheFunction,var,"bool");
 }
 else if (type == string("uint"))
 {
	 V_get = NamedValues[var];
	 init_val = ConstantInt::get(Context, APInt(32,0));
	 Alloca =  CreateEntryBlockAlloca(TheFunction,var,"uint");
 }
 else if (type == string("char"))
 {
	 V_get = NamedValues[var];
	 init_val = ConstantInt::get(Context, APInt(8,0));
	 Alloca =  CreateEntryBlockAlloca(TheFunction,var,"char");
 }

	Builder.CreateStore(init_val, Alloca);
	Old_vals[var] = NamedValues[var];
  NamedValues[var] = Alloca;

	return init_val;
}

Value *InitAssignmentNode::Codegen(map<string, AllocaInst *> &Old_vals)
{
	SingleId *pd = dynamic_cast<SingleId*>(location);
	Value * V_get;
	llvm::Function *TheFunction = Builder.GetInsertBlock()->getParent();
	llvm::Value *init_val = nullptr;
	llvm::AllocaInst *Alloca = nullptr;
	string var = pd->value;

	// Obvi cause init assign only for single cars
	if(type == string("int"))
	{
		V_get = NamedValues[var];
		Alloca =  CreateEntryBlockAlloca(TheFunction,var,"int");
	}
 	else if (type == string("bool"))
 	{
	 V_get = NamedValues[var];
	 Alloca =  CreateEntryBlockAlloca(TheFunction,var,"bool");
 	}
 	else if (type == string("uint"))
 	{
	 V_get = NamedValues[var];
	 Alloca =  CreateEntryBlockAlloca(TheFunction,var,"uint");
 	}
 	else if (type == string("char"))
 	{
	 V_get = NamedValues[var];
	 Alloca =  CreateEntryBlockAlloca(TheFunction,var,"char");
 	}
	Value * expr_val = expr->Codegen();
	Builder.CreateStore(expr_val,Alloca);
	Old_vals[var] = NamedValues[var];
	NamedValues[var] = Alloca;
	return expr_val;
}

Value *AssignmentNode::Codegen()
{
	// Only Single Id
	SingleId *pd = dynamic_cast<SingleId*>(location);
	Value *cur = NamedValues[pd->value];
	if(cur == nullptr)
	{
		cur = TheModule->getGlobalVariable(pd->value);
	}
	if (cur == nullptr) {
    // errors_IR++;
    // return generateError("ERROR: Unknown Variable Name " + loc->getName());
  }

	Value* expr_val = expr->Codegen();

	string var = pd->value;

	Value * variable_codegen = location->Codegen();

	cur = Builder.CreateLoad(variable_codegen);

	if(asgn_op == string("="))
	{	 Builder.CreateStore(expr_val,variable_codegen);}
	else if (asgn_op == string("+="))
	{
		Builder.CreateAdd(cur,expr_val,"peq");
	}
	else if (asgn_op == string("-=")){
		Builder.CreateSub(cur, expr_val, "meq");
	}
	return expr_val;
}

Value * SingleId::Codegen()
{
	Value * V = NamedValues[value];
	if( V == nullptr)
	{
		V = TheModule->getNamedGlobal(value);
	}
	if( V == nullptr)
	{
		//error
	}
	return V;
}

Value * StatementsNode::Codegen(map<string, AllocaInst *> &oldValues)
{
	Value *v = ConstantInt::get(Context, APInt(32, 1));
	for (auto &decl : statements_list) {
		if(dynamic_cast<SingleInitNode*>(decl)
		   || dynamic_cast<InitAssignmentNode*>(decl))
		{ v = decl->Codegen(oldValues);	}
  	else
		{	v = decl->Codegen();}
		if(v == nullptr)
		{
			return v;
		}
	}
	return v;
}


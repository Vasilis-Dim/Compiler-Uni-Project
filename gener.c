//****************************************************************************
//*         This is a part of the Mini-(C)ompiler Source Code. 
//*         All rights reserved. 
//****************************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "gener.h"
#include "defs.h"
#include "scope.h"
#include "error_str.h"
#include "err_code.h"

//*****************************************************
unary_op GetInfoFromUnOp(char minus,char addr,char ptr)
{
	unary_op unop=(unary_op)malloc(sizeof(struct strunary_operator));
	unop->minus=minus;
	unop->addr=addr;
	unop->ptr=ptr;
	return unop;
}
//*****************************************************
express  GetInfoFromUnExpr(unary_op unop,express primary)
{
express expr=(express)malloc(sizeof(struct strexpr));
entry info=(entry)malloc(sizeof(struct strentry));//edo allazoyme to info
entry prinfo;
TypeDescriptor desc;

//kanoyme copy ta fields toy primary
expr->lvalue=primary->lvalue;
prinfo=primary->info;
info->IDclass=prinfo->IDclass;
switch(prinfo->IDclass){
	case CONSTANT	:	if ((unop->addr)||(unop->ptr)) 
						{
							free(info);
							expr->errorcode=ILL_INDIRECTION;
							return expr;	//ERROR e.g &10 or *10 
						}
						info=prinfo;
						break;

	case VARIABLE	:	
	case VALUEPARAM	:
	case PROC		: 
						if (prinfo->IDclass==VARIABLE){
							info->kind.Variable.typeDesc=(TypeDescriptor)malloc(sizeof(struct strdescriptor));
							desc=info->kind.Variable.typeDesc;
							desc->sc_specif=prinfo->kind.Variable.typeDesc->sc_specif;
							desc->type_specif=prinfo->kind.Variable.typeDesc->type_specif;
							//edo sximatizoyme ton neo ptrLevel
							desc->ptrLevel=prinfo->kind.Variable.typeDesc->ptrLevel-unop->ptr;
						}
						else 
						if (prinfo->IDclass==VALUEPARAM){
							info->kind.ValueParam.typeDesc=(TypeDescriptor)malloc(sizeof(struct strdescriptor));
							desc=info->kind.ValueParam.typeDesc;
							desc->sc_specif=prinfo->kind.ValueParam.typeDesc->sc_specif;
							desc->type_specif=prinfo->kind.ValueParam.typeDesc->type_specif;
							//edo sximatizoyme ton neo ptrLevel
							desc->ptrLevel=prinfo->kind.ValueParam.typeDesc->ptrLevel-unop->ptr;
						}
						else{
							info->kind.Proc.ReturnType=(TypeDescriptor)malloc(sizeof(struct strdescriptor));
							desc=info->kind.Proc.ReturnType;
							desc->sc_specif=prinfo->kind.Proc.ReturnType->sc_specif;
							desc->type_specif=prinfo->kind.Proc.ReturnType->type_specif;
							//edo sximatizoyme ton neo ptrLevel
							desc->ptrLevel=prinfo->kind.Proc.ReturnType->ptrLevel-unop->ptr;
						}
	
						if (desc->ptrLevel<0)
						{
							free(desc);free(info);
							expr->errorcode=ILL_INDIRECTION;
							return expr;	//ERROR Illegal indirection 
						}
						desc->ptrLevel+=unop->addr;
						if ((desc->ptrLevel>0)&&(unop->minus!=0))
						{
							free(desc);free(info);
							expr->errorcode=FOUNDPTR;
							return expr;	//ERROR Illegal operation with pointer 
						}
						if (unop->ptr>0) expr->lvalue=ISLVALUE; //ypopsifia lvalue
						break;
}

if ((unop->minus!=0)||(unop->addr!=0)) expr->lvalue=ISNOTLVALUE;//-a or &a me int a;
expr->info=info;
expr->minus=unop->minus; //minus
expr->errorcode=NOERROR;
return expr;
}
//*****************************************************
express GetInfoFromID(char *ID)
{
	express expr=(express)malloc(sizeof(struct strexpr));
	entry info;
	info=find_ID(ID);
    if (info!=NULL) {
		expr->info=info;
		expr->place=info;//place=info
		expr->minus=0;  //minus 0 
		expr->lvalue=ISLVALUE;
	}
	else { 
		expr->place=(entry)malloc(sizeof(struct strentry));
		expr->place->name=ID;
		expr->errorcode=ID_NOTFOUND;
	} //error
	return expr;
}

//*****************************************************
express GetInfoFromFunc(char *funcname,symbol_table proc_st)
{
	express expr=(express)malloc(sizeof(struct strexpr));
	entry info;
	info=lookup(proc_st,funcname);
    if (info!=NULL) {
		expr->info=info;
		expr->place=NULL;
		expr->minus=0;				//minus 0 
		expr->lvalue=ISNOTLVALUE;	//is not lvalue
	}
	else expr->errorcode=FUNC_NOTFOUND; //error
	return expr;
}

//*****************************************************
express GetInfoFromConst(int DecValue)
{
	char buffer[10];
	express expr=(express)malloc(sizeof(struct strexpr));
	entry info=(entry)malloc(sizeof(struct strentry));
	info->IDclass=CONSTANT;
	_itoa(DecValue, buffer, 10 );
	info->name=(char *)malloc(sizeof(buffer));
	strcpy(info->name,buffer);
	info->previous=NULL;
	info->kind.Constant.ConstValue=DecValue;
    info->kind.Constant.ConstType=(TypeDescriptor)malloc(sizeof(struct strdescriptor));
	info->kind.Constant.ConstType->type_specif=CONST;
	info->kind.Constant.ConstType->sc_specif=NO_SC;
	info->kind.Constant.ConstType->ptrLevel=0;
	expr->info=info;
	expr->place=info;			//place=info
	expr->minus=0;				//minus=0;	
	expr->lvalue=ISNOTLVALUE;	//is not lvalue
	expr->errorcode=NOERROR;
	return expr;
}
//*****************************************************
expression_list StartExpression(express expr)
{
	expression_list newexprlist;
	newexprlist=(expression_list)malloc(sizeof(struct strexpressionlist));
	newexprlist->expr=expr;
	newexprlist->next=NULL;
	return newexprlist;
}

//*****************************************************
expression_list NextExpression(expression_list explist,express expr)
{
	expression_list newexprlist;
	newexprlist=StartExpression(expr);
	newexprlist->next=explist;
	return newexprlist;
}

//*****************************************************
param_list StartParamIdList(char *IDENT)
{
	param_list newid;
	newid=(param_list)malloc(sizeof(struct strparamlist));
	newid->name=IDENT;
	newid->next=NULL;
	return newid;
}

//*****************************************************
param_list NextParamID(param_list ParamIdList,char *IDENT)
{
	param_list newid;
	newid=StartParamIdList(IDENT);
	newid->next=ParamIdList;
	return newid;
}

//*****************************************************
declar2 GetDeclarator2(char *name,char proc,param_list paridlist)
{
	declar2 newdecl2;
	newdecl2=(declar2)malloc(sizeof(struct strdeclar2));
	newdecl2->name=name;
	newdecl2->proc=proc;
	newdecl2->exists=0;
	newdecl2->paridlist=paridlist;
	return newdecl2;
};

//*****************************************************
declar GetDeclarator(char ptrlevel,declar2 decl2)
{
	declar newdecl;
	newdecl=(declar)malloc(sizeof(struct strdeclar));
	newdecl->ptrlevel=ptrlevel;
	newdecl->decl2=decl2;
	return newdecl;
};
//*****************************************************
decl_list StartIdList(declar IDENT)
{
	decl_list newid;
	newid=(decl_list)malloc(sizeof(struct strdecllist));
	newid->decl=IDENT;
	newid->next=NULL;
	return newid;
}

//*****************************************************
decl_list NextID(decl_list IdList,declar IDENT)
{
	decl_list newid;
	newid=StartIdList(IDENT);
	newid->next=IdList;
	return newid;
}
//*****************************************************
decl_specif GetDeclSpecif(char sc_specif,char type_specif)
{
	decl_specif newds;
	newds=(decl_specif)malloc(sizeof(struct strdeclspecifiers));
	newds->sc_specif=sc_specif;
	newds->type_specif=type_specif;
	return newds;
}
//*****************************************************
declaration GetDeclaration(decl_specif dl_sp,decl_list *dl_list)
{
	declaration decl;
	TypeDescriptor TypeDsc;
	entry newentry;
	decl_list dlist=(*dl_list);
	mergeblocks();
	while ((*dl_list)!=NULL){
		if ((*dl_list)->decl->decl2->proc==PROC_DECLAR) return NULL;
		newentry=(entry)malloc(sizeof(struct strentry));
		newentry->name=(*dl_list)->decl->decl2->name;
		newentry->previous=NULL;

		if (stack_sym_table->block==PROC_BLOCK)
		{
			newentry->IDclass=VALUEPARAM; //������� ��� ����� ���������� ����������
			newentry->kind.ValueParam.global=NOGLOBAL;
			newentry->kind.ValueParam.typeDesc=(TypeDescriptor)malloc(sizeof(struct strdescriptor));
			TypeDsc=newentry->kind.ValueParam.typeDesc;
			TypeDsc->ptrLevel=(*dl_list)->decl->ptrlevel;
			TypeDsc->sc_specif=dl_sp->sc_specif;
			TypeDsc->type_specif=dl_sp->type_specif;
		
			//offsets
			if (TypeDsc->ptrLevel>0) newentry->kind.ValueParam.offset=stack_sym_table->offset-PTR_SIZE;
			  else 
				  if (TypeDsc->type_specif==CHAR_TYPE) newentry->kind.ValueParam.offset=stack_sym_table->offset-CHAR_SIZE;
					else if (TypeDsc->type_specif==INT_TYPE) newentry->kind.ValueParam.offset=stack_sym_table->offset-INT_SIZE;
			stack_sym_table->offset=newentry->kind.ValueParam.offset;
		}
		else 
		{
			newentry->IDclass=VARIABLE; //������� ��� ����� ��������� ��� ��� ���������� ����������
			newentry->kind.Variable.typeDesc=(TypeDescriptor)malloc(sizeof(struct strdescriptor));
			TypeDsc=newentry->kind.Variable.typeDesc;
			TypeDsc->ptrLevel=(*dl_list)->decl->ptrlevel;
			TypeDsc->sc_specif=dl_sp->sc_specif;
			TypeDsc->type_specif=dl_sp->type_specif;
			//offsets
			
			if (TypeDsc->ptrLevel>0) newentry->kind.Variable.offset=stack_sym_table->offset+PTR_SIZE;
			  else 
				  if (TypeDsc->type_specif==CHAR_TYPE) newentry->kind.Variable.offset=stack_sym_table->offset+CHAR_SIZE;
					else if (TypeDsc->type_specif==INT_TYPE) newentry->kind.Variable.offset=stack_sym_table->offset+INT_SIZE;
			stack_sym_table->offset=newentry->kind.Variable.offset;
			if (stack_sym_table->next==NULL) newentry->kind.Variable.global=GLOBAL;
			  else newentry->kind.Variable.global=NOGLOBAL;
		}
		
		if (!enter(current_scope(),newentry)) return NULL;
		
		*dl_list=(*dl_list)->next;
	}
	decl=(declaration)malloc(sizeof(struct strdeclaration));
	decl->declist=dlist;
	decl->declspecif=dl_sp;
	return decl;
}

//*****************************************************
declaration_list StartDeclarList(declaration decl)
{
	declaration_list newdlist;
	newdlist=(declaration_list)malloc(sizeof(struct strdeclarlist));
	newdlist->decl=decl;
	newdlist->next=NULL;
	return newdlist;
}

//*****************************************************
declaration_list NextDeclar(declaration_list DeclList,declaration decl)
{
	declaration_list newdlist;
	newdlist=StartDeclarList(decl);
	newdlist->next=DeclList;
	return newdlist;
}

//*****************************************************
typedef struct strTypeDescErr
{
	char occur; 
	TypeDescriptor typeDesc;
	errfuncdef error;
}*TypeDesc_Err;


//*****************************************************
TypeDesc_Err FindParamTypeDesc(declaration_list f_bd,char *name)
//returns the TypeDescriptor of the formal param following by
//error code
{
	#define DECL_SPECIF f_bd->decl->declspecif
	#define ID_LIST f_bd->decl->declist
	#define ID_NAME ID_LIST->decl->decl2->name
	#define PTR_LEVEL f_bd->decl->declist->decl->ptrlevel
	
	TypeDesc_Err retval=(TypeDesc_Err)malloc(sizeof(struct strTypeDescErr));
	TypeDescriptor typedesc;
	retval->occur=0;
	while (f_bd!=NULL){//search into declaration_list
		decl_list rID_LIST=ID_LIST;
		while (ID_LIST!=NULL){//search into declarator_list
			if (strcmp(ID_NAME,name)==0){
				ID_LIST->decl->decl2->exists=1;
				typedesc=(TypeDescriptor)malloc(sizeof(struct strdescriptor));
				typedesc->ptrLevel=PTR_LEVEL;
				typedesc->sc_specif=DECL_SPECIF->sc_specif;
				typedesc->type_specif=DECL_SPECIF->type_specif;
				retval->typeDesc=typedesc;
				retval->error=NULL;
				retval->occur+=1;
			}
			ID_LIST=ID_LIST->next;
		}
		ID_LIST=rID_LIST;
		f_bd=f_bd->next;
	}
	if (retval->occur==1) return retval;
	else {
			retval->typeDesc=NULL;
			retval->error=(errfuncdef)malloc(sizeof(struct strerrfuncdef));
			if (retval->occur==0) retval->error->code=FPAR_NOT_FOUND; //error 
			  else retval->error->code=FPAR_MORETONE;//more than one param with same name
			retval->error->formal_pname=name;
			return retval;
	}
	#undef DECL_SPECIF
	#undef ID_LIST
	#undef ID_NAME
	#undef PTR_LEVEL
}

//*****************************************************
entry StartLastParamList(char *name,TypeDescriptor typeDesc)
{
	entry entr;
	entry lentr=lookup(current_scope(),name);
	entr=(entry)malloc(sizeof(struct strentry));
	entr->name=name;
	entr->previous=NULL;
    entr->IDclass=VALUEPARAM;
	entr->kind.ValueParam.typeDesc=typeDesc;
	entr->kind.ValueParam.offset=lentr->kind.ValueParam.offset;
	return entr;
}

//*****************************************************
entry NextLastParam(char *name,TypeDescriptor typeDesc,entry prev)
{
	entry entr=StartLastParamList(name,typeDesc);
	entr->previous=prev;
	return entr;
}

//*****************************************************
errfuncdef FCheckDecllist(declaration_list f_bd)
{

	#define ID_LIST f_bd->decl->declist
	#define PARAM_NAME ID_LIST->decl->decl2->name
	#define PARAM ID_LIST->decl->decl2->exists
	#define NOEXISTS	0

	while (f_bd!=NULL){//search into declaration_list
		decl_list rID_LIST=ID_LIST;
		while (ID_LIST!=NULL){//search into declarator_list
			if (PARAM==NOEXISTS){
				errfuncdef error=(errfuncdef)malloc(sizeof(struct strerrfuncdef));
				error->formal_pname=PARAM_NAME;
				error->code=FPAR_NOT_FPARLIST;
				return error;
			}
			ID_LIST=ID_LIST->next;
		}
		ID_LIST=rID_LIST;
		f_bd=f_bd->next;
	}
	return  NULL;
}

//*****************************************************
funcdef extractparam(declar decl,declaration_list f_bd) 
//returns LastParam entry
{
	funcdef retval=(funcdef)malloc(sizeof(struct strfuncdef));
	entry entr=NULL;
	param_list parlist;
	parlist=decl->decl2->paridlist; //formal parameters
	if (parlist!=NULL){
		TypeDesc_Err typeDesc;
		typeDesc=FindParamTypeDesc(f_bd,parlist->name);
		if (typeDesc->error==NULL) entr=StartLastParamList(parlist->name,typeDesc->typeDesc);
		else {
				retval->entr=NULL;
				retval->error=typeDesc->error;//ERROR
				return retval;
		}
	parlist=parlist->next;
	}
	while (parlist!=NULL){
		TypeDesc_Err typeDesc;
		typeDesc=FindParamTypeDesc(f_bd,parlist->name);
		if (typeDesc->error==NULL) entr=NextLastParam(parlist->name,typeDesc->typeDesc,entr);
		else {
				retval->entr=NULL;
				retval->error=typeDesc->error;//ERROR
				return retval;
		}
		parlist=parlist->next;
	}
	retval->entr=entr;
	retval->error=FCheckDecllist(f_bd);
	return retval;
}

//*****************************************************
funcdef extractproc(decl_specif d_sp,declar decl,declaration_list f_bd)
//extract the proc info
{
	funcdef retval=(funcdef)malloc(sizeof(struct strfuncdef));
	entry entr=(entry)malloc(sizeof(struct strentry));
	TypeDescriptor RetType;
	
	//name,previous,IDclass
	entr->name=decl->decl2->name;
	entr->previous=NULL;
	entr->IDclass=PROC;
	
	//LastParam
	{
		funcdef fund=extractparam(decl,f_bd);
		if (fund->error==NULL) entr->kind.Proc.LastParam=fund->entr;
		else {
				retval->entr=NULL;
				retval->error=fund->error; //ERROR
				return retval;
		}
	}

	//ReturnType
	entr->kind.Proc.ReturnType=(TypeDescriptor)malloc(sizeof(struct strdescriptor));
	RetType=entr->kind.Proc.ReturnType;
	if (d_sp!=NULL){
		RetType->sc_specif=d_sp->sc_specif;
		RetType->type_specif=d_sp->type_specif;
		RetType->ptrLevel=decl->ptrlevel;
	}
	else{
		RetType->sc_specif=NO_SC;
		RetType->type_specif=INT_TYPE; //default returns int type;
		RetType->ptrLevel=0;
	}
	retval->entr=entr;
	retval->error=NULL; //NO ERROR
	return retval;
}

//*****************************************************
entry currproc(symbol_table table)
{
	return  table->st_entries->id;
}

//*****************************************************

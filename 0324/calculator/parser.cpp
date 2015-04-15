/*************************************************************************
  > File Name: parser.cpp
  > Author: Chao
  > Mail:1311159643@qq.com 
  > Created Time: Tue 24 Mar 2015 09:38:54 PM CST
 ************************************************************************/

#include "parser.h"
#include "node.h"
#include "scanner.h"
#include <assert.h>
#include <iostream>

	Parser::Parser(Scanner &sc)
: scanner_(sc), 
	tree_(NULL),
	status_(STATUS_OK)
{}

double Parser::calculate()
{
	if(NULL == tree_)
	{
		return 0.0;
	}
	return tree_->calc();
}
void Parser::parse()
{
	tree_ = expr();
}

Node *Parser::expr()
{
	Node *pNode = term();
	EToken token = scanner_.token();
	if(TOKEN_PLUS == token || TOKEN_MINUS == token)
	{
		MultipleNode *pMltNode = new SumNode(pNode);
		do
		{
			scanner_.accept();
			Node *pNextNode = term();
			pMltNode->addChild(pNextNode, TOKEN_PLUS == token);
			token = scanner_.token();
		}while(TOKEN_PLUS == token || TOKEN_MINUS == token);
		pNode = pMltNode;
	}
	return pNode;
	    //if(TOKEN_PLUS == token)
		//{
		//    scanner_.accept();
		//    Node * pNodeRight = expr();
		//    pNode = new AddNode(pNode, pNodeRight);
		//}
		//else if(TOKEN_MINUS == token)
		//{
		//    scanner_.accept();
		//    Node *pNodeRight = expr();
		//    pNode = new SubNode(pNode, pNodeRight);
		//}
		//return pNode;
}

Node *Parser::term()
{
	Node *pNode = factor();
	EToken token = scanner_.token();
	if(TOKEN_MULTIPLY == token || TOKEN_DIVIDE == token)
	{
		MultipleNode *pMltNode = new ProductNode(pNode);
		do
		{
			scanner_.accept();
			Node *pNextNode = factor();
			pMltNode->addChild(pNextNode, (TOKEN_MULTIPLY == token));
		}while(TOKEN_MULTIPLY == token || TOKEN_DIVIDE == token);
		pNode = pMltNode;
	}
	return pNode;
	//if(TOKEN_MULTIPLY == token)
	//{
	//    scanner_.accept();
	//    Node *pNodeRight = term();
	//    pNode = new MultiplyNode(pNode, pNodeRight);
	//}
	//else if(TOKEN_DIVIDE == token)
	//{
	//    scanner_.accept();
	//    Node *pNodeRight = term();
	//    pNode = new DivideNode(pNode, pNodeRight);
	//}
	//return pNode;
}

Node *Parser::factor()
{
	Node *pNode = NULL;
	EToken token = scanner_.token();
	if(TOKEN_LPARENTHESIS == token)
	{
		scanner_.accept();
		pNode = expr();
		if(scanner_.token() == TOKEN_RPARENTHESIS)
		{
			scanner_.accept();
		}
		else
		{
			status_ = STATUS_ERROR;
			std::cout << "missing )" << std::endl;
			pNode = NULL;
		}
	}
	else if(TOKEN_NUMBER == token)
	{
		pNode = new NumberNode(scanner_.number());
		scanner_.accept();
	}
	else if(TOKEN_MINUS == token)
	{
		scanner_.accept();
		pNode = new UMinusNode(factor());
	}
	else
	{
		status_ = STATUS_ERROR;
		std::cout << "not a valid expr" << std::endl;
		pNode = NULL;
	}

	return pNode;
}

EStatus Parser::getStatus()const
{
	return status_;
}




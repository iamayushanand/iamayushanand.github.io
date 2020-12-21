#include "lexer.h"
using namespace Lexer;
Lexer::Token_value curr_tok=Lexer::Token_value(0);
bool inCode=false;
int Lexer::getToken(){
	if(!templateFile){
		Lexer::curr_tok=Lexer::ENDF;
		return 0;
	}
	char ch=templateFile.peek();
	if(ch=='{'){
		Lexer::inCode=true;
		Lexer::curr_tok=Lexer::LP;
		templateFile>>ch;
		templateFile>>ch;
	}
	if(ch=='}'){
		std::cerr<<"reached";
		Lexer::inCode=false;
		Lexer::curr_tok=Lexer::RP;
		templateFile>>ch;
		templateFile>>ch;
	}
	return 0;
}

Lexer::Token_value Lexer::getCommand(){
	std::string s;
	templateFile>>s;
	//std::cerr<<s<<'\n';
	if(s=="Content"){
		return Lexer::CONTENT;
	}
	if(s=="}}"){
		Lexer::inCode=false;
	}
	return Lexer::ENDF;
}


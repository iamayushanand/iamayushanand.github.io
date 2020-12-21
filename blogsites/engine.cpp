#include "engine.h"
#include "lexer.cpp"

int Engine::createBlog(){
	Lexer::getToken();//initialize
	while(Lexer::curr_tok!=Lexer::ENDF){
		if(!Lexer::inCode){
			char ch;
			templateFile.get(ch);
			blogFile<<ch;
			Lexer::getToken();
			continue;
		}
		if(Lexer::getCommand()==Lexer::CONTENT){
//			std::cerr<<"yes";
			while(contentFile){
				char s;
				contentFile.get(s);
				blogFile<<s;
			}
		}
		Lexer::getToken();
	}
	return 0;
}

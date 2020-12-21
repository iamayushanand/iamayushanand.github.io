
namespace Lexer{
	enum Token_value{LP=1,RP=2,CONTENT=3,ENDF=4};
	Token_value curr_tok;
	int getToken();
	Token_value getCommand();
	bool inCode;
}

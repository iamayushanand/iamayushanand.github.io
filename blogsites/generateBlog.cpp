#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <fstream>
#include <fstream>
#include "driver.h"
#include "engine.cpp"
using namespace std;
		
int main(int argc,char *argv[]){
	if(argc!=2){
		cerr<<"Bad Arguments";
		return 1;
	}
	string file=argv[1];
	contentFile.open("contents/"+file);
	templateFile.open("template.html");
	blogFile.open(file);
	Engine::createBlog();
	return 0;
}
	

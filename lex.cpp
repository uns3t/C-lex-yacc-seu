#include <stdio.h>

#include "y.tab.h"

    #include <iostream>
    #include <string>
    #include <fstream>
    #include <streambuf>
    
    std::string inputSrc;
    
    int cp = 0;
    int state = 0;
    
    void dfa(char c);

    int main(int argc, const char * argv[]) {
        std::ifstream f(argv[1]);
        std::string str((std::istreambuf_iterator<char>(f)),
                        std::istreambuf_iterator<char>());
        inputSrc = str;
        while (cp < inputSrc.length()) {
            try {
                dfa(inputSrc[cp]);
            } catch(int e) {
                std::cout << "出现错误";
                break;
            }
        }
        return 0;
    }

	

void count(void);



int yywrap(void)

{

	return 1;

}





void comment(void)

{

	char c, prev = 0;

  

	while ((c = input()) != 0)      /* (EOF maps to 0) */

	{

		if (c == '/' && prev == '*')

			return;

		prev = c;

	}

	error("unterminated comment");

}





int column = 0;



void count(void)

{

	int i;



	for (i = 0; yytext[i] != '\0'; i++)

		if (yytext[i] == '\n')

			column = 0;

		else if (yytext[i] == '\t')

			column += 8 - (column % 8);

		else

			column++;



	ECHO;

}





int check_type(void)

{

/*

* pseudo code --- this is what it should check

*

*	if (yytext == type_name)

*		return TYPE_NAME;

*

*	return IDENTIFIER;

*/



/*

*	it actually will only return IDENTIFIER

*/



	return IDENTIFIER;

}


 	void dfa(char c){
        switch(state){
	
	case 3:
	switch (c) {

		case "u":
			state=2;
			cp++;
			break;

		case "â":
			state=5;
			cp++;
			break;

		case "Ã":
			state=3;
			cp++;
			break;

		case "U":
			state=1;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 4:
	switch (c) {

		case "U":
			state=1;
			cp++;
			break;

		case "Ã":
			state=3;
			cp++;
			break;

		case "â":
			state=4;
			cp++;
			break;

		case "u":
			state=2;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 5:
	switch (c) {

		case "Ã":
			state=3;
			cp++;
			break;

		case "u":
			state=2;
			cp++;
			break;

		case "U":
			state=1;
			cp++;
			break;

		case "â":
			state=4;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 0:
	switch (c) {

		case "U":
			state=1;
			cp++;
			break;

		case "u":
			state=2;
			cp++;
			break;

		case "Ã":
			state=3;
			cp++;
			break;

		case "â":
			state=4;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 1:
	switch (c) {

		case "Ã":
			state=3;
			cp++;
			break;

		case "â":
			state=4;
			cp++;
			break;

		case "U":
			state=1;
			cp++;
			break;

		case "u":
			state=2;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 2:
	switch (c) {

		case "â":
			state=5;
			cp++;
			break;

		case "U":
			state=1;
			cp++;
			break;

		case "u":
			state=2;
			cp++;
			break;

		case "Ã":
			state=3;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;


			default:
                throw 1;
                break;
        }
    }
    

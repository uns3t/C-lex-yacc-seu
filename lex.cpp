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


 	void dfa(char c){
        switch(state){
	
	case 56:
	switch (c) {

		case "i":
			state=74;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 111:
	switch (c) {

		case "e":
			state=117;
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

		default:
			{ count(); return('.'); }			printf("\n");
			state = 0;
			break;
}

	break;

	case 23:
	switch (c) {

		case "o":
			state=51;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 37:
	switch (c) {

		case "e":
			state=61;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 59:
	switch (c) {

		default:
			{ count(); return(MOD_ASSIGN); }			printf("\n");
			state = 0;
			break;
}

	break;

	case 85:
	switch (c) {

		case "i":
			state=99;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 90:
	switch (c) {

		case "e":
			state=101;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 109:
	switch (c) {

		default:
			{ count(); return(STRUCT); }			printf("\n");
			state = 0;
			break;
}

	break;

	case 22:
	switch (c) {

		case "o":
			state=50;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 32:
	switch (c) {

		default:
			{ count(); return('='); }			printf("\n");
			state = 0;
			break;
}

	break;

	case 36:
	switch (c) {

		case "n":
			state=60;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 38:
	switch (c) {

		case "y":
			state=62;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 71:
	switch (c) {

		case "o":
			state=87;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 101:
	switch (c) {

		default:
			{ count(); return(WHILE); }			printf("\n");
			state = 0;
			break;
}

	break;

	case 44:
	switch (c) {

		case "f":
			state=65;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 51:
	switch (c) {

		case "t":
			state=71;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 77:
	switch (c) {

		case "i":
			state=93;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 87:
	switch (c) {

		default:
			{ count(); return(GOTO); }			printf("\n");
			state = 0;
			break;
}

	break;

	case 93:
	switch (c) {

		case "g":
			state=104;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 116:
	switch (c) {

		case "e":
			state=119;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 12:
	switch (c) {

		default:
			{ count(); return('['); }			printf("\n");
			state = 0;
			break;
}

	break;

	case 53:
	switch (c) {

		default:
			{ count(); return(OR_ASSIGN); }			printf("\n");
			state = 0;
			break;
}

	break;

	case 83:
	switch (c) {

		default:
			{ count(); return(AUTO); }			printf("\n");
			state = 0;
			break;
}

	break;

	case 42:
	switch (c) {

		default:
			{ count(); return(ADD_ASSIGN); }			printf("\n");
			state = 0;
			break;
}

	break;

	case 45:
	switch (c) {

		case "n":
			state=66;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 52:
	switch (c) {

		case "s":
			state=72;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 33:
	switch (c) {

		case "B":
			state=58;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 50:
	switch (c) {

		case "i":
			state=70;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 81:
	switch (c) {

		case "u":
			state=97;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 92:
	switch (c) {

		case "l":
			state=103;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 115:
	switch (c) {

		default:
			{ count(); return(DEFAULT); }			printf("\n");
			state = 0;
			break;
}

	break;

	case 14:
	switch (c) {

		default:
			{ count(); return('{'); }			printf("\n");
			state = 0;
			break;
}

	break;

	case 20:
	switch (c) {

		case "o":
			state=49;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 70:
	switch (c) {

		case "d":
			state=86;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 73:
	switch (c) {

		case "a":
			state=89;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 113:
	switch (c) {

		case "f":
			state=118;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 117:
	switch (c) {

		case "d":
			state=120;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 19:
	switch (c) {

		case "t":
			state=48;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 49:
	switch (c) {

		case "n":
			state=69;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 60:
	switch (c) {

		case "s":
			state=77;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 62:
	switch (c) {

		case "p":
			state=79;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 65:
	switch (c) {

		case "a":
			state=81;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 67:
	switch (c) {

		case "o":
			state=83;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 7:
	switch (c) {

		default:
			{ count(); return('!'); }			printf("\n");
			state = 0;
			break;
}

	break;

	case 108:
	switch (c) {

		case "t":
			state=115;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 26:
	switch (c) {

		case "=":
			state=53;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 28:
	switch (c) {

		case "=":
			state=55;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 82:
	switch (c) {

		default:
			{ count(); return(LONG); }			printf("\n");
			state = 0;
			break;
}

	break;

	case 11:
	switch (c) {

		case ":":
			state=46;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 57:
	switch (c) {

		case "e":
			state=75;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 86:
	switch (c) {

		default:
			{ count(); return(VOID); }			printf("\n");
			state = 0;
			break;
}

	break;

	case 88:
	switch (c) {

		default:
			{ count(); return(ELSE); }			printf("\n");
			state = 0;
			break;
}

	break;

	case 114:
	switch (c) {

		default:
			{ count(); return(INLINE); }			printf("\n");
			state = 0;
			break;
}

	break;

	case 64:
	switch (c) {

		case "l":
			state=80;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 66:
	switch (c) {

		case "g":
			state=82;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 89:
	switch (c) {

		case "t":
			state=100;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 107:
	switch (c) {

		case "e":
			state=114;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 29:
	switch (c) {

		case "h":
			state=56;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 47:
	switch (c) {

		case "t":
			state=67;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 48:
	switch (c) {

		case "r":
			state=68;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 31:
	switch (c) {

		default:
			{ count(); return('}'); }			printf("\n");
			state = 0;
			break;
}

	break;

	case 84:
	switch (c) {

		case "c":
			state=98;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 106:
	switch (c) {

		case "e":
			state=113;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 17:
	switch (c) {

		default:
			{ count(); return('~'); }			printf("\n");
			state = 0;
			break;
}

	break;

	case 94:
	switch (c) {

		case "r":
			state=105;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 98:
	switch (c) {

		case "t":
			state=109;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 105:
	switch (c) {

		case "n":
			state=112;
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

		case "=":
			state=42;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 30:
	switch (c) {

		case "r":
			state=57;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 78:
	switch (c) {

		case "u":
			state=94;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 96:
	switch (c) {

		case "n":
			state=107;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 103:
	switch (c) {

		default:
			{ count(); return(BOOL); }			printf("\n");
			state = 0;
			break;
}

	break;

	case 55:
	switch (c) {

		default:
			{ count(); return(MUL_ASSIGN); }			printf("\n");
			state = 0;
			break;
}

	break;

	case 102:
	switch (c) {

		default:
			{ count(); return(BREAK); }			printf("\n");
			state = 0;
			break;
}

	break;

	case 104:
	switch (c) {

		case "n":
			state=111;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 79:
	switch (c) {

		case "e":
			state=95;
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

		default:
			{ count(); return('('); }			printf("\n");
			state = 0;
			break;
}

	break;

	case 18:
	switch (c) {

		case "u":
			state=47;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 21:
	switch (c) {

		default:
			{ count(); return('>'); }			printf("\n");
			state = 0;
			break;
}

	break;

	case 40:
	switch (c) {

		default:
			{ count(); return('?'); }			printf("\n");
			state = 0;
			break;
}

	break;

	case 41:
	switch (c) {

		case "n":
			state=64;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 58:
	switch (c) {

		case "o":
			state=76;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 46:
	switch (c) {

		default:
			{ count(); return('['); }			printf("\n");
			state = 0;
			break;
}

	break;

	case 76:
	switch (c) {

		case "o":
			state=92;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 118:
	switch (c) {

		default:
			{ count(); return(TYPEDEF); }			printf("\n");
			state = 0;
			break;
}

	break;

	case 119:
	switch (c) {

		default:
			{ count(); return(CONTINUE); }			printf("\n");
			state = 0;
			break;
}

	break;

	case 95:
	switch (c) {

		case "d":
			state=106;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 75:
	switch (c) {

		case "a":
			state=91;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 99:
	switch (c) {

		case "n":
			state=110;
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

		case "^":
			state=3;
			cp++;
			break;

		case "!":
			state=7;
			cp++;
			break;

		case "/":
			state=16;
			cp++;
			break;

		case "v":
			state=22;
			cp++;
			break;

		case "e":
			state=25;
			cp++;
			break;

		case "]":
			state=13;
			cp++;
			break;

		case "{":
			state=14;
			cp++;
			break;

		case ",":
			state=15;
			cp++;
			break;

		case "f":
			state=27;
			cp++;
			break;

		case "_":
			state=33;
			cp++;
			break;

		case "â":
			state=39;
			cp++;
			break;

		case "?":
			state=40;
			cp++;
			break;

		case ")":
			state=10;
			cp++;
			break;

		case "g":
			state=23;
			cp++;
			break;

		case "}":
			state=31;
			cp++;
			break;

		case "t":
			state=38;
			cp++;
			break;

		case "+":
			state=1;
			cp++;
			break;

		case "<":
			state=11;
			cp++;
			break;

		case "[":
			state=12;
			cp++;
			break;

		case "a":
			state=18;
			cp++;
			break;

		case ";":
			state=24;
			cp++;
			break;

		case "%":
			state=35;
			cp++;
			break;

		case "i":
			state=41;
			cp++;
			break;

		case "d":
			state=6;
			cp++;
			break;

		case "s":
			state=19;
			cp++;
			break;

		case "|":
			state=26;
			cp++;
			break;

		case "&":
			state=5;
			cp++;
			break;

		case "~":
			state=17;
			cp++;
			break;

		case "c":
			state=20;
			cp++;
			break;

		case ">":
			state=21;
			cp++;
			break;

		case "=":
			state=32;
			cp++;
			break;

		case "u":
			state=36;
			cp++;
			break;

		case ".":
			state=2;
			cp++;
			break;

		case "l":
			state=9;
			cp++;
			break;

		case "*":
			state=28;
			cp++;
			break;

		case "(":
			state=4;
			cp++;
			break;

		case "-":
			state=8;
			cp++;
			break;

		case "w":
			state=29;
			cp++;
			break;

		case "b":
			state=30;
			cp++;
			break;

		case ":":
			state=34;
			cp++;
			break;

		case "r":
			state=37;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 3:
	switch (c) {

		default:
			{ count(); return('^'); }			printf("\n");
			state = 0;
			break;
}

	break;

	case 5:
	switch (c) {

		case "&":
			state=43;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 24:
	switch (c) {

		default:
			{ count(); return(';'); }			printf("\n");
			state = 0;
			break;
}

	break;

	case 69:
	switch (c) {

		case "t":
			state=85;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 74:
	switch (c) {

		case "l":
			state=90;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 68:
	switch (c) {

		case "u":
			state=84;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 10:
	switch (c) {

		default:
			{ count(); return(')'); }			printf("\n");
			state = 0;
			break;
}

	break;

	case 25:
	switch (c) {

		case "l":
			state=52;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 39:
	switch (c) {

		case "â":
			state=63;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 61:
	switch (c) {

		case "t":
			state=78;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 80:
	switch (c) {

		case "i":
			state=96;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 112:
	switch (c) {

		default:
			{ count(); return(RETURN); }			printf("\n");
			state = 0;
			break;
}

	break;

	case 34:
	switch (c) {

		default:
			{ count(); return(':'); }			printf("\n");
			state = 0;
			break;
}

	break;

	case 43:
	switch (c) {

		default:
			{ count(); return(AND_OP); }			printf("\n");
			state = 0;
			break;
}

	break;

	case 72:
	switch (c) {

		case "e":
			state=88;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 6:
	switch (c) {

		case "e":
			state=44;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 35:
	switch (c) {

		case "=":
			state=59;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 100:
	switch (c) {

		default:
			{ count(); return(FLOAT); }			printf("\n");
			state = 0;
			break;
}

	break;

	case 16:
	switch (c) {

		default:
			{ count(); return('/'); }			printf("\n");
			state = 0;
			break;
}

	break;

	case 27:
	switch (c) {

		case "l":
			state=54;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 97:
	switch (c) {

		case "l":
			state=108;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 8:
	switch (c) {

		default:
			{ count(); return('-'); }			printf("\n");
			state = 0;
			break;
}

	break;

	case 9:
	switch (c) {

		case "o":
			state=45;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 63:
	switch (c) {

		default:
			{ /* consume //-comment */ }			printf("\n");
			state = 0;
			break;
}

	break;

	case 91:
	switch (c) {

		case "k":
			state=102;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 110:
	switch (c) {

		case "u":
			state=116;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 13:
	switch (c) {

		default:
			{ count(); return(']'); }			printf("\n");
			state = 0;
			break;
}

	break;

	case 15:
	switch (c) {

		default:
			{ count(); return(','); }			printf("\n");
			state = 0;
			break;
}

	break;

	case 54:
	switch (c) {

		case "o":
			state=73;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 120:
	switch (c) {

		default:
			{ count(); return(UNSIGNED); }			printf("\n");
			state = 0;
			break;
}

	break;


			default:
                throw 1;
                break;
        }
    }
    

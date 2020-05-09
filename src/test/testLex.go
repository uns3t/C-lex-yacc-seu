package main

import (
	"SeuLex"
	"fmt"
)

func main(){
	//读入lex源文件
	//SeuLex.ScanStart("/Users/tyh/Documents/GitHub/C-lex-yacc-seu/input/lextest.l","/Users/tyh/Documents/GitHub/C-lex-yacc-seu/output/test.c")
	//SeuLex.ReplacePredefinedElements("(L)?\"(((\\\\.)|[^\\\\\"\\n])*)\"")
	//对源文件进行分割
	str := SeuLex.Formalize("([a-zA-Z_])?\"(((\\\\.)|[^\\\\\"\\n])*)\"")
	fmt.Println(str)

}
package main

import (
	"SeuLex"
	"fmt"
	"strings"
)

func main() {
	//读入lex源文件
	//SeuLex.ScanStart("/Users/tyh/Documents/GitHub/C-lex-yacc-seu/input/lextest.l","/Users/tyh/Documents/GitHub/C-lex-yacc-seu/output/test.c")
	//SeuLex.ReplacePredefinedElements("(L)?\"(((\\\\.)|[^\\\\\"\\n])*)\"")
	//对源文件进行分割
	str := SeuLex.Formalize("(L)?\\\"(((\\\\\\\\.)|[^\\\\\\\\\\\"\\\\n])*)\\\"")
	fmt.Println(str)
	//fmt.Printf("%q",strings.Split(str,""))
	stack1 := SeuLex.Postfix(strings.Split(str, ""))
	var i = stack1.Len()
	var n = 0
	for n < i {
		s := stack1.Pop()
		fmt.Printf("%q", s)
		n++
	}
}

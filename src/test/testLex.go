package main

import (
	"SeuLex"
	"fmt"
	"strings"
	"time"
)

func TestDfa2nfa()  {
	Nnode1:=SeuLex.NState{257,nil,nil,""}
	Nnode2:=SeuLex.NState{97,nil,nil,""}
	Nnode3:=SeuLex.NState{98,nil,nil,""}
	Nnode4:=SeuLex.NState{256,nil,nil,""}
	Nnode1.Out1=&Nnode2
	Nnode1.Out2=&Nnode3
	Nnode2.Out1=&Nnode4
	Nnode3.Out1=&Nnode4
	dArr:=SeuLex.Nfa2dfa(Nnode1)
	SeuLex.Dfa2c(dArr)
}

func main() {
	//读入lex源文件
	SeuLex.ScanStart("/Users/tyh/Documents/GitHub/C-lex-yacc-seu/input/lextest.l","/Users/tyh/Documents/GitHub/C-lex-yacc-seu/output/test.c")
	SeuLex.ReplacePredefinedElements("(L)?\"(((\\\\.)|[^\\\\\"\\n])*)\"")
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

	TestDfa2nfa()
	time.Sleep(1000)
}

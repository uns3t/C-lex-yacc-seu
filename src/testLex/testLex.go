package main

import (
	"SeuLex"
	"fmt"
	"strings"
)

func TestDfa2nfa() {
	//Nnode1 := SeuLex.NState{257, nil, nil, ""}
	//Nnode2 := SeuLex.NState{97, nil, nil, ""}
	//Nnode3 := SeuLex.NState{98, nil, nil, ""}
	//Nnode4 := SeuLex.NState{256, nil, nil, ""}
	//Nnode1.Out1 = &Nnode2
	//Nnode1.Out2 = &Nnode3
	//Nnode2.Out1 = &Nnode4
	//Nnode3.Out1 = &Nnode4
	//dArr:=SeuLex.Nfa2dfa(Nnode1)
	//SeuLex.Dfa2c(dArr)
}

func main() {
	//"(L)?\\\"(((\\\\\\\\.)|[^\\\\\\\\\\\"\\\\n])*)\\\""
	regularExpression := "(a|b|c)?"
	fmt.Println("没有规范化的正则表达式:\n" + regularExpression)

	//读入lex源文件
	SeuLex.ScanStart("./input/lextest.l", "./output/testLex.c")
	SeuLex.ReplacePredefinedElements("(L)?\"(((\\\\.)|[^\\\\\"\\n])*)\"")
	//对源文件进行分割
	str := SeuLex.Formalize(regularExpression)
	fmt.Println("规范化后的正则表达式:\n" + str)
	fmt.Println("正则表达式规范化完成\n ")

	fmt.Println("中缀转后缀后的正则表达式:")
	postStr := SeuLex.Postfix(strings.Split(str, ""))
	fmt.Println(postStr)
	fmt.Println("正则表达式中缀转后缀完成\n ")

	fmt.Println("正则表达式转nfa:")
	startState, id2state := SeuLex.Post2Nfa(postStr, "Hello")
	SeuLex.PrintNfa(id2state)
	fmt.Println("正则表达式转nfa完成\n ")

	fmt.Println("nfa转dfa:")
	DNodes := SeuLex.Nfa2dfa(startState)
	_ = DNodes
	fmt.Println("nfa转dfa\n ")
	//TestDfa2nfa()
	//time.Sleep(1000)
}

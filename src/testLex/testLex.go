package main

import (
	"SeuLex"
	"fmt"
	"nfa2dfa_2"
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

func TestDfa2nfa2() {
	Nnode1 := nfa2dfa_2.NState{0, 257, nil, nil, ""}
	Nnode2 := nfa2dfa_2.NState{1, 97, nil, nil, ""}
	Nnode3 := nfa2dfa_2.NState{2, 98, nil, nil, ""}
	Nnode4 := nfa2dfa_2.NState{3, 256, nil, nil, ""}
	Nnode1.Out1 = &Nnode2
	Nnode1.Out2 = &Nnode3
	Nnode2.Out1 = &Nnode4
	Nnode3.Out1 = &Nnode4
	id2NState := make(map[int]*nfa2dfa_2.NState)
	id2NState[0] = &Nnode1
	id2NState[1] = &Nnode2
	id2NState[2] = &Nnode3
	id2NState[3] = &Nnode4
	_, id2DState := nfa2dfa_2.Nfa2Dfa(&Nnode1, id2NState)
	nfa2dfa_2.PrintDFA(id2DState)
}

func main() {
	test2()
}

func test1() {
	//"(L)?\\\"(((\\\\\\\\.)|[^\\\\\\\\\\\"\\\\n])*)\\\""
	regularExpression := "(a|b|c)?"
	fmt.Println("没有规范化的正则表达式:\n" + regularExpression)

	//读入lex源文件
	//SeuLex.ScanStart("./input/lextest.l")
	//SeuLex.ReplacePredefinedElements("(L)?\"(((\\\\.)|[^\\\\\"\\n])*)\"")
	//对源文件进行分割
	str := SeuLex.Formalize(regularExpression)
	fmt.Println("规范化后的正则表达式:\n" + str)
	fmt.Println("正则表达式规范化完成\n ")

	fmt.Println("中缀转后缀后的正则表达式:")
	postStr := SeuLex.Postfix(strings.Split(str, ""))
	fmt.Println(postStr)
	fmt.Println("正则表达式中缀转后缀完成\n ")

	fmt.Println("正则表达式转nfa:")
	nStart, id2NState := SeuLex.Post2Nfa(postStr, "Hello")
	SeuLex.PrintNfa(id2NState)
	fmt.Println("正则表达式转nfa完成\n ")

	fmt.Println("nfa转dfa:")
	dStart, id2DState := SeuLex.Nfa2Dfa(nStart, id2NState)
	SeuLex.PrintDFA(id2DState)
	_ = dStart
	fmt.Println("nfa转dfa完成\n ")

	//TestDfa2nfa2()
	fmt.Println("dfa转cpp:")
	SeuLex.Dfa2Cpp(id2DState, "", "")
}

func test2() {
	SeuLex.Lex("./input/lextest.l")
}

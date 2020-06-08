package SeuLex

import (
	"fmt"
	"strings"
)

func Lex(inputFileName string) {
	//解析.l文件
	ScanStart(inputFileName)
	counter := 0
	var nStart *NState
	var id2NState map[int]*NState
	for exp, endFunc := range GetExpMap() {
		fmt.Println(counter)
		fmt.Println("规范化...")
		formalizedExp := Formalize(exp)
		fmt.Println("中缀转后缀...")
		postExp := Postfix(strings.Split(formalizedExp, ""))
		fmt.Println("后缀转nfa...")
		nStartI, id2NStateI := Post2Nfa(postExp, endFunc, &counter)

		nStart = merge(nStart, nStartI, &counter)
		for stateIdI, nStateI := range id2NStateI {
			id2NState[stateIdI] = nStateI
		}
	}
	_, id2DState := Nfa2Dfa(nStart, id2NState)
	Dfa2Cpp(id2DState, strings.Join(GetInclude(), "\n"), strings.Join(GetComment(), "\n"))
}

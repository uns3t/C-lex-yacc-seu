package SeuLex

import (
	"strings"
)

func Lex(inputFileName string) {
	//解析.l文件
	ScanStart(inputFileName)
	for exp, endFunc := range GetExpMap() {
		formalizedExp := Formalize(exp)
		postExp := Postfix(strings.Split(formalizedExp, ""))
		nStart, id2NState := Post2Nfa(postExp, endFunc)
		_, id2DState := Nfa2Dfa(nStart, id2NState)
		Dfa2Cpp(id2DState, strings.Join(GetInclude(), "\n"), strings.Join(GetComment(), "\n"))
	}
}

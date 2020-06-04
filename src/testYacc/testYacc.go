package main

import (
	"SeuYacc"
	"strings"
)

func main() {
	yaccFile := SeuYacc.LoadYaccFile("./input/c99.y")
	grammar := SeuYacc.YaccToGrammar(yaccFile)
	dfaItem := SeuYacc.NewLrState("I0")
	dfaItem.PutItems("0-0", strings.Split("$", ""), 0, strings.Split(grammar.GrammarStart(), ""))
	//SeuYacc.GenerateLR1DFA(dfaItem,&grammar)
	parsingTable := SeuYacc.DfaToParsingTable(dfaItem, &grammar)
	SeuYacc.PrintParsingTable(parsingTable)
}

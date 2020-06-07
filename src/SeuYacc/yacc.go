package SeuYacc

import "strings"

func Yacc() {
	yaccFile := LoadYaccFile("./input/yacctest.y")
	grammar := YaccToGrammar(yaccFile)
	dfaItem := NewLrState("I0")
	dfaItem.PutItems("0-0", strings.Split("$", ""), 0, strings.Split(grammar.GrammarStart(), ""))
	//GenerateLR1DFA(dfaItem,&grammar)
	parsingTable := DfaToParsingTable(dfaItem, &grammar)
	PrintParsingTable(parsingTable)
	ParsingTableToCpp(parsingTable, grammar)
}

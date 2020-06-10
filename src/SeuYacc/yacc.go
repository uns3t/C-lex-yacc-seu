package SeuYacc

import (
	"fmt"
	"res"
)

func Yacc(input string) {
	res.SetOSType()
	yaccFile := LoadYaccFile(input)
	fmt.Println("yacc文件读取完成")
	grammar := YaccToGrammar(yaccFile)
	fmt.Println("grammar提取完成")
	dfaItem := GenerateLR1(&grammar)
	fmt.Println("dfa构造成功")
	parsingTable := DfaToParsingTable(dfaItem, &grammar)
	fmt.Println("dfa转parsingtable构造成功")
	PrintParsingTable(parsingTable)
	ParsingTableToCpp(parsingTable, grammar)
	fmt.Println("parsingtable转cpp成功")
}

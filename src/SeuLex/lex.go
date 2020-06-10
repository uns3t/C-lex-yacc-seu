package SeuLex

import (
	"fmt"
	"res"
	"strconv"
	"strings"
)

func Lex(inputFileName string) {
	//解析.l文件
	res.SetOSType()
	ScanStart(inputFileName)
	counter := 0
	regNum := 0
	var nStart, nStartI *NState
	var id2NState = make(map[int]*NState)
	var id2NStateI = make(map[int]*NState)
	for exp, endFunc := range GetExpMap() {
		fmt.Println(strconv.Itoa(counter) + "  处理的正规表达式: " + exp)
		fmt.Println("规范化...")
		formalizedExp := Formalize(exp)

		if strings.HasPrefix(formalizedExp, "\"") && strings.HasSuffix(formalizedExp, "\"") && len(formalizedExp) > 2 {
			//如果是关键字
			formalizedExp = formalizedExp[1 : len(formalizedExp)-1]
			nStartI, id2NStateI = Key2Nfa(strings.Split(formalizedExp, ""), endFunc, &counter)
			regNum++
		} else {
			fmt.Println("中缀转后缀...")
			postExp := Postfix(strings.Split(formalizedExp, ""))
			fmt.Println("后缀转nfa...")
			nStartI, id2NStateI = Post2Nfa(postExp, endFunc, &counter)
			regNum++
		}

		nStart = merge(nStart, nStartI, &counter)
		id2NState[nStart.StateId] = nStart
		for stateIdI, nStateI := range id2NStateI {
			id2NState[stateIdI] = nStateI
		}
	}
	fmt.Println("\nreg2nfa统计信息")

	fmt.Println("正则表达式数:" + strconv.Itoa(regNum))
	fmt.Println("nfa状态数:" + strconv.Itoa(counter))
	fmt.Println("起始nfa状态:" + strconv.Itoa(nStart.StateId))

	PrintNfa(id2NState)
	_, id2DState := Nfa2Dfa(nStart, id2NState)
	PrintDFA(id2DState)
	Dfa2Cpp(id2DState, strings.Join(GetInclude(), "\n"), strings.Join(GetComment(), "\n"))
}

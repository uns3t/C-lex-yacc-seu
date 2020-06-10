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
	var nStart, nStartK, nStartI *NState
	var id2NState = make(map[int]*NState)
	var id2NStateK = make(map[int]*NState)
	var id2NStateI = make(map[int]*NState)
	for exp, endFunc := range GetExpMap() {
		fmt.Println(strconv.Itoa(counter) + "  处理的正规表达式: " + exp)

		fmt.Print("规范化...     ")
		formalizedExp := Formalize(exp)
		fmt.Println(formalizedExp)

		if strings.HasPrefix(formalizedExp, "\"") && strings.HasSuffix(formalizedExp, "\"") && len(formalizedExp) > 2 {
			//如果是关键字
			formalizedExp = formalizedExp[1 : len(formalizedExp)-1]
			nStartI, id2NStateI = Key2Nfa(strings.Split(formalizedExp, ""), endFunc, &counter)
			regNum++

			nStartK = merge(nStartK, nStartI, &counter)
			id2NStateK[nStartK.StateId] = nStartK
			for stateIdI, nStateI := range id2NStateI {
				id2NStateK[stateIdI] = nStateI
			}
		} else {
			fmt.Println("中缀转后缀...")
			postExp := Postfix(strings.Split(formalizedExp, ""))
			fmt.Println("后缀转nfa...")
			nStartI, id2NStateI = Post2Nfa(postExp, endFunc, &counter)
			regNum++

			nStart = merge(nStart, nStartI, &counter)
			id2NState[nStart.StateId] = nStart
			for stateIdI, nStateI := range id2NStateI {
				id2NState[stateIdI] = nStateI
			}
		}

	}
	fmt.Println("\nreg2nfa统计信息")

	fmt.Println("正则表达式数:" + strconv.Itoa(regNum))
	fmt.Println("nfa状态数:" + strconv.Itoa(counter))
	fmt.Println("起始nfa状态:" + strconv.Itoa(nStart.StateId) + "\n----------------\n")

	_, id2DStateK := Nfa2Dfa(nStartK, id2NStateK)
	_, id2DState := Nfa2Dfa(nStart, id2NState)

	//testDFA(id2DState)
	//PrintDFA(id2DState)
	Dfa2Cpp(id2DState, id2DStateK, strings.Join(GetInclude(), ""), strings.Join(GetComment(), ""))
}

func testDFA(id2DState map[int]*DState) {
	fmt.Println("===========testDFA==============")
	endFuncNum := 0
	dStateNum := 0
	flag := make(map[string]bool)
	for _, expEndFunc := range GetExpMap() {
		flag[expEndFunc] = false
	}
	for _, dState := range id2DState {
		if dState.IsEnd {
			endFuncNum++
			flag[dState.EndFunc] = true
		}
		dStateNum++
	}
	fmt.Println("统计信息")
	fmt.Println("dfa状态数" + strconv.Itoa(dStateNum))
	fmt.Println("endFunc数" + strconv.Itoa(endFuncNum))
	fmt.Println("=========================")
	for str, f := range flag {
		if !f {
			fmt.Println(str + " 丢失")
		}
		_ = str
	}
	fmt.Println("===========testDFA完成==============")
}

func testN(id2NState map[int]*NState) {
	fmt.Println("===========testN==============")
	flag := make(map[string]bool)
	for _, expEndFunc := range GetExpMap() {
		flag[expEndFunc] = false
	}
	for _, nState := range id2NState {
		if nState.C == 256 && nState.EndFunc == "" {
			fmt.Println("Match 但是没有EndFunc")
		} else if nState.C == 256 && nState.EndFunc != "" {
			fmt.Println("Match " + nState.EndFunc)
			flag[nState.EndFunc] = true
		} else if nState.C != 256 && nState.EndFunc != "" {
			fmt.Println("有EndFunc 但不是Match")
		} else {

		}

	}
	fmt.Println("=========================")
	for str, f := range flag {
		if !f {
			fmt.Println(str + " 丢失")
		}
		_ = str
	}
}

func testNFA(id2NFAState map[int]*NFAState) {
	fmt.Println("===========testNFA==============")
	flag := make(map[string]bool)
	for _, expEndFunc := range GetExpMap() {
		flag[expEndFunc] = false
	}
	for _, nfaState := range id2NFAState {
		if nfaState.IsEnd && nfaState.EndFunc == "" {
			fmt.Println("isEnd 但是没有EndFunc")
		} else if nfaState.IsEnd && nfaState.EndFunc != "" {
			fmt.Println("isEnd " + nfaState.EndFunc)
			flag[nfaState.EndFunc] = true
		} else if !nfaState.IsEnd && nfaState.EndFunc != "" {
			fmt.Println("有EndFunc 但不是end")
		} else {

		}

	}
	fmt.Println("=========================")
	for str, f := range flag {
		if !f {
			fmt.Println(str + " 丢失")
		}
		_ = str
	}
	fmt.Println("===========testNFA完成==============")
}

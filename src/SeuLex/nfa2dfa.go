package SeuLex

import (
	"fmt"
	"reflect"
	"strconv"
)

//求闭包
func searchClosure(nState *NState, max int) map[int]*NState {
	//fmt.Println("求闭包" + strconv.Itoa(nState.StateId))
	closure := make(map[int]*NState)
	max++
	flag := make([]bool, max)
	back := []*NState{nState}
	for len(back) > 0 {
		temp := back[0]
		back = back[1:]
		closure[temp.StateId] = temp
		if temp.C > 256 {
			if temp.Out1 != nil {
				if !flag[temp.Out1.StateId] {
					back = append(back, temp.Out1)
					flag[temp.Out1.StateId] = true
				}
			}
			if temp.Out2 != nil {
				if !flag[temp.Out2.StateId] {
					back = append(back, temp.Out2)
					flag[temp.Out1.StateId] = true
				}
			}
		}
	}
	//fmt.Println("求闭包" + strconv.Itoa(nState.StateId) + "完成")
	return closure
}

func Nfa2Dfa(nStart *NState, id2NSate map[int]*NState) (*DState, map[int]*DState) {

	//1.ε-Nfa -> Nfa;消除ε边
	//求有效状态
	validNStates := make(map[int]*NState)
	validNStates[nStart.StateId] = nStart
	for _, nState := range id2NSate {
		if nState.C < 256 {
			//fmt.Println("有效状态输入字符"+string(nState.C))
			validNStates[nState.Out1.StateId] = nState.Out1
		}
	}

	//构建（没有确定化的，只是消除ε边的）NFA
	id2NFAState := make(map[int]*NFAState)
	for _, validNState := range validNStates {
		closure := searchClosure(validNState, len(id2NSate))
		nfaState := NewNFAState(validNState.StateId)
		id2NFAState[validNState.StateId] = nfaState
		nfaState.NStates = closure
		for _, closureNState := range closure {
			if closureNState.C == 256 && closureNState.EndFunc != "" {
				nfaState.IsEnd = true
				nfaState.EndFunc = closureNState.EndFunc
			}
		}
	}

	for _, nfaState := range id2NFAState {
		for _, nState := range nfaState.NStates {
			if nState.C < 256 {
				//fmt.Println(strconv.Itoa(nfaState.StateId)+"  -"+strconv.Itoa(nState.C)+"->  "+strconv.Itoa(nState.Out1.StateId))
				nfaState.Outs = append(nfaState.Outs, &Out{nState.C, id2NFAState[nState.Out1.StateId]})
			}
		}
	}

	//2.Nfa确定化

	counter := 0
	//初始状态
	dStart := NewDState(counter)
	counter++
	dStart.NFAStates[nStart.StateId] = id2NFAState[nStart.StateId]

	//放置未被处理的已经创建了的DFA状态
	loadingDStates := make([]*DState, 0)
	loadingDStates = append(loadingDStates, dStart)
	//放置已经存在的DFA状态
	id2DState := make(map[int]*DState)
	id2DState[dStart.StateId] = dStart

	for len(loadingDStates) > 0 {
		temp := loadingDStates[0]
		loadingDStates = loadingDStates[1:]
		for c, cMap := range getOuts(temp) {
			if ok, dState := isDStateExisted(id2DState, cMap); ok {
				temp.Out[c] = dState
			} else {
				newDState := NewDState(counter)
				newDState.NFAStates = cMap
				for _, nfaState := range cMap {
					if nfaState.IsEnd && nfaState.EndFunc != "" {
						newDState.IsEnd = true
						newDState.EndFunc = nfaState.EndFunc
					}
				}
				temp.Out[c] = newDState

				id2DState[counter] = newDState
				loadingDStates = append(loadingDStates, newDState)

				counter++
			}
		}
	}
	return dStart, id2DState
}

func isDStateExisted(id2DState map[int]*DState, NFAStates map[int]*NFAState) (bool, *DState) {
	for _, dState := range id2DState {
		if reflect.DeepEqual(dState.NFAStates, NFAStates) {
			return true, dState
		}
	}
	return false, nil
}

//通过c到达的所有Nfa状态的集合,即DState	c StateId NfaState
func getOuts(dState *DState) map[int]map[int]*NFAState {
	outNfaStates := make(map[int]map[int]*NFAState)
	for _, nfaState := range dState.NFAStates {
		for _, nfaStateOut := range nfaState.Outs {
			nfaStates := make(map[int]*NFAState)
			nfaStates[nfaStateOut.NFAState.StateId] = nfaStateOut.NFAState
			outNfaStates[nfaStateOut.C] = nfaStates
		}
	}
	return outNfaStates
}

func PrintDFA(id2DState map[int]*DState) {
	endFuncNum := 0
	dStateNum := 0
	for dStateId, dState := range id2DState {
		fmt.Print("stateId:" + strconv.Itoa(dStateId) + " ; ")
		if dState.IsEnd {
			endFuncNum++
			fmt.Println(" EndFunc:" + dState.EndFunc + "; ")
		} else {
			fmt.Println(" notEnd; ")
		}
		for c, out := range dState.Out {
			if c < 256 {
				fmt.Print("转义字符:" + string(c) + " " + strconv.Itoa(out.StateId) + "; ")
			} else if c == 256 {
				fmt.Print("Match; ")
			} else {
				fmt.Print("Spilt; ")
			}

		}
		dStateNum++
		fmt.Println("\n------")
	}
	fmt.Println("统计信息")
	fmt.Println("dfa状态数" + strconv.Itoa(dStateNum))
	fmt.Println("endFunc数" + strconv.Itoa(endFuncNum))
}

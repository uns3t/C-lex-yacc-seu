package nfa2dfa_2

import "reflect"

//求闭包
func searchClosure(nState *NState) []*NState {
	closure := make([]*NState, 0)
	back := []*NState{nState}
	for len(back) > 0 {
		temp := back[len(back)-1]
		back = back[:len(back)-1]
		closure = append(closure, temp)
		if temp.C > 255 {
			if temp.Out1 != nil {
				back = append(back, temp.Out1)
			}
			if temp.Out2 != nil {
				back = append(back, temp.Out2)
			}
		}
	}
	return closure
}

func Nfa2Dfa(nStart *NState, id2NSate map[int]*NState) (*DState, map[int]*DState) {

	//1.ε-Nfa -> Nfa;消除ε边
	//求有效状态
	validNStates := make([]*NState, 0)
	validNStates = append(validNStates, nStart)
	for _, nState := range id2NSate {
		if nState.C < 256 {
			validNStates = append(validNStates, nState.Out1)
		}
	}

	//构建（没有确定化的，只是消除ε边的）“Dfa”
	id2NFAState := make(map[int]*NFAState)
	for _, validNState := range validNStates {
		closure := searchClosure(validNState)
		nfaState := NewNFAState(validNState.StateId)
		id2NFAState[validNState.StateId] = nfaState
		nfaState.NStates = closure
		if validNState.C == 256 {
			nfaState.IsEnd = true
		}
	}

	for _, nfaState := range id2NFAState {
		for _, nState := range nfaState.NStates {
			if nState.C < 256 {
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
					if nfaState.IsEnd {
						newDState.IsEnd = true
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
	nfaStates := make(map[int]*NFAState)
	for _, nfaState := range dState.NFAStates {
		for _, nfaStateOut := range nfaState.Outs {
			nfaStates[nfaStateOut.NFAState.StateId] = nfaStateOut.NFAState
			outNfaStates[nfaStateOut.C] = nfaStates
		}
	}
	return outNfaStates
}

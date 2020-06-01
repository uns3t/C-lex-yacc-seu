package SeuYacc

import (
	"strconv"
	"strings"
)

//dfa to parsing table

//构想1:二维数组,指明列索引是action还是goto即可
//构想2:定义数据结构

type ActionAndGoto struct {
	actionTable map[string]string
	gotoTable   map[string]int
}

func getStateId(stateIdStr string) int {
	stateIdStr = strings.TrimLeft(stateIdStr, "I")
	stateId, _ := strconv.Atoi(stateIdStr)
	return stateId
}

func dfaToParsingTable(I0 *lrState, grammar *Grammar) map[int]ActionAndGoto {
	//let parsingTable = {}
	var parsingTable map[int]ActionAndGoto
	var stateId1, stateId2 int
	for stateName, state := range GenerateLR1DFA(I0, grammar) {
		// 移进和GOTO
		stateId1 = getStateId(stateName)
		for k, v := range state.edge {
			stateId2 = getStateId(v)
			if isVn(grammar, k) {
				// 非终结符填入 GOTO 子表
				parsingTable[stateId1].gotoTable[k] = stateId2
			} else {
				// 终结符填入 ACTION 子表 - 移进动作不会有冲突
				parsingTable[stateId1].actionTable[k] = "S" + string(stateId2)
			}
		}
		// 归约操作
		for itemName, item := range state.items {
			if item.position == len(item.rightPart) {
				// 点移动到末尾的情况需要处理
				for _, predictor := range item.predictor {
					if _, ok := parsingTable[stateId1].actionTable[predictor]; !ok {
						//if(!parsingTable[tableState].action[predictor])是指非空还是啥?
						parsingTable[stateId1].actionTable[predictor] = ""
					}
					//有点问题
					parsingTable[stateId1].actionTable[predictor] = "r" + strings.Split(itemName, "-")[0]
				}
			}

		}

		for vt, content := range parsingTable[stateId1].actionTable {
			if len(parsingTable[stateId1].actionTable[vt]) > 2 {
				parsingTable[stateId1].actionTable[vt] = "r" + strings.Split(content, "r")[0]
			}
		}
	}
	return parsingTable
}

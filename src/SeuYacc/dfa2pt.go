package SeuYacc

import (
	"fmt"
	"sort"
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

func DfaToParsingTable(lrStates map[string]*lrState, grammar *Grammar) map[int]*ActionAndGoto {
	//let parsingTable = {}
	var parsingTable = make(map[int]*ActionAndGoto)
	var stateId1, stateId2 int
	for stateName, state := range lrStates {
		// 移进和GOTO
		stateId1 = getStateId(stateName)
		parsingTable[stateId1] = &ActionAndGoto{make(map[string]string), make(map[string]int)}
		for k, v := range state.edge {
			stateId2 = getStateId(v) //这边有问题
			//stateId2=strconv.Itoa(strings.Split(,"-")[0])
			if isVn(grammar, k) {
				// 非终结符填入 GOTO 子表
				parsingTable[stateId1].gotoTable[k] = stateId2
			} else {
				// 终结符填入 ACTION 子表 - 移进动作不会有冲突
				parsingTable[stateId1].actionTable[k] = "S" + strconv.Itoa(stateId2)
			}
		}
		// 归约操作
		for itemName, item := range state.items {
			if item.position == len(item.rightPart) {
				// 点移动到末尾的情况需要处理
				for _, predictor := range item.predictor {
					if _, ok := parsingTable[stateId1].actionTable[predictor]; !ok {
						parsingTable[stateId1].actionTable[predictor] = ""
					}
					//有点问题
					parsingTable[stateId1].actionTable[predictor] += "r" + strings.Split(itemName, "-")[0]
				}
			}

		}

		//for vt, content := range parsingTable[stateId1].actionTable {
		//	if len(parsingTable[stateId1].actionTable[vt]) > 2 {
		//		parsingTable[stateId1].actionTable[vt] = "r" + strings.Split(content, "r")[0]
		//	}
		//}

		for vt, content := range parsingTable[stateId1].actionTable {
			temp1 := make([]string, 0)
			if len(parsingTable[stateId1].actionTable[vt]) > 1 {
				temp := strings.FieldsFunc(content, split)
				//temp中元素可能以r/S开头;我们只需要r
				sort.Strings(temp)
				for _, v := range temp {
					if strings.HasPrefix(v, "r") {
						temp1 = append(temp1, v)
					}
				}
			}
			if len(temp1) > 0 {
				parsingTable[stateId1].actionTable[vt] = temp1[0]
			}
		}
	}
	return parsingTable
}

func split(s rune) bool {
	if s == 'r' || s == 'S' {
		return true
	}
	return false
}

func PrintParsingTable(pt map[int]*ActionAndGoto) {
	fmt.Println("ParsingTable:")
	for stateId, AAG := range pt {
		fmt.Println("stateId:" + strconv.Itoa(stateId) + "	")
		for vt, actionJob := range AAG.actionTable {
			fmt.Print(vt + " " + actionJob + "  ")
		}
		fmt.Println()
		for vn, gotoJob := range AAG.gotoTable {
			fmt.Print(vn + " " + strconv.Itoa(gotoJob) + "  ")
		}
		fmt.Println()
	}
}

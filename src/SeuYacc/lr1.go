package SeuYacc

import (
	"crypto/sha1"
	"fmt"
	"sort"
	"strconv"
	"strings"
)

//lr1语法分析

//语法解析, 状态构建, 状态去重, 状态转移, Action表与Goto表的构建
//s->s·a /s->s·b a,b s->sa·
func getOutEdge(dfaItem *lrState) []string {
	var outEdge []string
	for n := range dfaItem.items {
		if dfaItem.items[n].position < len(dfaItem.items[n].rightPart) {
			outEdge = append(outEdge, dfaItem.items[n].rightPart[dfaItem.items[n].position])
		}
	}
	return outEdge
}

func nextStep(dfaItem *lrState, edge string) *lrState {
	newDfaItem := NewLrState("")
	var sig []string
	for n := range dfaItem.items {
		pCode := strings.Split(n,"-")[0]
		if dfaItem.items[n].position < len(dfaItem.items[n].rightPart) {
			if dfaItem.items[n].rightPart[dfaItem.items[n].position] == edge {
				temp := NewItemp(dfaItem.items[n].predictor,dfaItem.items[n].position+1, dfaItem.items[n].rightPart)
				flag := pCode + "-" + strconv.Itoa(dfaItem.items[n].position+1)
				str := flag + "-" + strings.Join(temp.predictor,"|")
				sig = append(sig, str)
				newDfaItem.items[flag] = temp
			}
		}
	}

	sort.Strings(sig)
	t := sha1.New()
	t.Write([]byte(strings.Join(sig,"•")))
	newDfaItem.signature = string(t.Sum(nil))
	return newDfaItem
}

func GenerateLR1(grammar *Grammar) map[string]*lrState {
	dfaItem := NewLrState("I0")
	dfaItem.PutItems("0-0", strings.Split("$", ""), 0, strings.Split(grammar.GrammarStart(), ""))
	return generateLR1DFA(dfaItem,grammar)
}

func generateLR1DFA(I0 *lrState,grammar *Grammar) map[string]*lrState {
	lrDFA := make(map[string]*lrState)
	lr1DfaSigniture := make(map[string]string)
	dfaItemQ := NewDfaQueue()
	nameCounter := 1

	I0 = expandDFAItem(I0,grammar)
	dfaItemQ.Push(I0)
	lr1DfaSigniture[I0.signature] = "I0"
	for len(dfaItemQ.lrStatequeue)>0 {
		currentItem := dfaItemQ.Shift()
		outEdges := getOutEdge(currentItem)
		if outEdges == nil{
			lrDFA[currentItem.name] = currentItem
			fmt.Println(currentItem.name+"已构造完成\n")
			continue
		}
		for i := range outEdges {
			nextItem := nextStep(currentItem,outEdges[i])
			if lr1DfaSigniture[nextItem.signature] == "" {
				nextItem.name = "I" + strconv.Itoa(nameCounter)
				lr1DfaSigniture[nextItem.signature] = nextItem.name
				nextItem = expandDFAItem(nextItem,grammar)
				nameCounter++
				dfaItemQ.Push(nextItem)
				currentItem.edge[outEdges[i]] = nextItem.name
			}else {
				currentItem.edge[outEdges[i]] = lr1DfaSigniture[nextItem.signature]
			}
		}
		lrDFA[currentItem.name] = currentItem
		fmt.Println(currentItem.name+"已构造完成\n")
	}
	return lrDFA
}
//S->S' 扩展成s->s',s'->....,...,
func expandDFAItem(dfaItem *lrState, grammar *Grammar) *lrState {
	expandFlag := true
	for expandFlag {
		expandFlag = false
		for itemName := range dfaItem.items {
			item := dfaItem.items[itemName]
			position := item.position
			pCode := strings.Split(itemName,"-")[0]//11-0
			predictor := item.predictor
			rightPart := getRightPart(*grammar,pCode)
			if position < len(rightPart){
				if isVn(grammar,rightPart[position]) {
					// 点的后面是非终结符
					newPredictor := make(map[string]bool)
					var newKey []string
					newKey = newKey[:0]
					// 先计算新的预测符
					for vt := range predictor {
						betaAlpha := append(rightPart[position+1:],predictor[vt])
						first := first(betaAlpha,*grammar)
						for vtt := range first {//a,a,b,b
							newPredictor[first[vtt]] = true
						}
					}
					for s := range newPredictor {
						newKey = append(newKey, s)
					}
					sort.Strings(newKey)

					creator := grammar.p[rightPart[position]]
					// 遍历该非终结符为左部的所有的产生式
					for p := range creator {
						name := creator[p].code + "-0"
						if dfaItem.items[name] != nil {
							// 如果已经包含该产生式，检查是否需要扩展预测符
							if strings.Join(newKey,"|") != strings.Join(dfaItem.items[name].predictor,"|") {
								// 新的预测符和旧的不相等，判断是否属于包含关系
								old := strings.Join(dfaItem.items[name].predictor,"｜")
								for i := range newKey {
									if !strings.Contains(old,newKey[i]) {
										dfaItem.items[name].predictor = append(dfaItem.items[name].predictor, newKey[i])
										expandFlag = true// 有新的预测符加入
									}
								}
								if expandFlag {
									sort.Strings(dfaItem.items[name].predictor)
								}
							}
						}else {
							dfaItem.items[name] = NewItemp(newKey,0,
								getRightPart(*grammar,creator[p].code))
							expandFlag = true
						}
					}
				}
			}

		}
	}
	// 对 dfaItem 计算签名，用于后续判断是否出现重复状态
	// signature 是完整签名


	//var sig []string
	//for n := range dfaItem.items {
	//	str := n + "-" + strings.Join(dfaItem.items[n].predictor,"|")
	//	//str := n + "-" + strconv.Itoa(len(dfaItem.items[n].predictor))
	//	sig = append(sig, str)
	//}
	//sort.Strings(sig)
	//t := sha1.New()
	//t.Write([]byte(strings.Join(sig,"•")))
	//dfaItem.signature = string(t.Sum(nil))

	return dfaItem
}

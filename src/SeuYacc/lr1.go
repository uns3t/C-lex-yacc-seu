package SeuYacc

import (
	"sort"
	"strings"
)

//lr1语法分析

//语法解析, 状态构建, 状态去重, 状态转移, Action表与Goto表的构建
//


func generateLR1DFA(I0 *lrState,grammar *grammar)  {
	I0 = expandDFAItem(I0,grammar)
}

func expandDFAItem(dfaItem *lrState, grammar *grammar) *lrState {
	expandFlag := true
	for expandFlag {
		expandFlag = false
		for itemName := range dfaItem.items {
			item := dfaItem.items[itemName]
			position := item.position
			pCode := strings.Split(itemName,"-")[0]
			predictor := item.predictor
			rightPart := getRightPart(grammar,pCode)
			if isVn(grammar,rightPart[position]) {
				// 点的后面是非终结符
				newPredictor := make(map[string]bool)
				var newKey []string
				// 先计算新的预测符
				for vt := range predictor {
					betaAlpha := append(rightPart[position+1:],predictor[vt])
					first := first(betaAlpha,grammar)
					for vtt := range first {
						newPredictor[first[vtt]] = true
						newKey = append(newKey, first[vtt])
					}
				}
				sort.Strings(newKey)

				creator := p(grammar,rightPart[position])
				// 遍历该非终结符为左部的所有的产生式
				for p := range creator {
					name := getPCode(creator[p]) + "-0"
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
						dfaItem.items[name] = NewItemp(newKey,0,strings.Join(
							getRightPart(grammar,getPCode(creator[p])),""))
						expandFlag = true
					}
				}
			}
		}
	}
	// 对 dfaItem 计算签名，用于后续判断是否出现重复状态
	// signature 是完整签名

	/*
	??????????????
	 */
	return dfaItem
}

func getOutEdge()  {
	
}
package SeuLex

//Split := 257
//Match := 256
//type DNode struct {
//	NStates []NState
//	DOut []DState
//}
//
//type DState struct {
//	c int
//	out *DNode
//}

var backLook []NState

func searchClosure(Nnode NState) []NState {
	ret := []NState{}
	back := []NState{Nnode}
	for len(back) > 0 {
		temp := back[len(back)-1]
		back = back[:len(back)-1]
		ret = append(ret, temp)
		if temp.C > 255 {
			if temp.Out1 != nil {
				back = append(back, *temp.Out1)
			}
			if temp.Out2 != nil {
				back = append(back, *temp.Out2)
			}
		}
	}
	return ret
}

type Dtemp struct {
	Nnode    NState
	NClosure []NState
}

func Nfa2dfa(nfa *NState) []*DNode {
	dTemp := make([]Dtemp,0)               //保存是否求过闭包
	backLook = append(backLook, *nfa) //回溯还未处理（判断是否求过闭包）的新状态
	dArr := make([]*DNode,0)              //最后返回的DFA
	for len(backLook) > 0 {
		tempNode := backLook[0]
		backLook = backLook[1:]
		flag := false
		//判断是否求过闭包
		for i := 0; i < len(dTemp); i++ {
			if dTemp[i].Nnode == tempNode {
				flag = true
			}
		}
		//如果没有求过闭包，就求闭包，然后保存
		if !flag {
			isEnd := false
			if tempNode.C == 256 {
				isEnd = true
			}
			tempClosure := searchClosure(tempNode)
			dArr = append(dArr, DNode{tempClosure,0, isEnd, []*DState{}})
			//临时变量，用来保存闭包
			Oedema := Dtemp{tempNode, tempClosure}
			dTemp = append(dTemp, Oedema)

			for i := 0; i < len(tempClosure); i++ {
				if tempClosure[i].C <= 255 {
					backLook = append(backLook, *tempClosure[i].Out1)
				}
			}
		}
	}

	//构建dfa
	for i := 0; i < len(dArr); i++ {
		for j := 0; j < len(dArr[i].NStates); j++ {
			if dArr[i].NStates[j].C <= 255 {
				idx := 0
				for true {
					if dTemp[idx].Nnode == *dArr[i].NStates[j].Out1 {
						dArr[i].DOut = append(dArr[i].DOut, &DState{dArr[i].NStates[j].C, &dArr[idx]})
						break
					}
					idx++
				}
			}
		}
	}
	for k:=range dArr{
		dArr[k].id=k
		dArr[k].NStates=nil
	}

	return dArr
}

package SeuLex

import "fmt"

//Split := 257
//Match := 256
//type Dnode struct {
//	Nnodes []NState
//	Dout []Dstate
//}
//
//type Dstate struct {
//	c int
//	out *Dnode
//}



var backLook []NState

func searchClosure(Nnode NState) []NState{
	ret:=[]NState{}
	back:=[]NState{Nnode}
	for len(back)>0{
		temp:=back[len(back)-1]
		back=back[:len(back)-1]
		ret=append(ret,temp)
		if temp.C>255{
			if temp.Out1!=nil{
				back=append(back,*temp.Out1)
			}
			if temp.Out2!=nil{
				back=append(back,*temp.Out2)
			}
		}
	}
	return ret
}



type Dtemp struct {
	Nnode NState
	NClosure []NState
}


func Nfa2dfa(nfa NState) []Dnode{
	dtemp:=[]Dtemp{}     //保存是否求过闭包
	backLook=append(backLook,nfa)   //回溯还未处理（判断是否求过闭包）的新状态
	dArr:=[]Dnode{}   //最后返回的DFA
	for len(backLook)>0{
		tempNode:=backLook[0]
		backLook=backLook[1:]
		flag:=false
		//判断是否求过闭包
		for i:=0;i<len(dtemp);i++{
			if dtemp[i].Nnode==tempNode{
				flag=true
			}
		}
		//如果没有求过闭包，就求闭包，然后保存
		if !flag{
			isEnd:=false
			if tempNode.C==256{
				isEnd=true
			}
			tempClosure:=searchClosure(tempNode)
			dArr= append(dArr, Dnode{tempClosure,isEnd,[]Dstate{}})
			//临时变量，用来保存闭包
			Oedema :=Dtemp{tempNode,tempClosure}
			dtemp=append(dtemp, Oedema)


			for i:=0;i<len(tempClosure);i++{
				if tempClosure[i].C<=255{
					backLook=append(backLook,*tempClosure[i].Out1)
				}
			}
		}
	}
	//构建dfa
	for i:=0;i<len(dArr);i++{
		for j:=0;j<len(dArr[i].Nnodes);j++{
			if dArr[i].Nnodes[j].C<=255{
				idx:=0
				for true{
					if dtemp[idx].Nnode==*dArr[i].Nnodes[j].Out1{
						dArr[i].Dout=append(dArr[i].Dout,Dstate{dArr[i].Nnodes[j].C,&dArr[idx]})
						break
					}
					idx++
				}
			}
		}
	}

	for i:=0;i<len(dArr);i++{
		fmt.Println("Dfa out C: ")
		for j:=0;j<len(dArr[i].Dout);j++{
			fmt.Println(dArr[i].Dout[j].C)
		}
	}
	return dArr
}

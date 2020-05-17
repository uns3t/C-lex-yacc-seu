package SeuLex


//Split := 257
//Match := 256
//type Dnode struct {
//	Nnodes []NState
//	Dout []Dstate
//}
//
//type Dstate struct {
//	c int
//	out Dnode
//}



var backLook []NState

func searchClosure(Nnode NState) []NState{
	ret:=[]NState{}
	back:=[]NState{Nnode}
	for len(back)>0{
		temp:=back[len(back)]
		back=back[:len(back)]
		ret=append(ret,temp)
		if temp.C>255{
			if temp.Out1!=nil{
				back=append(back,temp.Out1)
			}
			if temp.Out2!=nil{
				back=append(back,temp.Out2)
			}
		}
	}
	return ret
}



type Dtemp struct {
	Nnode NState
	NClosure []NState
}


func nfa2dfa(nfa NState) []Dnode{
	dtemp:=[]Dtemp{}
	backLook=append(backLook,nfa)
	dArr:=[]Dnode{}
	for len(backLook)>0{
		tempNode:=backLook[0]
		backLook=backLook[1:]
		flag:=false
		for i:=0;i<len(dtemp);i++{
			if dtemp[i].Nnode==tempNode{
				flag=true
			}
		}
		if !flag{
			tempClosure:=searchClosure(tempNode)
			dArr= append(dArr, Dnode{tempClosure,[]Dstate{}})
			Oedema :=Dtemp{tempNode,tempClosure}
			dtemp=append(dtemp, Oedema)
			for i:=0;i<len(tempClosure);i++{
				if tempClosure[i].C<=255{
					backLook=append(backLook,tempClosure[i])
				}
			}
		}
	}
	for i:=0;i<len(dArr);i++{
		for j:=0;j<len(dArr[i].Nnodes);j++{
			if dArr[i].Nnodes[j].C<=255{
				idx:=0
				for true{
					if dtemp[idx].Nnode==dArr[i].Nnodes[j]{
						dArr[i].Dout=append(dArr[i].Dout,Dstate{dArr[i].Nnodes[j].C,dArr[idx]})
						break
					}
					idx++
				}
			}
		}
	}
	return dArr
}

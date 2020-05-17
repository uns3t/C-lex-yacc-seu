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
		if temp.c>255{
			if(temp.out1!=nil){
				back=append(back,temp.out1)
			}
			if(temp.out2!=nil){
				back=append(back,temp.out2)
			}
		}
	}
	return ret
}

func retDnodeOut(Narr []NState)  {
	for i:=0;i<len(Narr);i++{
		if(Narr[i].c<=255){
			backLook=append(backLook,Narr[i])
		}
	}
}

type Dtemp struct {
	Nnode NState
	NClosure []NState
}


func nfa2dfa(nfa NState){
	dtemp:=[]Dtemp{}
	backLook=append(backLook,nfa)
	for len(backLook)>0{
		tempNode:=backLook[0]
		backLook=backLook[1:]
		flag:=false
		for i:=0;i<len(dtemp);i++{
			if(dtemp[i].Nnode==tempNode){
				flag=true
			}
		}
		if(!flag){
			tempClosure:=searchClosure(tempNode)
			Onedtemp:=Dtemp{tempNode,tempClosure}
			dtemp=append(dtemp,Onedtemp)
			for i:=0;i<len(tempClosure);i++{
				if(tempClosure[i].c<=255){
					backLook=append(backLook,tempClosure[i])
				}
			}
		}

	}

}

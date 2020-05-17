package SeuLex


//Split := 257
//Match := 256

func searchClosure(Nnode NState) []NState{
	ret:=[]NState{}
	for Nnode.c!=256{
		if Nnode.c<=255{
			ret=append(ret,Nnode)
			Nnode=Nnode.out2
		}else if  Nnode.c==257{

		}
	}
}

func nfa2dfa(nfa NState){

}

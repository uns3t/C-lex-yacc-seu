package main

import "SeuLex"

func Testdfa2nfa()  {
	Nnode1:=SeuLex.NState{257,nil,nil,""}
	Nnode2:=SeuLex.NState{2,nil,nil,""}
	Nnode3:=SeuLex.NState{3,nil,nil,""}
	Nnode4:=SeuLex.NState{256,nil,nil,""}
	Nnode1.Out1=Nnode2
	Nnode1.Out2=Nnode3
	Nnode2.Out1=Nnode4
	Nnode3.Out1=Nnode4
}

package SeuLex

type NState struct {
	C int
	//isStart    bool
	//isEnd      bool
	//transition map[string]*NState
	Out1    *NState
	Out2    *NState
	EndFunc string // 结束状态所对应的函数, 只有该点为Match时, 值可以视为有效
}

//NFA片段
type Fragment struct {
	Start *NState // 起始节点
	End   *NState // 尾节点
}

type Dnode struct {
	Nnodes []NState
	Dout []Dstate
}

type Dstate struct {
	C int
	Out *Dnode
}


func NewNState() *NState {
	return &NState{0, nil, nil, ""}
}

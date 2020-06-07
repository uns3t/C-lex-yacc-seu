package nfa2dfa_1

type NState struct {
	StateId int
	/*选择2^8是因为string[i]类型为uint8
	256 match
	257 spilt
	<256 字符对应的ascii值
	*/
	C int

	//isStart    bool
	//isEnd      bool
	//transition map[string]*NState
	//实边
	Out1    *NState
	Out2    *NState
	EndFunc string // 结束状态所对应的函数, 只有该点为Match时, 值可以视为有效
}

//NFA片段
type Fragment struct {
	Start *NState // 起始节点
	End   *NState // 尾节点
}

type DNode struct {
	NStates []NState
	isEnd   bool
	DOut    []DState
	//感觉这里可以用 map[int]*DNode  key: int C    value:  *DNode Out		-王伟
}

type DState struct {
	C   int
	Out *DNode
}

type DFAstate struct {
	isEnd bool
	id    int
	value []*DState
}

func NewNState() *NState {
	return &NState{0, 0, nil, nil, ""}
}

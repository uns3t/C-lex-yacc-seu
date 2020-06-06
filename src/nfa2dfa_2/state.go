package nfa2dfa_2

type NState struct {
	StateId int
	/*选择2^8是因为string[i]类型为uint8
	256 match
	257 spilt
	<256 字符对应的ascii值
	*/
	C int

	//isStart    bool
	//IsEnd      bool
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

//消除了ε边的NFA
type NFAState struct {
	StateId int
	NStates []*NState
	IsEnd   bool
	Outs    []*Out
}
type Out struct {
	C        int
	NFAState *NFAState
}

//Nfa确定化之后的dfa
type DState struct {
	StateId   int
	NFAStates map[int]*NFAState
	IsEnd     bool
	Out       map[int]*DState
}

func NewNFAState(DStateId int) *NFAState {
	return &NFAState{DStateId, make([]*NState, 0), false, make([]*Out, 0)}
}

func NewDState(DStateId int) *DState {
	return &DState{DStateId, make(map[int]*NFAState), false, make(map[int]*DState)}
}

func NewNState() *NState {
	return &NState{0, 0, nil, nil, ""}
}

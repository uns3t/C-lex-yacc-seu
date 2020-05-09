package SeuLex

type NState struct {
	c int
	//isStart    bool
	//isEnd      bool
	//transition map[string]*NState
	out1    *NState
	out2    *NState
	endFunc string // 结束状态所对应的函数, 只有该点为Match时, 值可以视为有效
}

//NFA片段
type Fragment struct {
	start *NState // 起始节点
	end   *NState // 尾节点
}

func NewNState() *NState {
	return &NState{0, nil, nil, ""}
}

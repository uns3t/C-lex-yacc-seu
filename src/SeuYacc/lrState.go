package SeuYacc

//记录了LR1状态转换图中的每一个状态
type lrState struct {
	//I0
	name      string
	//LR1状态中项的集合  key为"X-Y" 其中X表示第几号产生式，Y表示点的位置如0-0
	items     map[string]*item
	//签名，用于去重
	signature string
	//出边的集合   key为输入的下一个符号  value为LR1状态的名称
	edge      map[string]string
}
//LR1状态中的项
type item struct {
	//预测符集
	predictor []string
	//点的位置 从0开始
	position  int
	//产生式右部
	rightPart []string
}

func NewLrState(n string) *lrState {
	return &lrState{name: n, items: make(map[string]*item), edge: make(map[string]string)}
}
func (this *lrState) PutItems(name string, pre []string, pos int, right []string) {
	this.items[name] = NewItemp(pre, pos, right)
}

func NewItemp(pre []string, pos int, rightP []string) *item {
	return &item{predictor: pre, position: pos, rightPart: rightP}
}

type dfaItemQueue struct {
	lrStatequeue []*lrState
}

func NewDfaQueue() *dfaItemQueue {
	return &dfaItemQueue{}
}
func (this *dfaItemQueue) Push(state *lrState) {
	this.lrStatequeue = append(this.lrStatequeue, state)
}
func (this *dfaItemQueue) Shift() *lrState {
	if len(this.lrStatequeue) == 0 {
		panic("dfa队列错误，为空")
	}
	temp := this.lrStatequeue[0]
	this.lrStatequeue = this.lrStatequeue[1:]
	return temp
}

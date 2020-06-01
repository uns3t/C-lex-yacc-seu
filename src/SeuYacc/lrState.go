package SeuYacc

//记录了LR1状态转换图中的每一个状态
type lrState struct {
	name      string
	items     map[string]*item
	signature string
	edge      map[string]string
}

type item struct {
	predictor []string
	position  int
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

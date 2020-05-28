package SeuYacc

//记录了LR1状态转换图中的每一个状态
type lrState struct {
	name string
	items map[string]*item

}

type item struct {
	predictor []string
	position int
	rightPart string
}

func NewItemp(pre []string, pos int, rightP string) *item {
	return &item{predictor: pre,position: pos,rightPart: rightP}
}
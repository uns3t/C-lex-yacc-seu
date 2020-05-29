package SeuYacc

type pNode struct {
	code string
	rightPart []string
}

type Grammar struct {
	start string
	vtList []string
	vnList []string
	p map[string][]pNode
}

func arrayInclude(arr []string,val string) bool {
	for _,v:= range arr{
		if val==v{
			return true
		}
	}
	return false
}

var gramme Grammar


func yaccToGrammar(yaccFile YaccFile){
	gramme.start=yaccFile.DefineSegment.Start
	gramme.vnList=[]string{"S"}
	gramme.vtList=yaccFile.DefineSegment.Token
	gramme.vtList=append(gramme.vtList,"$")
	gramme.p["S"]=[]pNode{{"0",[]string{gramme.start}}}
	pCounter:=1
	for _,v:=range yaccFile.GrammarSegment{
		if !arrayInclude(gramme.vnList,v.leftPart){
			gramme.vnList=append(gramme.vnList,v.leftPart)
		}
		gramme.p[v.leftPart]=[]pNode{}
		for _,val:=range v.rightPart{
			for _,newVal:=range val{
				if newVal[0]=='\''{
					vt:=newVal[1:len(newVal)]
					if !arrayInclude(gramme.vtList,vt){
						gramme.vtList=append(gramme.vtList,vt)
					}
				}
			}
		}
	}



}

func calcFirst(){

}





func getRightPart(grammar *grammar, pCode string) []string {
	return nil
}
func isVn(grammar *grammar, syn string) bool {
	return true
}
func p(grammar *grammar, syn string) []string {
	return nil
}
func getPCode(p string) string {
	return ""
}
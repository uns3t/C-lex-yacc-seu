package SeuYacc

import (
	"fmt"
	"strconv"
)

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


func yaccToGrammar(yaccFile YaccFile) Grammar{
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
					vt:=newVal[1:len(newVal)-1]
					if !arrayInclude(gramme.vtList,vt){
						gramme.vtList=append(gramme.vtList,vt)
					}
				}
			}
			rightTemp:=make([]string,0)
			for _,newVal:=range val{
				if newVal[0]=='\''{
					rightTemp=append(rightTemp, newVal[1:len(newVal)-1])
				}else{
					rightTemp=append(rightTemp, newVal)
				}
			}
			gramme.p[v.leftPart]=append(gramme.p[v.leftPart],pNode{strconv.Itoa(pCounter),rightTemp})
			pCounter+=1
		}
	}

	return gramme

}

func first(p []string,gram Grammar)[]string{
	head:=0
	firstSet:= map[string]bool{}
	if arrayInclude(gram.vtList,p[head]){
		firstSet[p[head]]=true
	}else if arrayInclude(gram.vnList,p[head]){
		for _,v:=range gram.p[p[head]]{
			if v.rightPart[0]!=p[head]{
				arr:=first(v.rightPart,gram)
				for _,k:=range arr {
					firstSet[k]=true
				}
			}
		}
	}else {
		fmt.Println("first出现错误")
	}
	ret:=make([]string,0)
	for k,_:=range firstSet{
		ret=append(ret,k)
	}
	return ret
}


func getRightPart(gram Grammar, pCode string) []string {
	for _,v:=range gram.p{
		for _,k:=range v{
			if k.code==pCode{
				return k.rightPart
			}
		}
	}
	fmt.Println("未找到rightPart")
	return []string{}
}
func isVn(gram Grammar, vn string) bool {
	return arrayInclude(gram.vnList,vn)
}
func getLeftPart(gram Grammar, pCode string) string {
	for key,v:=range gram.p{
		for _,k:=range v{
			if k.code==pCode{
				return key
			}
		}
	}
	fmt.Println("未找到LeftPart")
	return ""
}

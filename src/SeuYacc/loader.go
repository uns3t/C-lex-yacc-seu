package SeuYacc

import (
	"fmt"
	"io/ioutil"
	"strings"
)

type YaccFile struct {
	DefineSegment defineSegment
	GrammarSegment []grammarSegment
	ProgramSegment string
}
type defineSegment struct {
	Token []string
	Start string
}

type grammarSegment struct {
	leftPart string
	rightPart [][]string
}

func LoadYaccFile(yaccPath string) YaccFile {
	yaccData, err := ioutil.ReadFile(yaccPath)
	if err != nil {
		fmt.Println("打开Lex文件失败",err)
	}
	yaccSegment:=strings.Split(string(yaccData),"%%")

	temp1:=parseDefineSegment(yaccSegment[0])
	temp2:=parseGrammarSegment(yaccSegment[1])
	ret:=YaccFile{temp1,temp2,yaccSegment[2]}

	return ret
}

func parseDefineSegment(str string)  defineSegment{
	arr:=strings.Split(str,"\r\n")
	ret:=defineSegment{[]string{},""}
	for _,v:=range arr{
		if len(v)>0{
			temp:=strings.Split(v," ")
			if temp[0]=="%token"{
				for i:=1;i<len(temp);i++{
					ret.Token=append(ret.Token,temp[i])
				}
			}else if temp[0]=="%start"{
				ret.Start=strings.TrimSpace(temp[1])
			}
		}
	}
	return ret
}

func parseGrammarSegment(str string)  []grammarSegment{
	str=strings.TrimSpace(str)
	arr:=strings.Split(str,"\t;")
	newArr:=make([]string, 0)
	ret:=make([]grammarSegment, 0)
	for k,_:=range arr{
		arr[k]=strings.TrimSpace(arr[k])
		if len(arr[k])>0{
			newArr=append(newArr,arr[k])
		}
	}
	for i:=0;i<len(newArr);i++{
		if len(newArr[i])>0{
			temp:=strings.Split(newArr[i],"\t:")
			tempRight:=strings.Split(strings.TrimSpace(temp[1]),"\t|")
			right:=make([][]string,0)
			for _,v:=range tempRight{
				right=append(right,strings.Split(strings.TrimSpace(v)," "))
			}
			left:=strings.TrimSpace(temp[0])
			ret=append(ret,grammarSegment{left,right})
		}
	}
	return ret
}

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
	ret:=YaccFile{nil,nil,nil}
	ret.DefineSegment=parseDefineSegment(yaccSegment[0])
	ret.GrammarSegment=parseGrammarSegment(yaccSegment[1])
	ret.ProgramSegment=yaccSegment[2]
	return ret
}

func parseDefineSegment(str string)  defineSegment{
	arr:=strings.Split("\r\n",str)
	ret:=defineSegment{[]string{},""}
	for _,v:=range arr{
		if string(v[0])=="%"{
			temp:=strings.Split(v," ")
			if temp[0]=="%token"{
				for i:=1;i<len(temp);i++{
					ret.Token=append(ret.Token,temp[i])
				}
			}else if temp[0]=="%start"{
				ret.Start=temp[1]
			}
		}
	}
	return ret
}

func parseGrammarSegment(str string)  []grammarSegment{
	arr:=strings.Split("\r\n;",str)
	newArr:=make([]string, len(arr))
	ret:=make([]grammarSegment, len(arr))
	for k,_:=range arr{
		arr[k]=strings.Trim(arr[k]," ")
		if len(arr[k])>0{
			newArr=append(newArr,arr[k])
		}
	}
	for _,v:=range newArr{
		temp:=strings.Split(v,":")
		tempRight:=strings.Split(strings.Trim(temp[1]," "),"|")
		right:=make([][]string,len(tempRight))
		for _,v:=range tempRight{
			right=append(right,strings.Split(strings.Trim(v," ")," "))
		}
		ret=append(ret,grammarSegment{strings.Trim(temp[0]," "),right})
	}
	return ret
}

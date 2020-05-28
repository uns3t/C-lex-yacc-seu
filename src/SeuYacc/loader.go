package SeuYacc

import (
	"fmt"
	"io/ioutil"
	"strings"
)

type YaccFile struct {
	DefineSegment defineSegment
	GrammarSegment grammarSegment
	ProgramSegment string
}
type defineSegment struct {

}

type grammarSegment struct {

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
	
}

func parseGrammarSegment(str string)  grammarSegment{
	
}

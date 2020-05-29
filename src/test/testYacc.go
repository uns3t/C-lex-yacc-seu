package main

import (
	"SeuYacc"
)

func main()  {
	yaccFile:=SeuYacc.LoadYaccFile("./input/c99.y")
	SeuYacc.YaccToGrammar(yaccFile)

}

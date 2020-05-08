package SeuLex

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

var LexFile *os.File
var OutFile *os.File

var Def_Map  map[string]string
var Exp_Map map[string]string

func ScanStart(lexFile string,outFile string)  {

	Def_Map = make(map[string]string)

	file, err := os.Open(lexFile)
	LexFile = file
	if err != nil {
		fmt.Println("打开Lex文件失败",err)
		return
	}
	file = nil
	file, err = os.Open(outFile)
	OutFile = file
	if err != nil {
		fmt.Println("打开Out文件失败",err)
		return
	}
	defer LexFile.Close()
	defer OutFile.Close()
	scanner()
}


func scanner()  {
	var state = 0
	var line = 0
	var text, outPut string
	var errIn, errOut error
	var reader = bufio.NewReader(LexFile)
	var writer = bufio.NewWriter(OutFile)
	for true {
		line++
		lineS := strconv.Itoa(line)
		text, errIn = reader.ReadString('\n')
		if errIn == io.EOF {
			fmt.Println("读取文件完成")
			errF := writer.Flush()
			if errF != nil {
				fmt.Println(lineS + "flush失败")
			}
			break
		}
		switch state {
			case 0:{
				if strings.HasPrefix(text,"%{") {
					state = 1
				} else if strings.HasPrefix(text,"%%") {
					state = 2
				}else {
					arr := strings.Split(text," ")
					if Def_Map != nil{
						Def_Map[arr[0]] = arr[len(arr)-1]
					}
				}
				break
			}
			case 1:{
				if strings.HasPrefix(text,"}%") {
					_, errOut = writer.WriteString("//}% end\n")
					errF := writer.Flush()
					if errF != nil {
						fmt.Println(lineS + "flush失败")
					}
					state = 0
				}else {
					_, errOut = writer.WriteString(text)
				}
				if errOut != nil{
					fmt.Println(lineS + "写入失败")
				}
				break
			}

			case 2:{
				if strings.HasPrefix(text,"%%") {
					getRegularAndFunc(outPut)
					_, errOut = writer.WriteString("//%% end\n")
					errF := writer.Flush()
					if errF != nil {
						fmt.Println(lineS + "flush失败")
					}
					state = 3
				}else {
					outPut += text
				}
				break
			}
			case 3:{
				_, errOut = writer.WriteString(text)
				break
			}

			default:{
			fmt.Println(lineS + "结构不完整")
			break
			}
		}
		if state != 3 {
			fmt.Println(lineS + "结构不完整")
		}
	}

}

func getFunc(text string, line int)  {
	
}

func getRegularAndFunc(outPut string)  {
	exp := strings.Split(outPut,"\n")
	for i := range exp {
		temp := strings.Split(exp[i],"\t")
		Exp_Map[temp[0]] = temp[len(temp)-1]
	}
}


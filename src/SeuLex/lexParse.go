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

func ScanStart(lexFile string,outFile string)  {
	file, err := os.Open(lexFile)
	LexFile = file
	if err != nil {
		fmt.Println("打开Lex文件失败",err)
		return
	}
	file, err = os.Open(outFile)
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
			break
		}
		switch state {
			case 0:{
				if strings.HasPrefix(text,"%{") {
					state = 1
					_, errOut = writer.WriteString("//%{ start\n")
				}else if strings.HasPrefix(text,"%!") {
					state = 2
					_, errOut = writer.WriteString("//%! start\n")
				}else if strings.HasPrefix(text,"%%") {
					state = 3
					_, errOut = writer.WriteString("//%% start\n")
				}else if strings.HasPrefix(text,"//") {
					state = 4
				}else {
					state = 0
					if len(text) != 0 {
						fmt.Errorf(lineS+text+"error")
					}
				}
				if errOut != nil{
					fmt.Println(lineS + "写入失败")
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
					_, errOut = writer.WriteString(text+"\n")
				}
				if errOut != nil{
					fmt.Println(lineS + "写入失败")
				}
				break
			}
			case 2:{
				if strings.HasPrefix(text,"%!") {
					_, errOut = writer.WriteString("//%! end\n")
					errF := writer.Flush()
					if errF != nil {
						fmt.Println(lineS + "flush失败")
					}
					state = 0
				}else {
					getFunc(text,line)
				}
				break
			}
			case 3:{
				if strings.HasPrefix(text,"%%") {
					getRegular(outPut,line)
					_, errOut = writer.WriteString("//%% end\n")
					errF := writer.Flush()
					if errF != nil {
						fmt.Println(lineS + "flush失败")
					}
					state = 0
				}else if strings.HasPrefix(text,"%$") {
					getRegular(outPut,line)
					outPut = ""
				}else {
					outPut += text
				}
				break
			}
			case 4:{
				state = 0
				break
			}
			default:{
			fmt.Println(lineS + "结构不完整")
			break
			}
		}
		if state != 0 {
			fmt.Println(lineS + "结构不完整")
		}
	}

}

func getFunc(text string, line int)  {
	
}

func getRegular(outPut string,line int)  {
	
}

func getRegAndFunc()  {
	
}

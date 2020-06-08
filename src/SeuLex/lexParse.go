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

var def_Map map[string]string
var exp_Map map[string]string
var includeStr []string
var commentStr []string

//输入lex文件
func ScanStart(lexFile string) {

	def_Map = make(map[string]string)
	exp_Map = make(map[string]string)

	file, err := os.Open(lexFile)
	LexFile = file
	if err != nil {
		fmt.Println("打开Lex文件失败", err)
		return
	}

	defer LexFile.Close()
	scanner()
}

func scanner() {
	var state = 0
	var line = 0
	var lineS string
	var text, outPut string
	var errIn error
	var reader = bufio.NewReader(LexFile)
	for true {
		fmt.Println("读取到第" + strconv.Itoa(line) + "行")
		line++
		lineS = strconv.Itoa(line)
		text, errIn = reader.ReadString('\n')
		if errIn == io.EOF {
			fmt.Println("读取.lex文件完成")
			break
		}
		switch state {
		case 0:
			{
				if strings.HasPrefix(text, "%{") {
					state = 1
				} else if strings.HasPrefix(text, "%%") {
					state = 2
				} else if text == "\n" {
					break
				} else {
					arr := strings.Split(text, "\t")
					exTemp := strings.Split(arr[len(arr)-1], "\n")[0]
					if def_Map != nil {
						def_Map[arr[0]] = exTemp
					}
				}
				break
			}
		case 1:
			{
				if strings.HasPrefix(text, "%}") {
					state = 0
				} else {
					if strings.HasPrefix(text, "#") {
						includeStr = append(includeStr, text)
					} else {
						commentStr = append(commentStr, text)
					}
				}
				break
			}

		case 2:
			{
				if strings.HasPrefix(text, "%%") {
					getRegularAndFunc(outPut)
					state = 3
				} else if text == "\n" {
					break
				} else {
					outPut += text
				}
				break
			}
		case 3:
			{
				commentStr = append(commentStr, text)
				break
			}
		default:
			{
				fmt.Println(lineS + "结构不完整")
				break
			}
		}
	}
	if state != 3 {
		fmt.Println(lineS + "结构不完整")
	}

}

func getRegularAndFunc(outPut string) {
	exp := strings.Split(outPut, "\n")
	for i := range exp {
		temp := strings.Split(exp[i], "\t")
		replacedExp := ReplacePredefinedElements(temp[0])
		exp_Map[replacedExp] = temp[len(temp)-1]
	}
}

func EscapeQuotation(exp string) {
	input := strings.Split(exp, "")
	start := 0
	for start < len(input) {
		end := start + 1
		if input[start] == "\"" && input[start-1] != "\\" {
			for end < len(input) && !(input[end] == "\"" && input[end-1] != "\\") {
				end++
			}
		}
		head := input[0:start]
		tail := input[end+1:]
		for i := start; i < end; i++ {
			input[i] = "\\" + input[i]
		}
		fmt.Println(head)
		fmt.Println(tail)

	}
}

func ReplacePredefinedElements(exp string) string {
	replaced := exp
	flag := true
	for flag {
		flag = false
		for k := range def_Map {
			if strings.Index(replaced, k) != -1 {
				flag = true
				replaced = strings.ReplaceAll(replaced, k, def_Map[k])
			}
		}
	}
	return replaced
}

func GetInclude() []string {
	return includeStr
}

func GetComment() []string {
	return commentStr
}

func GetExpMap() map[string]string {
	return exp_Map
}

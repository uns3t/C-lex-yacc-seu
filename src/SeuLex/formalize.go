package SeuLex

import (
	"bytes"
	"encoding/binary"
	"encoding/hex"
	"strings"
)

var escape_Map = map[string]string{
	"+":  "\\+",
	"*":  "\\*",
	"•":  "\\•",
	"(":  "\\(",
	")":  "\\)",
	"[":  "\\[",
	"]":  "\\]",
	"-":  "\\-",
	"^":  "\\^",
	"?":  "\\?",
	"|":  "\\|",
	".":  "\\.",
	"\\": "\\\\"}

var escape_Map_Reverse = map[string]string{
	"\\+":  "+",
	"\\*":  "*",
	"\\•":  "•",
	"\\(":  "(",
	"\\)":  ")",
	"\\[":  "[",
	"\\]":  "]",
	"\\-":  "-",
	"\\^":  "^",
	"\\?":  "?",
	"\\|":  "|",
	"\\.":  ".",
	"\\\\": "\\"}

func unicodeTrans(code []string) string {
	bs, _ := hex.DecodeString(strings.Join(code, ""))
	r := 0
	binary.Read(bytes.NewReader(bs), binary.BigEndian, &r)
	return string(r)
}

func processUnicodeEscape(exp string) string {
	input := strings.Split(exp, "")
	start := 0
	escapMap := map[string]string{
		"t": "\t",
		"n": "\n",
		"b": "\b",
		"f": "\f",
		"v": "\v",
		"r": "\r",
		"s": " "}
	for start < len(input) {
		if input[start] == "\\" {
			if len(escapMap[input[start+1]]) != 0 {
				input[start] = ""
				input[start+1] = escapMap[input[start+1]]
			} else if input[start+1] == "u" {
				input[start] = unicodeTrans(input[start+2 : start+6])
				for i := 1; i < 6; i++ {
					input[start+i] = ""
				}
			}
		}
		start++
	}
	return strings.Join(input, "")
}

func processRegexEscape(exp string) []string {
	input := strings.Split(exp, "")
	start := 0
	for start < len(input) {
		if input[start] == "\\" {
			if len(escape_Map[input[start+1]]) != 0 {
				input[start] = escape_Map[input[start+1]]
				head := input[0 : start+1]
				tail := input[start+2:]
				input = append(head, tail...)
			}
		}
		start++
	}

	return input
}

/*
	解析.(a|b|c|...)
*/
func transformAllExp(exp string) string {
	input := processRegexEscape(exp)
	start := 0
	var charSet []string
	for i := 0; i < 127; i++ {
		c := string(i)
		if len(escape_Map[c]) != 0 {
			c = escape_Map[c]
		}
		charSet = append(charSet, c)
	}
	allChar := strings.Join(charSet, "|")
	allChar = "(" + allChar + ")"
	for start < len(input) {
		if input[start] == "." {
			input[start] = allChar
		}
		start++
	}
	return strings.Join(input, "")
}

/*
	解析[^] (a|b|c...)
*/
func transformNegRangeExp(exp string) string {
	input := processRegexEscape(exp)
	start := 0
	for start < len(input) {
		if input[start] == "[" && input[start+1] == "^" {
			end := start + 1
			for input[end] != "]" {
				end++
			}
			negCharSet := strings.Join(input[start+2:end], "")
			var charSet []string
			for i := 0; i < 127; i++ {
				c := string(i)
				if len(escape_Map[c]) != 0 {
					c = escape_Map[c]
				}
				if strings.Index(negCharSet, c) != -1 {
					continue
				}
				charSet = append(charSet, c)
			}
			negChar := strings.Join(charSet, "|")
			head := input[0:start]
			tail := input[end+1:]
			negChar = "(" + negChar + ")"
			input = append(append(head, negChar), tail...)
		}
		start++
	}
	return strings.Join(input, "")
}

/*
	解析[?-?] [a-z] (a|b
*/
func transformRangeExpAdvanced(exp string) string {
	input := processRegexEscape(exp)
	start := 0
	for start < len(input) {
		if input[start] == "[" {
			end := start
			for input[end] != "]" {
				end++
			}
			var rangeContent []string
			for i := start; i < end; i++ {
				if input[i] == "-" {
					rangeStart := input[i-1]
					if len(escape_Map_Reverse[rangeStart]) != 0 {
						rangeStart = escape_Map_Reverse[rangeStart]
					}
					rangeEnd := input[i+1]
					if len(escape_Map_Reverse[rangeEnd]) != 0 {
						rangeEnd = escape_Map_Reverse[rangeEnd]
					}
					charCode := int([]byte(rangeStart)[0])
					charCodeEnd := int([]byte(rangeEnd)[0])
					for ; charCode < charCodeEnd; charCode++ {
						char := string(charCode)
						if len(escape_Map[char]) != 0 {
							char = escape_Map[char]
						}
						rangeContent = append(rangeContent, char)
					}
				} else if i != start && i != end && input[i-1] != "-" && input[i+1] != "-" {
					rangeContent = append(rangeContent, input[i])
				}
			}
			rangeContentStr := "(" + strings.Join(rangeContent, "|") + ")"
			head := input[0:start]
			tail := input[end+1:]
			input = append(append(head, rangeContentStr), tail...)
		}
		start++
	}
	return strings.Join(input, "")
}

/*
	解析()+
*/
func transformOneOrMore(exp string) string {
	input := processRegexEscape(exp)
	pointer := 0
	for pointer < len(input) {
		if input[pointer] == "+" {
			end := pointer - 1
			start := end
			for i := 1; i > 0; {
				start--
				if start < 0 {
					panic("()+匹配出错")
				}
				if (start != 0 && input[start] == "(") || (start == 0 && input[start] == "(") {
					i--
				} else if (start != 0 && input[start] == ")") || (start == 0 && input[start] == ")") {
					i++
				}
			}
			head := input[0:start]
			tail := input[end+2:]
			content := strings.Join(input[start+1:end], "")
			content = "(" + content + ")•(" + content + ")?"
			input = append(append(head, content), tail...)
			pointer++
		} else {
			pointer++
		}
	}
	return strings.Join(input, "")
}

/*
	解析()?
*/
func transformZeroOrMore(exp string) string {
	input := processRegexEscape(exp)
	pointer := 0
	for pointer < len(input) {
		if input[pointer] == "?" {
			end := pointer - 1
			start := end
			for i := 1; i > 0; {
				start--
				if start < 0 {
					panic("()?匹配出错")
				}
				if (start != 0 && input[start] == "(") || (start == 0 && input[start] == "(") {
					i--
				} else if (start != 0 && input[start] == ")") || (start == 0 && input[start] == ")") {
					i++
				}
			}
			head := input[0:start]
			tail := input[end+2:]
			content := strings.Join(input[start+1:end], "")
			content = "(((" + content + ")*)|ø)"
			input = append(append(head, content), tail...)
			pointer++
		} else {
			pointer++
		}
	}
	return strings.Join(input, "")
}

/*
	转义字符恢复
*/
func escapeReverse(exp string) string {
	escapeMapReverse := map[string]string{
		"\\+": "+",
		"\\[": "[",
		"\\]": "]",
		"\\-": "-",
		"\\^": "^",
		"\\?": "?",
		"\\.": "."}
	input := processRegexEscape(exp)
	for i := range input {
		if len(escapeMapReverse[input[i]]) != 0 {
			input[i] = escapeMapReverse[input[i]]
		}
	}
	return strings.Join(input, "")
}

/*
	添加连接符号
*/
func addConnectPoint(exp string) string {
	input := processRegexEscape(exp)
	start := 0
	keyChar := "()|*•"
	for start < len(input)-1 {
		if !strings.Contains(keyChar, input[start]) && !strings.Contains(keyChar, input[start+1]) && len(input[start+1]) != 0 {
			var head, tail []string
			head = make([]string, len(input[0:start+1]))
			tail = make([]string, len(input[start+1:]))
			copy(head, input[0:start+1])
			copy(tail, input[start+1:])
			head = append(head, "•")
			input = append(head, tail...)
			start += 2
			continue
		} else if !strings.Contains(keyChar, input[start]) && input[start+1] == "(" && len(input[start+1]) != 0 {
			var head, tail []string
			head = make([]string, len(input[0:start+1]))
			tail = make([]string, len(input[start+1:]))
			copy(head, input[0:start+1])
			copy(tail, input[start+1:])
			head = append(head, "•")
			input = append(head, tail...)
			start += 2
			continue
		} else if input[start] == ")" && !strings.Contains(keyChar, input[start+1]) && len(input[start+1]) != 0 {
			var head, tail []string
			head = make([]string, len(input[0:start+1]))
			tail = make([]string, len(input[start+1:]))
			copy(head, input[0:start+1])
			copy(tail, input[start+1:])
			head = append(head, "•")
			input = append(head, tail...)
			start += 2
			continue
		} else if input[start] == ")" && input[start+1] == "(" && len(input[start+1]) != 0 {
			var head, tail []string
			head = make([]string, len(input[0:start+1]))
			tail = make([]string, len(input[start+1:]))
			copy(head, input[0:start+1])
			copy(tail, input[start+1:])
			head = append(head, "•")
			input = append(head, tail...)
			start += 2
			continue
		}
		start += 1
	}
	return strings.Join(input, "")
}

func Formalize(exp string) string {
	if strings.HasPrefix(exp, "\"") && strings.HasSuffix(exp, "\"") {
		return exp
	}
	return addConnectPoint(
		escapeReverse(
			transformZeroOrMore(
				transformOneOrMore(
					transformRangeExpAdvanced(
						transformNegRangeExp(
							transformAllExp(
								processUnicodeEscape(exp))))))))
}

func Test() {
	println(addConnectPoint(escapeReverse(transformZeroOrMore(
		transformOneOrMore(
			transformRangeExpAdvanced("0[xX]([a-fA-F0-9])+(((u|U)|(u|U)?(l|[a-zA-Z_]|ll|[a-zA-Z_][a-zA-Z_])|(l|[a-zA-Z_]|ll|[a-zA-Z_][a-zA-Z_])(u|U)))?"))))))
}

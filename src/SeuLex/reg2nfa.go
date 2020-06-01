package SeuLex

import (
	"C-lex-yacc-seu/src/stack"
	"strconv"
)

/*
实现 正则转nfa
1.把正则表达式转化为后缀表达式
2.把后缀表达式转化为NFA
*/

//实现 合并两个nfa
func merge(n1, n2 NState, cs1, cs2 map[int]string) (*NState, map[int]string) {
	n := NState{257, &n1, &n2, ""}
	for k, v := range cs2 {
		cs1[k] = v
	}
	return &n, cs1
}

//中缀表达式转后缀表达式
func Postfix(exp []string) *stack.Stack {
	//exp = processRegexEscape(exp)
	//exp为正则表达式转义处理后的结果

	var stack1 = stack.NewStack()
	var Output = stack.NewStack()
	var pointer = 0
	for pointer < len(exp) {
		// 运算符和左括号
		if exp[pointer] == "*" || exp[pointer] == "|" || exp[pointer] == "(" || exp[pointer] == "•" {
			stack1.Push(exp[pointer])
		} else if exp[pointer] == ")" && exp[pointer-1] != "\\" {
			// 右括号
			var top = stack1.Pop()
			for top != "(" {
				Output.Push(top)
				top = stack1.Pop()
			}
		} else {
			Output.Push(exp[pointer])
		}
		pointer++
	}

	//no idea
	for stack1.Len() > 0 {
		Output.Push(stack1.Pop())
	}
	return Output
	//返回类型待定
	//没有释放空间!!!
}

//后缀表达式转nfa
//每条正则语句对应于一条NFA
//形参得添加一个action(endFunction)
func Post2Nfa(post []string) (*NState, map[int]string) {
	LINK := 01
	Split := 257
	Match := 256

	println("Post2Nfa loading...")
	var funcStr string // 该NFA所对应的终止状态的处理函数, 该NFA所对应的结局
	var FragStack = stack.NewStack()
	var f, f1, f2 Fragment

	var charSet map[int]string

	if post == nil {
		return nil, nil
	}

	for p := 0; p < len(post); p++ {
		switch post[p] {
		//连接符, 对于两个Frag片段, 如果有连接符存在, 则进行连接操作对于正则表达式来说, 需要选择一个不会被用到的字符
		case strconv.Itoa(LINK):
			f2 = FragStack.Pop().(Fragment)
			f1 = FragStack.Pop().(Fragment)

			if f1.End.C == Split {
				//end默认为match;所以这个表示第二次连接(不可能出现)
				f1.End.Out2 = f2.Start
			} else {
				f1.End.C = Split
				f1.End.Out1 = f2.Start
			}
			FragStack.Push(Fragment{f1.Start, f2.End})
			break

		case "?":
			//可选的
			f = FragStack.Pop().(Fragment)
			End := NState{Match, nil, nil, ""}
			Start := NState{Split, f.Start, &End, ""}
			if f.End.C == Split {
				f.End.Out2 = &End
			} else {
				f.End.C = Split
				f.End.Out1 = &End
			}
			FragStack.Push(Fragment{&Start, &End})
			break

		case "|":
			f1 = FragStack.Pop().(Fragment)
			f2 = FragStack.Pop().(Fragment)
			Start := NState{Split, f1.Start, f2.Start, ""}
			End := NState{Match, nil, nil, ""}
			f1.End.C = Split
			f2.End.C = Split
			f1.End.Out1 = &End
			f2.End.Out1 = &End
			FragStack.Push(Fragment{&Start, &End})
			break

		case "*":
			f = FragStack.Pop().(Fragment)
			End := NState{Match, nil, nil, ""}
			Start := NState{Split, f.Start, &End, ""}
			f.End.C = Split
			f.End.Out1 = f.Start
			f.End.Out2 = &End
			FragStack.Push(Fragment{&Start, &End})
			break

		case "+":
			f = FragStack.Pop().(Fragment)
			Start := NState{Split, f.Start, nil, ""}
			End := NState{Match, nil, nil, ""}
			f.End.C = Split
			f.End.Out1 = f.Start
			f.End.Out2 = &End
			FragStack.Push(Fragment{&Start, &End})
			break

		case "\\":
			//转义字符
			p++
			End := NState{Match, nil, nil, ""}
			i, _ := strconv.Atoi(post[p])
			Start := NState{i, &End, nil, ""}
			charSet[p] = strconv.Itoa(p)
			FragStack.Push(Fragment{&Start, &End})
			break

		default:
			End := NState{Match, nil, nil, ""}
			i, _ := strconv.Atoi(post[p])
			Start := NState{i, &End, nil, ""}
			charSet[i] = post[p]
			FragStack.Push(Fragment{&Start, &End})
			break
		}
	}
	f = FragStack.Pop().(Fragment)
	//f已经是个完整的nfa自动机

	// 如果栈中仍然存在其余元素, 则不匹配
	if FragStack.Len() != 0 {
		println("error occurred;FragStack非空\n")
		//this->showNFA(e.Start);
	}

	if f.End.C == Match {
		f.End.EndFunc = funcStr
	} else {
		End := NState{Match, nil, nil, funcStr}
		f.End.Out1 = &End
		f.End = &End
	}

	nfaS := f.Start
	//nfa_e := f.End

	return nfaS, charSet
}

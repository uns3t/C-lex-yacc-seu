package SeuLex

import (
	"fmt"
	"stack"
	"strconv"
)

/*
实现 正则转nfa
1.把正则表达式转化为后缀表达式
2.把后缀表达式转化为NFA
*/

//实现 合并两个nfa
func merge(n1, n2 *NState) *NState {
	n := NState{888888, 257, n1, n2, ""}
	return &n
}

//中缀表达式转后缀表达式
func Postfix(exp []string) []string {

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

	for stack1.Len() > 0 {
		Output.Push(stack1.Pop())
	}

	//stack 转 []string
	var OutputStr []string
	var flag = true
	for flag {
		outputTop := Output.Pop()
		switch outputTop.(type) {
		case string:
			OutputStr = append(OutputStr, outputTop.(string))
			break
		}
		if Output.Len() == 0 {
			flag = false
		}
	}
	for i, j := 0, len(OutputStr)-1; i < j; i, j = i+1, j-1 {
		OutputStr[i], OutputStr[j] = OutputStr[j], OutputStr[i]
	}
	return OutputStr
}

//后缀表达式转nfa
//每条正则语句对应于一条NFA
//funcStr string 该NFA所对应的终止状态的处理函数, 该NFA所对应的结局
func Post2Nfa(post []string, funcStr string) (*NState, map[int]*NState) {
	//连接符
	LINK := 01
	Split := 257
	Match := 256

	fmt.Println("Post2Nfa loading...")

	stateId := 0
	var FragStack = stack.NewStack()
	var f, f1, f2 Fragment
	id2state := make(map[int]*NState)

	if post == nil {
		return nil, nil
	}

	for p := 0; p < len(post); p++ {
		switch post[p] {
		//连接符, 对于两个Frag片段, 如果有连接符存在, 则进行连接操作对于正则表达式来说, 需要选择一个不会被用到的字符
		case string(LINK):
			f2 = FragStack.Pop().(Fragment)
			f1 = FragStack.Pop().(Fragment)

			f1.End.C = Split
			f1.End.Out1 = f2.Start

			FragStack.Push(Fragment{f1.Start, f2.End})
			break

		case "?":
			//可选的
			f = FragStack.Pop().(Fragment)
			End := NState{stateId, Match, nil, nil, ""}
			id2state[stateId] = &End
			stateId++
			Start := NState{stateId, Split, f.Start, &End, ""}
			id2state[stateId] = &Start
			stateId++

			f.End.C = Split
			f.End.Out1 = &End

			FragStack.Push(Fragment{&Start, &End})
			break

		case "|":
			f1 = FragStack.Pop().(Fragment)

			f2 = FragStack.Pop().(Fragment)
			//fTemp := FragStack.Pop()
			//if fTemp==nil {
			//	fmt.Println(funcStr)
			//}else {
			//	f2=fTemp.(Fragment)
			//}

			Start := NState{stateId, Split, f1.Start, f2.Start, ""}
			id2state[stateId] = &Start
			stateId++
			End := NState{stateId, Match, nil, nil, ""}
			id2state[stateId] = &End
			stateId++

			f1.End.C = Split
			f2.End.C = Split
			f1.End.Out1 = &End
			f2.End.Out1 = &End

			FragStack.Push(Fragment{&Start, &End})
			break

		case "*":
			f = FragStack.Pop().(Fragment)
			End := NState{stateId, Match, nil, nil, ""}
			id2state[stateId] = &End
			stateId++
			Start := NState{stateId, Split, f.Start, &End, ""}
			id2state[stateId] = &Start
			stateId++

			f.End.C = Split
			f.End.Out1 = f.Start
			f.End.Out2 = &End

			FragStack.Push(Fragment{&Start, &End})
			break

		case "+":
			f = FragStack.Pop().(Fragment)
			Start := NState{stateId, Split, f.Start, nil, ""}
			id2state[stateId] = &Start
			stateId++
			End := NState{stateId, Match, nil, nil, ""}
			id2state[stateId] = &End
			stateId++

			f.End.C = Split
			f.End.Out1 = f.Start
			f.End.Out2 = &End

			FragStack.Push(Fragment{&Start, &End})
			break

		case "\\":
			//转义字符
			p++
			End := NState{stateId, Match, nil, nil, ""}
			id2state[stateId] = &End
			stateId++
			Start := NState{stateId, int(post[p][0]), &End, nil, ""}
			id2state[stateId] = &Start
			stateId++
			FragStack.Push(Fragment{&Start, &End})
			break

		default:
			End := NState{stateId, Match, nil, nil, ""}
			id2state[stateId] = &End
			stateId++
			Start := NState{stateId, int(post[p][0]), &End, nil, ""}
			id2state[stateId] = &Start
			stateId++
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
		End := NState{stateId, Match, nil, nil, funcStr}
		id2state[stateId] = &End
		stateId++
		f.End.C = Split
		f.End.Out1 = &End
		f.End = &End
	}
	fmt.Println("起始状态stateId" + strconv.Itoa(f.Start.StateId))
	return f.Start, id2state

}

func PrintNfa(id2state map[int]*NState) {
	for stateId, state := range id2state {
		fmt.Print("StateId:" + strconv.Itoa(stateId) + ";  ")
		fmt.Print("C:" + strconv.Itoa(state.C) + ";  ")
		if state.Out1 != nil {
			fmt.Print("Out1:" + strconv.Itoa(state.Out1.StateId) + ";  ")
		}
		if state.Out2 != nil {
			fmt.Print("Out2:" + strconv.Itoa(state.Out2.StateId) + ";  ")
		}
		if state.EndFunc != "" {
			fmt.Println("EndFunc:" + state.EndFunc + ";  ")
		} else {
			fmt.Println("null EndFunc;  ")
		}
	}
}

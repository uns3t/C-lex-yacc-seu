package SeuLex

import (
	"stack"
	"strconv"
)

/*
实现 正则转nfa
1.把正则表达式转化为后缀表达式
2.把后缀表达式转化为NFA
*/

//实现 合并nfa

//const { processRegexEscape } = require('./formalize')

//中缀表达式转后缀表达式
func Postfix(exp []string) *stack.Stack {
	//exp = processRegexEscape(exp)
	var stack1 = stack.NewStack()
	var output = stack.NewStack()
	var pointer = 0
	for pointer < len(exp) {
		// 运算符和左括号
		if exp[pointer] == "*" || exp[pointer] == "|" || exp[pointer] == "(" || exp[pointer] == "•" {
			stack1.Push(exp[pointer])
		} else if exp[pointer] == ")" && exp[pointer-1] != "\\" {
			// 右括号
			var top = stack1.Pop()
			for top != "(" {
				output.Push(top)
				top = stack1.Pop()
			}
		} else {
			output.Push(exp[pointer])
		}
		pointer++
	}

	//no idea
	for stack1.Len() > 0 {
		output.Push(stack1.Pop())
	}
	return output
	//返回类型待定
	//没有释放空间!!!
}

//后缀表达式转nfa
//每条正则语句对应于一条NFA
func Post2Nfa(post []string) *NState {
	println("Post2Nfa loading...")
	var funcStr string // 该NFA所对应的终止状态的处理函数, 该NFA所对应的结局
	Split := 257
	Match := 256
	var FragStack = stack.NewStack()
	var f, f1, f2 Fragment
	if post == nil {
		return nil
	}

	for p := 0; p < len(post); p++ {
		switch post[p] {
		//连接符, 对于两个Frag片段, 如果有连接符存在, 则进行连接操作对于正则表达式来说, 需要选择一个不会被用到的字符
		case "LINK":
			f2 = FragStack.Pop().(Fragment)
			f1 = FragStack.Pop().(Fragment)

			if f1.end.c == Split {
				f1.end.out1 = f2.start
			} else {
				f1.end.c = Split
				f1.end.out1 = f2.start
			}
			FragStack.Push(Fragment{f1.start, f2.end})
			break

		case "?":
			//可选的
			f = FragStack.Pop().(Fragment)
			end := NState{Match, nil, nil, ""}
			start := NState{Split, f.start, &end, ""}
			if f.end.c == Split {
				f.end.out1 = &end
			} else {
				f.end.c = Split
				f.end.out2 = &end
			}
			FragStack.Push(Fragment{&start, &end})
			break

		case "|":
			f1 = FragStack.Pop().(Fragment)
			f2 = FragStack.Pop().(Fragment)
			start := NState{Split, f1.start, f2.start, ""}
			end := NState{Match, nil, nil, ""}
			f1.end.c = Split
			f2.end.c = Split
			f1.end.out2 = &end
			f2.end.out2 = &end
			FragStack.Push(Fragment{&start, &end})
			break

		case "*":
			f = FragStack.Pop().(Fragment)
			end := NState{Match, nil, nil, ""}
			start := NState{Split, f.start, &end, ""}
			f.end.c = Split
			f.end.out2 = f.start
			f.end.out1 = &end
			FragStack.Push(Fragment{&start, &end})
			break

		case "+":
			f = FragStack.Pop().(Fragment)
			start := NState{Split, f.start, nil, ""}
			end := NState{Match, nil, nil, ""}
			f.end.c = Split
			f.end.out2 = f.start
			f.end.out1 = &end
			FragStack.Push(Fragment{&start, &end})
			break

		case "\\":
			p++
			end := NState{Match, nil, nil, ""}
			i, _ := strconv.Atoi(post[p])
			start := NState{i, &end, nil, ""}
			//char_set.insert(*p)
			FragStack.Push(Fragment{&start, &end})
			break

		default:
			end := NState{Match, nil, nil, ""}
			i, _ := strconv.Atoi(post[p])
			start := NState{i, &end, nil, ""}
			//char_set.insert(*p)
			FragStack.Push(Fragment{&start, &end})
			break
		}
	}
	f = FragStack.Pop().(Fragment)

	// 如果栈中仍然存在其余元素, 则不匹配
	// 这里还有点问题
	if FragStack.Len() != 0 {
		println("error occurred\n")
		//this->showNFA(e.start);
	}

	if f.end.c == Match {
		//e.end->out1 = end;
		//printf ( "already matched\n" );
		f.end.endFunc = funcStr
	} else {
		end := NState{Match, nil, nil, ""}
		end.endFunc = funcStr
		f.end.out1 = &end
		f.end = &end
	}

	nfa_s := f.start
	//nfa_e := f.end

	return nfa_s
}

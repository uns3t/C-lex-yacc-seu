package SeuLex

import "C-lex-yacc-seu/src/stack"
/*
实现 正则转nfa
1.把正则表达式转化为后缀表达式
2.把后缀表达式转化为NFA
*/

//实现 合并nfa


//const { processRegexEscape } = require('./formalize')

//中缀表达式转后缀表达式
func postfix(exp []string) *stack.Stack {
	//input = processRegexEscape(exp)
	input := exp
	var stack1 = stack.NewStack()
	var output = stack.NewStack()
	var pointer = 0
	for pointer < len(input) {
		// 运算符和左括号
		if input[pointer] == "*" || input[pointer] == "|" || input[pointer] == "(" || input[pointer] == "•" {
			stack1.Push(input[pointer])
		} else if input[pointer] == ")" && input[pointer-1] != "\\" {
			// 右括号
			var top = stack1.Pop().(string)
			for top != "(" {
				output.Push(top)
				top = stack1.Pop().(string)
			}
		} else {
			output.Push(input[pointer])
		}
		pointer++
	}
	for stack1.Size() > 0 {
		output.Push(stack1.Pop().(string))
	}
	return output
	//返回类型待定
	//没有释放空间!!!
}

//后缀表达式转nfa
//stateBias int, endName, action不知道啥类型
func thompson(postfixExp []string, stateBias int, endName string, action string) {
	var automaStack = stack.NewStack()
	var stateNo = stateBias
	var pointer = 0
	for pointer < len(postfixExp) {
		if postfixExp[pointer] == "|" {
			var top_1 = automaStack.Pop()
			var top_2 = automaStack.Pop()
			stateNo++
			var startState = stateNo
			stateNo++
			var endState = stateNo
			//var automa = {
			//start: `S${startState}`,
			//end: `S${endState}`
			//}
			//自动机的开始状态和终止状态
			automa.stateList = ([automa.start, automa.end]).concat(top_1.stateList, top_2.stateList)
automa[automa.start] ={'ø':[top_1.start, top_2.start]}
automa[automa.end] = {'ø':[]}
top_1.stateList.forEach(k = > {
automa[k] = top_1[k]
})
top_2.stateList.forEach(k => {
automa[k] = top_2[k]
})
automa[top_1.end]['ø'].push(automa.end)
automa[top_2.end]['ø'].push(automa.end)
automaStack.push(automa)
pointer+=1
continue
}
if (postfixExp[pointer]== = '*'){
var top = automaStack.pop()
var startState = stateNo++
var endState = stateNo++
var automa = {
start: `S${startState}`,
end: `S${endState}`
}
automa.stateList = ([automa.start, automa.end]).concat(top.stateList)
automa[automa.end] = {'ø':[]}
automa[automa.start] ={'ø':[top.start, automa.end]}
top.stateList.forEach(k = > {
automa[k] = top[k]
})
automa[top.end]['ø'].push(top.start, automa.end)
automaStack.push(automa)
pointer+=1
continue
}
if (postfixExp[pointer]== = '•'){
var top_2 = automaStack.pop()
var top_1 = automaStack.pop()
var startState = stateNo++
var endState = stateNo++
var automa = {
start: `S${startState}`,
end: `S${endState}`
}
automa.stateList = ([automa.start, automa.end]).concat(top_1.stateList, top_2.stateList)
automa[automa.start] ={'ø':[top_1.start]}
automa[automa.end] = {'ø':[]}
top_1.stateList.forEach(k = > {
automa[k] = top_1[k]
})
top_2.stateList.forEach(k => {
automa[k] = top_2[k]
})
automa[top_1.end]['ø'].push(top_2.start)
automa[top_2.end]['ø'].push(automa.end)
automaStack.push(automa)
pointer+=1
continue
}
// 执行到此处，表明是普通字符
var startState = stateNo++
var endState = stateNo++
var automa = {
start: `S${startState}`,
end: `S${endState}`,
}
automa.stateList = [automa.start, automa.end]
automa[automa.start] = {'ø':[]}
automa[automa.end] = {'ø':[]}
automa[automa.start][postfixExp[pointer].slice(-1)] = automa.end // 把转译字符恢复
automaStack.push(automa)
pointer += 1
}
if (automaStack.length != = 1){
throw Error('Thompson算法构造NFA出错')
}
var automa = automaStack[0]
automa.stateList = automa.stateList.sort((a, b) = >{
a = parseInt(a.slice(1))
b = parseInt(b.slice(1))
return a-b
})
var endState = {}
endState[automa.end] = { name:endName, action }
automa.end = [endState]
automa.nextBias = stateNo
var alphabet = {}
automa.stateList.forEach( k => {
var subAlphabet = Object.keys(automa[k])
subAlphabet.forEach( l = > {
if (l!= = 'ø'){
alphabet[l] = true
}
})
})
alphabet = Object.keys(alphabet)
automa.alphabet = alphabet
return automa
}

//module.exports = {postfix, thompson}
//console.log(thompson(postfix('\\a•b'), 0, 'test'))
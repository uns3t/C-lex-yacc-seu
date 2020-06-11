package SeuLex

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func Dfa2Cpp(id2DState map[int]*DState, id2DStateK map[int]*DState, userDefineHead string, userDefineProgram string) {

	head := userDefineHead
	head += `
    #include <iostream>
    #include <string>
    #include <fstream>
    #include <streambuf>
    
    std::string inputSrc;
    
    int cp = 0;
    int state = 0;
	int keyState=0;//关键字对应的state
    
    void dfa(char c);

    int main(int argc, const char * argv[]) {
        std::ifstream f(argv[1]);
        std::string str((std::istreambuf_iterator<char>(f)),
                        std::istreambuf_iterator<char>());
        inputSrc = str;
        while (cp < inputSrc.length()) {
            try {
                dfa(inputSrc[cp]);
            } catch(int e) {
                std::cout << "出现错误";
                break;
            }
        }
        return 0;
    }
	`
	head += userDefineProgram

	//关键字对应的第二层switch
	//对于cp++如何处理    思考...
	var coreOutputK = make([]string, 0)
	var codeK string
	for dStateId, dState := range id2DStateK {
		codeK = "\tcase " + strconv.Itoa(dStateId) + ":\n\tswitch (c) {\n"
		coreOutputK = append(coreOutputK, codeK)

		for outC, outDState := range dState.Out {
			codeK = "\t\tcase '" + string(outC) + "':\n" +
				"\t\t\tkeyState=" + strconv.Itoa(outDState.StateId) + ";\n" +
				"\t\t\tbreak;\n"
			coreOutputK = append(coreOutputK, codeK)
		}
		if dState.IsEnd {
			//EndFunc
			codeK = "\t\tdefault:\n" +
				"\t\t\t" + dState.EndFunc +
				"\t\t\tprintf(\"\\n\");\n" +
				"\t\t\tkeyState = 0;\n" +
				"\t\t\tbreak;\n" +
				"}\n"
			coreOutputK = append(coreOutputK, codeK)
		} else {
			codeK = "\t\tdefault:\n" +
				"\t\t\tprintf(\"Keywords ERROR! 不是关键字\");\n" +
				"\t\t\tkeyState = 0;\n" +
				"\t\t\tbreak;\n" +
				"}"
			coreOutputK = append(coreOutputK, codeK)
		}
		codeK = "\tbreak;\n"
		coreOutputK = append(coreOutputK, codeK)
	}

	var coreOutput = make([]string, 0)
	var code string
	for dStateId, dState := range id2DState {
		code = "\tcase " + strconv.Itoa(dStateId) + ":\n\tswitch (c) {\n"
		coreOutput = append(coreOutput, code)

		for outC, outDState := range dState.Out {
			code = "\t\tcase '" + string(outC) + "':\n" +
				"\t\t\tstate=" + strconv.Itoa(outDState.StateId) + ";\n" +
				"\t\t\tcp++;\n" +
				"\t\t\tbreak;\n"
			coreOutput = append(coreOutput, code)
		}
		if dState.IsEnd {
			//EndFunc
			code = "\t\tdefault:\n" +
				"\t\t\t" + dState.EndFunc +
				"\t\t\tprintf(\"\\n\");\n" +
				"\t\t\tstate = 0;\n" +
				"\t\t\tbreak;\n" +
				"}\n"
			coreOutput = append(coreOutput, code)
		} else {
			code = "\t\tdefault:\n" +
				"\t\t\tprintf(\"ERROR!\");\n" +
				"\t\t\tstate = 0;\n" +
				"\t\t\tthrow 2;\n" +
				"\t\t\tbreak;\n" +
				"}"
			coreOutput = append(coreOutput, code)
		}
		code = "\tbreak;\n"
		coreOutput = append(coreOutput, code)
	}

	var dfaOutput = make([]string, 5)
	dfaOutput[0] = `
 	void dfa(char c){
		switch(keyState){
    `
	dfaOutput[1] = strings.Join(coreOutputK, "\n")
	dfaOutput[2] = `
			default:
                break;
        }
		switch(state){
	`
	dfaOutput[3] = strings.Join(coreOutput, "\n")
	dfaOutput[4] = `
			default:
                throw 1;
                break;
        }
    }
    `
	dfaOutputStr := strings.Join(dfaOutput, "\n")

	//写入lex.c
	f, err := os.Create("lex.cpp")
	if err != nil {
		fmt.Println(err)
		return
	}
	l, err := f.WriteString(head + "\n" + dfaOutputStr + "\n")
	if err != nil {
		fmt.Println(err)
		f.Close()
		return
	}
	fmt.Println(l, "LEX written successfully")
	err = f.Close()
	if err != nil {
		fmt.Println(err)
		return
	}
}

//userDefineProgram!!

//import (
//	"fmt"
//	"os"
//	"strconv"
//)
//
//var dfaString string
//
////将此作为DNodeId
//func getIndex(dNodes []*DNode, dNode *DNode) int {
//	for k, v := range dNodes {
//		if v == dNode {
//			return k
//		}
//	}
//	return -1
//}
//
//func Dfa2c(dNodes []*DNode) {
//	stateNum := 0
//	lexFile, err := os.OpenFile("./output/testLex.c", os.O_APPEND|os.O_WRONLY, 0)
//	if err != nil {
//		fmt.Println("打开Out文件失败", err)
//		return
//	}
//	dfaString = "\n\tswitch (stateNum) {\n"
//	//for i:=0;i<len(dNodes);i++{
//	//	if dNodes[i].isEnd{
//	//		dfaString=dfaString+"\n\tdefault:\n\t\tbreak;}"
//	//	}else {
//	//		for j:=0;j<len(dNodes[i].DOut);j++{
//	//			dfaString=dfaString+"\t\tcase '"+string(dNodes[i].DOut[j].C)+"':\n"+"\t\tbreak;\n"
//	//		}
//	//	}
//	//}
//
//	for k, v := range dNodes {
//		str := "case " + strconv.Itoa(k) + ":{\n" + "switch (c){\n"
//		for _, d := range v.DOut {
//			idx := getIndex(dNodes, d)
//			str += "case " + string(d.C) + ":{\nstateNum=" + strconv.Itoa(idx) + ";\n+break;\n"
//		}
//		str += "\n\tdefault:\n\t\tbreak;}"
//		dfaString += str
//	}
//
//	fullOutput := `
//   int stateNum=0;
//   void dfa(char c);
//
//   int main(int argc, const char * argv[]) {
//		fp = fopen(argv[1], "r");
//       while (1) {
//			if(feof(fp)) break;
//			char buf;
//			fscanf(fp,"%c",buf)
//           try {
//               dfa(buf);
//           } catch(int e) {
//               printf("出现错误")
//               break;
//           }
//       }
//       return 0;
//   }
//
//   void dfa(char c){` + dfaString + `
//   }
//   `
//	lexFile.WriteString(fullOutput)
//	fmt.Println("写入lex.c完成")
//	defer lexFile.Close()
//}

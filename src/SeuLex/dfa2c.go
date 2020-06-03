package SeuLex

import (
	"fmt"
	"os"
	"strconv"
)

var dfaString string

//将此作为DNodeId
func getIndex(dNodes []*DNode, dNode *DNode) int {
	for k, v := range dNodes {
		if v == dNode {
			return k
		}
	}
	return -1
}

func Dfa2c(dNodes []*DNode) {
	stateNum := 0
	lexFile, err := os.OpenFile("./output/test.c", os.O_APPEND|os.O_WRONLY, 0)
	if err != nil {
		fmt.Println("打开Out文件失败", err)
		return
	}
	dfaString = "\n\tswitch (stateNum) {\n"
	//for i:=0;i<len(dNodes);i++{
	//	if dNodes[i].isEnd{
	//		dfaString=dfaString+"\n\tdefault:\n\t\tbreak;}"
	//	}else {
	//		for j:=0;j<len(dNodes[i].DOut);j++{
	//			dfaString=dfaString+"\t\tcase '"+string(dNodes[i].DOut[j].C)+"':\n"+"\t\tbreak;\n"
	//		}
	//	}
	//}

	for k, v := range dNodes {
		str := "case " + strconv.Itoa(k) + ":{\n" + "switch (c){\n"
		for _, d := range v.DOut {
			idx := getIndex(dNodes, d)
			str += "case " + string(d.C) + ":{\nstateNum=" + strconv.Itoa(idx) + ";\n+break;\n"
		}
		str += "\n\tdefault:\n\t\tbreak;}"
		dfaString += str
	}

	fullOutput := `
   int stateNum=0;
   void dfa(char c);

   int main(int argc, const char * argv[]) {
		fp = fopen(argv[1], "r");
       while (1) {
			if(feof(fp)) break;
			char buf;
			fscanf(fp,"%c",buf)
           try {
               dfa(buf);
           } catch(int e) {
               printf("出现错误")
               break;
           }
       }
       return 0;
   }

   void dfa(char c){` + dfaString + `
   }
   `
	lexFile.WriteString(fullOutput)
	fmt.Println("写入lex.c完成")
	defer lexFile.Close()
}

package SeuLex

import (
	"fmt"
	"os"
	"strconv"
)

var dfaString string

func findIndex(dArr []Dnode,dnode Dnode)int{
	for k,_:=range dArr{
		if dArr[k]==dnode{
			return k
		}
	}
	return -1
}


func Dfa2c(dArr []Dnode)  {
	stateNum:=0
	lexFile,err:=os.OpenFile("./output/test.c",os.O_APPEND|os.O_WRONLY, 0)
	if err != nil {
		fmt.Println("打开Out文件失败",err)
		return
	}
	dfaString="\n\tswitch (stateNum) {\n"
	//for i:=0;i<len(dArr);i++{
	//	if dArr[i].isEnd{
	//		dfaString=dfaString+"\n\tdefault:\n\t\tbreak;}"
	//	}else {
	//		for j:=0;j<len(dArr[i].Dout);j++{
	//			dfaString=dfaString+"\t\tcase '"+string(dArr[i].Dout[j].C)+"':\n"+"\t\tbreak;\n"
	//		}
	//	}
	//}

	for k,v:=range dArr{
		str:="case "+strconv.Itoa(k)+":{\n"+"switch (c){\n"
		for _,d:=range v.Dout{
			idx:=findIndex(dArr,d)
			str+="case "+string(d.C)+":{\nstateNum="+strconv.Itoa(idx)+";\n+break;\n"
		}
		str+="\n\tdefault:\n\t\tbreak;}"
		dfaString+=str
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
    
    void dfa(char c){`+dfaString+`
    }
    `
	lexFile.WriteString(fullOutput)
	fmt.Println("写入lex.c完成")
	defer lexFile.Close()
}
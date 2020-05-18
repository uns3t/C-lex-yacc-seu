package SeuLex

import (
	"fmt"
	"os"
)


func Dfa2c(dArr []Dnode)  {
	lexFile,_:=os.Create("lex.c")

	fullOutput := `
  
    int cp = 0;
    int state = 0;
    
    void dfa(char c);
    
    ${dfa.userDefineProgram}

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
    
    void dfa(char c){
        switch(state){
            ${coreOutput.join('\n')}
            default:
                throw 1;
                break;
        }
    }
    `
	lexFile.WriteString(fullOutput)
	fmt.Println("写入lex.c完成")
}
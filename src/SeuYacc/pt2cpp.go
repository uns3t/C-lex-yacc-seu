package SeuYacc

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

//parsing table to cpp

func ParsingTableToCpp(parsingTable map[int]*ActionAndGoto, grammar Grammar) {
	head := `#include <iostream>
    #include <fstream>
    #include <vector>
    #include <string>
    
    std::vector<std::string> inputBuf;
    std::vector<int> stateStack;
    std::vector<std::string> symbolStack;
    int reader = 0;
    
    std::string a;
    int s;
    
    void lrParsing();
    
    int actionTable(int s, std::string a);
    int gotoTable(int t, std::string vn);
    
    int main(int argc, const char * argv[]) {
        std::ifstream f(argv[1]);
        std::string s;
        while(getline(f, s)){
            inputBuf.push_back(s);
        }
        inputBuf.push_back("$");
        stateStack.push_back(0);
        lrParsing();
        return 0;
    }
    
    void lrParsing() {
        a = inputBuf[0];
        while(1){
            s = stateStack.back();
            switch (actionTable(s, a)) {
                case 1:
                    std::cout<<"success!"<<std::endl;
                    return;
                case -1:
                    std::cout<<"error!"<<std::endl;
                    return;
                default:
                    break;
            }
        }
    }
    
    void S(int state){
        stateStack.push_back(state);
        symbolStack.push_back(inputBuf[reader]);
        a = inputBuf[++reader];
    }
    
    void r(int length, std::string vn){
        for(int i = 0; i < length; i++){
            stateStack.pop_back();
            symbolStack.pop_back();
        }
        int t = stateStack.back();
        stateStack.push_back(gotoTable(t, vn));
        symbolStack.push_back(vn);
    }
    `

	var actionTableItem []string
	var gotoTableItem []string
	var code string

	for stateId, ActionAndGoto := range parsingTable {
		//action部分转换
		var actions []string
		for vt, job := range ActionAndGoto.actionTable {
			if strings.HasPrefix(job, "S") {
				code = "if ( a ==\" " + vt + "\" )\n {\n S(" + strconv.Itoa(stateId) + ");\n return 0;\n }"
				actions = append(actions, code)
			} else if job == "r0" {
				code = "if ( a == \"" + vt + "\" ) {\n return 1;\n }"
				actions = append(actions, code)
			} else if strings.HasPrefix(job, "r") {
				job1 := string([]byte(job)[1:])
				leftPart := getLeftPart(grammar, job1)
				rightPart := getRightPart(grammar, job1)
				code = "if ( a == \"" + vt + "\")\n {\n  r(" + strconv.Itoa(len(rightPart)) + ",\"" + leftPart + "\");" +
					"" + " return 0;\n }"
				code += "std::cout << \"归约：\" << \"" + leftPart + "\" => \" << \"" + strings.Join(rightPart, " ") + "\" << std::endl;\n"
				actions = append(actions, code)
			}
		}
		code = "case " + strconv.Itoa(stateId) + ":\n" + strings.Join(actions, "\n") + "\nreturn -1;"
		actionTableItem = append(actionTableItem, code)

		// goto部分转换
		var gotos []string
		for vn, job := range ActionAndGoto.gotoTable {
			code = " if (vn == \"" + vn + "\") \n return " + strconv.Itoa(job) + ";"
			gotos = append(gotos, code)
		}
		code = "case" + strconv.Itoa(stateId) + ":\n" + strings.Join(gotos, "\n") + "\nreturn -1;"
		gotoTableItem = append(gotoTableItem, code)

	}

	var actionTableOutput = make([]string, 3)
	actionTableOutput[0] = `
    int actionTable(int s, std::string a) {
        switch (s) {
	`
	actionTableOutput[1] = strings.Join(actionTableItem, "\n")

	actionTableOutput[2] = `
            default:
                return -1;
        }
    }
    `
	actionTableOutputStr := strings.Join(actionTableOutput, "\n")

	var gotoTableOutput = make([]string, 3)
	gotoTableOutput[0] = `
    int gotoTable(int t, std::string vn) {
        switch (t) {
	`
	gotoTableOutput[1] = strings.Join(gotoTableItem, "\n")
	gotoTableOutput[2] = `
			default:
                return -1;
        }
    }
    `
	gotoTableOutputStr := strings.Join(gotoTableOutput, "\n")

	//写入yacc.c
	f, err := os.Create("yacc.cpp")
	if err != nil {
		fmt.Println(err)
		return
	}
	l, err := f.WriteString(head + "\n" + actionTableOutputStr + "\n" + gotoTableOutputStr)
	if err != nil {
		fmt.Println(err)
		f.Close()
		return
	}
	fmt.Println(l, "YACC written successfully")
	err = f.Close()
	if err != nil {
		fmt.Println(err)
		return
	}
}

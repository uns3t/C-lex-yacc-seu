
	#include <iostream>
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
    

    int actionTable(int s, std::string a) {
        switch (s) {
	
case 65:
if ( a == "TYPE_NAME")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "INLINE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "DOUBLE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "FLOAT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "UNION")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "LONG")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "SIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "ENUM")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "STATIC")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "CONST")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "CHAR")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "IMAGINARY")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "REGISTER")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "SHORT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "UNSIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "VOID")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" STRUCT" )
 {
 S(65);
 return 0;
 }
if ( a == "TYPEDEF")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "EXTERN")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "RESTRICT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "AUTO")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "BOOL")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "VOLATILE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "COMPLEX")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "INT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 31:
if ( a == "IMAGINARY")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 6:
if ( a == "ENUM")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 37:
if ( a == "UNION")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "AUTO")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "VOLATILE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "UNSIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "SIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "FLOAT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "EXTERN")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "DOUBLE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "CONST")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "REGISTER")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "ENUM")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "t")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" CHAR" )
 {
 S(37);
 return 0;
 }
if ( a == "SHORT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "TYPE_NAME")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "INT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "STATIC")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" VOID" )
 {
 S(37);
 return 0;
 }
if ( a == "TYPEDEF")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "LONG")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" STRUCT" )
 {
 S(37);
 return 0;
 }
if ( a == "IMAGINARY")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" INLINE" )
 {
 S(37);
 return 0;
 }
if ( a == "BOOL")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" RESTRICT" )
 {
 S(37);
 return 0;
 }
if ( a == "COMPLEX")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 47:
if ( a == "UNSIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 60:
if ( a == "VOID")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 59:
if ( a == "DOUBLE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 32:
if ( a == "TYPE_NAME")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 26:
if ( a == "UNSIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 41:
if ( a == "UNION")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" STRUCT" )
 {
 S(41);
 return 0;
 }
return -1;
case 49:
if ( a ==" STRUCT" )
 {
 S(49);
 return 0;
 }
if ( a == "UNION")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 56:
if ( a == "ENUM")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 72:
if ( a == "CONST")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "BOOL")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "FLOAT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "AUTO")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "DOUBLE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" STRUCT" )
 {
 S(72);
 return 0;
 }
if ( a == "STATIC")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "UNION")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "REGISTER")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "SIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "TYPE_NAME")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "LONG")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" INLINE" )
 {
 S(72);
 return 0;
 }
if ( a == "INT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" CHAR" )
 {
 S(72);
 return 0;
 }
if ( a == "VOLATILE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" RESTRICT" )
 {
 S(72);
 return 0;
 }
if ( a == "ENUM")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "UNSIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "TYPEDEF")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "IMAGINARY")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" VOID" )
 {
 S(72);
 return 0;
 }
if ( a == "SHORT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "COMPLEX")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "EXTERN")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 76:
if ( a == "CONST")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "SIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "AUTO")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "IMAGINARY")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "BOOL")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "EXTERN")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "ENUM")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "SHORT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "UNION")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "DOUBLE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "VOLATILE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "TYPE_NAME")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "REGISTER")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "VOID")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "FLOAT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "INT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "LONG")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" STRUCT" )
 {
 S(76);
 return 0;
 }
if ( a == "INLINE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "TYPEDEF")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "UNSIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "STATIC")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "CHAR")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "RESTRICT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "COMPLEX")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 57:
if ( a == "INLINE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 51:
if ( a == "AUTO")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 33:
if ( a == "DOUBLE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "IMAGINARY")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "LONG")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "UNSIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "INT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "SIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "TYPE_NAME")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "UNION")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "CHAR")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" STRUCT" )
 {
 S(33);
 return 0;
 }
if ( a == "VOID")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "SHORT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "EXTERN")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "VOLATILE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "ENUM")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "RESTRICT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "BOOL")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "CONST")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "STATIC")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "FLOAT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "AUTO")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "INLINE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "COMPLEX")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "REGISTER")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "TYPEDEF")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 53:
if ( a == "CONST")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "RESTRICT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "VOLATILE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 70:
if ( a ==" STRUCT" )
 {
 S(70);
 return 0;
 }
if ( a == "VOID")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "REGISTER")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "VOLATILE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "CONST")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "CHAR")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "LONG")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "TYPE_NAME")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "IMAGINARY")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "SIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "TYPEDEF")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "INLINE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "EXTERN")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "FLOAT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "STATIC")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "SHORT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "BOOL")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "INT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "DOUBLE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "COMPLEX")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "UNSIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "ENUM")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "RESTRICT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "UNION")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "AUTO")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 20:
if ( a ==" INLINE" )
 {
 S(20);
 return 0;
 }
return -1;
case 12:
if ( a == "REGISTER")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 2:
if ( a ==" CHAR" )
 {
 S(2);
 return 0;
 }
return -1;
case 64:
if ( a == "TYPE_NAME")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 58:
if ( a == "CONST")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 61:
if ( a == "SHORT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 29:
if ( a == "VOLATILE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "CONST")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" RESTRICT" )
 {
 S(29);
 return 0;
 }
return -1;
case 54:
if ( a == "STATIC")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 52:
if ( a == "TYPEDEF")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "EXTERN")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "STATIC")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "AUTO")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "REGISTER")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 25:
if ( a == "SHORT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 44:
if ( a == "EXTERN")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 34:
if ( a == "BOOL")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "STATIC")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" STRUCT" )
 {
 S(34);
 return 0;
 }
if ( a == "REGISTER")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "VOLATILE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "AUTO")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "LONG")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "CONST")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" CHAR" )
 {
 S(34);
 return 0;
 }
if ( a == "INT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "SIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "COMPLEX")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" RESTRICT" )
 {
 S(34);
 return 0;
 }
if ( a == "TYPE_NAME")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "UNION")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "IMAGINARY")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "UNSIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "ENUM")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "SHORT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" VOID" )
 {
 S(34);
 return 0;
 }
if ( a == "DOUBLE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" INLINE" )
 {
 S(34);
 return 0;
 }
if ( a == "EXTERN")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "TYPEDEF")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "FLOAT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 69:
if ( a == "IMAGINARY")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 15:
if ( a == "STATIC")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 67:
if ( a == "INT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 10:
if ( a == "UNION")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 4:
if ( a ==" CHAR" )
 {
 S(4);
 return 0;
 }
if ( a == "UNION")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" STRUCT" )
 {
 S(4);
 return 0;
 }
if ( a == "FLOAT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "ENUM")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "REGISTER")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "EXTERN")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" INLINE" )
 {
 S(4);
 return 0;
 }
if ( a == "TYPE_NAME")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "STATIC")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "VOLATILE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "SIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "AUTO")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "UNSIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "IMAGINARY")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "SHORT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "CONST")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" RESTRICT" )
 {
 S(4);
 return 0;
 }
if ( a == "TYPEDEF")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" VOID" )
 {
 S(4);
 return 0;
 }
if ( a == "INT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "BOOL")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "COMPLEX")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "DOUBLE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "LONG")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 68:
if ( a == "BOOL")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 14:
if ( a == "TYPEDEF")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 27:
if ( a == "VOLATILE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 22:
if ( a == "SIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 18:
if ( a == "FLOAT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "DOUBLE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "ENUM")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" VOID" )
 {
 S(18);
 return 0;
 }
if ( a == "TYPE_NAME")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "COMPLEX")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "LONG")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" CHAR" )
 {
 S(18);
 return 0;
 }
if ( a == "BOOL")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "UNSIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" STRUCT" )
 {
 S(18);
 return 0;
 }
if ( a == "SIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "IMAGINARY")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "UNION")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "SHORT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "INT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 43:
if ( a == "ENUM")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 1:
if ( a ==" VOID" )
 {
 S(1);
 return 0;
 }
return -1;
case 46:
if ( a == "FLOAT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 30:
if ( a == "LONG")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 11:
if ( a == "ENUM")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 8:
if ( a == "UNION")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" STRUCT" )
 {
 S(8);
 return 0;
 }
return -1;
case 38:
if ( a == "STATIC")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "COMPLEX")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" VOID" )
 {
 S(38);
 return 0;
 }
if ( a == "REGISTER")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "EXTERN")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "TYPE_NAME")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "VOLATILE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "AUTO")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "BOOL")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" STRUCT" )
 {
 S(38);
 return 0;
 }
if ( a == "INT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "UNSIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "FLOAT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "LONG")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "DOUBLE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" RESTRICT" )
 {
 S(38);
 return 0;
 }
if ( a == "TYPEDEF")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "SIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "ENUM")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "UNION")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "IMAGINARY")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "CONST")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "SHORT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" CHAR" )
 {
 S(38);
 return 0;
 }
if ( a ==" INLINE" )
 {
 S(38);
 return 0;
 }
return -1;
case 9:
if ( a ==" STRUCT" )
 {
 S(9);
 return 0;
 }
return -1;
case 36:
if ( a == "EXTERN")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 73:
if ( a == "IMAGINARY")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "UNION")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "VOLATILE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "STATIC")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" STRUCT" )
 {
 S(73);
 return 0;
 }
if ( a == "ENUM")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "FLOAT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "TYPE_NAME")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "EXTERN")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "SIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "LONG")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "DOUBLE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "SHORT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "TYPEDEF")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "COMPLEX")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "INT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" INLINE" )
 {
 S(73);
 return 0;
 }
if ( a == "AUTO")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" RESTRICT" )
 {
 S(73);
 return 0;
 }
if ( a == "BOOL")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "CONST")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "REGISTER")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" VOID" )
 {
 S(73);
 return 0;
 }
if ( a ==" CHAR" )
 {
 S(73);
 return 0;
 }
if ( a == "UNSIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 75:
if ( a == "INT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "SIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "COMPLEX")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "VOLATILE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "ENUM")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "TYPE_NAME")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" VOID" )
 {
 S(75);
 return 0;
 }
if ( a == "UNSIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "DOUBLE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "REGISTER")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "BOOL")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" STRUCT" )
 {
 S(75);
 return 0;
 }
if ( a == "STATIC")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "UNION")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "SHORT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" INLINE" )
 {
 S(75);
 return 0;
 }
if ( a == "TYPEDEF")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" CHAR" )
 {
 S(75);
 return 0;
 }
if ( a == "LONG")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" RESTRICT" )
 {
 S(75);
 return 0;
 }
if ( a == "IMAGINARY")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "FLOAT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "AUTO")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "EXTERN")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "CONST")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 40:
if ( a == "REGISTER")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 24:
if ( a ==" STRUCT" )
 {
 S(24);
 return 0;
 }
if ( a == "UNION")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 39:
if ( a == "TYPEDEF")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 55:
if ( a == "COMPLEX")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 42:
if ( a == "RESTRICT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 66:
if ( a == "INLINE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 3:
if ( a ==" RESTRICT" )
 {
 S(3);
 return 0;
 }
return -1;
case 77:
if ( a == "ENUM")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "FLOAT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "EXTERN")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "UNSIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "UNION")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "AUTO")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" VOID" )
 {
 S(77);
 return 0;
 }
if ( a ==" INLINE" )
 {
 S(77);
 return 0;
 }
if ( a == "VOLATILE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "DOUBLE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "REGISTER")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "TYPE_NAME")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" CHAR" )
 {
 S(77);
 return 0;
 }
if ( a == "STATIC")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "SIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" STRUCT" )
 {
 S(77);
 return 0;
 }
if ( a == "IMAGINARY")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "BOOL")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "TYPEDEF")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "CONST")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "COMPLEX")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" RESTRICT" )
 {
 S(77);
 return 0;
 }
if ( a == "SHORT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "INT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "LONG")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 63:
if ( a == "SIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 17:
if ( a == "CONST")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 74:
if ( a ==" CHAR" )
 {
 S(74);
 return 0;
 }
if ( a == "VOLATILE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "LONG")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "BOOL")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" STRUCT" )
 {
 S(74);
 return 0;
 }
if ( a == "FLOAT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "SIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" RESTRICT" )
 {
 S(74);
 return 0;
 }
if ( a == "IMAGINARY")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "CONST")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "ENUM")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "SHORT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" INLINE" )
 {
 S(74);
 return 0;
 }
if ( a == "TYPE_NAME")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "DOUBLE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "STATIC")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "REGISTER")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "UNSIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "COMPLEX")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "UNION")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" VOID" )
 {
 S(74);
 return 0;
 }
if ( a == "INT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "TYPEDEF")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "EXTERN")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "AUTO")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 28:
if ( a == "AUTO")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 0:
if ( a ==" VOID" )
 {
 S(0);
 return 0;
 }
if ( a == "REGISTER")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "UNSIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "SIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "ENUM")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "BOOL")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "AUTO")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "LONG")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "t")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" CHAR" )
 {
 S(0);
 return 0;
 }
if ( a ==" INLINE" )
 {
 S(0);
 return 0;
 }
if ( a == "COMPLEX")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "INT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "FLOAT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "EXTERN")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "TYPEDEF")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "STATIC")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "VOLATILE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "TYPE_NAME")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "DOUBLE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" RESTRICT" )
 {
 S(0);
 return 0;
 }
if ( a ==" STRUCT" )
 {
 S(0);
 return 0;
 }
if ( a == "UNION")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "CONST")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "SHORT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "IMAGINARY")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 35:
if ( a ==" RESTRICT" )
 {
 S(35);
 return 0;
 }
if ( a ==" CHAR" )
 {
 S(35);
 return 0;
 }
if ( a == "UNION")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "ENUM")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "VOLATILE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "STATIC")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "SHORT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "SIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "TYPE_NAME")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "BOOL")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "CONST")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "EXTERN")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "FLOAT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" VOID" )
 {
 S(35);
 return 0;
 }
if ( a ==" INLINE" )
 {
 S(35);
 return 0;
 }
if ( a == "UNSIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "DOUBLE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "AUTO")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "TYPEDEF")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "INT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "REGISTER")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "IMAGINARY")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "COMPLEX")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" STRUCT" )
 {
 S(35);
 return 0;
 }
if ( a == "LONG")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 50:
if ( a == "SIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" STRUCT" )
 {
 S(50);
 return 0;
 }
if ( a == "UNION")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "UNSIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "FLOAT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "INT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "IMAGINARY")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "CHAR")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "BOOL")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "DOUBLE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "COMPLEX")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "SHORT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "LONG")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "VOID")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "TYPE_NAME")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "ENUM")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 16:
if ( a == "BOOL")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 23:
if ( a == "COMPLEX")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 5:
if ( a == "EXTERN")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "STATIC")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "AUTO")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "REGISTER")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "TYPEDEF")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 71:
if ( a == "EXTERN")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "VOLATILE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "ENUM")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "SIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "UNSIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "IMAGINARY")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "DOUBLE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "BOOL")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" INLINE" )
 {
 S(71);
 return 0;
 }
if ( a == "AUTO")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "SHORT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" RESTRICT" )
 {
 S(71);
 return 0;
 }
if ( a ==" STRUCT" )
 {
 S(71);
 return 0;
 }
if ( a == "TYPE_NAME")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "TYPEDEF")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "REGISTER")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "COMPLEX")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" CHAR" )
 {
 S(71);
 return 0;
 }
if ( a == "CONST")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" VOID" )
 {
 S(71);
 return 0;
 }
if ( a == "FLOAT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "INT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "LONG")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "UNION")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "STATIC")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 13:
if ( a == "INT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 48:
if ( a == "VOLATILE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 45:
if ( a == "CHAR")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 21:
if ( a == "DOUBLE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 19:
if ( a == "FLOAT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 62:
if ( a == "LONG")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 7:
if ( a ==" INLINE" )
 {
 S(7);
 return 0;
 }
return -1;

            default:
                return -1;
        }
    }
    

    int gotoTable(int t, std::string vn) {
        switch (t) {
	
case65:
 if (vn == "storage_class_specifier") 
 return 52;
 if (vn == "declaration_specifiers") 
 return 65;
 if (vn == "enum_specifier") 
 return 56;
 if (vn == "struct_or_union") 
 return 49;
 if (vn == "struct_or_union_specifier") 
 return 41;
 if (vn == "type_specifier") 
 return 50;
 if (vn == "type_qualifier") 
 return 53;
 if (vn == "function_specifier") 
 return 66;
return -1;
case31:

return -1;
case6:
 if (vn == "enum_specifier") 
 return 6;
return -1;
case37:
 if (vn == "storage_class_specifier") 
 return 5;
 if (vn == "type_specifier") 
 return 18;
 if (vn == "external_declaration") 
 return 38;
 if (vn == "function_definition") 
 return 33;
 if (vn == "declaration") 
 return 35;
 if (vn == "function_specifier") 
 return 20;
 if (vn == "struct_or_union") 
 return 8;
 if (vn == "struct_or_union_specifier") 
 return 24;
 if (vn == "enum_specifier") 
 return 6;
 if (vn == "declaration_specifiers") 
 return 4;
 if (vn == "translation_unit") 
 return 34;
 if (vn == "type_qualifier") 
 return 29;
return -1;
case47:

return -1;
case60:

return -1;
case59:

return -1;
case32:

return -1;
case26:

return -1;
case41:
 if (vn == "struct_or_union_specifier") 
 return 41;
 if (vn == "struct_or_union") 
 return 49;
return -1;
case49:
 if (vn == "struct_or_union") 
 return 49;
return -1;
case56:
 if (vn == "enum_specifier") 
 return 56;
return -1;
case72:
 if (vn == "struct_or_union") 
 return 8;
 if (vn == "function_specifier") 
 return 20;
 if (vn == "external_declaration") 
 return 74;
 if (vn == "translation_unit") 
 return 72;
 if (vn == "function_definition") 
 return 70;
 if (vn == "declaration") 
 return 73;
 if (vn == "type_qualifier") 
 return 29;
 if (vn == "declaration_specifiers") 
 return 71;
 if (vn == "struct_or_union_specifier") 
 return 24;
 if (vn == "enum_specifier") 
 return 6;
 if (vn == "storage_class_specifier") 
 return 5;
 if (vn == "type_specifier") 
 return 18;
return -1;
case76:
 if (vn == "function_specifier") 
 return 66;
 if (vn == "type_qualifier") 
 return 53;
 if (vn == "enum_specifier") 
 return 56;
 if (vn == "declaration_specifiers") 
 return 76;
 if (vn == "storage_class_specifier") 
 return 52;
 if (vn == "type_specifier") 
 return 50;
 if (vn == "struct_or_union_specifier") 
 return 41;
 if (vn == "struct_or_union") 
 return 49;
return -1;
case57:

return -1;
case51:

return -1;
case33:
 if (vn == "storage_class_specifier") 
 return 52;
 if (vn == "type_specifier") 
 return 50;
 if (vn == "struct_or_union") 
 return 49;
 if (vn == "declaration_specifiers") 
 return 65;
 if (vn == "struct_or_union_specifier") 
 return 41;
 if (vn == "type_qualifier") 
 return 53;
 if (vn == "enum_specifier") 
 return 56;
 if (vn == "function_specifier") 
 return 66;
 if (vn == "function_definition") 
 return 33;
return -1;
case53:
 if (vn == "type_qualifier") 
 return 53;
return -1;
case70:
 if (vn == "storage_class_specifier") 
 return 52;
 if (vn == "type_qualifier") 
 return 53;
 if (vn == "enum_specifier") 
 return 56;
 if (vn == "struct_or_union") 
 return 49;
 if (vn == "declaration_specifiers") 
 return 76;
 if (vn == "function_definition") 
 return 70;
 if (vn == "type_specifier") 
 return 50;
 if (vn == "struct_or_union_specifier") 
 return 41;
 if (vn == "function_specifier") 
 return 66;
return -1;
case20:
 if (vn == "function_specifier") 
 return 20;
return -1;
case12:

return -1;
case2:

return -1;
case64:

return -1;
case58:

return -1;
case61:

return -1;
case29:
 if (vn == "type_qualifier") 
 return 29;
return -1;
case54:

return -1;
case52:
 if (vn == "storage_class_specifier") 
 return 52;
return -1;
case25:

return -1;
case44:

return -1;
case34:
 if (vn == "struct_or_union_specifier") 
 return 24;
 if (vn == "struct_or_union") 
 return 8;
 if (vn == "function_definition") 
 return 70;
 if (vn == "function_specifier") 
 return 20;
 if (vn == "enum_specifier") 
 return 6;
 if (vn == "translation_unit") 
 return 72;
 if (vn == "declaration") 
 return 73;
 if (vn == "type_qualifier") 
 return 29;
 if (vn == "type_specifier") 
 return 18;
 if (vn == "external_declaration") 
 return 74;
 if (vn == "declaration_specifiers") 
 return 71;
 if (vn == "storage_class_specifier") 
 return 5;
return -1;
case69:

return -1;
case15:

return -1;
case67:

return -1;
case10:

return -1;
case4:
 if (vn == "declaration_specifiers") 
 return 4;
 if (vn == "function_specifier") 
 return 20;
 if (vn == "struct_or_union") 
 return 8;
 if (vn == "storage_class_specifier") 
 return 5;
 if (vn == "struct_or_union_specifier") 
 return 24;
 if (vn == "enum_specifier") 
 return 6;
 if (vn == "type_specifier") 
 return 18;
 if (vn == "type_qualifier") 
 return 29;
return -1;
case68:

return -1;
case14:

return -1;
case27:

return -1;
case22:

return -1;
case18:
 if (vn == "struct_or_union") 
 return 8;
 if (vn == "struct_or_union_specifier") 
 return 24;
 if (vn == "type_specifier") 
 return 18;
 if (vn == "enum_specifier") 
 return 6;
return -1;
case43:

return -1;
case1:

return -1;
case46:

return -1;
case30:

return -1;
case11:

return -1;
case8:
 if (vn == "struct_or_union") 
 return 8;
return -1;
case38:
 if (vn == "external_declaration") 
 return 38;
 if (vn == "storage_class_specifier") 
 return 5;
 if (vn == "declaration_specifiers") 
 return 4;
 if (vn == "declaration") 
 return 35;
 if (vn == "type_specifier") 
 return 18;
 if (vn == "function_definition") 
 return 33;
 if (vn == "struct_or_union_specifier") 
 return 24;
 if (vn == "struct_or_union") 
 return 8;
 if (vn == "function_specifier") 
 return 20;
 if (vn == "type_qualifier") 
 return 29;
 if (vn == "enum_specifier") 
 return 6;
return -1;
case9:

return -1;
case36:

return -1;
case73:
 if (vn == "type_qualifier") 
 return 29;
 if (vn == "declaration") 
 return 73;
 if (vn == "enum_specifier") 
 return 6;
 if (vn == "function_specifier") 
 return 20;
 if (vn == "storage_class_specifier") 
 return 5;
 if (vn == "type_specifier") 
 return 18;
 if (vn == "struct_or_union_specifier") 
 return 24;
 if (vn == "declaration_specifiers") 
 return 77;
 if (vn == "struct_or_union") 
 return 8;
return -1;
case75:
 if (vn == "declaration_specifiers") 
 return 75;
 if (vn == "struct_or_union_specifier") 
 return 24;
 if (vn == "function_specifier") 
 return 20;
 if (vn == "storage_class_specifier") 
 return 5;
 if (vn == "type_specifier") 
 return 18;
 if (vn == "struct_or_union") 
 return 8;
 if (vn == "type_qualifier") 
 return 29;
 if (vn == "enum_specifier") 
 return 6;
return -1;
case40:

return -1;
case24:
 if (vn == "struct_or_union_specifier") 
 return 24;
 if (vn == "struct_or_union") 
 return 8;
return -1;
case39:

return -1;
case55:

return -1;
case42:

return -1;
case66:
 if (vn == "function_specifier") 
 return 66;
return -1;
case3:

return -1;
case77:
 if (vn == "type_qualifier") 
 return 29;
 if (vn == "function_specifier") 
 return 20;
 if (vn == "type_specifier") 
 return 18;
 if (vn == "struct_or_union") 
 return 8;
 if (vn == "enum_specifier") 
 return 6;
 if (vn == "storage_class_specifier") 
 return 5;
 if (vn == "struct_or_union_specifier") 
 return 24;
 if (vn == "declaration_specifiers") 
 return 77;
return -1;
case63:

return -1;
case17:

return -1;
case74:
 if (vn == "function_definition") 
 return 70;
 if (vn == "external_declaration") 
 return 74;
 if (vn == "storage_class_specifier") 
 return 5;
 if (vn == "declaration") 
 return 73;
 if (vn == "function_specifier") 
 return 20;
 if (vn == "struct_or_union_specifier") 
 return 24;
 if (vn == "struct_or_union") 
 return 8;
 if (vn == "enum_specifier") 
 return 6;
 if (vn == "declaration_specifiers") 
 return 71;
 if (vn == "type_qualifier") 
 return 29;
 if (vn == "type_specifier") 
 return 18;
return -1;
case28:

return -1;
case0:
 if (vn == "storage_class_specifier") 
 return 5;
 if (vn == "declaration_specifiers") 
 return 4;
 if (vn == "external_declaration") 
 return 38;
 if (vn == "function_specifier") 
 return 20;
 if (vn == "type_qualifier") 
 return 29;
 if (vn == "translation_unit") 
 return 34;
 if (vn == "struct_or_union_specifier") 
 return 24;
 if (vn == "type_specifier") 
 return 18;
 if (vn == "struct_or_union") 
 return 8;
 if (vn == "function_definition") 
 return 33;
 if (vn == "declaration") 
 return 35;
 if (vn == "enum_specifier") 
 return 6;
return -1;
case35:
 if (vn == "enum_specifier") 
 return 6;
 if (vn == "function_specifier") 
 return 20;
 if (vn == "type_specifier") 
 return 18;
 if (vn == "struct_or_union_specifier") 
 return 24;
 if (vn == "declaration_specifiers") 
 return 75;
 if (vn == "type_qualifier") 
 return 29;
 if (vn == "declaration") 
 return 35;
 if (vn == "struct_or_union") 
 return 8;
 if (vn == "storage_class_specifier") 
 return 5;
return -1;
case50:
 if (vn == "struct_or_union") 
 return 49;
 if (vn == "type_specifier") 
 return 50;
 if (vn == "struct_or_union_specifier") 
 return 41;
 if (vn == "enum_specifier") 
 return 56;
return -1;
case16:

return -1;
case23:

return -1;
case5:
 if (vn == "storage_class_specifier") 
 return 5;
return -1;
case71:
 if (vn == "type_specifier") 
 return 18;
 if (vn == "enum_specifier") 
 return 6;
 if (vn == "function_specifier") 
 return 20;
 if (vn == "declaration_specifiers") 
 return 71;
 if (vn == "struct_or_union_specifier") 
 return 24;
 if (vn == "struct_or_union") 
 return 8;
 if (vn == "storage_class_specifier") 
 return 5;
 if (vn == "type_qualifier") 
 return 29;
return -1;
case13:

return -1;
case48:

return -1;
case45:

return -1;
case21:

return -1;
case19:

return -1;
case62:

return -1;
case7:

return -1;

			default:
                return -1;
        }
    }
    

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
	
case 37:
if ( a == "VOLATILE")
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

if ( a == "UNSIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" CONST" )
 {
 S(37);
 return 0;
 }
if ( a == "STRUCT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "SHORT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "INLINE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "ENUM")
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

if ( a == "IMAGINARY")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "REGISTER")
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
if ( a == "SIGNED")
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

if ( a ==" CHAR" )
 {
 S(37);
 return 0;
 }
if ( a == "RESTRICT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" FLOAT" )
 {
 S(37);
 return 0;
 }
if ( a == "INT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "t")
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

if ( a == "UNION")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 72:
if ( a == "AUTO")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 60:
if ( a == "TYPEDEF")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 21:
if ( a == "VOLATILE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 53:
if ( a == "BOOL")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 59:
if ( a == "ENUM")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 30:
if ( a == "INT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 36:
if ( a == "AUTO")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 43:
if ( a ==" VOID" )
 {
 S(43);
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

if ( a == "RESTRICT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" CHAR" )
 {
 S(43);
 return 0;
 }
if ( a == "AUTO")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "REGISTER")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "INT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" FLOAT" )
 {
 S(43);
 return 0;
 }
if ( a == "BOOL")
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

if ( a == "ENUM")
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

if ( a ==" CONST" )
 {
 S(43);
 return 0;
 }
if ( a == "SIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "LONG")
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

if ( a == "INLINE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "IMAGINARY")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "VOLATILE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "UNION")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "STRUCT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 57:
if ( a == "CHAR")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 54:
if ( a == "IMAGINARY")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 38:
if ( a == "UNION")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 48:
if ( a == "SHORT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 20:
if ( a == "STRUCT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "UNION")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 34:
if ( a == "SHORT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 4:
if ( a == "INT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" CONST" )
 {
 S(4);
 return 0;
 }
if ( a == "COMPLEX")
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

if ( a == "STRUCT")
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

if ( a == "INLINE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "IMAGINARY")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" VOID" )
 {
 S(4);
 return 0;
 }
if ( a == "SIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "UNSIGNED")
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

if ( a == "ENUM")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "RESTRICT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" FLOAT" )
 {
 S(4);
 return 0;
 }
if ( a ==" CHAR" )
 {
 S(4);
 return 0;
 }
if ( a == "VOLATILE")
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

if ( a == "REGISTER")
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

return -1;
case 24:
if ( a == "ENUM")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 66:
if ( a == "EXTERN")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 58:
if ( a == "LONG")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 35:
if ( a == "LONG")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 51:
if ( a == "TYPEDEF")
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

if ( a == "UNSIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "CHAR")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "DOUBLE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "RESTRICT")
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

if ( a == "LONG")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "BOOL")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "STRUCT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "AUTO")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "ENUM")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "INLINE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "UNION")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "TYPE_NAME")
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

if ( a == "CONST")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "VOLATILE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "EXTERN")
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

if ( a == "REGISTER")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 75:
if ( a == "SIGNED")
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

if ( a == "IMAGINARY")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "LONG")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "CHAR")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "REGISTER")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "STRUCT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "UNSIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "CONST")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "INLINE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "RESTRICT")
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

if ( a == "SHORT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "VOID")
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

if ( a == "TYPEDEF")
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

if ( a == "INT")
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

if ( a == "BOOL")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 12:
if ( a == "ENUM")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 3:
if ( a == "STRUCT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "UNION")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 70:
if ( a == "FLOAT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 73:
if ( a == "DOUBLE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 23:
if ( a == "REGISTER")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 8:
if ( a ==" FLOAT" )
 {
 S(8);
 return 0;
 }
return -1;
case 25:
if ( a == "COMPLEX")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "BOOL")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "RESTRICT")
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

if ( a == "IMAGINARY")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "VOID")
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

if ( a == "UNION")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "ENUM")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "CONST")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "UNSIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "STRUCT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "VOLATILE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "LONG")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "INT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "CHAR")
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

if ( a == "INLINE")
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

if ( a == "EXTERN")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "TYPEDEF")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 9:
if ( a ==" CONST" )
 {
 S(9);
 return 0;
 }
return -1;
case 31:
if ( a == "COMPLEX")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 68:
if ( a == "VOID")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 61:
if ( a == "SIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 11:
if ( a == "IMAGINARY")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 13:
if ( a == "TYPE_NAME")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 71:
if ( a == "STATIC")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 14:
if ( a == "RESTRICT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 41:
if ( a == "STATIC")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "ENUM")
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

if ( a == "SIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" CONST" )
 {
 S(41);
 return 0;
 }
if ( a == "TYPEDEF")
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

if ( a == "REGISTER")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" CHAR" )
 {
 S(41);
 return 0;
 }
if ( a == "UNSIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "EXTERN")
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

if ( a == "SHORT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" VOID" )
 {
 S(41);
 return 0;
 }
if ( a ==" FLOAT" )
 {
 S(41);
 return 0;
 }
if ( a == "INT")
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

if ( a == "AUTO")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "STRUCT")
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

return -1;
case 56:
if ( a == "REGISTER")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 74:
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
case 0:
if ( a ==" CHAR" )
 {
 S(0);
 return 0;
 }
if ( a == "DOUBLE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "COMPLEX")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" VOID" )
 {
 S(0);
 return 0;
 }
if ( a == "TYPE_NAME")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "STRUCT")
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

if ( a == "TYPEDEF")
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

if ( a == "BOOL")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "EXTERN")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "INLINE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "UNION")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" FLOAT" )
 {
 S(0);
 return 0;
 }
if ( a == "VOLATILE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "SIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" CONST" )
 {
 S(0);
 return 0;
 }
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

if ( a == "RESTRICT")
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

if ( a == "SHORT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 65:
if ( a == "CONST")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 2:
if ( a ==" CONST" )
 {
 S(2);
 return 0;
 }
if ( a == "RESTRICT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "VOLATILE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 50:
if ( a == "STRUCT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "UNION")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 6:
if ( a ==" VOID" )
 {
 S(6);
 return 0;
 }
return -1;
case 7:
if ( a ==" CHAR" )
 {
 S(7);
 return 0;
 }
return -1;
case 15:
if ( a == "SIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 32:
if ( a == "UNSIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "INT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" FLOAT" )
 {
 S(32);
 return 0;
 }
if ( a == "COMPLEX")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "RESTRICT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "TYPEDEF")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "UNION")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "EXTERN")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "REGISTER")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "INLINE")
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

if ( a == "AUTO")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "IMAGINARY")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "ENUM")
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

if ( a == "TYPE_NAME")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "BOOL")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "STRUCT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" CONST" )
 {
 S(32);
 return 0;
 }
if ( a == "LONG")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "VOLATILE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" CHAR" )
 {
 S(32);
 return 0;
 }
if ( a ==" VOID" )
 {
 S(32);
 return 0;
 }
return -1;
case 52:
if ( a == "SHORT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "STRUCT")
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

if ( a == "SIGNED")
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

if ( a == "DOUBLE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "VOID")
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

if ( a == "FLOAT")
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

if ( a == "ENUM")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "TYPE_NAME")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 33:
if ( a == "INLINE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 17:
if ( a == "TYPEDEF")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 10:
if ( a == "STATIC")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "RESTRICT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "ENUM")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" VOID" )
 {
 S(10);
 return 0;
 }
if ( a == "LONG")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "IMAGINARY")
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

if ( a == "TYPEDEF")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "TYPE_NAME")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" CHAR" )
 {
 S(10);
 return 0;
 }
if ( a == "COMPLEX")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "SHORT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" FLOAT" )
 {
 S(10);
 return 0;
 }
if ( a == "AUTO")
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

if ( a ==" CONST" )
 {
 S(10);
 return 0;
 }
if ( a == "STRUCT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "UNSIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "BOOL")
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

if ( a == "INLINE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "VOLATILE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 39:
if ( a == "DOUBLE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" VOID" )
 {
 S(39);
 return 0;
 }
if ( a == "RESTRICT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" CONST" )
 {
 S(39);
 return 0;
 }
if ( a == "STATIC")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "EXTERN")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "IMAGINARY")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" CHAR" )
 {
 S(39);
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

if ( a == "UNSIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "LONG")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "STRUCT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "SIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "SHORT")
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

if ( a == "INLINE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "UNION")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "TYPE_NAME")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "COMPLEX")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "AUTO")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" FLOAT" )
 {
 S(39);
 return 0;
 }
if ( a == "BOOL")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "ENUM")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 44:
if ( a == "STRUCT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "UNION")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 55:
if ( a == "VOLATILE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 64:
if ( a == "INLINE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 18:
if ( a == "STATIC")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 46:
if ( a == "RESTRICT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 47:
if ( a == "INLINE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 28:
if ( a == "DOUBLE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 76:
if ( a == "STATIC")
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

if ( a == "INT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "EXTERN")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" FLOAT" )
 {
 S(76);
 return 0;
 }
if ( a == "RESTRICT")
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

if ( a == "STRUCT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "VOLATILE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" CONST" )
 {
 S(76);
 return 0;
 }
if ( a == "SIGNED")
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

if ( a == "LONG")
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

if ( a == "UNSIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" CHAR" )
 {
 S(76);
 return 0;
 }
if ( a == "REGISTER")
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

if ( a == "COMPLEX")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" VOID" )
 {
 S(76);
 return 0;
 }
return -1;
case 40:
if ( a == "INLINE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "INT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "ENUM")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "STRUCT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "COMPLEX")
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

if ( a == "EXTERN")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "CONST")
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

if ( a == "AUTO")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "CHAR")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "SIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "DOUBLE")
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

if ( a == "RESTRICT")
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

if ( a == "BOOL")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "LONG")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "VOLATILE")
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

return -1;
case 26:
if ( a == "STRUCT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 49:
if ( a == "UNSIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 19:
if ( a == "UNSIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 22:
if ( a == "EXTERN")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 42:
if ( a ==" CHAR" )
 {
 S(42);
 return 0;
 }
if ( a == "SHORT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "SIGNED")
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

if ( a == "AUTO")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" FLOAT" )
 {
 S(42);
 return 0;
 }
if ( a == "STRUCT")
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

if ( a == "INT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "COMPLEX")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "RESTRICT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "ENUM")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" CONST" )
 {
 S(42);
 return 0;
 }
if ( a == "UNION")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "INLINE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "LONG")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" VOID" )
 {
 S(42);
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

if ( a == "UNSIGNED")
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

if ( a == "DOUBLE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 67:
if ( a == "COMPLEX")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 45:
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
case 63:
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
case 29:
if ( a == "INLINE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 5:
if ( a ==" CHAR" )
 {
 S(5);
 return 0;
 }
if ( a == "SHORT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "STRUCT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "TYPE_NAME")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" FLOAT" )
 {
 S(5);
 return 0;
 }
if ( a == "BOOL")
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

if ( a ==" CONST" )
 {
 S(5);
 return 0;
 }
if ( a == "INLINE")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" VOID" )
 {
 S(5);
 return 0;
 }
if ( a == "COMPLEX")
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

if ( a == "IMAGINARY")
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

if ( a == "RESTRICT")
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

if ( a == "EXTERN")
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

if ( a == "TYPEDEF")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 69:
if ( a == "INT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 27:
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
case 62:
if ( a == "TYPE_NAME")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;
case 1:
if ( a == "COMPLEX")
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

if ( a ==" VOID" )
 {
 S(1);
 return 0;
 }
if ( a ==" CHAR" )
 {
 S(1);
 return 0;
 }
if ( a == "SIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "BOOL")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "TYPE_NAME")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "STRUCT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

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

if ( a == "INT")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a == "UNSIGNED")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

if ( a ==" FLOAT" )
 {
 S(1);
 return 0;
 }
if ( a == "ENUM")
 {
  r(0,""); return 0;
 }std::cout << "归约：" << "" => " << "" << std::endl;

return -1;

            default:
                return -1;
        }
    }
    

    int gotoTable(int t, std::string vn) {
        switch (t) {
	
case37:
 if (vn == "external_declaration") 
 return 32;
 if (vn == "storage_class_specifier") 
 return 27;
 if (vn == "type_qualifier") 
 return 2;
 if (vn == "function_specifier") 
 return 33;
 if (vn == "type_specifier") 
 return 1;
 if (vn == "declaration_specifiers") 
 return 5;
 if (vn == "enum_specifier") 
 return 12;
 if (vn == "struct_or_union_specifier") 
 return 20;
 if (vn == "translation_unit") 
 return 4;
 if (vn == "struct_or_union") 
 return 3;
 if (vn == "declaration") 
 return 10;
 if (vn == "function_definition") 
 return 25;
return -1;
case72:

return -1;
case60:

return -1;
case21:

return -1;
case53:

return -1;
case59:

return -1;
case30:

return -1;
case36:

return -1;
case43:
 if (vn == "type_qualifier") 
 return 2;
 if (vn == "enum_specifier") 
 return 12;
 if (vn == "type_specifier") 
 return 1;
 if (vn == "declaration_specifiers") 
 return 43;
 if (vn == "function_specifier") 
 return 33;
 if (vn == "struct_or_union_specifier") 
 return 20;
 if (vn == "storage_class_specifier") 
 return 27;
 if (vn == "struct_or_union") 
 return 3;
return -1;
case57:

return -1;
case54:

return -1;
case38:

return -1;
case48:

return -1;
case20:
 if (vn == "struct_or_union") 
 return 3;
 if (vn == "struct_or_union_specifier") 
 return 20;
return -1;
case34:

return -1;
case4:
 if (vn == "function_definition") 
 return 40;
 if (vn == "type_qualifier") 
 return 2;
 if (vn == "enum_specifier") 
 return 12;
 if (vn == "external_declaration") 
 return 42;
 if (vn == "struct_or_union") 
 return 3;
 if (vn == "type_specifier") 
 return 1;
 if (vn == "declaration_specifiers") 
 return 39;
 if (vn == "declaration") 
 return 41;
 if (vn == "struct_or_union_specifier") 
 return 20;
 if (vn == "translation_unit") 
 return 4;
 if (vn == "storage_class_specifier") 
 return 27;
 if (vn == "function_specifier") 
 return 33;
return -1;
case24:

return -1;
case66:

return -1;
case58:

return -1;
case35:

return -1;
case51:
 if (vn == "function_specifier") 
 return 64;
 if (vn == "storage_class_specifier") 
 return 63;
 if (vn == "struct_or_union_specifier") 
 return 44;
 if (vn == "declaration_specifiers") 
 return 51;
 if (vn == "struct_or_union") 
 return 50;
 if (vn == "type_specifier") 
 return 52;
 if (vn == "enum_specifier") 
 return 74;
 if (vn == "type_qualifier") 
 return 45;
return -1;
case75:
 if (vn == "enum_specifier") 
 return 74;
 if (vn == "type_qualifier") 
 return 45;
 if (vn == "declaration_specifiers") 
 return 75;
 if (vn == "struct_or_union_specifier") 
 return 44;
 if (vn == "struct_or_union") 
 return 50;
 if (vn == "type_specifier") 
 return 52;
 if (vn == "function_specifier") 
 return 64;
 if (vn == "storage_class_specifier") 
 return 63;
return -1;
case12:
 if (vn == "enum_specifier") 
 return 12;
return -1;
case3:
 if (vn == "struct_or_union") 
 return 3;
return -1;
case70:

return -1;
case73:

return -1;
case23:

return -1;
case8:

return -1;
case25:
 if (vn == "declaration_specifiers") 
 return 51;
 if (vn == "type_specifier") 
 return 52;
 if (vn == "storage_class_specifier") 
 return 63;
 if (vn == "struct_or_union_specifier") 
 return 44;
 if (vn == "function_definition") 
 return 25;
 if (vn == "type_qualifier") 
 return 45;
 if (vn == "function_specifier") 
 return 64;
 if (vn == "enum_specifier") 
 return 74;
 if (vn == "struct_or_union") 
 return 50;
return -1;
case9:

return -1;
case31:

return -1;
case68:

return -1;
case61:

return -1;
case11:

return -1;
case13:

return -1;
case71:

return -1;
case14:

return -1;
case41:
 if (vn == "struct_or_union") 
 return 3;
 if (vn == "struct_or_union_specifier") 
 return 20;
 if (vn == "declaration_specifiers") 
 return 76;
 if (vn == "enum_specifier") 
 return 12;
 if (vn == "function_specifier") 
 return 33;
 if (vn == "storage_class_specifier") 
 return 27;
 if (vn == "type_specifier") 
 return 1;
 if (vn == "type_qualifier") 
 return 2;
 if (vn == "declaration") 
 return 41;
return -1;
case56:

return -1;
case74:
 if (vn == "enum_specifier") 
 return 74;
return -1;
case16:

return -1;
case0:
 if (vn == "enum_specifier") 
 return 12;
 if (vn == "storage_class_specifier") 
 return 27;
 if (vn == "type_qualifier") 
 return 2;
 if (vn == "function_definition") 
 return 25;
 if (vn == "declaration_specifiers") 
 return 5;
 if (vn == "declaration") 
 return 10;
 if (vn == "struct_or_union") 
 return 3;
 if (vn == "translation_unit") 
 return 4;
 if (vn == "type_specifier") 
 return 1;
 if (vn == "struct_or_union_specifier") 
 return 20;
 if (vn == "external_declaration") 
 return 32;
 if (vn == "function_specifier") 
 return 33;
return -1;
case65:

return -1;
case2:
 if (vn == "type_qualifier") 
 return 2;
return -1;
case50:
 if (vn == "struct_or_union") 
 return 50;
return -1;
case6:

return -1;
case7:

return -1;
case15:

return -1;
case32:
 if (vn == "enum_specifier") 
 return 12;
 if (vn == "storage_class_specifier") 
 return 27;
 if (vn == "function_definition") 
 return 25;
 if (vn == "declaration") 
 return 10;
 if (vn == "type_qualifier") 
 return 2;
 if (vn == "struct_or_union") 
 return 3;
 if (vn == "function_specifier") 
 return 33;
 if (vn == "type_specifier") 
 return 1;
 if (vn == "declaration_specifiers") 
 return 5;
 if (vn == "struct_or_union_specifier") 
 return 20;
 if (vn == "external_declaration") 
 return 32;
return -1;
case52:
 if (vn == "enum_specifier") 
 return 74;
 if (vn == "struct_or_union") 
 return 50;
 if (vn == "type_specifier") 
 return 52;
 if (vn == "struct_or_union_specifier") 
 return 44;
return -1;
case33:
 if (vn == "function_specifier") 
 return 33;
return -1;
case17:

return -1;
case10:
 if (vn == "type_specifier") 
 return 1;
 if (vn == "enum_specifier") 
 return 12;
 if (vn == "declaration") 
 return 10;
 if (vn == "function_specifier") 
 return 33;
 if (vn == "struct_or_union_specifier") 
 return 20;
 if (vn == "struct_or_union") 
 return 3;
 if (vn == "type_qualifier") 
 return 2;
 if (vn == "declaration_specifiers") 
 return 43;
 if (vn == "storage_class_specifier") 
 return 27;
return -1;
case39:
 if (vn == "function_specifier") 
 return 33;
 if (vn == "struct_or_union") 
 return 3;
 if (vn == "struct_or_union_specifier") 
 return 20;
 if (vn == "declaration_specifiers") 
 return 39;
 if (vn == "type_specifier") 
 return 1;
 if (vn == "enum_specifier") 
 return 12;
 if (vn == "type_qualifier") 
 return 2;
 if (vn == "storage_class_specifier") 
 return 27;
return -1;
case44:
 if (vn == "struct_or_union") 
 return 50;
 if (vn == "struct_or_union_specifier") 
 return 44;
return -1;
case55:

return -1;
case64:
 if (vn == "function_specifier") 
 return 64;
return -1;
case18:

return -1;
case46:

return -1;
case47:

return -1;
case28:

return -1;
case76:
 if (vn == "struct_or_union") 
 return 3;
 if (vn == "struct_or_union_specifier") 
 return 20;
 if (vn == "function_specifier") 
 return 33;
 if (vn == "type_specifier") 
 return 1;
 if (vn == "enum_specifier") 
 return 12;
 if (vn == "type_qualifier") 
 return 2;
 if (vn == "storage_class_specifier") 
 return 27;
 if (vn == "declaration_specifiers") 
 return 76;
return -1;
case40:
 if (vn == "struct_or_union_specifier") 
 return 44;
 if (vn == "function_specifier") 
 return 64;
 if (vn == "declaration_specifiers") 
 return 75;
 if (vn == "enum_specifier") 
 return 74;
 if (vn == "type_specifier") 
 return 52;
 if (vn == "struct_or_union") 
 return 50;
 if (vn == "type_qualifier") 
 return 45;
 if (vn == "function_definition") 
 return 40;
 if (vn == "storage_class_specifier") 
 return 63;
return -1;
case26:

return -1;
case49:

return -1;
case19:

return -1;
case22:

return -1;
case42:
 if (vn == "enum_specifier") 
 return 12;
 if (vn == "struct_or_union_specifier") 
 return 20;
 if (vn == "storage_class_specifier") 
 return 27;
 if (vn == "declaration_specifiers") 
 return 39;
 if (vn == "function_specifier") 
 return 33;
 if (vn == "type_specifier") 
 return 1;
 if (vn == "declaration") 
 return 41;
 if (vn == "function_definition") 
 return 40;
 if (vn == "type_qualifier") 
 return 2;
 if (vn == "struct_or_union") 
 return 3;
 if (vn == "external_declaration") 
 return 42;
return -1;
case67:

return -1;
case45:
 if (vn == "type_qualifier") 
 return 45;
return -1;
case63:
 if (vn == "storage_class_specifier") 
 return 63;
return -1;
case29:

return -1;
case5:
 if (vn == "struct_or_union_specifier") 
 return 20;
 if (vn == "type_specifier") 
 return 1;
 if (vn == "type_qualifier") 
 return 2;
 if (vn == "struct_or_union") 
 return 3;
 if (vn == "enum_specifier") 
 return 12;
 if (vn == "storage_class_specifier") 
 return 27;
 if (vn == "declaration_specifiers") 
 return 5;
 if (vn == "function_specifier") 
 return 33;
return -1;
case69:

return -1;
case27:
 if (vn == "storage_class_specifier") 
 return 27;
return -1;
case62:

return -1;
case1:
 if (vn == "struct_or_union") 
 return 3;
 if (vn == "type_specifier") 
 return 1;
 if (vn == "enum_specifier") 
 return 12;
 if (vn == "struct_or_union_specifier") 
 return 20;
return -1;

			default:
                return -1;
        }
    }
    

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
	
case 39:
if ( a ==" AUTO" )
 {
 S(39);
 return 0;
 }
if ( a ==" REGISTER" )
 {
 S(39);
 return 0;
 }
if ( a ==" TYPEDEF" )
 {
 S(39);
 return 0;
 }
if ( a ==" EXTERN" )
 {
 S(39);
 return 0;
 }
if ( a ==" STATIC" )
 {
 S(39);
 return 0;
 }
return -1;
case 4:
if ( a ==" RESTRICT" )
 {
 S(4);
 return 0;
 }
return -1;
case 22:
if ( a ==" VOLATILE" )
 {
 S(22);
 return 0;
 }
return -1;
case 73:
if ( a ==" SIGNED" )
 {
 S(73);
 return 0;
 }
if ( a ==" ENUM" )
 {
 S(73);
 return 0;
 }
if ( a ==" CHAR" )
 {
 S(73);
 return 0;
 }
if ( a ==" VOID" )
 {
 S(73);
 return 0;
 }
if ( a ==" LONG" )
 {
 S(73);
 return 0;
 }
if ( a ==" EXTERN" )
 {
 S(73);
 return 0;
 }
if ( a ==" VOLATILE" )
 {
 S(73);
 return 0;
 }
if ( a ==" IMAGINARY" )
 {
 S(73);
 return 0;
 }
if ( a ==" STATIC" )
 {
 S(73);
 return 0;
 }
if ( a ==" STRUCT" )
 {
 S(73);
 return 0;
 }
if ( a ==" DOUBLE" )
 {
 S(73);
 return 0;
 }
if ( a ==" COMPLEX" )
 {
 S(73);
 return 0;
 }
if ( a ==" SHORT" )
 {
 S(73);
 return 0;
 }
if ( a ==" REGISTER" )
 {
 S(73);
 return 0;
 }
if ( a ==" TYPEDEF" )
 {
 S(73);
 return 0;
 }
if ( a ==" FLOAT" )
 {
 S(73);
 return 0;
 }
if ( a ==" AUTO" )
 {
 S(73);
 return 0;
 }
if ( a ==" UNSIGNED" )
 {
 S(73);
 return 0;
 }
if ( a ==" INT" )
 {
 S(73);
 return 0;
 }
if ( a ==" RESTRICT" )
 {
 S(73);
 return 0;
 }
if ( a ==" INLINE" )
 {
 S(73);
 return 0;
 }
if ( a ==" TYPE_NAME" )
 {
 S(73);
 return 0;
 }
if ( a ==" CONST" )
 {
 S(73);
 return 0;
 }
if ( a ==" UNION" )
 {
 S(73);
 return 0;
 }
if ( a ==" BOOL" )
 {
 S(73);
 return 0;
 }
return -1;
case 60:
if ( a ==" AUTO" )
 {
 S(60);
 return 0;
 }
return -1;
case 34:
if ( a ==" IMAGINARY" )
 {
 S(34);
 return 0;
 }
return -1;
case 18:
if ( a ==" SHORT" )
 {
 S(18);
 return 0;
 }
if ( a ==" FLOAT" )
 {
 S(18);
 return 0;
 }
if ( a ==" VOLATILE" )
 {
 S(18);
 return 0;
 }
if ( a ==" STATIC" )
 {
 S(18);
 return 0;
 }
if ( a ==" COMPLEX" )
 {
 S(18);
 return 0;
 }
if ( a ==" INT" )
 {
 S(18);
 return 0;
 }
if ( a ==" TYPEDEF" )
 {
 S(18);
 return 0;
 }
if ( a ==" EXTERN" )
 {
 S(18);
 return 0;
 }
if ( a ==" STRUCT" )
 {
 S(18);
 return 0;
 }
if ( a ==" AUTO" )
 {
 S(18);
 return 0;
 }
if ( a ==" UNSIGNED" )
 {
 S(18);
 return 0;
 }
if ( a ==" INLINE" )
 {
 S(18);
 return 0;
 }
if ( a ==" TYPE_NAME" )
 {
 S(18);
 return 0;
 }
if ( a ==" RESTRICT" )
 {
 S(18);
 return 0;
 }
if ( a ==" ENUM" )
 {
 S(18);
 return 0;
 }
if ( a ==" CHAR" )
 {
 S(18);
 return 0;
 }
if ( a ==" CONST" )
 {
 S(18);
 return 0;
 }
if ( a ==" SIGNED" )
 {
 S(18);
 return 0;
 }
if ( a ==" DOUBLE" )
 {
 S(18);
 return 0;
 }
if ( a ==" BOOL" )
 {
 S(18);
 return 0;
 }
if ( a ==" IMAGINARY" )
 {
 S(18);
 return 0;
 }
if ( a ==" LONG" )
 {
 S(18);
 return 0;
 }
if ( a ==" REGISTER" )
 {
 S(18);
 return 0;
 }
if ( a ==" UNION" )
 {
 S(18);
 return 0;
 }
if ( a ==" VOID" )
 {
 S(18);
 return 0;
 }
return -1;
case 43:
if ( a ==" VOLATILE" )
 {
 S(43);
 return 0;
 }
return -1;
case 48:
if ( a ==" EXTERN" )
 {
 S(48);
 return 0;
 }
return -1;
case 6:
if ( a ==" TYPEDEF" )
 {
 S(6);
 return 0;
 }
if ( a ==" EXTERN" )
 {
 S(6);
 return 0;
 }
if ( a ==" STATIC" )
 {
 S(6);
 return 0;
 }
if ( a ==" AUTO" )
 {
 S(6);
 return 0;
 }
if ( a ==" REGISTER" )
 {
 S(6);
 return 0;
 }
return -1;
case 11:
if ( a ==" ENUM" )
 {
 S(11);
 return 0;
 }
return -1;
case 64:
if ( a ==" DOUBLE" )
 {
 S(64);
 return 0;
 }
return -1;
case 55:
if ( a ==" INLINE" )
 {
 S(55);
 return 0;
 }
return -1;
case 12:
if ( a ==" SIGNED" )
 {
 S(12);
 return 0;
 }
if ( a ==" TYPE_NAME" )
 {
 S(12);
 return 0;
 }
if ( a ==" LONG" )
 {
 S(12);
 return 0;
 }
if ( a ==" CHAR" )
 {
 S(12);
 return 0;
 }
if ( a ==" ENUM" )
 {
 S(12);
 return 0;
 }
if ( a ==" INT" )
 {
 S(12);
 return 0;
 }
if ( a ==" BOOL" )
 {
 S(12);
 return 0;
 }
if ( a ==" IMAGINARY" )
 {
 S(12);
 return 0;
 }
if ( a ==" STRUCT" )
 {
 S(12);
 return 0;
 }
if ( a ==" COMPLEX" )
 {
 S(12);
 return 0;
 }
if ( a ==" SHORT" )
 {
 S(12);
 return 0;
 }
if ( a ==" DOUBLE" )
 {
 S(12);
 return 0;
 }
if ( a ==" VOID" )
 {
 S(12);
 return 0;
 }
if ( a ==" UNSIGNED" )
 {
 S(12);
 return 0;
 }
if ( a ==" FLOAT" )
 {
 S(12);
 return 0;
 }
if ( a ==" UNION" )
 {
 S(12);
 return 0;
 }
return -1;
case 27:
if ( a ==" UNION" )
 {
 S(27);
 return 0;
 }
if ( a ==" STRUCT" )
 {
 S(27);
 return 0;
 }
if ( a ==" UNSIGNED" )
 {
 S(27);
 return 0;
 }
if ( a ==" TYPEDEF" )
 {
 S(27);
 return 0;
 }
if ( a ==" DOUBLE" )
 {
 S(27);
 return 0;
 }
if ( a ==" EXTERN" )
 {
 S(27);
 return 0;
 }
if ( a ==" CONST" )
 {
 S(27);
 return 0;
 }
if ( a ==" FLOAT" )
 {
 S(27);
 return 0;
 }
if ( a ==" VOLATILE" )
 {
 S(27);
 return 0;
 }
if ( a ==" CHAR" )
 {
 S(27);
 return 0;
 }
if ( a ==" REGISTER" )
 {
 S(27);
 return 0;
 }
if ( a ==" ENUM" )
 {
 S(27);
 return 0;
 }
if ( a ==" LONG" )
 {
 S(27);
 return 0;
 }
if ( a ==" BOOL" )
 {
 S(27);
 return 0;
 }
if ( a ==" COMPLEX" )
 {
 S(27);
 return 0;
 }
if ( a ==" STATIC" )
 {
 S(27);
 return 0;
 }
if ( a ==" INT" )
 {
 S(27);
 return 0;
 }
if ( a ==" TYPE_NAME" )
 {
 S(27);
 return 0;
 }
if ( a ==" AUTO" )
 {
 S(27);
 return 0;
 }
if ( a ==" SIGNED" )
 {
 S(27);
 return 0;
 }
if ( a ==" INLINE" )
 {
 S(27);
 return 0;
 }
if ( a ==" SHORT" )
 {
 S(27);
 return 0;
 }
if ( a ==" IMAGINARY" )
 {
 S(27);
 return 0;
 }
if ( a ==" VOID" )
 {
 S(27);
 return 0;
 }
if ( a ==" RESTRICT" )
 {
 S(27);
 return 0;
 }
return -1;
case 56:
if ( a ==" COMPLEX" )
 {
 S(56);
 return 0;
 }
return -1;
case 59:
if ( a ==" TYPEDEF" )
 {
 S(59);
 return 0;
 }
return -1;
case 10:
if ( a ==" STRUCT" )
 {
 S(10);
 return 0;
 }
if ( a ==" UNION" )
 {
 S(10);
 return 0;
 }
return -1;
case 68:
if ( a ==" INT" )
 {
 S(68);
 return 0;
 }
return -1;
case 77:
if ( a ==" CHAR" )
 {
 S(77);
 return 0;
 }
if ( a ==" SIGNED" )
 {
 S(77);
 return 0;
 }
if ( a ==" STRUCT" )
 {
 S(77);
 return 0;
 }
if ( a ==" AUTO" )
 {
 S(77);
 return 0;
 }
if ( a ==" UNION" )
 {
 S(77);
 return 0;
 }
if ( a ==" RESTRICT" )
 {
 S(77);
 return 0;
 }
if ( a ==" IMAGINARY" )
 {
 S(77);
 return 0;
 }
if ( a ==" STATIC" )
 {
 S(77);
 return 0;
 }
if ( a ==" EXTERN" )
 {
 S(77);
 return 0;
 }
if ( a ==" LONG" )
 {
 S(77);
 return 0;
 }
if ( a ==" BOOL" )
 {
 S(77);
 return 0;
 }
if ( a ==" COMPLEX" )
 {
 S(77);
 return 0;
 }
if ( a ==" TYPEDEF" )
 {
 S(77);
 return 0;
 }
if ( a ==" VOLATILE" )
 {
 S(77);
 return 0;
 }
if ( a ==" INLINE" )
 {
 S(77);
 return 0;
 }
if ( a ==" FLOAT" )
 {
 S(77);
 return 0;
 }
if ( a ==" UNSIGNED" )
 {
 S(77);
 return 0;
 }
if ( a ==" REGISTER" )
 {
 S(77);
 return 0;
 }
if ( a ==" TYPE_NAME" )
 {
 S(77);
 return 0;
 }
if ( a ==" INT" )
 {
 S(77);
 return 0;
 }
if ( a ==" DOUBLE" )
 {
 S(77);
 return 0;
 }
if ( a ==" CONST" )
 {
 S(77);
 return 0;
 }
if ( a ==" ENUM" )
 {
 S(77);
 return 0;
 }
if ( a ==" VOID" )
 {
 S(77);
 return 0;
 }
if ( a ==" SHORT" )
 {
 S(77);
 return 0;
 }
return -1;
case 54:
if ( a ==" VOLATILE" )
 {
 S(54);
 return 0;
 }
if ( a ==" CONST" )
 {
 S(54);
 return 0;
 }
if ( a ==" RESTRICT" )
 {
 S(54);
 return 0;
 }
return -1;
case 25:
if ( a ==" LONG" )
 {
 S(25);
 return 0;
 }
return -1;
case 8:
if ( a ==" STATIC" )
 {
 S(8);
 return 0;
 }
return -1;
case 38:
if ( a ==" COMPLEX" )
 {
 S(38);
 return 0;
 }
return -1;
case 26:
if ( a ==" VOID" )
 {
 S(26);
 return 0;
 }
if ( a ==" UNSIGNED" )
 {
 S(26);
 return 0;
 }
if ( a ==" DOUBLE" )
 {
 S(26);
 return 0;
 }
if ( a ==" RESTRICT" )
 {
 S(26);
 return 0;
 }
if ( a ==" COMPLEX" )
 {
 S(26);
 return 0;
 }
if ( a ==" t" )
 {
 S(26);
 return 0;
 }
if ( a ==" REGISTER" )
 {
 S(26);
 return 0;
 }
if ( a ==" VOLATILE" )
 {
 S(26);
 return 0;
 }
if ( a ==" INT" )
 {
 S(26);
 return 0;
 }
if ( a ==" SHORT" )
 {
 S(26);
 return 0;
 }
if ( a ==" IMAGINARY" )
 {
 S(26);
 return 0;
 }
if ( a ==" ENUM" )
 {
 S(26);
 return 0;
 }
if ( a ==" LONG" )
 {
 S(26);
 return 0;
 }
if ( a ==" UNION" )
 {
 S(26);
 return 0;
 }
if ( a ==" TYPEDEF" )
 {
 S(26);
 return 0;
 }
if ( a ==" CONST" )
 {
 S(26);
 return 0;
 }
if ( a ==" AUTO" )
 {
 S(26);
 return 0;
 }
if ( a ==" STATIC" )
 {
 S(26);
 return 0;
 }
if ( a ==" INLINE" )
 {
 S(26);
 return 0;
 }
if ( a ==" EXTERN" )
 {
 S(26);
 return 0;
 }
if ( a ==" SIGNED" )
 {
 S(26);
 return 0;
 }
if ( a ==" TYPE_NAME" )
 {
 S(26);
 return 0;
 }
if ( a ==" FLOAT" )
 {
 S(26);
 return 0;
 }
if ( a ==" BOOL" )
 {
 S(26);
 return 0;
 }
if ( a ==" CHAR" )
 {
 S(26);
 return 0;
 }
if ( a ==" STRUCT" )
 {
 S(26);
 return 0;
 }
return -1;
case 32:
if ( a ==" DOUBLE" )
 {
 S(32);
 return 0;
 }
return -1;
case 35:
if ( a ==" AUTO" )
 {
 S(35);
 return 0;
 }
return -1;
case 58:
if ( a ==" ENUM" )
 {
 S(58);
 return 0;
 }
return -1;
case 0:
if ( a ==" REGISTER" )
 {
 S(0);
 return 0;
 }
if ( a ==" INT" )
 {
 S(0);
 return 0;
 }
if ( a ==" EXTERN" )
 {
 S(0);
 return 0;
 }
if ( a ==" STATIC" )
 {
 S(0);
 return 0;
 }
if ( a ==" VOID" )
 {
 S(0);
 return 0;
 }
if ( a ==" DOUBLE" )
 {
 S(0);
 return 0;
 }
if ( a ==" IMAGINARY" )
 {
 S(0);
 return 0;
 }
if ( a ==" COMPLEX" )
 {
 S(0);
 return 0;
 }
if ( a ==" TYPEDEF" )
 {
 S(0);
 return 0;
 }
if ( a ==" SHORT" )
 {
 S(0);
 return 0;
 }
if ( a ==" UNION" )
 {
 S(0);
 return 0;
 }
if ( a ==" SIGNED" )
 {
 S(0);
 return 0;
 }
if ( a ==" t" )
 {
 S(0);
 return 0;
 }
if ( a ==" UNSIGNED" )
 {
 S(0);
 return 0;
 }
if ( a ==" AUTO" )
 {
 S(0);
 return 0;
 }
if ( a ==" TYPE_NAME" )
 {
 S(0);
 return 0;
 }
if ( a ==" LONG" )
 {
 S(0);
 return 0;
 }
if ( a ==" INLINE" )
 {
 S(0);
 return 0;
 }
if ( a ==" VOLATILE" )
 {
 S(0);
 return 0;
 }
if ( a ==" FLOAT" )
 {
 S(0);
 return 0;
 }
if ( a ==" STRUCT" )
 {
 S(0);
 return 0;
 }
if ( a ==" CONST" )
 {
 S(0);
 return 0;
 }
if ( a ==" RESTRICT" )
 {
 S(0);
 return 0;
 }
if ( a ==" BOOL" )
 {
 S(0);
 return 0;
 }
if ( a ==" ENUM" )
 {
 S(0);
 return 0;
 }
if ( a ==" CHAR" )
 {
 S(0);
 return 0;
 }
return -1;
case 53:
if ( a ==" VOID" )
 {
 S(53);
 return 0;
 }
if ( a ==" COMPLEX" )
 {
 S(53);
 return 0;
 }
if ( a ==" IMAGINARY" )
 {
 S(53);
 return 0;
 }
if ( a ==" TYPE_NAME" )
 {
 S(53);
 return 0;
 }
if ( a ==" ENUM" )
 {
 S(53);
 return 0;
 }
if ( a ==" DOUBLE" )
 {
 S(53);
 return 0;
 }
if ( a ==" INT" )
 {
 S(53);
 return 0;
 }
if ( a ==" CHAR" )
 {
 S(53);
 return 0;
 }
if ( a ==" LONG" )
 {
 S(53);
 return 0;
 }
if ( a ==" SHORT" )
 {
 S(53);
 return 0;
 }
if ( a ==" UNION" )
 {
 S(53);
 return 0;
 }
if ( a ==" SIGNED" )
 {
 S(53);
 return 0;
 }
if ( a ==" BOOL" )
 {
 S(53);
 return 0;
 }
if ( a ==" STRUCT" )
 {
 S(53);
 return 0;
 }
if ( a ==" FLOAT" )
 {
 S(53);
 return 0;
 }
if ( a ==" UNSIGNED" )
 {
 S(53);
 return 0;
 }
return -1;
case 52:
if ( a ==" UNION" )
 {
 S(52);
 return 0;
 }
if ( a ==" CHAR" )
 {
 S(52);
 return 0;
 }
if ( a ==" ENUM" )
 {
 S(52);
 return 0;
 }
if ( a ==" CONST" )
 {
 S(52);
 return 0;
 }
if ( a ==" SIGNED" )
 {
 S(52);
 return 0;
 }
if ( a ==" TYPEDEF" )
 {
 S(52);
 return 0;
 }
if ( a ==" VOLATILE" )
 {
 S(52);
 return 0;
 }
if ( a ==" VOID" )
 {
 S(52);
 return 0;
 }
if ( a ==" COMPLEX" )
 {
 S(52);
 return 0;
 }
if ( a ==" UNSIGNED" )
 {
 S(52);
 return 0;
 }
if ( a ==" AUTO" )
 {
 S(52);
 return 0;
 }
if ( a ==" RESTRICT" )
 {
 S(52);
 return 0;
 }
if ( a ==" STRUCT" )
 {
 S(52);
 return 0;
 }
if ( a ==" EXTERN" )
 {
 S(52);
 return 0;
 }
if ( a ==" DOUBLE" )
 {
 S(52);
 return 0;
 }
if ( a ==" IMAGINARY" )
 {
 S(52);
 return 0;
 }
if ( a ==" INT" )
 {
 S(52);
 return 0;
 }
if ( a ==" REGISTER" )
 {
 S(52);
 return 0;
 }
if ( a ==" SHORT" )
 {
 S(52);
 return 0;
 }
if ( a ==" STATIC" )
 {
 S(52);
 return 0;
 }
if ( a ==" TYPE_NAME" )
 {
 S(52);
 return 0;
 }
if ( a ==" INLINE" )
 {
 S(52);
 return 0;
 }
if ( a ==" LONG" )
 {
 S(52);
 return 0;
 }
if ( a ==" FLOAT" )
 {
 S(52);
 return 0;
 }
if ( a ==" BOOL" )
 {
 S(52);
 return 0;
 }
return -1;
case 21:
if ( a ==" CHAR" )
 {
 S(21);
 return 0;
 }
return -1;
case 7:
if ( a ==" EXTERN" )
 {
 S(7);
 return 0;
 }
return -1;
case 33:
if ( a ==" BOOL" )
 {
 S(33);
 return 0;
 }
return -1;
case 15:
if ( a ==" UNSIGNED" )
 {
 S(15);
 return 0;
 }
return -1;
case 61:
if ( a ==" RESTRICT" )
 {
 S(61);
 return 0;
 }
return -1;
case 62:
if ( a ==" CHAR" )
 {
 S(62);
 return 0;
 }
return -1;
case 63:
if ( a ==" SHORT" )
 {
 S(63);
 return 0;
 }
return -1;
case 9:
if ( a ==" STRUCT" )
 {
 S(9);
 return 0;
 }
if ( a ==" UNION" )
 {
 S(9);
 return 0;
 }
return -1;
case 19:
if ( a ==" IMAGINARY" )
 {
 S(19);
 return 0;
 }
if ( a ==" INT" )
 {
 S(19);
 return 0;
 }
if ( a ==" SIGNED" )
 {
 S(19);
 return 0;
 }
if ( a ==" TYPE_NAME" )
 {
 S(19);
 return 0;
 }
if ( a ==" ENUM" )
 {
 S(19);
 return 0;
 }
if ( a ==" DOUBLE" )
 {
 S(19);
 return 0;
 }
if ( a ==" UNION" )
 {
 S(19);
 return 0;
 }
if ( a ==" COMPLEX" )
 {
 S(19);
 return 0;
 }
if ( a ==" VOID" )
 {
 S(19);
 return 0;
 }
if ( a ==" AUTO" )
 {
 S(19);
 return 0;
 }
if ( a ==" SHORT" )
 {
 S(19);
 return 0;
 }
if ( a ==" FLOAT" )
 {
 S(19);
 return 0;
 }
if ( a ==" BOOL" )
 {
 S(19);
 return 0;
 }
if ( a ==" UNSIGNED" )
 {
 S(19);
 return 0;
 }
if ( a ==" LONG" )
 {
 S(19);
 return 0;
 }
if ( a ==" CONST" )
 {
 S(19);
 return 0;
 }
if ( a ==" REGISTER" )
 {
 S(19);
 return 0;
 }
if ( a ==" RESTRICT" )
 {
 S(19);
 return 0;
 }
if ( a ==" VOLATILE" )
 {
 S(19);
 return 0;
 }
if ( a ==" STATIC" )
 {
 S(19);
 return 0;
 }
if ( a ==" CHAR" )
 {
 S(19);
 return 0;
 }
if ( a ==" STRUCT" )
 {
 S(19);
 return 0;
 }
if ( a ==" INLINE" )
 {
 S(19);
 return 0;
 }
if ( a ==" EXTERN" )
 {
 S(19);
 return 0;
 }
if ( a ==" TYPEDEF" )
 {
 S(19);
 return 0;
 }
return -1;
case 16:
if ( a ==" CONST" )
 {
 S(16);
 return 0;
 }
return -1;
case 29:
if ( a ==" REGISTER" )
 {
 S(29);
 return 0;
 }
return -1;
case 3:
if ( a ==" TYPE_NAME" )
 {
 S(3);
 return 0;
 }
return -1;
case 24:
if ( a ==" STRUCT" )
 {
 S(24);
 return 0;
 }
return -1;
case 30:
if ( a ==" VOID" )
 {
 S(30);
 return 0;
 }
return -1;
case 67:
if ( a ==" STATIC" )
 {
 S(67);
 return 0;
 }
return -1;
case 49:
if ( a ==" REGISTER" )
 {
 S(49);
 return 0;
 }
return -1;
case 51:
if ( a ==" BOOL" )
 {
 S(51);
 return 0;
 }
return -1;
case 13:
if ( a ==" RESTRICT" )
 {
 S(13);
 return 0;
 }
if ( a ==" VOLATILE" )
 {
 S(13);
 return 0;
 }
if ( a ==" CONST" )
 {
 S(13);
 return 0;
 }
return -1;
case 46:
if ( a ==" UNSIGNED" )
 {
 S(46);
 return 0;
 }
return -1;
case 74:
if ( a ==" VOID" )
 {
 S(74);
 return 0;
 }
if ( a ==" COMPLEX" )
 {
 S(74);
 return 0;
 }
if ( a ==" CHAR" )
 {
 S(74);
 return 0;
 }
if ( a ==" CONST" )
 {
 S(74);
 return 0;
 }
if ( a ==" ENUM" )
 {
 S(74);
 return 0;
 }
if ( a ==" VOLATILE" )
 {
 S(74);
 return 0;
 }
if ( a ==" FLOAT" )
 {
 S(74);
 return 0;
 }
if ( a ==" BOOL" )
 {
 S(74);
 return 0;
 }
if ( a ==" UNSIGNED" )
 {
 S(74);
 return 0;
 }
if ( a ==" REGISTER" )
 {
 S(74);
 return 0;
 }
if ( a ==" AUTO" )
 {
 S(74);
 return 0;
 }
if ( a ==" EXTERN" )
 {
 S(74);
 return 0;
 }
if ( a ==" INT" )
 {
 S(74);
 return 0;
 }
if ( a ==" TYPE_NAME" )
 {
 S(74);
 return 0;
 }
if ( a ==" LONG" )
 {
 S(74);
 return 0;
 }
if ( a ==" SIGNED" )
 {
 S(74);
 return 0;
 }
if ( a ==" DOUBLE" )
 {
 S(74);
 return 0;
 }
if ( a ==" TYPEDEF" )
 {
 S(74);
 return 0;
 }
if ( a ==" RESTRICT" )
 {
 S(74);
 return 0;
 }
if ( a ==" STATIC" )
 {
 S(74);
 return 0;
 }
if ( a ==" UNION" )
 {
 S(74);
 return 0;
 }
if ( a ==" INLINE" )
 {
 S(74);
 return 0;
 }
if ( a ==" SHORT" )
 {
 S(74);
 return 0;
 }
if ( a ==" IMAGINARY" )
 {
 S(74);
 return 0;
 }
if ( a ==" STRUCT" )
 {
 S(74);
 return 0;
 }
return -1;
case 5:
if ( a ==" TYPE_NAME" )
 {
 S(5);
 return 0;
 }
if ( a ==" BOOL" )
 {
 S(5);
 return 0;
 }
if ( a ==" STRUCT" )
 {
 S(5);
 return 0;
 }
if ( a ==" CONST" )
 {
 S(5);
 return 0;
 }
if ( a ==" VOID" )
 {
 S(5);
 return 0;
 }
if ( a ==" ENUM" )
 {
 S(5);
 return 0;
 }
if ( a ==" DOUBLE" )
 {
 S(5);
 return 0;
 }
if ( a ==" TYPEDEF" )
 {
 S(5);
 return 0;
 }
if ( a ==" INLINE" )
 {
 S(5);
 return 0;
 }
if ( a ==" IMAGINARY" )
 {
 S(5);
 return 0;
 }
if ( a ==" SIGNED" )
 {
 S(5);
 return 0;
 }
if ( a ==" REGISTER" )
 {
 S(5);
 return 0;
 }
if ( a ==" INT" )
 {
 S(5);
 return 0;
 }
if ( a ==" LONG" )
 {
 S(5);
 return 0;
 }
if ( a ==" CHAR" )
 {
 S(5);
 return 0;
 }
if ( a ==" COMPLEX" )
 {
 S(5);
 return 0;
 }
if ( a ==" RESTRICT" )
 {
 S(5);
 return 0;
 }
if ( a ==" FLOAT" )
 {
 S(5);
 return 0;
 }
if ( a ==" UNSIGNED" )
 {
 S(5);
 return 0;
 }
if ( a ==" STATIC" )
 {
 S(5);
 return 0;
 }
if ( a ==" UNION" )
 {
 S(5);
 return 0;
 }
if ( a ==" VOLATILE" )
 {
 S(5);
 return 0;
 }
if ( a ==" EXTERN" )
 {
 S(5);
 return 0;
 }
if ( a ==" SHORT" )
 {
 S(5);
 return 0;
 }
if ( a ==" AUTO" )
 {
 S(5);
 return 0;
 }
return -1;
case 17:
if ( a ==" INLINE" )
 {
 S(17);
 return 0;
 }
return -1;
case 23:
if ( a ==" ENUM" )
 {
 S(23);
 return 0;
 }
return -1;
case 47:
if ( a ==" TYPE_NAME" )
 {
 S(47);
 return 0;
 }
return -1;
case 76:
if ( a ==" IMAGINARY" )
 {
 S(76);
 return 0;
 }
if ( a ==" FLOAT" )
 {
 S(76);
 return 0;
 }
if ( a ==" SHORT" )
 {
 S(76);
 return 0;
 }
if ( a ==" TYPE_NAME" )
 {
 S(76);
 return 0;
 }
if ( a ==" CONST" )
 {
 S(76);
 return 0;
 }
if ( a ==" UNION" )
 {
 S(76);
 return 0;
 }
if ( a ==" BOOL" )
 {
 S(76);
 return 0;
 }
if ( a ==" AUTO" )
 {
 S(76);
 return 0;
 }
if ( a ==" STATIC" )
 {
 S(76);
 return 0;
 }
if ( a ==" COMPLEX" )
 {
 S(76);
 return 0;
 }
if ( a ==" EXTERN" )
 {
 S(76);
 return 0;
 }
if ( a ==" REGISTER" )
 {
 S(76);
 return 0;
 }
if ( a ==" CHAR" )
 {
 S(76);
 return 0;
 }
if ( a ==" LONG" )
 {
 S(76);
 return 0;
 }
if ( a ==" INT" )
 {
 S(76);
 return 0;
 }
if ( a ==" INLINE" )
 {
 S(76);
 return 0;
 }
if ( a ==" RESTRICT" )
 {
 S(76);
 return 0;
 }
if ( a ==" TYPEDEF" )
 {
 S(76);
 return 0;
 }
if ( a ==" SIGNED" )
 {
 S(76);
 return 0;
 }
if ( a ==" UNSIGNED" )
 {
 S(76);
 return 0;
 }
if ( a ==" VOID" )
 {
 S(76);
 return 0;
 }
if ( a ==" VOLATILE" )
 {
 S(76);
 return 0;
 }
if ( a ==" STRUCT" )
 {
 S(76);
 return 0;
 }
if ( a ==" DOUBLE" )
 {
 S(76);
 return 0;
 }
if ( a ==" ENUM" )
 {
 S(76);
 return 0;
 }
return -1;
case 70:
if ( a ==" STATIC" )
 {
 S(70);
 return 0;
 }
if ( a ==" BOOL" )
 {
 S(70);
 return 0;
 }
if ( a ==" VOID" )
 {
 S(70);
 return 0;
 }
if ( a ==" SIGNED" )
 {
 S(70);
 return 0;
 }
if ( a ==" SHORT" )
 {
 S(70);
 return 0;
 }
if ( a ==" IMAGINARY" )
 {
 S(70);
 return 0;
 }
if ( a ==" LONG" )
 {
 S(70);
 return 0;
 }
if ( a ==" ENUM" )
 {
 S(70);
 return 0;
 }
if ( a ==" COMPLEX" )
 {
 S(70);
 return 0;
 }
if ( a ==" RESTRICT" )
 {
 S(70);
 return 0;
 }
if ( a ==" TYPEDEF" )
 {
 S(70);
 return 0;
 }
if ( a ==" AUTO" )
 {
 S(70);
 return 0;
 }
if ( a ==" TYPE_NAME" )
 {
 S(70);
 return 0;
 }
if ( a ==" UNION" )
 {
 S(70);
 return 0;
 }
if ( a ==" DOUBLE" )
 {
 S(70);
 return 0;
 }
if ( a ==" INLINE" )
 {
 S(70);
 return 0;
 }
if ( a ==" FLOAT" )
 {
 S(70);
 return 0;
 }
if ( a ==" CHAR" )
 {
 S(70);
 return 0;
 }
if ( a ==" CONST" )
 {
 S(70);
 return 0;
 }
if ( a ==" EXTERN" )
 {
 S(70);
 return 0;
 }
if ( a ==" VOLATILE" )
 {
 S(70);
 return 0;
 }
if ( a ==" STRUCT" )
 {
 S(70);
 return 0;
 }
if ( a ==" REGISTER" )
 {
 S(70);
 return 0;
 }
if ( a ==" UNSIGNED" )
 {
 S(70);
 return 0;
 }
if ( a ==" INT" )
 {
 S(70);
 return 0;
 }
return -1;
case 44:
if ( a ==" VOID" )
 {
 S(44);
 return 0;
 }
return -1;
case 66:
if ( a ==" INLINE" )
 {
 S(66);
 return 0;
 }
return -1;
case 36:
if ( a ==" SHORT" )
 {
 S(36);
 return 0;
 }
return -1;
case 42:
if ( a ==" CONST" )
 {
 S(42);
 return 0;
 }
return -1;
case 14:
if ( a ==" INLINE" )
 {
 S(14);
 return 0;
 }
return -1;
case 28:
if ( a ==" SIGNED" )
 {
 S(28);
 return 0;
 }
if ( a ==" VOLATILE" )
 {
 S(28);
 return 0;
 }
if ( a ==" LONG" )
 {
 S(28);
 return 0;
 }
if ( a ==" AUTO" )
 {
 S(28);
 return 0;
 }
if ( a ==" CHAR" )
 {
 S(28);
 return 0;
 }
if ( a ==" EXTERN" )
 {
 S(28);
 return 0;
 }
if ( a ==" VOID" )
 {
 S(28);
 return 0;
 }
if ( a ==" INT" )
 {
 S(28);
 return 0;
 }
if ( a ==" UNION" )
 {
 S(28);
 return 0;
 }
if ( a ==" COMPLEX" )
 {
 S(28);
 return 0;
 }
if ( a ==" ENUM" )
 {
 S(28);
 return 0;
 }
if ( a ==" TYPE_NAME" )
 {
 S(28);
 return 0;
 }
if ( a ==" UNSIGNED" )
 {
 S(28);
 return 0;
 }
if ( a ==" FLOAT" )
 {
 S(28);
 return 0;
 }
if ( a ==" INLINE" )
 {
 S(28);
 return 0;
 }
if ( a ==" IMAGINARY" )
 {
 S(28);
 return 0;
 }
if ( a ==" RESTRICT" )
 {
 S(28);
 return 0;
 }
if ( a ==" CONST" )
 {
 S(28);
 return 0;
 }
if ( a ==" BOOL" )
 {
 S(28);
 return 0;
 }
if ( a ==" SHORT" )
 {
 S(28);
 return 0;
 }
if ( a ==" DOUBLE" )
 {
 S(28);
 return 0;
 }
if ( a ==" STATIC" )
 {
 S(28);
 return 0;
 }
if ( a ==" STRUCT" )
 {
 S(28);
 return 0;
 }
if ( a ==" REGISTER" )
 {
 S(28);
 return 0;
 }
if ( a ==" TYPEDEF" )
 {
 S(28);
 return 0;
 }
return -1;
case 40:
if ( a ==" FLOAT" )
 {
 S(40);
 return 0;
 }
return -1;
case 69:
if ( a ==" IMAGINARY" )
 {
 S(69);
 return 0;
 }
return -1;
case 20:
if ( a ==" TYPEDEF" )
 {
 S(20);
 return 0;
 }
return -1;
case 57:
if ( a ==" STRUCT" )
 {
 S(57);
 return 0;
 }
if ( a ==" UNION" )
 {
 S(57);
 return 0;
 }
return -1;
case 65:
if ( a ==" ENUM" )
 {
 S(65);
 return 0;
 }
return -1;
case 50:
if ( a ==" LONG" )
 {
 S(50);
 return 0;
 }
return -1;
case 37:
if ( a ==" INT" )
 {
 S(37);
 return 0;
 }
return -1;
case 71:
if ( a ==" UNSIGNED" )
 {
 S(71);
 return 0;
 }
if ( a ==" SIGNED" )
 {
 S(71);
 return 0;
 }
if ( a ==" ENUM" )
 {
 S(71);
 return 0;
 }
if ( a ==" EXTERN" )
 {
 S(71);
 return 0;
 }
if ( a ==" STRUCT" )
 {
 S(71);
 return 0;
 }
if ( a ==" VOID" )
 {
 S(71);
 return 0;
 }
if ( a ==" CONST" )
 {
 S(71);
 return 0;
 }
if ( a ==" TYPE_NAME" )
 {
 S(71);
 return 0;
 }
if ( a ==" COMPLEX" )
 {
 S(71);
 return 0;
 }
if ( a ==" LONG" )
 {
 S(71);
 return 0;
 }
if ( a ==" BOOL" )
 {
 S(71);
 return 0;
 }
if ( a ==" TYPEDEF" )
 {
 S(71);
 return 0;
 }
if ( a ==" INLINE" )
 {
 S(71);
 return 0;
 }
if ( a ==" VOLATILE" )
 {
 S(71);
 return 0;
 }
if ( a ==" SHORT" )
 {
 S(71);
 return 0;
 }
if ( a ==" IMAGINARY" )
 {
 S(71);
 return 0;
 }
if ( a ==" RESTRICT" )
 {
 S(71);
 return 0;
 }
if ( a ==" INT" )
 {
 S(71);
 return 0;
 }
if ( a ==" STATIC" )
 {
 S(71);
 return 0;
 }
if ( a ==" REGISTER" )
 {
 S(71);
 return 0;
 }
if ( a ==" AUTO" )
 {
 S(71);
 return 0;
 }
if ( a ==" CHAR" )
 {
 S(71);
 return 0;
 }
if ( a ==" UNION" )
 {
 S(71);
 return 0;
 }
if ( a ==" DOUBLE" )
 {
 S(71);
 return 0;
 }
if ( a ==" FLOAT" )
 {
 S(71);
 return 0;
 }
return -1;
case 41:
if ( a ==" STRUCT" )
 {
 S(41);
 return 0;
 }
if ( a ==" UNION" )
 {
 S(41);
 return 0;
 }
return -1;
case 72:
if ( a ==" CHAR" )
 {
 S(72);
 return 0;
 }
if ( a ==" REGISTER" )
 {
 S(72);
 return 0;
 }
if ( a ==" VOLATILE" )
 {
 S(72);
 return 0;
 }
if ( a ==" UNSIGNED" )
 {
 S(72);
 return 0;
 }
if ( a ==" SIGNED" )
 {
 S(72);
 return 0;
 }
if ( a ==" EXTERN" )
 {
 S(72);
 return 0;
 }
if ( a ==" UNION" )
 {
 S(72);
 return 0;
 }
if ( a ==" INT" )
 {
 S(72);
 return 0;
 }
if ( a ==" RESTRICT" )
 {
 S(72);
 return 0;
 }
if ( a ==" INLINE" )
 {
 S(72);
 return 0;
 }
if ( a ==" TYPEDEF" )
 {
 S(72);
 return 0;
 }
if ( a ==" AUTO" )
 {
 S(72);
 return 0;
 }
if ( a ==" SHORT" )
 {
 S(72);
 return 0;
 }
if ( a ==" COMPLEX" )
 {
 S(72);
 return 0;
 }
if ( a ==" DOUBLE" )
 {
 S(72);
 return 0;
 }
if ( a ==" CONST" )
 {
 S(72);
 return 0;
 }
if ( a ==" IMAGINARY" )
 {
 S(72);
 return 0;
 }
if ( a ==" LONG" )
 {
 S(72);
 return 0;
 }
if ( a ==" TYPE_NAME" )
 {
 S(72);
 return 0;
 }
if ( a ==" ENUM" )
 {
 S(72);
 return 0;
 }
if ( a ==" STRUCT" )
 {
 S(72);
 return 0;
 }
if ( a ==" FLOAT" )
 {
 S(72);
 return 0;
 }
if ( a ==" STATIC" )
 {
 S(72);
 return 0;
 }
if ( a ==" VOID" )
 {
 S(72);
 return 0;
 }
if ( a ==" BOOL" )
 {
 S(72);
 return 0;
 }
return -1;
case 31:
if ( a ==" UNION" )
 {
 S(31);
 return 0;
 }
return -1;
case 75:
if ( a ==" UNSIGNED" )
 {
 S(75);
 return 0;
 }
if ( a ==" VOID" )
 {
 S(75);
 return 0;
 }
if ( a ==" CHAR" )
 {
 S(75);
 return 0;
 }
if ( a ==" AUTO" )
 {
 S(75);
 return 0;
 }
if ( a ==" SHORT" )
 {
 S(75);
 return 0;
 }
if ( a ==" ENUM" )
 {
 S(75);
 return 0;
 }
if ( a ==" TYPEDEF" )
 {
 S(75);
 return 0;
 }
if ( a ==" STATIC" )
 {
 S(75);
 return 0;
 }
if ( a ==" UNION" )
 {
 S(75);
 return 0;
 }
if ( a ==" REGISTER" )
 {
 S(75);
 return 0;
 }
if ( a ==" EXTERN" )
 {
 S(75);
 return 0;
 }
if ( a ==" FLOAT" )
 {
 S(75);
 return 0;
 }
if ( a ==" IMAGINARY" )
 {
 S(75);
 return 0;
 }
if ( a ==" INLINE" )
 {
 S(75);
 return 0;
 }
if ( a ==" INT" )
 {
 S(75);
 return 0;
 }
if ( a ==" COMPLEX" )
 {
 S(75);
 return 0;
 }
if ( a ==" CONST" )
 {
 S(75);
 return 0;
 }
if ( a ==" SIGNED" )
 {
 S(75);
 return 0;
 }
if ( a ==" RESTRICT" )
 {
 S(75);
 return 0;
 }
if ( a ==" DOUBLE" )
 {
 S(75);
 return 0;
 }
if ( a ==" LONG" )
 {
 S(75);
 return 0;
 }
if ( a ==" VOLATILE" )
 {
 S(75);
 return 0;
 }
if ( a ==" TYPE_NAME" )
 {
 S(75);
 return 0;
 }
if ( a ==" BOOL" )
 {
 S(75);
 return 0;
 }
if ( a ==" STRUCT" )
 {
 S(75);
 return 0;
 }
return -1;
case 45:
if ( a ==" SIGNED" )
 {
 S(45);
 return 0;
 }
return -1;
case 2:
if ( a ==" SIGNED" )
 {
 S(2);
 return 0;
 }
return -1;
case 1:
if ( a ==" FLOAT" )
 {
 S(1);
 return 0;
 }
return -1;

            default:
                return -1;
        }
    }
    

    int gotoTable(int t, std::string vn) {
        switch (t) {
	
case39:
 if (vn == "storage_class_specifier") 
 return 39;
return -1;
case4:

return -1;
case22:

return -1;
case73:
 if (vn == "function_specifier") 
 return 14;
 if (vn == "declaration_specifiers") 
 return 77;
 if (vn == "declaration") 
 return 73;
 if (vn == "storage_class_specifier") 
 return 6;
 if (vn == "struct_or_union_specifier") 
 return 10;
 if (vn == "type_qualifier") 
 return 13;
 if (vn == "enum_specifier") 
 return 11;
 if (vn == "type_specifier") 
 return 12;
 if (vn == "struct_or_union") 
 return 9;
return -1;
case60:

return -1;
case34:

return -1;
case18:
 if (vn == "function_specifier") 
 return 14;
 if (vn == "enum_specifier") 
 return 11;
 if (vn == "struct_or_union_specifier") 
 return 10;
 if (vn == "function_definition") 
 return 72;
 if (vn == "type_qualifier") 
 return 13;
 if (vn == "translation_unit") 
 return 74;
 if (vn == "struct_or_union") 
 return 9;
 if (vn == "external_declaration") 
 return 70;
 if (vn == "storage_class_specifier") 
 return 6;
 if (vn == "declaration_specifiers") 
 return 71;
 if (vn == "type_specifier") 
 return 12;
 if (vn == "declaration") 
 return 73;
return -1;
case43:

return -1;
case48:

return -1;
case6:
 if (vn == "storage_class_specifier") 
 return 6;
return -1;
case11:
 if (vn == "enum_specifier") 
 return 11;
return -1;
case64:

return -1;
case55:
 if (vn == "function_specifier") 
 return 55;
return -1;
case12:
 if (vn == "enum_specifier") 
 return 11;
 if (vn == "struct_or_union_specifier") 
 return 10;
 if (vn == "type_specifier") 
 return 12;
 if (vn == "struct_or_union") 
 return 9;
return -1;
case27:
 if (vn == "declaration_specifiers") 
 return 19;
 if (vn == "enum_specifier") 
 return 11;
 if (vn == "function_specifier") 
 return 14;
 if (vn == "storage_class_specifier") 
 return 6;
 if (vn == "type_specifier") 
 return 12;
 if (vn == "external_declaration") 
 return 27;
 if (vn == "declaration") 
 return 28;
 if (vn == "function_definition") 
 return 5;
 if (vn == "struct_or_union") 
 return 9;
 if (vn == "struct_or_union_specifier") 
 return 10;
 if (vn == "type_qualifier") 
 return 13;
return -1;
case56:

return -1;
case59:

return -1;
case10:
 if (vn == "struct_or_union") 
 return 9;
 if (vn == "struct_or_union_specifier") 
 return 10;
return -1;
case68:

return -1;
case77:
 if (vn == "struct_or_union") 
 return 9;
 if (vn == "enum_specifier") 
 return 11;
 if (vn == "declaration_specifiers") 
 return 77;
 if (vn == "storage_class_specifier") 
 return 6;
 if (vn == "type_specifier") 
 return 12;
 if (vn == "function_specifier") 
 return 14;
 if (vn == "type_qualifier") 
 return 13;
 if (vn == "struct_or_union_specifier") 
 return 10;
return -1;
case54:
 if (vn == "type_qualifier") 
 return 54;
return -1;
case25:

return -1;
case8:

return -1;
case38:

return -1;
case26:
 if (vn == "type_specifier") 
 return 12;
 if (vn == "external_declaration") 
 return 27;
 if (vn == "enum_specifier") 
 return 11;
 if (vn == "function_specifier") 
 return 14;
 if (vn == "struct_or_union") 
 return 9;
 if (vn == "type_qualifier") 
 return 13;
 if (vn == "struct_or_union_specifier") 
 return 10;
 if (vn == "function_definition") 
 return 5;
 if (vn == "declaration") 
 return 28;
 if (vn == "storage_class_specifier") 
 return 6;
 if (vn == "declaration_specifiers") 
 return 19;
 if (vn == "translation_unit") 
 return 18;
return -1;
case32:

return -1;
case35:

return -1;
case58:

return -1;
case0:
 if (vn == "declaration_specifiers") 
 return 19;
 if (vn == "enum_specifier") 
 return 11;
 if (vn == "function_definition") 
 return 5;
 if (vn == "declaration") 
 return 28;
 if (vn == "type_qualifier") 
 return 13;
 if (vn == "struct_or_union") 
 return 9;
 if (vn == "translation_unit") 
 return 18;
 if (vn == "storage_class_specifier") 
 return 6;
 if (vn == "struct_or_union_specifier") 
 return 10;
 if (vn == "function_specifier") 
 return 14;
 if (vn == "external_declaration") 
 return 27;
 if (vn == "type_specifier") 
 return 12;
return -1;
case53:
 if (vn == "type_specifier") 
 return 53;
 if (vn == "struct_or_union_specifier") 
 return 41;
 if (vn == "enum_specifier") 
 return 65;
 if (vn == "struct_or_union") 
 return 57;
return -1;
case52:
 if (vn == "struct_or_union") 
 return 57;
 if (vn == "type_qualifier") 
 return 54;
 if (vn == "function_specifier") 
 return 55;
 if (vn == "declaration_specifiers") 
 return 52;
 if (vn == "struct_or_union_specifier") 
 return 41;
 if (vn == "type_specifier") 
 return 53;
 if (vn == "enum_specifier") 
 return 65;
 if (vn == "storage_class_specifier") 
 return 39;
return -1;
case21:

return -1;
case7:

return -1;
case33:

return -1;
case15:

return -1;
case61:

return -1;
case62:

return -1;
case63:

return -1;
case9:
 if (vn == "struct_or_union") 
 return 9;
return -1;
case19:
 if (vn == "storage_class_specifier") 
 return 6;
 if (vn == "enum_specifier") 
 return 11;
 if (vn == "struct_or_union_specifier") 
 return 10;
 if (vn == "type_qualifier") 
 return 13;
 if (vn == "function_specifier") 
 return 14;
 if (vn == "type_specifier") 
 return 12;
 if (vn == "declaration_specifiers") 
 return 19;
 if (vn == "struct_or_union") 
 return 9;
return -1;
case16:

return -1;
case29:

return -1;
case3:

return -1;
case24:

return -1;
case30:

return -1;
case67:

return -1;
case49:

return -1;
case51:

return -1;
case13:
 if (vn == "type_qualifier") 
 return 13;
return -1;
case46:

return -1;
case74:
 if (vn == "external_declaration") 
 return 70;
 if (vn == "function_specifier") 
 return 14;
 if (vn == "enum_specifier") 
 return 11;
 if (vn == "struct_or_union_specifier") 
 return 10;
 if (vn == "type_specifier") 
 return 12;
 if (vn == "declaration") 
 return 73;
 if (vn == "declaration_specifiers") 
 return 71;
 if (vn == "translation_unit") 
 return 74;
 if (vn == "function_definition") 
 return 72;
 if (vn == "struct_or_union") 
 return 9;
 if (vn == "type_qualifier") 
 return 13;
 if (vn == "storage_class_specifier") 
 return 6;
return -1;
case5:
 if (vn == "function_definition") 
 return 5;
 if (vn == "function_specifier") 
 return 55;
 if (vn == "type_qualifier") 
 return 54;
 if (vn == "declaration_specifiers") 
 return 52;
 if (vn == "struct_or_union") 
 return 57;
 if (vn == "enum_specifier") 
 return 65;
 if (vn == "type_specifier") 
 return 53;
 if (vn == "storage_class_specifier") 
 return 39;
 if (vn == "struct_or_union_specifier") 
 return 41;
return -1;
case17:

return -1;
case23:

return -1;
case47:

return -1;
case76:
 if (vn == "declaration_specifiers") 
 return 76;
 if (vn == "struct_or_union") 
 return 57;
 if (vn == "struct_or_union_specifier") 
 return 41;
 if (vn == "type_qualifier") 
 return 54;
 if (vn == "function_specifier") 
 return 55;
 if (vn == "enum_specifier") 
 return 65;
 if (vn == "storage_class_specifier") 
 return 39;
 if (vn == "type_specifier") 
 return 53;
return -1;
case70:
 if (vn == "declaration_specifiers") 
 return 71;
 if (vn == "struct_or_union") 
 return 9;
 if (vn == "struct_or_union_specifier") 
 return 10;
 if (vn == "enum_specifier") 
 return 11;
 if (vn == "external_declaration") 
 return 70;
 if (vn == "function_specifier") 
 return 14;
 if (vn == "function_definition") 
 return 72;
 if (vn == "type_qualifier") 
 return 13;
 if (vn == "declaration") 
 return 73;
 if (vn == "type_specifier") 
 return 12;
 if (vn == "storage_class_specifier") 
 return 6;
return -1;
case44:

return -1;
case66:

return -1;
case36:

return -1;
case42:

return -1;
case14:
 if (vn == "function_specifier") 
 return 14;
return -1;
case28:
 if (vn == "enum_specifier") 
 return 11;
 if (vn == "type_specifier") 
 return 12;
 if (vn == "struct_or_union_specifier") 
 return 10;
 if (vn == "declaration_specifiers") 
 return 75;
 if (vn == "function_specifier") 
 return 14;
 if (vn == "struct_or_union") 
 return 9;
 if (vn == "storage_class_specifier") 
 return 6;
 if (vn == "declaration") 
 return 28;
 if (vn == "type_qualifier") 
 return 13;
return -1;
case40:

return -1;
case69:

return -1;
case20:

return -1;
case57:
 if (vn == "struct_or_union") 
 return 57;
return -1;
case65:
 if (vn == "enum_specifier") 
 return 65;
return -1;
case50:

return -1;
case37:

return -1;
case71:
 if (vn == "struct_or_union") 
 return 9;
 if (vn == "enum_specifier") 
 return 11;
 if (vn == "type_specifier") 
 return 12;
 if (vn == "function_specifier") 
 return 14;
 if (vn == "declaration_specifiers") 
 return 71;
 if (vn == "struct_or_union_specifier") 
 return 10;
 if (vn == "type_qualifier") 
 return 13;
 if (vn == "storage_class_specifier") 
 return 6;
return -1;
case41:
 if (vn == "struct_or_union") 
 return 57;
 if (vn == "struct_or_union_specifier") 
 return 41;
return -1;
case72:
 if (vn == "enum_specifier") 
 return 65;
 if (vn == "struct_or_union") 
 return 57;
 if (vn == "type_specifier") 
 return 53;
 if (vn == "function_definition") 
 return 72;
 if (vn == "type_qualifier") 
 return 54;
 if (vn == "struct_or_union_specifier") 
 return 41;
 if (vn == "function_specifier") 
 return 55;
 if (vn == "declaration_specifiers") 
 return 76;
 if (vn == "storage_class_specifier") 
 return 39;
return -1;
case31:

return -1;
case75:
 if (vn == "function_specifier") 
 return 14;
 if (vn == "type_qualifier") 
 return 13;
 if (vn == "enum_specifier") 
 return 11;
 if (vn == "type_specifier") 
 return 12;
 if (vn == "declaration_specifiers") 
 return 75;
 if (vn == "struct_or_union") 
 return 9;
 if (vn == "storage_class_specifier") 
 return 6;
 if (vn == "struct_or_union_specifier") 
 return 10;
return -1;
case45:

return -1;
case2:

return -1;
case1:

return -1;

			default:
                return -1;
        }
    }
    

    #include <iostream>
    #include <string>
    #include <fstream>
    #include <streambuf>
    
    std::string inputSrc;
    
    int cp = 0;
    int state = 0;
    
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

	

 	void dfa(char c){
        switch(state){
	
	case 0:
	switch (c) {

		case "Ã":
			state=1;
			cp++;
			break;

		case "b":
			state=1;
			cp++;
			break;

		case "a":
			state=1;
			cp++;
			break;

		case "c":
			state=1;
			cp++;
			break;

		default:
			printf("ERROR!");
			state = 0;
			throw 2;
			break;
}
	break;

	case 1:
	switch (c) {

		case "c":
			state=2;
			cp++;
			break;

		case "a":
			state=2;
			cp++;
			break;

		case "b":
			state=2;
			cp++;
			break;

		default:
						printf("\n");
			state = 0;
			break;
}

	break;

	case 2:
	switch (c) {

		case "c":
			state=2;
			cp++;
			break;

		case "b":
			state=2;
			cp++;
			break;

		case "a":
			state=2;
			cp++;
			break;

		default:
						printf("\n");
			state = 0;
			break;
}

	break;


			default:
                throw 1;
                break;
        }
    }
    

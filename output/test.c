#include <stdio.h>


void comment();
//}% end
//%% end

void comment(){
	char c,prev=0;
	while(++yy_cp!=0)
	{
		c=*yy_cp;
		if(c=='/'&&prev=='*')
			return;
		prev=c;
	}
	printf("ERROR: unterminated comment!");
}

    
    
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
    
    void dfa(char c){
	switch (c) {
		case 'b':
		break;
		case 'a':
		break;

	default:
		break;}
    }
    
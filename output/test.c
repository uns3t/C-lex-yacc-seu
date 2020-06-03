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

#include <stdio.h>

int count = 0;

int main() {
	int a=1, b=1, c=1, d=1;
	for(a=1; a<10; a++) {
		if((a*110 + c*102 < b*90 + d*11))
		for(b=1; b<10; b++) {
			for(c=1; c<10; c++) {
				for(d=0; d<10; d++) {
if((a*110 + c*102 == b*90 + d*11)) {
	printf("%d%d%d + %d%d%d = %d%d%d\n", a,b,c,c,a,c,b,d,d);
}
				}
			}
		}
	}
	return 0;
}
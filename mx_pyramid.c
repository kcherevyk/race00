#include <unistd.h>

void mx_printchar(char c);

void mx_top(int vertical, int diag, int k, int m) {
    for (int f = 0; f < vertical; f++) {
		for (int l = 0; l < diag - f - 1; l++) mx_printchar(' ');
		mx_printchar('/');
		for (k = 0;k < f; k++) {
			mx_printchar(' ');
			if(k > 0)  {
				mx_printchar(' ');
			}
		}
		mx_printchar('\\');
		for (m = 0; m < f; m++) 
			mx_printchar(' ');
		if (f > 0) mx_printchar('\\');
		mx_printchar('\n');
	}
}

void mx_side(int vertical, int k, int m) {
    for (int f = 0; f < vertical - 1; f++) {
		for (int l = 0; l < vertical - f - 1; l++) mx_printchar(' ');
		mx_printchar('/');
		for (m = 0; m < (f + vertical) * 2 - 1; m++) mx_printchar(' ');
		mx_printchar('\\');
			for (k = 0; k < vertical - f - 1; k++) mx_printchar(' ');
		mx_printchar('|');
		mx_printchar('\n');
	}
}

void mx_pyramid(int n) {
	int line = n * 2 - 3, 
		vertical = n / 2,
		diag = n;
	int m = 0,
        k = 0;
	if(n <= 1 || n % 2 != 0) return;
    mx_top(vertical, diag, k, m);
    mx_side(vertical, k, m);
	mx_printchar('/');
	for (int i = 0; i < line; i++)
		mx_printchar('-');
	mx_printchar('\\');
	mx_printchar('|');
	mx_printchar('\n');
}


#include <unistd.h>

void mx_printchar(char c);
void mx_top_side(int n);
void mx_bottom_side(int n);
void mx_top_fill(int i, int n, int j, int k);
void mx_cube_face_side(int n);
void mx_cube_inside_right_side(int i, int j, int n);
void mx_cube_right_side(int n);

void print_top_side(int n) {
    for (int f = 0; f < n / 2 + 1; f++) 
        mx_printchar(' ');
    mx_printchar('+');
    for (int f = 0; f < n * 2; f++) 
        mx_printchar('-');
    mx_printchar('+');
    mx_printchar('\n');
}

void mx_top_fill(int i, int n, int j, int a) {
    for (i = n / 2; i > 0; i--) {
        for (j = i; j > 0; j--) { 
            mx_printchar(' ');
        }
        mx_printchar('/');
        for (int l = 0; l < n * 2; l++)
            mx_printchar(' ');
        mx_printchar('/');
        for (a = n / 2 - i; a > 0; a--) 
            mx_printchar(' ');
        mx_printchar('|');
        mx_printchar('\n');
    }
}

void mx_cube_face_side(int n) {
    mx_printchar('+');
    for (int f = 0; f < n * 2; f++)
        mx_printchar('-');
    mx_printchar('+');
    for (int f = 0; f < n / 2; f++)
        mx_printchar(' ');
    mx_printchar('|');
    mx_printchar('\n');
}

void mx_cube_right_side(int n) {
    int mod = n / 2;
    if(n % 2 == 0) mod = n / 2 - 1;   
    for (int f = 0; f < mod; f++) {
            mx_printchar('|');
        for (int l = 0; l < n * 2; l++) {
                mx_printchar(' ');    
            }

        mx_printchar('|');

        for (int f = 0; f < n / 2; f++) {
            mx_printchar(' ');
        }
        mx_printchar('|');
        mx_printchar('\n');
    }
}

void mx_cube_inside_right_side(int i, int j, int n) {
    mx_printchar('|');
    for (int f = 0; f < n * 2; f++) 
        mx_printchar(' ');
    mx_printchar('|');
    for (int f = 0; f < n / 2; f++) 
        mx_printchar(' ');
    mx_printchar('+');
    mx_printchar('\n');
    for (i = n / 2; i > 0; i--) {
        mx_printchar('|');
            for (j = 0; j < n * 2; j++)
                mx_printchar(' ');
            mx_printchar('|');
            for (j = i - 1; j > 0; j--)
                mx_printchar(' ');
        mx_printchar('/');
        mx_printchar('\n');
    }
}

void mx_bottom_side(int n) {
    mx_printchar('+');
    for (int f = 0; f < n * 2; f++) 
        mx_printchar('-');
    mx_printchar('+');
    mx_printchar('\n');
}

void mx_cube(int n) {
    int i = 0;
    int j = 0;
    int a = 0;
    
    if (n > 1) {
    mx_top_side(n);
    mx_top_fill(i, n, j, a);
    mx_cube_face_side(n);
    mx_cube_right_side(n);
    mx_cube_inside_right_side(i, j, n);
    mx_bottom_side(n);
    }
    else {
        return;
    }
}


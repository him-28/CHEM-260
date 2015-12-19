int timestwo(int);
main() {
 int a=10, b;
 float c=5.5, d;
 b=timestwo(a);
 printf("%d x 2 =%d\n",a,b);
 d=timestwo(c);
 printf("%4.2f x 2 =%4.2f\n",c,d);
}
int timestwo(int i) {
 return 2*i;
} 

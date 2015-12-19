int main(void) {
int guess, secret=7;
do {
printf("Guess the secret number (1-10):");
scanf("%d",&guess);
} while (guess != secret); /* Note ";" */
}

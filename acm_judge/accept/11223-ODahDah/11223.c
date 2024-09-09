#include <stdio.h>
#include <string.h>

char Symble[53] = 
{
	'A', 'B', 'C', 'D', 'E', 
	'F', 'G', 'H', 'I', 'J',
	'K', 'L', 'M', 'N', 'O', 
	'P', 'Q', 'R', 'S', 'T', 
	'U', 'V', 'W', 'X', 'Y', 
	'Z', '0', '1', '2', '3',
	'4', '5', '6', '7', '8', 
	'9', '.', ',', '?', '\'',
	'!', '/', '(', ')', '&', 
	':', ';', '=', '+', '-',
	'_', '\"', '@' 
};

char Code[53][7] = 
{ 
	".-",     "-...",   "-.-.",  "-..",    ".",     
	"..-.",   "--.",    "....",   "..",     ".---",
	"-.-",    ".-..",   "--",    "-.",     "---",   
	".--.",   "--.-",   ".-.",    "...",    "-",
	"..-",    "...-",   ".--",   "-..-",   "-.--",  
	"--..",   "-----",  ".----",  "..---",  "...--",
	"....-",  ".....",  "-....", "--...",  "---..", 
	"----.",  ".-.-.-", "--..--", "..--..", ".----.",
	"-.-.--", "-..-.",  "-.--.", "-.--.-", ".-...", 
	"---...", "-.-.-.", "-...-",  ".-.-.",  "-....-",
	"..--.-", ".-..-.", ".--.-." 
};
char message[11][1000];
int t;

void compare(char s[],int it) {
   int i;
   for(i = 0; i < 53; i++) {
      if(!strcmp(Code[i], s))
         message[it][t++] = Symble[i];
   }
}

int main() {
   int  i, n, m = 0 , flag = 0;
   char ch;
   char tempCode[10];

   scanf("%d", &n);
   for(i = 0; i <= n; i++) {
      while((ch = getchar()) != '\n') {
         if(ch != ' ') {
               tempCode[m++] = ch;
               flag = 0;
         }
         else if(ch == ' ' && flag == 0) {
               tempCode[m] = '\0';
               compare(tempCode, i);
               m = 0;
               flag = 1;
         }
         else if(flag == 1) {
            message[i][t++] = ' ';
            flag = 0;
         }
      }
      tempCode[m] = '\0';
      compare(tempCode, i);
      message[i][t] = '\0';
      t = 0;
      m = 0;
      flag = 0;
   }

   for(i = 1; i <= n; i++) {
   	if(i > 1){
   		printf("\n");
   	}
      printf("Message #%d\n" , i);
      printf("%s\n", message[i]);
   }
   return 0;
}

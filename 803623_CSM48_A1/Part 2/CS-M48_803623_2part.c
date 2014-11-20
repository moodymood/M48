/* 
Quine example written by Francesca Madeddu 
803623@swansea.ac.uk
07/11/2014

The quine main() function is composed by:
- print(char *c): actually print the source code;
- char *str: contains the text used by the function to print the source code;
- a call to the method print(char*);
The basic idea is to have a string which contains some text that opportunately printed can replicate
the entire source code of the program itself.


The print(char*) function requires three for cicles mainly because of the double quotes character (ASCII 34):
- The first cicle prints the first part of the string str, which correspond to 
the entire source code till the first instance of the " character;
- the second cicle prints the entire content of the string str;
- the last cicle prints only the last part of the string str corresponding to the function print(char*)
calling.
*/

int main(){
	void print(char* c){
			int i = 0;
			for(i=0;i<196;i++)
				putchar(c[i]);
			putchar(34);
			i=0;
			for(i=0;i<208;i++)
				putchar(c[i]);
			putchar(34);
			putchar(59);
			i=0;
			for(i=196;i<208;i++)
				putchar(c[i]);
	}
			char *str = "int main(){void print(char* c){int i = 0;for(i=0;i<196;i++)putchar(c[i]);putchar(34);i=0;for(i=0;i<208;i++)putchar(c[i]);putchar(34);putchar(59);i=0;for(i=196;i<208;i++)putchar(c[i]);}char *str = print(str);}";
			print(str);
	}

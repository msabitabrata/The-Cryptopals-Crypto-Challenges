#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *decryptXorString(char *, char *, char *);
char *convertHexToBinary(char *);
char *fixedXorBinary(char *, char *);
char *convertBinaryToAscii(char *);
char *convertBinaryToHex(char *);
int binaryToDecimal(char *);
int power(int ,int );

struct hex_bin
{
	char hex;
	char *bin;
};

struct common_words
{
	char *words;
};

struct hex_bin dict[16] = 
{
	{'0',"0000"},{'1',"0001"},{'2',"0010"},{'3',"0011"},
	{'4',"0100"},{'5',"0101"},{'6',"0110"},{'7',"0111"},
	{'8',"1000"},{'9',"1001"},{'a',"1010"},{'b',"1011"},
	{'c',"1100"},{'d',"1101"},{'e',"1110"},{'f',"1111"}
};

struct common_words comm_words[14] = {{"an"},{"the"},{"this"},{"that"},{"is"},{"are"},{"was"},{"were"},{"by"},{"of"},{"at"},{"like"},{"for"},{"and"}};

int main()
{
	char *hexString = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";	
	char *strKey = (char *)malloc(sizeof(char)*8);
	char *asciiString = (char *)malloc(sizeof(char)*strlen(hexString)/2);
	decryptXorString(hexString, asciiString, strKey);
	printf("Decrypted string : %s\nKey : %s\n",asciiString,convertBinaryToHex(strKey));
}

char *decryptXorString(char *hexString, char *asciiString, char *strKey)
{
	int i=0,j=0,match=0;
	for(i=0;i<16;i++)
	{
		for(j=0;j<16;j++)
		{		
 			strcpy(strKey,dict[i].bin);
			strcat(strKey,dict[j].bin);
			int inputLength = strlen(hexString);
			int k=0;
			char *key = (char *)malloc(sizeof(char)*8*inputLength/2);
			for(k=0;k<inputLength/2;k++)
			{
				strcat(key,strKey);
			}
			char *binaryString = convertHexToBinary(hexString);
			char *xorBinaryString = fixedXorBinary(binaryString,key);
			strcpy(asciiString,convertBinaryToAscii(xorBinaryString));
			if(asciiString[0] >= 'A' && asciiString[0] <= 'Z')
			{
				char *word = (char *)malloc(sizeof(char)*200);
				char *p=asciiString,*q=word,*r=word;
				while(*p != '\0')
				{
					*q++=*p++;
					if(*p==' ')
					{
						*q='\0';
						word[0] = tolower(word[0]);
						int l=0;
						match=0
						for(l=0;l<14;l++)
						{
							if(strcmp(comm_words[l].words,word)==0)
							{
								match=1;
								break;
							} 
						}
						if(match==1)
							return;
						else
						{
							memset(word,'\0',strlen(word));
							q=&word[0];
							*p++;
						}
					}
				}
			}
		}
	}
	if(match==0)
	{
		strcpy(asciiString,"");
	}
}

char *convertHexToBinary(char *input)
{
	int i=0,j=0;
	char *binaryString = (char *)malloc(sizeof(char)*4*strlen(input));
	strcpy(binaryString, "");
	for(i=0;input[i]!='\0';i++)
	{
		for(j=0;j<16;j++)
		{
			if(input[i]==dict[j].hex)
			{
				binaryString = strcat(binaryString,dict[j].bin);
				break;
			}
		}
	}
	return(binaryString);
}

char *convertBinaryToHex(char *input)
{
	int i=0,j=0,k=0,l=0;
	char *hexString = (char *)malloc(sizeof(char)*2048);
	
	
	for(i=0;input[i]!='\0';i++)
	{
		char temp[4];
		temp[j++] = input[i];
		if(j==4)
		{
			temp[j]='\0';
			for(k=0;k<16;k++)
			{
				if(strcmp(dict[k].bin,temp) == 0)
				{
					hexString[l++]=dict[k].hex;
					break;
				}
			}
			j=0;
		}
	}
	hexString[l] = '\0';
	return(hexString);
	
}

char *fixedXorBinary(char *bin1, char *bin2)
{
	int length = strlen(bin1);
	int i=0,j=0;
	char *xorBinaryString = (char *)malloc(sizeof(char)*length);
	for(i=0;i<length;i++)
	{
		if(bin1[i]==bin2[i])
			xorBinaryString[j++]='0';
		else 
			xorBinaryString[j++]='1';
		
	}
	xorBinaryString[j]='\0';
	return(xorBinaryString);
}

char *convertBinaryToAscii(char *input)
{
	int i=0,j=0,k=0,l=0;	
	char *asciiString = (char *)malloc(sizeof(char)*strlen(input)/8);
	
	for(i=0;input[i]!='\0';i++)
	{
		char temp[8];
		temp[j++] = input[i];
		if(j==8)
		{
			temp[j]='\0';
			char ch = (char)binaryToDecimal(temp);
			asciiString[l++]=ch;
			j=0;
		}
	}
	asciiString[l] = '\0';
	return(asciiString);
	
}
int binaryToDecimal(char *input)
{
	int i=0,j=0,sum=0,length = strlen(input);
	for(i=length-1;i>=0;i--)
	{
		int num = input[i] == '0' ? 0 : 1;
		sum += power(2,j)*num;
		j++;
	}
	return(sum);
}

int power(int base,int power)
{
	if(power==0)
		return 1;
	else 
	{
		int i=0,product=1;
		for(i=0;i<power;i++)
		{
			product = product*base;
		}
		return product;
	}		
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *convertHexToBinary(char *);
char *fixedXorBinary(char *, char *);
char *fixedXorHex(char *, char *);
char *convertBinaryToHex(char *);

struct hex_bin
{
	char hex;
	char *bin;
};

struct hex_bin dict[16] = 
{
	{'0',"0000"},{'1',"0001"},{'2',"0010"},{'3',"0011"},
	{'4',"0100"},{'5',"0101"},{'6',"0110"},{'7',"0111"},
	{'8',"1000"},{'9',"1001"},{'a',"1010"},{'b',"1011"},
	{'c',"1100"},{'d',"1101"},{'e',"1110"},{'f',"1111"}
};

int main()
{
	char *xorHexString = fixedXorHex("1c0111001f010100061a024b53535009181c","686974207468652062756c6c277320657965");
	printf("%s\n",xorHexString);
}

char *convertHexToBinary(char *input)
{
	int i=0,j=0;
	char *binaryString = (char *)malloc(sizeof(char)*2048);
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

char *fixedXorHex(char *hex1, char *hex2)
{
	char *bin1 = convertHexToBinary(hex1);
	char *bin2 = convertHexToBinary(hex2);
	char *xorBinaryString = fixedXorBinary(bin1,bin2);
	char *xorHexString = convertBinaryToHex(xorBinaryString);
	return xorHexString;
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
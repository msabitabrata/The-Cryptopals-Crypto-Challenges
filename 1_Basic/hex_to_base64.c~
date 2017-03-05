#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *convertHexToBinary(char *);
char *convertBinaryToBase64(char *);
int binaryToDecimal(char *);
int power(int ,int );

struct hex_bin
{
	char hex;
	char *bin;
};

char *base64_codes = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

struct hex_bin dict[16] = 
{
	{'0',"0000"},{'1',"0001"},{'2',"0010"},{'3',"0011"},
	{'4',"0100"},{'5',"0101"},{'6',"0110"},{'7',"0111"},
	{'8',"1000"},{'9',"1001"},{'a',"1010"},{'b',"1011"},
	{'c',"1100"},{'d',"1101"},{'e',"1110"},{'f',"1111"}
};

int main() 
{
	char *binary = convertHexToBinary("49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d");
	printf("%s\n",convertBinaryToBase64(binary));
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

char *convertBinaryToBase64(char *input)
{
	int i=0;
	char *base64 = (char *)malloc(sizeof(char *)*2048);
	strcpy(base64,"");
	int buf_length = 0;
	
	if(strlen(input)%6==0)
	{
		char str[6];
		int length = strlen(input);
		int j=0;
		for(i=0;i<length;i++)
		{
			str[j++]=input[i];
			if(j==6)
			{
				int dec = binaryToDecimal(str);
				buf_length = strlen(base64);
				base64[buf_length++]=base64_codes[dec];
				base64[buf_length]='\0';
				j=0;
			}
		}
		return base64;
	}
	if(strlen(input)%6==2)
	{
		char str[6];
		int j=0;
		char *intermediate = strcpy(input,"0000");
		int length = strlen(intermediate);
		for(i=0;i<length;i++)
		{
			str[j++]=intermediate[i];
			if(j==6)
			{
				int dec = binaryToDecimal(str);
				buf_length = strlen(base64);
				base64[buf_length++]=base64_codes[dec];
				base64[buf_length]='\0';
				j=0;
			}
		}
		base64 = strcpy(base64,"==");
		return base64;
	}
	if(strlen(input)%6==4)
	{
		char str[6];
		int j=0;
		char *intermediate = strcpy(input,"0000");
		int length = strlen(intermediate);
		for(i=0;i<length;i++)
		{
			str[j++]=intermediate[i];
			if(j==6)
			{
				int dec = binaryToDecimal(str);
				buf_length = strlen(base64);
				base64[buf_length++]=base64_codes[dec];
				base64[buf_length]='\0';
				j=0;
			}
		}
		base64 = strcpy(base64,"==");
		return base64;
	}
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
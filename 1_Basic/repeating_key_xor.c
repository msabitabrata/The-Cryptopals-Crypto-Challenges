#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *convertAsciiToBinary(char *);
char *fixedXorBinary(char *, char *);
char *convertBinaryToHex(char *);
char *convertDecimalToBinary(int ,int );
char *reverseString(char *);
char *formRepeatingKey(char *,int );

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
	char *key = "ICE";
	char *inputString = "Burning 'em, if you ain't quick and nimble\nI go crazy when I hear a cymbal";	
	char *keyString = formRepeatingKey(key,strlen(inputString));
	

	char *binaryInputString = convertAsciiToBinary(inputString);
	char *binaryKeyString = convertAsciiToBinary(keyString);

	char *xorBinaryString = fixedXorBinary(binaryInputString,binaryKeyString);
	printf("%s\n",convertBinaryToHex(xorBinaryString));
}

char *convertAsciiToBinary(char *input)
{
	char *binary = (char *)malloc(sizeof(char)*strlen(input)*8);
	strcpy(binary,"");
	char *p = input;
	int i=0;
	while(*p!='\0')
	{
		int ascii_code =(int)*p++;
		strcat(binary,convertDecimalToBinary(ascii_code,8));
	}
	return(binary);
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

char *convertDecimalToBinary(int input,int bit_length)
{
	char *binaryString = (char *)malloc(sizeof(char)*bit_length);
	memset(binaryString,'0',bit_length);
	int i = input,j=0;
	while(i>0)
	{
		binaryString[j++] = i%2 == 0 ? '0' : '1';
		i = i/2;
	}
	return(reverseString(binaryString));
}

char *reverseString(char *input)
{
	char *output = (char *)malloc(sizeof(char)*strlen(input));
	char *p=output;
	int i=strlen(input)-1;
	while(i>=0)
	{
		*p++=input[i--];
	}
	*p='\0';
	return output;
}

char *formRepeatingKey(char *key,int stringLength)
{
    char *strKey = (char *)malloc(sizeof(char)*stringLength) ;
    int keyLength = strlen(key);
    int i=0,j=0;
    while(i<stringLength/keyLength)
    {
        strcat(strKey,key);
        i++;
    }
    
    if(stringLength%keyLength != 0)
    {
        int index = strlen(strKey);
        while(j<stringLength/keyLength)
        {
            strKey[index++]=key[j++];
        }
        strKey[index]='\0';
    }
    return(strKey);
}


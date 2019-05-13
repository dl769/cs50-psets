#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{

    if (argc!=2)
    {

        printf("Usage: ./caesar key");

        return 1;

    }

    printf("plaintext: ");

    char text[100];

    fgets(text, sizeof(text), stdin);

    int key = atoi( argv[1]);  //converting string from argv[1] to an int

    int temp = key / 26;

    key = key - (temp * 26);

    int n=0; //for counting number of characters in the text

    while(text[n] != '\0')
    {

        n++;

    }

    printf("ciphertext: ");

    for (int i=0; i<n-1; i++)
    {

        int characterToPrint=0; 
        //has to be int otherwise lower case letters may cause problems cause they'll eventually go beyond ASCII range
        
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {

            if (text[i] >= 'A' && text[i] <= 'Z')
            {

                characterToPrint = text[i] + key;

                if (characterToPrint > 'Z')
                {

                    printf("%c", characterToPrint - 'Z' + 'A' - 1);

                }

                else  printf("%c", text[i] + key);

            }

            if (text[i] >= 'a' && text[i] <= 'z'){

                characterToPrint = text[i] + key;

                if (characterToPrint > 'z')
                {

                    printf("%c", characterToPrint - 'z' + 'a' - 1);

                }

                else printf("%c", characterToPrint);

            }

        }

        else
        {

            if (text[i] != '\0') 
            {

                printf("%c", text[i]);

            }

        }

    }

    printf("\n");

    return 0;

}

/* file_recognizer.c
 * compile with gcc file_recognizer.c
 * run with:
 * ./a.out [fileName].[fileExtension]
 * only recognizes .pdf, .gif, .elf, .zip, .java, .png 
 */


/*
GIF: 47 49 46 38 39 61 or
GIF: 47 49 46 38 37 61
ELF: 7f 45 4C 46
PDF: 25 50 44 46
ZIP: 50 4B
JAVA: CA FE BA BE
PNG: 89 50 4E 47 0D 0A 1A 0A

ANYTHING ELSE: use your imagination...



*/
#include<stdio.h>
//#include<fstream>
int main(int argc, char *argv[]){
  if (argc == 2){
    //printf("proper arguments\n");
    int i;
    unsigned char byteInArr[10];

    unsigned int gifArr1[6] = {0x47, 0x49, 0x46, 0x38, 0x39, 0x61};
    unsigned int gifArr2[6] = {0x47, 0x49, 0x46, 0x38, 0x37, 0x61};
    unsigned int elfArr[4] = {0x7f, 0x45, 0x4C, 0x46};
    unsigned int pdfArr[4] = {0x25, 0x50, 0x44, 0x46};
    unsigned int zipArr[2] = {0x50, 0x4B};
    unsigned int javaArr[4] = {0xCA, 0xFE, 0xBA, 0xBE};
    unsigned int pngArr[8] = {0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A};
    //printf("initializations checked out\n");

    FILE *fp = fopen(argv[1], "r");
    //printf("file accessed successfully\n");

    rewind(fp);
    //printf("file rewound successfully\n");

    for (i = 0; i < 10; i++){
      fscanf(fp, "%c", &byteInArr[i]);
      //printf("char number %d : byteVal %x\n", i, byteInArr[i]);
    }
    int j;
    int count = 0;
    if (byteInArr[0] == 0x47){
      for (j = 0; j < 6; j++){
        if (gifArr1[j] != byteInArr[j] || gifArr2[j] != byteInArr[j]){
          break;
        }
        count++;
        if (count == 6){
          printf("This is a GIF file.\n");
          return 0;
        }
      }
    }
    if (byteInArr[0] == 0x7f){
      for (j = 0; j < 4; j++){
        if (elfArr[j] != byteInArr[j]){
          break;
        }
        count++;
        if (count == 4){
          printf("This is an ELF file.\n");
          return 0;
        }
      }
    }
    if (byteInArr[0] == 0x25){
      for (j = 0; j < 4; j++){
        if (pdfArr[j] != byteInArr[j]){
          break;
        }
        count++;
        if (count == 4){
          printf("This is a PDF file.\n");
          return 0;
        }
      }
    }
    if (byteInArr[0] == 0x50){
      for (j = 0; j < 2; j++){
        if (zipArr[j] != byteInArr[j]){
          break;
        }
        count++;
        if (count == 2){
          printf("This is a ZIP file.\n");
          return 0;
        }
      }
    }
    if (byteInArr[0] == 0xCA){
      for (j = 0; j < 4; j++){
        if (javaArr[j] != byteInArr[j]){
          break;
        }
        count++;
        if (count == 4){
          printf("This is a Java class file.\n");
          return 0;
        }
      }
    }
    if (byteInArr[0] == 0x89){
      for (j = 0; j < 8; j++){
        if (pngArr[j] != byteInArr[j]){
          break;
        }
        count++;
        if (count == 8){
          printf("This is a PNG file.\n");
          return 0;
        }
      }
    }
    printf("File type unknown.\n");


  } else {
    printf("Invalid input\n");
  }

}


/*
int j;
int count;
for (j = 0; j < (sizeof(pdfArr)/sizeof(unsigned int)); j++){
  printf("element %d : pdfarr = %x, byteInArr = %x\n", j, pdfArr[j], byteInArr[j]);
  if (pdfArr[j] != byteInArr[j]){
    break;
  }
  count++;
}

*/

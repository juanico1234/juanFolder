#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int save = 0;

struct Recipe{
	char Nama[100];
  int banyak;
  char Ingredients[100][100];
}next[100];

void search(){
  int count=0;
  char nama[100];
  printf("Masukan Nama Resep : ");
  scanf(" %[^\n]" , nama);
  for(int i=1 ; i<=100 ; i++){
    if(strcmp(nama , next[i].Nama) == 0){
      count=1;
      printf("%s\n" , next[i].Nama);
      for(int j=1 ; j<=next[i].banyak ; j++){
        printf("%d. %s\n" ,j , next[i].Ingredients[j] );
      }
    }
  }
    if(count==0) puts("Data Not Found");
      printf( "Tekan enter untuk lanjut\n");
      getchar();
      getchar();
}

int cookBook(){
  int nomor;
  printf( "=========================\n"
          "        Cook Book\n"
          "1. Add Recipe\n"
          "2. Search\n"
          "3. Exit\n"
          "=========================\n"
          "Masukan Input >> ");
          scanf("%d" , &nomor);
  if(nomor == 1){
    save++;
    printf("Nama Makanan : ");
    scanf(" %[^\n]" , next[save].Nama );
    printf("Banyak Bahan : ");
    scanf(" %d" , &next[save].banyak);
    printf("Bahan Bahan :\n");
    for(int i=1 ; i<=next[save].banyak ; i++){
      printf("%d. " ,i);
      scanf(" %[^\n]" , next[save].Ingredients[i]);
    }
    printf( "Resep Berhasil Dimasukan\n"
            "Tekan enter untuk lanjut\n");
    getchar();
    getchar();
    return nomor;
  }
  else if(nomor == 2){
    search();
    return nomor;
  }
  else if(nomor == 3)
  return nomor;
}


int homePage(){
  int nomor;
  printf( "=========================\n"
          "        Home Page\n"
          "1. Recipe Suggestions\n"
          "2. Search\n"
          "3. Exit\n"
          "=========================\n"
          "Masukan Input >> ");
          scanf("%d" , &nomor);
  if(nomor == 1){
    for(int i=1 ; i<=100 ; i++){
      if(next[i].Nama[0]!=NULL)
      printf("%d. %s\n" , i , next[i].Nama);
      else {
      printf( "Tekan enter untuk lanjut\n");
      getchar();
      getchar();
      break;
      }
    }
  }
  else if(nomor == 2){
    search();
  }
  else if(nomor == 3){
    return nomor;
  }
}

int mainMenu(){
  int nomor;
  printf( "=========================\n"
          "        Main Menu\n"
          "1. Home Page\n"
          "2. Cookbook\n"
          "3. Kitchen\n"
          "4. Pantry\n"
          "5. Profile\n"
          "6. Exit\n"
          "=========================\n"
          "Masukan Input >> ");
  scanf("%d" , &nomor);
  return nomor;
}

int main(){
  system("clear");
  int loop = 0;
  for( ; loop == 0 ; ){
    system("clear");
    int input = mainMenu();
    if(input == 1){
      for(int count=1 ; count==1 ; ){
        system("clear");
        input = homePage();
        if(input != 3) continue;
        else count++;
      }
    }

    else if(input == 2){
      for(int count=1 ; count==1 ; ){
      system("clear");
      input = cookBook();
      if(input != 3 )
        continue;
      else
        count++;
      }
    }

    else if(input == 3){
      system("clear");
    }

    else if(input == 4){
      system("clear");
    }

    else if(input == 5){
      system("clear");
    }

    if(input == 6)
    	return 0;
  }

}

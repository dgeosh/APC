#include <iostream>
using namespace std;

int main(){
  freopen("filename.txt", "r", stdin); //open the file in read mode
  int int1, int2, int3; //initialize variables
  scanf("%i", &int1); //take input from filename.txt 
  scanf("%d %d", &int2, &int3);
  fclose(stdin); //close stream

  freopen("filename.txt", "w", stdout); //open the file in write mode
  printf("this was written to a file"); //write to file
  fclose(stdout); //close stream

  return 0;
}

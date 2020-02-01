#include <bits/stdc++.h
#include <dirent.h
using namespace std
typedef pair<int, int> ii
typedef long long ll
const int oo = 1e9 + 7
char src[2048], buffer[20480], input[2048]
int n
void Fix(char* file_name) 
  FILE* in = fopen(file_name, "r")
  size_t len = strlen(file_name)
  memcpy(src + 0, "source\\", 7)
  memcpy(src + 7, file_name, len)
  src[len + 7] = '\0'
  printf("FIX '%s' -> '%s'\n", file_name, src)
  FILE* out = fopen(src, "w")
  while (fgets(buffer, sizeof buffer, in) != NULL) 
    len = strlen(buffer)
    buffer[len - 1] = '\0'
    buffer[len - 2] = char(10)
    fprintf(out, "%s", buffer)
  
  fclose(out)
  fclose(in)

int main() 
  ios::sync_with_stdio(0)
  cin.tie(0)
  DIR* d = opendir(".")
  dirent *dir
  if (d) 
    while ((dir = readdir(d)) != NULL) 
      if (dir->d_type == DT_REG) {       
        Fix(dir->d_name)
      
    
    closedir(d)
  
  return 0


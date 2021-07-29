#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstring>

struct fra{
  int arj;
  std::string anun;
}fraarr[10];

struct zxc{
    int bn;
    double amb;
    bool ka;
    std::string name;
}arr[100];
std::ifstream file;

int foofra(std::string str1){
  for(int i = 0;i < 100;i++){
    if(arr[i].name == str1){
      return i;
    }
  }
  return 0;
}

std::string kazangvacum1(std::string str1){
  for(int i = 0;i < 100;i++){
    if(arr[i].name == str1){
      return str1;
    }
  }
  return "chunes element: ";
  
}
int kazangvacum(std::string str1){
  for(int i = 0;i < 100; i++){
    if(arr[i].name == str1)
    return arr[i].bn;
    
  }
  return 0;
}

void etefoo(std::string str1){
  while (str1 != ")")
  {
    file >> str1;
  }
  
  return ;
}

int tiv(std::string str1){
  std::stringstream a(str1);
  int c = 0;
  a >> c;
  return c;

}

bool footiv(std::string str1){
  for(int i = 0;i < 10 ; i++)
  if(str1[i] >= 48 && str1[i] <= 57){
    return 1;
  }
  else{
    return 0;
  }
  return 0;
}

bool foo(std::string str1){
  int x = str1.size();
  for(int i = 0 ; i < x ; i++)
  
  if(str1[i] >= 65 && str1[i] <= 122){
 
  return 1;
  
  }
  else{
  
    return 0;
  }
  return 0;
}

int  main()
{
  int t = 0;
  int y = 0;
 
  file.open("mfile.txt");
  std::string str1;
  int i = 0;
  while(!file.eof())     ///////////////////////////////////while
  {                                                        
                                                                                      
  str1 = "";
  file >> str1;
        
pr:

 if(str1 == "bn"){      ////////////////////////////////int-bn
  fra1:
  i++;
  file>>str1;
 
  int k;
  k = foo(str1);

 if( k ){

  arr[i].name = str1;  
  int abc;
  file>>str1;
  
  if(str1 == "$"){
    
    file>>str1;
    
    std::stringstream a(str1);
    
    file >> str1;
    if(str1 == "`"){
    int c = 0;
    a >> c;
    abc = c;
    arr[i].bn = abc;
    }else{
      std::cout<<"Error: ` pakasa";
    }

  
  }
  
}
else{

  std::cout<<"Error: bn-ic heto tveq popoxakan: ";

}

} if(str1 == "amb"){                ////////////////////double - amb
  i++;
  file>>str1;
 
  int k;
  k = foo(str1);

 if( k ){

  arr[i].name = str1;  
  double abc;
  file>>str1;
  
  if(str1 == "$"){
    
    file>>str1;
    
    std::stringstream a(str1);
    
    file >> str1;
    if(str1 == "`"){
    double c = 0;
    a >> c;
    abc = c;
    arr[i].amb = abc;
    }else{
      std::cout<<"Error: ` pakasa";
    }

  
  }
  
}
else{

  std::cout<<"Error: bn-ic heto tveq popoxakan: ";

}

}if(foo(str1))
for(int j = 0;j < 100; j++){   /////////////////////////popoxakaneri het gorcoxutyun;
  if(str1 == arr[j].name){
    
    file >> str1;
  
  if(str1 == "@$"){
    
    file >> str1;
    std::stringstream a(str1);
    int c = 0;
    a >> c;
    file >> str1;
    if(str1 == "`"){
    arr[j].bn += c;
    arr[j].amb += c;
    }
    else{
      std::cout<<"Error: ` pakasa:";
    }
  
  }
  if(str1 == "~$"){
    file >> str1;
    std::stringstream a(str1);
    int c = 0;
    a >> c;
    file >> str1;
    if(str1 == "`"){
    arr[j].bn -= c;
    arr[j].amb -= c;
    }
    else{
      std::cout<<"Error: ` pakasa:";
    }
  }
  if(str1 == "^$"){
    file >> str1;
    std::stringstream a(str1);
    int c = 0;
    a >> c;
    file >> str1;
    if(str1 == "`"){
    arr[j].bn *= c;
    arr[j].amb *= c;
    }
    else{
      std::cout<<"Error: ` pakasa:";
    }
  }
  if(str1 == "%$"){
    file >> str1;
    std::stringstream a(str1);
    int c = 0;
    a >> c;
    file >> str1;
    if(str1 == "`"){
    arr[j].bn /= c;
    arr[j].amb /= c;
    }
    else{
      std::cout<<"Error: ` pakasa:";
    }
  }

  }

} if(str1 == "tpi"){         /////////////////////////// cout

file >> str1;
if(str1 == "<-")
{   
    file >> str1;
    if(str1 == "{"){                                       
    std::getline(file,str1);

    int x = str1.length();

  if(str1[x - 3] == '}'){
    
    str1[x - 3] = ' ';
  
  if(str1[x-1] == '`'){
  
    str1[x - 1] = ' ';
    std::cout<<str1<<std::endl;
  
  }else{
    
    std::cout<<"Error: ` pakasa";
    break;
  
  }
  
  }

}if(footiv(str1)){
    
  std::stringstream a(str1);
  a >> t; 
  file >> str1;
  if(str1 == "@"){
  
  file >> str1;
  std::stringstream b(str1);
  b >> y;
  file >> str1;
  
  if(str1 == "`"){
  
  std::cout<<t+y<<std::endl;
  
  }else{
    
    std::cout<<"Error: ` pakasa";
  
  }
  }
  if(str1 == "~"){
  file >> str1;
  std::stringstream b(str1);
  b >> y;
  file >> str1;
  if(str1 == "`"){
  
    std::cout<<t - y<<std::endl;
  
  }else{
  
    std::cout<<"Error: ` pakasa";
  
  }
  }
  if(str1 == "^"){
  file >> str1;
  std::stringstream b(str1);
  b >> y;
  file >> str1;
  if(str1 == "`"){
  
    std::cout<<t * y<<std::endl;
  
  }else{
    
    std::cout<<"Error: ` pakasa";
  
  }
  }
  if(str1 == "%"){
  file >> str1;
  std::stringstream b(str1);
  b >> y;
  file >> str1;
  if(str1 == "`"){
    
    std::cout<<t/y<<std::endl;
  
  }else{
    
    std::cout<<"Error: ` pakasa";
  
  }


    }
      
      
  }if(foo(str1)){

  for(int j = 0; j < 100;j++){
    
    
    if(str1 == arr[j].name){
      file >> str1;
      if(str1 == "@"){
        file >> str1;
        if(foo(str1)){
          for(int k = 0;k < 100;k++){
            if(str1 == arr[k].name){
            
            if(arr[j].bn && arr[k].bn){
            std::cout<<arr[j].bn + arr[k].bn<<std::endl;
            
            }
            if(arr[j].amb && arr[k].amb){
            std::cout<<arr[j].amb + arr[k].amb<<std::endl;
            }
            
            }

          }
        
        }else{
        
        int l = 0;
        l = tiv(str1);
        if(arr[j].bn){
      
      std::cout<<arr[j].bn + l<<std::endl;
      
      }
      
      if(arr[j].amb){
      
      std::cout<<arr[j].amb + l<<std::endl;
        }
      }

      }
      if(str1 == "^"){
      
        file >> str1;
      if(foo(str1)){
          for(int k = 0;k < 100;k++){
            if(str1 == arr[k].name){
            
            if(arr[j].bn && arr[k].bn){
            std::cout<<arr[j].bn * arr[k].bn<<std::endl;
            
            }
            if(arr[j].amb && arr[k].amb){
            std::cout<<arr[j].amb * arr[k].amb<<std::endl;
            }
            
            }

          }
        
        }else{
        
        int l = 0;
        l = tiv(str1);
      if(arr[j].bn){
      
      std::cout<<arr[j].bn * l<<std::endl;
      
      }
      
      if(arr[j].amb){
      
      std::cout<<arr[j].amb * l<<std::endl;
        }
      }
      }
      if(str1 == "~"){
      
        file >> str1;
        if(foo(str1)){
          for(int k = 0;k < 100;k++){
            if(str1 == arr[k].name){
            
            if(arr[j].bn && arr[k].bn){
            std::cout<<arr[j].bn - arr[k].bn<<std::endl;
            
            }
            if(arr[j].amb && arr[k].amb){
            std::cout<<arr[j].amb - arr[k].amb<<std::endl;
            }
            
            }

          }
        
        }else{
        
        int l = 0;
        l = tiv(str1);
      if(arr[j].bn){
      
      std::cout<<arr[j].bn - l<<std::endl;
      
      }
      
      if(arr[j].amb){
      
      std::cout<<arr[j].amb - l<<std::endl;
        }
      }
      }
      if(str1 == "%"){

        file >> str1;
          if(foo(str1)){
          for(int k = 0;k < 100;k++){
            if(str1 == arr[k].name){
            if(arr[j].bn && arr[k].bn){
            std::cout<<arr[j].bn / arr[k].bn<<std::endl;
            
            }
            if(arr[j].amb && arr[k].amb){
            std::cout<<arr[j].amb / arr[k].amb<<std::endl;
            }
            }
          }
        
        }else{
        
        int l = 0;
        l = tiv(str1);
      if(arr[j].bn){
      
      std::cout<<arr[j].bn / l<<std::endl;
      
      }
      
      if(arr[j].amb){
      
      std::cout<<arr[j].amb / l<<std::endl;
        }
      }
      }else if(arr[j].bn){
      if(arr[j].bn){
      std::cout<<arr[j].bn<<std::endl;
  
      break;
      }
      // if(arr[j].amb){
      // std::cout<<arr[j].amb<<std::endl;
  
      // break;
        
      // }
    }else{
            if(arr[j].amb){
      std::cout<<arr[j].amb<<std::endl;
  
      break;
        
      }
    }

  }

}

}

}else{                    
                              
  std::cout<<"Error: tpi-ic heto dir <-"; 
  break;                     


}

    
        
 }
if(str1 == "ete"){            ////////////////////////// if -- ete 
  file >> str1;
  
  if(str1 == "|"){
    file >> str1;
    
    if(footiv(str1)){
      int g = 0;
      g = tiv(str1);
      
      file >> str1;
      if(str1 == ">"){
        file >> str1;
        int r = 0 ;
        r = tiv(str1);
        file >> str1;
        if(str1 == "|"){
          file >> str1;
         if(g > r){
         
          goto pr;
         
         }else{

         etefoo(str1);
         
         }

        }

      }
      else if(str1 == "<"){
        file >> str1;
        int r = 0 ;
        r = tiv(str1);
        file >> str1;
        if(str1 == "|"){
          file >> str1;
         if(g < r){
         
          goto pr;
         
         } else{
          
          etefoo(str1);
         
         }
         
        }
      }
      else if(str1 == "$$"){
        file >> str1;
        int r = 0;
        r = tiv(str1);
        file >> str1;
        if(str1 == "|"){
          file >> str1;
          if(g == r){
           
            goto pr;
          
          } else{
           
            etefoo(str1);
          
          }
        }
      }

    }

  }


}

if(str1 == "fra"){              ////////////////////// for -- fra 
  
  int l = 0;
  l++;
  file >> str1;
  if(str1 == "."){
  
    file >> str1;
    if(str1 == "bn"){
      file >> str1;
      if(foo(str1)){
        fraarr[l].anun = str1;
        file >> str1;
        if(str1 == "$"){

          file >> str1;
          if(footiv(str1)){
            int q = 0;
            q = tiv(str1);
            fraarr[l].arj = q;
            file >> str1;
            if(str1 == ":"){
              file >> str1;
              if(str1 == fraarr[l].anun){
                file >> str1;
                if(str1 == ">"){                      //////////////////for mec//////////////////
                  file >> str1;                  
                  int f = 0;
                  f = tiv(str1);
                  if(fraarr[l].arj > f){
                    file >> str1;
                    if(str1 == ":"){
                      file >> str1;
                      if(str1 == fraarr[l].anun){
                        file >> str1;                        
                        if(str1 == "@$"){
                          file >> str1;
                          if(tiv(str1)){
                            int u = tiv(str1);
                            file >> str1;                       
                            if(str1 == "."){
                              file >> str1;
                              if(str1 == "tpi"){
                                file >> str1;
                                if(str1 == "<-"){
                                  file >> str1;
                                  if(str1 == fraarr[l].anun){
                                    file >> str1;
                                   if(str1 == "`"){
                                for(fraarr[l].anun ; fraarr[l].arj > f ; fraarr[l].arj += u){
                                  std::cout<< fraarr[l].arj<<" ";
                                     }
                                    }else{
                                      std::cout<<"Error: dir ` ";
                                    }
                                  }
                                }
                              }else if(kazangvacum(str1)){
                                int x = kazangvacum(str1);
                                int ind = foofra(str1);
                                file >> str1;
                               
                                if(str1 == "@$"){
                                  file >> str1;
                                  if(footiv(str1)){
                                    int y = tiv(str1);
                                    for(fraarr[l].anun; fraarr[l].arj > f; fraarr[l].arj += u){
                                      arr[ind].bn += y;

                                    }
                                  }
                                }else if(str1 == "^$"){
                                  file >> str1;
                                  if(footiv(str1)){
                                    int y = tiv(str1);
                                    for(fraarr[l].anun; fraarr[l].arj > f; fraarr[l].arj += u){
                                      arr[ind].bn *= y;
                                    }
                                  }
                                }else if(str1 == "~$"){
                                  file >> str1;
                                  if(footiv(str1)){
                                    int y = tiv(str1);
                                    for(fraarr[l].anun; fraarr[l].arj > f; fraarr[l].arj += u){
                                      arr[ind].bn -= y;
                                    }
                                  }
                                }else if(str1 == "%$"){
                                  file >> str1;
                                  if(footiv(str1)){
                                    int y = tiv(str1);
                                    for(fraarr[l].anun; fraarr[l].arj > f; fraarr[l].arj += u){
                                      arr[ind].bn /= y;
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }else if(str1 == "~$"){
                             file >> str1;
                          if(tiv(str1)){
                            int u = tiv(str1);
                            file >> str1;
                            if(str1 == "."){
                              file >> str1;
                              if(str1 == "tpi"){
                                file >> str1;
                                if(str1 == "<-"){
                                  file >> str1;
                                  if(str1 == fraarr[l].anun){
                                    file >> str1;
                                    if(str1 == "`"){
                                for(fraarr[l].anun ; fraarr[l].arj > f ; fraarr[l].arj -= u){
                                  std::cout<< fraarr[l].arj<<" ";
                                     }
                                    }else{
                                      std::cout<<"Error: dir ` ";
                                    }
                                  }
                                }
                              }else if(kazangvacum(str1)){
                                int x = kazangvacum(str1);
                                int ind = foofra(str1);
                                file >> str1;
                               
                                if(str1 == "@$"){
                                  file >> str1;
                                  if(footiv(str1)){
                                    int y = tiv(str1);
                                    for(fraarr[l].anun; fraarr[l].arj > f; fraarr[l].arj -= u){
                                      arr[ind].bn += y;
                                    }
                                  }
                                }else if(str1 == "^$"){
                                  file >> str1;
                                  if(footiv(str1)){
                                    int y = tiv(str1);
                                    for(fraarr[l].anun; fraarr[l].arj > f; fraarr[l].arj -= u){
                                      arr[ind].bn *= y;
                                    }
                                  }
                                }else if(str1 == "~$"){
                                  file >> str1;
                                  if(footiv(str1)){
                                    int y = tiv(str1);
                                    for(fraarr[l].anun; fraarr[l].arj > f; fraarr[l].arj -= u){
                                      arr[ind].bn -= y;
                                    }
                                  }
                                }else if(str1 == "%$"){
                                  file >> str1;
                                  if(footiv(str1)){
                                    int y = tiv(str1);
                                    for(fraarr[l].anun; fraarr[l].arj > f; fraarr[l].arj -= u){
                                      arr[ind].bn /= y;
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }else if(str1 == "^$"){
                           file >> str1;
                          if(tiv(str1)){
                            int u = tiv(str1);
                            file >> str1;
                            if(str1 == "."){
                              file >> str1;
                              if(str1 == "tpi"){
                                file >> str1;
                                if(str1 == "<-"){
                                  file >> str1;
                                  if(str1 == fraarr[l].anun){
                                    file >> str1;
                                    if(str1 == "`"){
                                for(fraarr[l].anun ; fraarr[l].arj > f ; fraarr[l].arj *= u){
                                  std::cout<< fraarr[l].arj<<" ";
                                     }
                                    }else{
                                      std::cout<<"Error: dir ` ";
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }else if(str1 == "%$"){
                           file >> str1;
                          if(tiv(str1)){
                            int u = tiv(str1);
                            file >> str1;
                            if(str1 == "."){
                              file >> str1;
                              if(str1 == "tpi"){
                                file >> str1;
                                if(str1 == "<-"){
                                  file >> str1;
                                  if(str1 == fraarr[l].anun){
                                    file >> str1;
                                    if(str1 == "`"){
                                for(fraarr[l].anun ; fraarr[l].arj > f ; fraarr[l].arj /= u){
                                  std::cout<< fraarr[l].arj<<" ";
                                     }
                                    }else{
                                      std::cout<<"Error: dir ` ";
                                    }
                                  }
                                }
                              }else if(kazangvacum(str1)){
                                int x = kazangvacum(str1);
                                int ind = foofra(str1);
                                file >> str1;
                               
                                if(str1 == "@$"){
                                  file >> str1;
                                  if(footiv(str1)){
                                    int y = tiv(str1);
                                    for(fraarr[l].anun; fraarr[l].arj > f; fraarr[l].arj /= u){
                                      arr[ind].bn += y;

                                    }
                                  }
                                }else if(str1 == "^$"){
                                  file >> str1;
                                  if(footiv(str1)){
                                    int y = tiv(str1);
                                    for(fraarr[l].anun; fraarr[l].arj > f; fraarr[l].arj /= u){
                                      arr[ind].bn *= y;
                                    }
                                  }
                                }else if(str1 == "~$"){
                                  file >> str1;
                                  if(footiv(str1)){
                                    int y = tiv(str1);
                                    for(fraarr[l].anun; fraarr[l].arj > f; fraarr[l].arj /= u){
                                      arr[ind].bn -= y;
                                    }
                                  }
                                }else if(str1 == "%$"){
                                  file >> str1;
                                  if(footiv(str1)){
                                    int y = tiv(str1);
                                    for(fraarr[l].anun; fraarr[l].arj > f; fraarr[l].arj /= u){
                                      arr[ind].bn /= y;
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }else if(str1 == "<"){                 ///////////////////////////////////for poqr/////////////
                  file >> str1;
                  int f = 0;
                  f = tiv(str1);
                  if(fraarr[l].arj < f){
                 
                  file >> str1;
                    if(str1 == ":"){
                      file >> str1;
                      if(str1 == fraarr[l].anun){
                        file >> str1;
                        if(str1 == "@$"){
                          file >> str1;
                          if(tiv(str1)){
                            int u = tiv(str1);
                            file >> str1;
                            if(str1 == "."){
                              file >> str1;
                              if(str1 == "tpi"){
                                file >> str1;
                                if(str1 == "<-"){
                                  file >> str1;
                                  if(str1 == fraarr[l].anun){
                                    file >> str1;
                                    if(str1 == "`"){
                                for(fraarr[l].anun ; fraarr[l].arj < f ; fraarr[l].arj += u){
                                  std::cout<< fraarr[l].arj<<" ";
                                     }
                                    }else{
                                      std::cout<<"Error: dir ` ";
                                    }
                                  }
                                }
                              }else if(kazangvacum(str1)){
                                int x = kazangvacum(str1);
                                int ind = foofra(str1);
                                file >> str1;
                               
                                if(str1 == "@$"){
                                  file >> str1;
                                  if(footiv(str1)){
                                    int y = tiv(str1);
                                    for(fraarr[l].anun; fraarr[l].arj < f; fraarr[l].arj += u){
                                      arr[ind].bn += y;
                                    }
                                  }
                                }else if(str1 == "^$"){

                                  file >> str1;
                                  if(footiv(str1)){
                                    int y = tiv(str1);
                                    for(fraarr[l].anun; fraarr[l].arj < f; fraarr[l].arj += u){
                                      arr[ind].bn *= y;
                                    }
                                  }
                                }else if(str1 == "~$"){
                                  
                                  file >> str1;
                                  if(footiv(str1)){
                                   
                                    int y = tiv(str1);
                                    for(fraarr[l].anun; fraarr[l].arj < f; fraarr[l].arj += u){
                                      arr[ind].bn -= y;
                                    }
                                  }
                                }else if(str1 == "%$"){
                                  file >> str1;
                                  if(footiv(str1)){
                                    int y = tiv(str1);
                                    for(fraarr[l].anun; fraarr[l].arj < f; fraarr[l].arj += u){
                                      arr[ind].bn /= y;
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }else if(str1 == "~$"){
                             file >> str1;
                          if(tiv(str1)){
                            int u = tiv(str1);
                            file >> str1;
                            if(str1 == "."){
                              file >> str1;
                              if(str1 == "tpi"){
                                file >> str1;
                                if(str1 == "<-"){
                                  file >> str1;
                                  if(str1 == fraarr[l].anun){
                                    file >> str1;
                                    if(str1 == "`"){
                                for(fraarr[l].anun ; fraarr[l].arj < f ; fraarr[l].arj -= u){
                                  std::cout<< fraarr[l].arj<<" ";
                                     }
                                    }else{
                                      std::cout<<"Error: dir ` ";
                                    }
                                  }
                                }
                              }else if(kazangvacum(str1)){
                                int x = kazangvacum(str1);
                                int ind = foofra(str1);
                                file >> str1;
                               
                                if(str1 == "@$"){
                                  file >> str1;
                                  if(footiv(str1)){
                                    int y = tiv(str1);
                                    for(fraarr[l].anun; fraarr[l].arj < f; fraarr[l].arj -= u){
                                      arr[ind].bn += y;
                                    }
                                  }
                                }else if(str1 == "^$"){
                                  file >> str1;
                                  if(footiv(str1)){
                                    int y = tiv(str1);
                                    for(fraarr[l].anun; fraarr[l].arj < f; fraarr[l].arj -= u){
                                      arr[ind].bn *= y;
                                    }
                                  }
                                }else if(str1 == "~$"){
                                  file >> str1;
                                  if(footiv(str1)){
                                    int y = tiv(str1);
                                    for(fraarr[l].anun; fraarr[l].arj < f; fraarr[l].arj -= u){
                                      arr[ind].bn -= y;
                                    }
                                  }
                                }else if(str1 == "%$"){
                                  file >> str1;
                                  if(footiv(str1)){
                                    int y = tiv(str1);
                                    for(fraarr[l].anun; fraarr[l].arj < f; fraarr[l].arj -= u){
                                      arr[ind].bn /= y;
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }else if(str1 == "^$"){
                           file >> str1;
                          if(tiv(str1)){
                            int u = tiv(str1);
                            file >> str1;
                            if(str1 == "."){
                              file >> str1;
                              if(str1 == "tpi"){
                                file >> str1;
                                if(str1 == "<-"){
                                  file >> str1;
                                  if(str1 == fraarr[l].anun){
                                    file >> str1;
                                    if(str1 == "`"){
                                for(fraarr[l].anun ; fraarr[l].arj < f ; fraarr[l].arj *= u){
                                  std::cout<< fraarr[l].arj<<" ";
                                     }
                                    }else{
                                      std::cout<<"Error: dir ` ";
                                    }
                                  }
                                }
                              }else if(kazangvacum(str1)){
                                int x = kazangvacum(str1);
                                int ind = foofra(str1);
                                file >> str1;
                               
                                if(str1 == "@$"){
                                  file >> str1;
                                  if(footiv(str1)){
                                    int y = tiv(str1);
                                    for(fraarr[l].anun; fraarr[l].arj < f; fraarr[l].arj *= u){
                                      arr[ind].bn += y;
                                    }
                                  }
                                }else if(str1 == "^$"){
                                  file >> str1;
                                  if(footiv(str1)){
                                    int y = tiv(str1);
                                    for(fraarr[l].anun; fraarr[l].arj < f; fraarr[l].arj *= u){
                                      arr[ind].bn *= y;
                                    }
                                  }
                                }else if(str1 == "~$"){
                                  file >> str1;
                                  if(footiv(str1)){
                                    int y = tiv(str1);
                                    for(fraarr[l].anun; fraarr[l].arj < f; fraarr[l].arj *= u){
                                      arr[ind].bn -= y;
                                    }
                                  }
                                }else if(str1 == "%$"){
                                  file >> str1;
                                  if(footiv(str1)){
                                    int y = tiv(str1);
                                    for(fraarr[l].anun; fraarr[l].arj < f; fraarr[l].arj *= u){
                                      arr[ind].bn /= y;
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }else if(str1 == "%$"){
                           file >> str1;
                          if(tiv(str1)){
                            int u = tiv(str1);
                            file >> str1;
                            if(str1 == "."){
                              file >> str1;
                              if(str1 == "tpi"){
                                file >> str1;
                                if(str1 == "<-"){
                                  file >> str1;
                                  if(str1 == fraarr[l].anun){
                                    file >> str1;
                                    if(str1 == "`"){
                                for(fraarr[l].anun ; fraarr[l].arj < f ; fraarr[l].arj /= u){
                                  std::cout<< fraarr[l].arj<<" ";
                                     }
                                    }else{
                                      std::cout<<"Error: dir ` ";
                                    }
                                  }
                                }
                              }else if(kazangvacum(str1)){
                                int x = kazangvacum(str1);
                                int ind = foofra(str1);
                                file >> str1;
                               
                                if(str1 == "@$"){
                                  file >> str1;
                                  if(footiv(str1)){
                                    int y = tiv(str1);
                                    for(fraarr[l].anun; fraarr[l].arj < f; fraarr[l].arj /= u){
                                      arr[ind].bn += y;
                                    }
                                  }
                                }else if(str1 == "^$"){
                                  file >> str1;
                                  if(footiv(str1)){
                                    int y = tiv(str1);
                                    for(fraarr[l].anun; fraarr[l].arj < f; fraarr[l].arj /= u){
                                      arr[ind].bn *= y;
                                    }
                                  }
                                }else if(str1 == "~$"){
                                  file >> str1;
                                  if(footiv(str1)){
                                    int y = tiv(str1);
                                    for(fraarr[l].anun; fraarr[l].arj < f; fraarr[l].arj /= u){
                                      arr[ind].bn -= y;
                                    }
                                  }
                                }else if(str1 == "%$"){
                                  file >> str1;
                                  if(footiv(str1)){
                                    int y = tiv(str1);
                                    for(fraarr[l].anun; fraarr[l].arj < f; fraarr[l].arj /= u){
                                      arr[ind].bn /= y;
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  
                  }
                }
              } 
            }
          }
        }  
      }
    }
    else{                           ///////////////////////////////////////////
      std::string x;
      x = kazangvacum1(str1);
      file >> str1;
      if(str1 == ":"){
        file >> str1;
        if(str1 == x){
          file >> str1;
          if(str1 == ">"){
            file >> str1;
            int f = 0;
            f = tiv(str1);
            if(arr[i].bn > f){
              file >> str1;
              if(str1 == ":"){
                file >> str1;
                if(str1 == x){
                  file >> str1;
                  if(str1 == "@$"){
                    file >> str1;
                    if(tiv(str1)){
                      int u = tiv(str1);
                      file >> str1;
                      if(str1 == "."){
                        file >> str1;
                        if(str1 == "tpi"){
                          file >> str1;
                          if(str1 == "<-"){
                            file >> str1;
                            if(str1 == x){
                              file >> str1;
                              if(str1 == "`"){
                                int ind = foofra(x);
                          for(arr[ind].bn ; arr[ind].bn > f ; arr[ind].bn += u){
                            std::cout<< arr[ind].bn<<" ";
                                }
                                arr[ind].bn = f ;
                              }else{
                                std::cout<<"Error: dir ` ";
                              }
                            }
                          }
                        }else{
                          int ind = foofra(x);
                          for(arr[ind].bn ; arr[ind].bn > f ; arr[ind].bn += u){

                          }
                          arr[ind].bn = f;
                        }
                      }
                    }
                  }else if(str1 == "~$"){
                        file >> str1;
                    if(tiv(str1)){
                      int u = tiv(str1);
                      file >> str1;
                      if(str1 == "."){
                        file >> str1;
                        if(str1 == "tpi"){
                          file >> str1;
                          if(str1 == "<-"){
                            file >> str1;
                            if(str1 == x){
                              file >> str1;
                              if(str1 == "`"){
                                int ind = foofra(x);
                          for(arr[ind].bn ; arr[ind].bn > f ; arr[ind].bn -= u){
                            std::cout<< arr[ind].bn<<" ";
                                }
                                arr[ind].bn = f ;
                              }else{
                                std::cout<<"Error: dir ` ";
                              }
                            }
                          }
                        }else{
                          int ind = foofra(x);
                          for(arr[ind].bn ; arr[ind].bn > f ; arr[ind].bn += u){

                          }
                          arr[ind].bn = f;
                        }
                      }
                    }
                  }else if(str1 == "^$"){
                      file >> str1;
                    if(tiv(str1)){
                      int u = tiv(str1);
                      file >> str1;
                      if(str1 == "."){
                        file >> str1;
                        if(str1 == "tpi"){
                          file >> str1;
                          if(str1 == "<-"){
                            file >> str1;
                            if(str1 == x){
                              file >> str1;
                              if(str1 == "`"){
                                int ind = foofra(x);
                          for(arr[ind].bn ; arr[ind].bn > f ; arr[ind].bn *= u){
                            std::cout<< arr[ind].bn<<" ";
                                }
                                arr[ind].bn = f ;
                              }else{
                                std::cout<<"Error: dir ` ";
                              }
                            }
                          }
                        }else{
                          int ind = foofra(x);
                          for(arr[ind].bn ; arr[ind].bn > f ; arr[ind].bn *= u){

                          }
                          arr[ind].bn = f;
                        }
                      }
                    }
                  }else if(str1 == "%$"){
                      file >> str1;
                    if(tiv(str1)){
                      int u = tiv(str1);
                      file >> str1;
                      if(str1 == "."){
                        file >> str1;
                        if(str1 == "tpi"){
                          file >> str1;
                          if(str1 == "<-"){
                            file >> str1;
                            if(str1 == x){
                              file >> str1;
                              if(str1 == "`"){
                                int ind = foofra(x);
                          for(arr[ind].bn ; arr[ind].bn > f ; arr[ind].bn /= u){
                            std::cout<< arr[ind].bn<<" ";
                                }
                                arr[ind].bn = f ;
                              }else{
                                std::cout<<"Error: dir ` ";
                              }
                            }
                          }
                        }else{
                          int ind = foofra(x);
                          for(arr[ind].bn ; arr[ind].bn > f ; arr[ind].bn /= u){

                          }
                          arr[ind].bn = f;
                        }
                      }
                    }
                  }
                }
              }
            }
          }else if(str1 == "<"){                 ///////////////////////////////////for poqr/////////////
            file >> str1;
            int f = 0;
            f = tiv(str1);
            if(arr[i].bn < f){
            
            file >> str1;
              if(str1 == ":"){
                file >> str1;
                if(str1 == x){
                  file >> str1;
                  if(str1 == "@$"){
                    file >> str1;
                    if(tiv(str1)){
                      int u = tiv(str1);
                      file >> str1;
                      if(str1 == "."){
                        file >> str1;
                        if(str1 == "tpi"){
                          file >> str1;
                          if(str1 == "<-"){
                            file >> str1;
                            if(str1 == x){
                              file >> str1;
                              if(str1 == "`"){
                                int ind = foofra(x);
                          for(arr[ind].bn ; arr[ind].bn < f ; arr[ind].bn += u){
                            std::cout<< arr[ind].bn<<" ";
                                }
                                arr[ind].bn = f ;
                              }else{
                                std::cout<<"Error: dir ` ";
                              }
                            }
                          }
                        }else{
                          int ind = foofra(x);
                          for(arr[ind].bn ; arr[ind].bn < f ; arr[ind].bn += u){

                          }
                          arr[ind].bn = f;
                        }
                      }
                    }
                  }else if(str1 == "~$"){
                        file >> str1;
                    if(tiv(str1)){
                      int u = tiv(str1);
                      file >> str1;
                      if(str1 == "."){
                        file >> str1;
                        if(str1 == "tpi"){
                          file >> str1;
                          if(str1 == "<-"){
                            file >> str1;
                            if(str1 == x){
                              file >> str1;
                              if(str1 == "`"){
                                int ind = foofra(x);
                          for(arr[ind].bn ; arr[ind].bn < f ; arr[ind].bn -= u){
                            std::cout<< arr[ind].bn<<" ";
                                }
                                arr[ind].bn = f ;
                              }else{
                                std::cout<<"Error: dir ` ";
                              }
                            }
                          }
                        }else{
                          int ind = foofra(x);
                          for(arr[ind].bn ; arr[ind].bn < f ; arr[ind].bn -= u){

                          }
                          arr[ind].bn = f;
                        }
                      }
                    }
                  }else if(str1 == "^$"){
                      file >> str1;
                    if(tiv(str1)){
                      int u = tiv(str1);
                      file >> str1;
                      if(str1 == "."){
                        file >> str1;
                        if(str1 == "tpi"){
                          file >> str1;
                          if(str1 == "<-"){
                            file >> str1;
                            if(str1 == x){
                              file >> str1;
                              if(str1 == "`"){
                                int ind = foofra(x);
                          for(arr[ind].bn ; arr[ind].bn < f ; arr[ind].bn *= u){
                            std::cout<< arr[ind].bn<<" ";
                                }
                                arr[ind].bn = f ;
                              }else{
                                std::cout<<"Error: dir ` ";
                              }
                            }
                          }
                        }else{
                          int ind = foofra(x);
                          for(arr[ind].bn ; arr[ind].bn < f ; arr[ind].bn *= u){

                          }
                          arr[ind].bn = f;
                        }
                      }
                    }
                  }else if(str1 == "%$"){
                      file >> str1;
                    if(tiv(str1)){
                      int u = tiv(str1);
                      file >> str1;
                      if(str1 == "."){
                        file >> str1;
                        if(str1 == "tpi"){
                          file >> str1;
                          if(str1 == "<-"){
                            file >> str1;
                            if(str1 == x){
                              file >> str1;
                              if(str1 == "`"){
                                int ind = foofra(x);
                          for(arr[ind].bn ; arr[ind].bn < f ; arr[ind].bn /= u){
                            std::cout<< arr[ind].bn<<" ";
                                }
                                arr[ind].bn = f ;
                              }else{
                                std::cout<<"Error: dir ` ";
                              }
                            }
                          }
                        }else{
                          int ind = foofra(x);
                          for(arr[ind].bn ; arr[ind].bn < f ; arr[ind].bn /= u){

                          }
                          arr[ind].bn = f;
                        }
                      }
                    }
                  }
                }
              }
            
            }
          }
        } 

      }

      
    }

  }

}


        
}
  


  std::cout<<std::endl;
  std::cout<<std::endl;
  std::cout<<std::endl<<arr[1].name<<arr[1].bn;
  std::cout<<std::endl<<arr[2].name<<arr[2].amb;
  std::cout<<std::endl;
  file.close();
  return 0;
}     
#include<iostream>
class game {
public:
    game() {
        for(int i = 0 ;i < 3;i++) {
            arr[i] = new Gamer[3];
        }
    }
    void gaming() 
    {
        int x;
        int y;
        char xNull = '-';
        bool flag = true;
        bool hert = true;
        while (flag)
        {
            if(hert) {
                xNull = 'X';
                hert = false;
            } else {
                xNull = 'O';
                hert = true;
            }
            std::cin >> x >> y ;
            go(x,y,xNull);
            flag = checkWin();
        }
    }
    ~game()
    {
        std::cout << "\n!!! the game finsh !!!\n";  
        for(int i = 0;i < 3;i++) {
            delete [] arr[i];
        } 
        delete [] arr;
    }
private:
    void go(int x ,int y,char xNull) 
    {
        --x; --y;
        if(check(x,y)) {
            if(x > 2 && x < 0 && y > 2 && y < 0 ) {
                
                std::cout << "SEGMENTATION";
                return;
            }
            if(xNull == 'X' || xNull == 'O') {
                Gamer obj(x,y,xNull);
                arr[obj.x][obj.y] = obj;
            } else {
                std::cout << "sxal nshan";
                return;
            }
            std::cout << std::endl;
            print();
        } 
    }
    void print()
    {
        for(int i = 0; i < 3;i++) {
            for(int j = 0; j < 3;j++) {
                std::cout << "|" << arr[i][j].xNull << "|";
            }                       
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    bool check(int x,int y) 
    {
        if(arr[x][y].xNull == 'X' || arr[x][y].xNull == 'O') {
            std::cout << "inches anum ape!!!!!!!!\n";
            return false;
        } else {
            return true; }
    }
    bool checkWin() 
    {
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 1;++j) {
                if(arr[i][j].xNull != '-' && arr[i][j + 1].xNull != '-' && arr[i][j + 2].xNull != '-') {
                    if(arr[i][j].xNull == arr[i][j + 1].xNull && arr[i][j + 1].xNull == arr[i][j + 2].xNull) {
                        std::cout << arr[i][j].xNull << " WON ";
                        return false;
                    }
                }
                if(i == j) {
                    if(arr[i][j].xNull != '-' && arr[i + 1][j + 1].xNull != '-' && arr[i + 2][j + 2].xNull != '-') {
                        if(arr[i][j].xNull == arr[i + 1][j + 1].xNull && arr[i + 1][j + 1].xNull == arr[i + 2][j + 2].xNull) {
                            std::cout << arr[i][j].xNull << " WON ";
                            return false;
                        }
                    }
                }
                if(i == 3 - j - 1) {
                    if(arr[i][j].xNull != '-' && arr[i - 1][j + 1].xNull != '-' && arr[i - 2][j + 2].xNull != '-') {
                        if(arr[i][j].xNull == arr[i - 1][j + 1].xNull && arr[i - 1][j + 1].xNull == arr[i - 2][j + 2].xNull) {
                            std::cout << arr[i][j].xNull << " WON ";
                            return false;
                        }
                    }
                }
                if(arr[j][i].xNull != '-' && arr[j + 1][i].xNull != '-' && arr[j + 2][i].xNull != '-') {
                    if(arr[j][i].xNull == arr[j + 1][i].xNull && arr[j + 1][i].xNull == arr[j + 2][i].xNull) {
                        std::cout << arr[j][i].xNull << " WON ";
                        return false;
                    }
                }
            }
        }
        return true;
    }
private:
    struct Gamer {
        Gamer() {
            xNull = '-';
        }
        Gamer(int x,int y,char xNull) {
            this->x = x;
            this->y = y;
            this->xNull = xNull;
        }
        int x;
        int y;
        char xNull;
    };
private:
    Gamer ** arr = new Gamer *[3];
};

int main()
{
    
    game obj;
    obj.gaming();    
}
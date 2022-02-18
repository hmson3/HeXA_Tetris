#include <iostream>
#include "block.cpp"
#include <windows.h>
#include <conio.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

class map
{
private:
    int size;
    int x_pos;
    int y_pos;
    int pMap[10][10];
    int stack[10][10];
public:
    map() : size(10), x_pos(0), y_pos(0), pMap{ }, stack{ }
    {
    }

    ~map()
    {

    }
    
    void posinit()
    {
        x_pos = 0;
        y_pos = 0;
    }
    //x_pos,y_pos에 블록 놓기
    template<class T>
    void setblock(T s)
    {

        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                
                if (1 == pMap[y_pos + i][x_pos + j] && 0 == s.getinfo(i, j));
                else
                    pMap[y_pos + i][x_pos + j] = s.getinfo(i, j);
            }
        }
    }
    //x_pos,y_pos에 블록 없애기
    template<class T>
    void unblock(T s)
    {
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (1 == pMap[y_pos + i][x_pos + j] && 0 == s.getinfo(i, j));
                else
                    pMap[y_pos + i][x_pos + j] = 0;
            }
        }
    }
    //콘솔창 초기화
    void mapinit()
    { 
        system("cls");
    }
    //블록 한칸 내리기
    template<class T>
    void down(T s)
    {
        unblock<T>(s);
        ++y_pos;
        setblock<T>(s);
    }
    //블록 한칸 왼쪽으로
    template<class T>
    void left(T s)
    {
   
        unblock<T>(s);
        --x_pos;
        setblock<T>(s);
    }
    //블록 한칸 오른쪽으로
    template<class T>
    void right(T s)
    {
        unblock<T>(s);
        ++x_pos;
        setblock<T>(s);
    }
    //맵 출력
    void showmap()
    {

        for (int i = 0; i < size; ++i)
        {
            std::cout << "■";
        }
        std::cout << std::endl;
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                if (1 == pMap[i][j])
                    std::cout << "■";
                else
                    std::cout << "□";
            }
            std::cout << std::endl;
        }
        for (int i = 0; i < size; ++i)
        {
            std::cout << "■";
        }
        std::cout << std::endl;
    }
    //키 입력 받고 작동하기
    template<class T>
    void getkey(T s)
    {

        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {

                pMap[i][j] = stack[i][j];
            }
        }
        while (true)
        {   

            if (size - 3 == y_pos && 1 == s.getinfo(2, 0)) break;
            else if (size - 3 == y_pos && 1 == s.getinfo(2, 1)) break;
            else if (size - 3 == y_pos && 1 == s.getinfo(2, 2)) break;
            else if (size - 2 == y_pos && 1 == s.getinfo(1, 0)) break;
            else if (size - 2 == y_pos && 1 == s.getinfo(1, 1)) break;
            else if (size - 2 == y_pos && 1 == s.getinfo(1, 2)) break;
            else if (1 == pMap[y_pos + 3][x_pos] && 1 == s.getinfo(2, 0)) break;
            else if (1 == pMap[y_pos + 3][x_pos + 1] && 1 == s.getinfo(2, 1)) break;
            else if (1 == pMap[y_pos + 3][x_pos + 2] && 1 == s.getinfo(2, 2)) break;
            else if (1 == pMap[y_pos + 2][x_pos] && 1 == s.getinfo(1, 0) && 0 == s.getinfo(2, 0)) break;
            else if (1 == pMap[y_pos + 2][x_pos + 1] && 1 == s.getinfo(1, 1) && 0 == s.getinfo(2, 1)) break;
            else if (1 == pMap[y_pos + 2][x_pos + 2] && 1 == s.getinfo(1, 2) && 0 == s.getinfo(2, 2)) break;

            int i = _getch();
            i = _getch();
            switch (i)
            {
            case UP:
                if (size - 2 == x_pos && 1 == s.getinfo(0, 1)) left<T>(s);
                else if (size - 2 == x_pos && 1 == s.getinfo(1, 1)) left<T>(s);
                else if (size - 2 == x_pos && 1 == s.getinfo(2, 1)) left<T>(s);
                else if (-1 == x_pos && 1 == s.getinfo(0, 1)) right<T>(s);
                else if (-1 == x_pos && 1 == s.getinfo(1, 1)) right<T>(s);
                else if (-1 == x_pos && 1 == s.getinfo(2, 1)) right<T>(s);
                mapinit();
                unblock<T>(s);
                s.rotate();

                setblock<T>(s);
                showmap();
                break;
            case DOWN:
                
                if (size - 3 == y_pos && 1 == s.getinfo(2, 0)) break;
                else if (size - 3 == y_pos && 1 == s.getinfo(2, 1)) break;
                else if (size - 3 == y_pos && 1 == s.getinfo(2, 2)) break;           
                else if (size - 2 == y_pos && 1 == s.getinfo(1, 0)) break;
                else if (size - 2 == y_pos && 1 == s.getinfo(1, 1)) break;
                else if (size - 2 == y_pos && 1 == s.getinfo(1, 2)) break;
               

                mapinit();
                down<T>(s);
                showmap();
                break;
            case LEFT:
                if (0 == x_pos && 1 == s.getinfo(0, 0)) break;
                else if (0 == x_pos && 1 == s.getinfo(1, 0)) break;
                else if (0 == x_pos && 1 == s.getinfo(2, 0)) break;
                else if (-1 == x_pos && 1 == s.getinfo(0, 1)) break;
                else if (-1 == x_pos && 1 == s.getinfo(1, 1)) break;
                else if (-1 == x_pos && 1 == s.getinfo(2, 1)) break;
                else if (1 == pMap[y_pos][x_pos - 1] && 1 == s.getinfo(0, 0)) break;
                else if (1 == pMap[y_pos + 1][x_pos - 1] && 1 == s.getinfo(1, 0)) break;
                else if (1 == pMap[y_pos + 2][x_pos - 1] && 1 == s.getinfo(2, 0)) break;
                else if (1 == pMap[y_pos][x_pos] && 1 == s.getinfo(0, 1) && 0 == s.getinfo(0, 0)) break;
                else if (1 == pMap[y_pos + 1][x_pos] && 1 == s.getinfo(1, 1) && 0 == s.getinfo(1, 0)) break;
                else if (1 == pMap[y_pos + 2][x_pos] && 1 == s.getinfo(2, 1) && 0 == s.getinfo(2, 0)) break;
                mapinit();
                left<T>(s);
                showmap();
                break;
            case RIGHT:
                if (size - 3 == x_pos && 1 == s.getinfo(0, 2)) break;
                else if (size - 3 == x_pos && 1 == s.getinfo(1, 2)) break;
                else if (size - 3 == x_pos && 1 == s.getinfo(2, 2)) break;
                else if (size - 2 == x_pos && 1 == s.getinfo(0, 1)) break;
                else if (size - 2 == x_pos && 1 == s.getinfo(1, 1)) break;
                else if (size - 2 == x_pos && 1 == s.getinfo(2, 1)) break;
                else if (1 == pMap[y_pos][x_pos + 3] && 1 == s.getinfo(0, 2)) break;
                else if (1 == pMap[y_pos + 1][x_pos + 3] && 1 == s.getinfo(1, 2)) break;
                else if (1 == pMap[y_pos + 2][x_pos + 3] && 1 == s.getinfo(2, 2)) break;
                else if (1 == pMap[y_pos][x_pos + 2] && 1 == s.getinfo(0, 1) && 0 == s.getinfo(0, 2)) break;
                else if (1 == pMap[y_pos + 1][x_pos + 2] && 1 == s.getinfo(1, 1) && 0 == s.getinfo(1, 2)) break;
                else if (1 == pMap[y_pos + 2][x_pos + 2] && 1 == s.getinfo(2, 1) && 0 == s.getinfo(2, 2)) break;
                mapinit();
                right<T>(s);
                showmap();
                break;
            }
            
        }
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                stack[i][j] = pMap[i][j];
            }
        }
        
    }
    //만약 한 줄이 다차면 사라지게 하고 위에 있는 것들 내리기
    void oneline()
    {
        
        for (int i = 0; i < size; ++i)
        {
            int one = 0;
            for (int j = 0; j < size; ++j)
            {
                if (1 == stack[i][j]) 
                    ++one;
            }
            if (10 == one)
            {
                for(int k = 0; k < size; ++k)
                    stack[i][k] = 0;
                for (int o = i -1; o >= 0; --o)
                {
                    for (int k = 0; k < size; ++k)
                    {
                        if (1 == stack[o][k])
                        {
                            stack[o + 1][k] = stack[o][k];
                            stack[o][k] = 0;
                        }
                    }
                }
            }
        }
    }


};


void tetris()
{
    map dd;
    oh o;
    stick l;
    sshape s;
    zshape z;
    nieun n;
    re_nieun r;
    nemo m;

    while (true)
    {
        dd.oneline();
        int i = rand() % 7;
        switch (i)
        {
        case 0:
            
            dd.setblock<oh>(o);
            dd.showmap();
            dd.getkey<oh>(o);
            
            dd.posinit();
            dd.mapinit();
            break;
        case 1:
            
            dd.setblock<stick>(l);
            dd.showmap();
            dd.getkey<stick>(l);
            
            dd.posinit();
            dd.mapinit();
            break;
        case 2:
            
            dd.setblock<sshape>(s);
            dd.showmap();
            dd.getkey<sshape>(s);
            
            dd.posinit();
            dd.mapinit();
            break;
        case 3:
           
            dd.setblock<zshape>(z);
            dd.showmap();
            dd.getkey<zshape>(z);
            
            dd.posinit();
            dd.mapinit();
            break;
        case 4:
            
            dd.setblock<nieun>(n);
            dd.showmap();
            dd.getkey<nieun>(n);
            
            dd.posinit();
            dd.mapinit();
            break;
        case 5:
            
            dd.setblock<re_nieun>(r);
            dd.showmap();
            dd.getkey<re_nieun>(r);
            dd.posinit();
            dd.mapinit();
            break;
        case 6:
            
            dd.setblock<nemo>(m);
            dd.showmap();
            dd.getkey<nemo>(m);
            
            dd.posinit();
            dd.mapinit();
            break;
        }
    }
}


int main()
{
    tetris();

   
    
    return 0;
}
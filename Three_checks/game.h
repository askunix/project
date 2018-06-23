#ifndef __GAME_H__
#define __GAME_H__

#include<stdio.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>

#define ROW 3
#define COL 3

void InitBoard(char board[ROW][COL], int row, int col);
void Display(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row,int col);
int IsWin(char board[ROW][COL], int row, int col);
//char IsFull(char board[ROW][COL], int row, int col);
//x ����Ӯ            0���Ӯ                    ' 'ÿ����           'Q'ƽ��
#endif

#include "Maze.h"


int main(int argc, char *argv[]) 
{
	MazeType maze[N][N];
	PosType start, end;
	//    SElemType_Sq e;
	char again = 'y';
	int flag = 0;

	while (again == 'y')
	{
		InitMaze(maze, &start, &end);
		ShowMaze(maze);
		flag = MazePath(maze, start, end);
		if (flag == OK)
		{
			printf("\n  We made it!!!");
		}
		else 
		{
			printf("\n Mission failed.");
		}
		printf("Wanna try again?(y/n)");
		scanf("%c", &again);
	}
	return 0;
}

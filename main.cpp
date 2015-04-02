//
//  main.cpp
//  Sudoku
//
//  Created by 刘彦超 on 14/11/1.
//  Copyright (c) 2014年 刘彦超. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>

//#define MYDEBUG

using namespace std;

int grid[9][9];
int solutionCnt = 0;
int record[9][9];

int rowcheck[9][10];
int colcheck[9][10];
int matcheck[9][10];

struct Sustate {
  int row;
  int col;
  int mat;
  int cnt;
};

typedef struct Sustate Sustate;

vector<Sustate> pos;

void printSudoku();

bool placeNum(int num, Sustate state);

bool myCmp(Sustate s1,Sustate s2);

void findSolution(int visit);

int main() {
  //freopen("data.in", "r", stdin);
  int testcase = 0, No_puzzle = 0, index = 0;
  char inputChar;
  scanf("%d", &testcase);
  while (testcase--) {
    No_puzzle++;
    index = 0;
    solutionCnt = 0;
    pos.clear();
    memset(rowcheck, 0, sizeof(rowcheck));
    memset(colcheck, 0, sizeof(colcheck));
    memset(matcheck, 0, sizeof(matcheck));
    while (index < 81) {
      inputChar = getchar();
      if (inputChar == '_') {
	Sustate tmp;
	tmp.row=index/9;
	tmp.col=index%9;
	tmp.mat=(tmp.row/3)*3+(tmp.col/3);
	tmp.cnt=0;
	grid[tmp.row][tmp.col] = 0;
	pos.push_back(tmp);
	index++;
      } else if (inputChar > '0' && inputChar <= '9') {
	int row = index / 9;
	int col = index % 9;
	int mat = (row / 3) * 3 + (col / 3);
	grid[row][col] = inputChar - '0';
	rowcheck[row][grid[row][col]] = 1;
	rowcheck[row][0]++;
	colcheck[col][grid[row][col]] = 1;
	colcheck[col][0]++;
	matcheck[mat][grid[row][col]] = 1;
	matcheck[mat][0]++;
	index++;
      }
    }
    if (pos.empty()) {
      printf("Puzzle %d solution is\n",No_puzzle);
      memcpy(record, grid, sizeof(grid));
      printSudoku();
    }else{
      for (int i=0; i<(int)pos.size(); i++) {
	pos[i].cnt+=rowcheck[pos[i].row][0]+colcheck[pos[i].col][0]+matcheck[pos[i].mat][0];
      }
      sort(pos.begin(), pos.end(),myCmp);
      findSolution(0);
      if (solutionCnt == 1) {
	printf("Puzzle %d solution is\n", No_puzzle);
	printSudoku();
      } else {
	printf("Puzzle %d has ", No_puzzle);
	if (solutionCnt == 0)
	  printf("no solution\n");
	else
	  printf("%d solutions\n", solutionCnt);
      }
    }
#ifdef MYDEBUG
    printf("time past: %.2fs\n",(double)clock()/CLOCKS_PER_SEC);
#endif
    if (testcase != 0)
      printf("\n");
  }
  return 0;
}

void printSudoku() {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      printf("%d", record[i][j]);
    }
    printf("\n");
  }
}

bool placeNum(int num, Sustate state) {
  return !(rowcheck[state.row][num] || colcheck[state.col][num] || matcheck[state.mat][num]);
}

void findSolution(int visit) {
  int num = 1;
  if (visit < (int) pos.size()) {
    while (num <= 9) {
      if (placeNum(num, pos[visit])) {
	if (visit >= (int) pos.size() - 1) {
	  grid[pos[visit].row][pos[visit].col] = num;
	  if (solutionCnt == 0) {
	    memcpy(record, grid, sizeof(grid));
	  }
	  solutionCnt++;
	  return;
	} else{
	  rowcheck[pos[visit].row][num] = 1;
	  colcheck[pos[visit].col][num] = 1;
	  matcheck[pos[visit].mat][num] = 1;
	  grid[pos[visit].row][pos[visit].col] = num;
	  findSolution(visit + 1);
	  rowcheck[pos[visit].row][num] = 0;
	  colcheck[pos[visit].col][num] = 0;
	  matcheck[pos[visit].mat][num] = 0;
	}
	//grid[row][col] = 0;
      }
      num++;
    }
  }
}
bool myCmp(Sustate s1,Sustate s2){
  return s1.cnt>s2.cnt;
}                                 
